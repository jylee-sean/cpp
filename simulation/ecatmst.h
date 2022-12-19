/**
 * @brief		EtherCAT master class based on KPA stack
 * @details		
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */


#ifndef __SSI_ECATMST_H__
#define __SSI_ECATMST_H__

#include "config.h"

#include <cerrno>
#include <cassert>
#include <cstdint>
#include <cstddef>
#include <cstdlib>

#include <atomic>
#include <vector>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <functional>
#include <syslog.h>

#include <dmkpa.h>
#include <dmkparpc.h>
#include <ecatsvr.h>
#include <ecatmkpa.h>
#include <mkpaconfig.h>
#include <eh/ecatslave_eh.h>
#include <eh/ecattopology_eh.h>
#include <eh/ecatmaster_eh.h>

#include <ccl/event.h>
#include <ccl/singleton.h>

#include <ssi/config.h>
#include <ssi/env.h>
#include <ssi/copi.h>
#include <ssi/comst.h>
#include <ssi/priority.h>
#include <ssi/exception.h>

#include <ssi/kpa_sync.h>
#include <ssi/kpa_event.h>

#include <sys/syspage.h>
#include <sys/neutrino.h>

// koenig-pa made a mistake obviously
// a header cannot generate C function signature, because there's no extern "C" declaration 
#if defined(__cplusplus)
extern "C" {
	#include <scommon/mkpaauxiliary.h>
	#include <scommon/mkpasyncfeedback.h>
}
#endif


#define ECATMST_RESTRICT_PDO

#if !defined(KPA_TIMEOUT_INFINITY)
namespace { constexpr ECAT_DWORD KPA_TIMEOUT_INFINITY = static_cast<ECAT_DWORD>(-1); }
#endif

#if !defined(MAILBOX_LIST_TYPE)
namespace { constexpr ECAT_WORD MAILBOX_LIST_TYPE = 1u; }
#endif

namespace ssi
{
	class ecatmst : public comst, public ccl::event::subject<ecatmst>
	{
		friend class ccl::singleton<ecatmst>;

	public:
		using comst::event;
		using comst::sync_done;

		using ccl::event::subject<ecatmst>::attach;
		using ccl::event::subject<ecatmst>::detach;
		using ccl::event::subject<ecatmst>::notify;

		// event from ecatmst
		class isync_done : public ccl::event::base { };

		enum struct mode_t
		{
			/**
			 * synchronous master mode
			 * there is no separate application cycle in constrast to asynchronous mode.
			 * all control algorithms are implemented in a callback function which is called at every master cycle
			 */
			synchronous,
			/**
			 * application task, which implements control algorithms, and a master cycle,
			 * which updates process image, run indenpendently
			 * and the callback is called at the beginning of every master cycle
			 */
			asynchronous
		};

		/**
		 * EtherCAT master & slaves state definition
		 * the values are same with KPA API's.
		 */
		enum struct state_t
		{
			init = EcatStateI, 
			pre_operational = EcatStateP,
			safe_operational = EcatStateS,
			operational = EcatStateO,
			bootstrap = EcatStateB
		};

		enum struct coe_service_t
		{
			upload = coeServiceUpload,
			download = coeServiceDownload,
			caupload = coeServiceCAUpload,
			cadownload = coeServiceCADownload
		};

		using callback_t = std::function<int(void*)>;

		/**
		 * KPA EtherCAT variables
		 */
		struct kpa_t
		{
			ECAT_HANDLE handle;
			ECAT_HANDLE server;
			ECAT_WORD adapter_index;
			const ECAT_WCHAR* adapter_name[2];
			std::string eni_file;
			ECAT_BYTE state;
			ECAT_DWORD cycle_time;
			ECAT_DWORD sub_cycle_time;
			kpa_event_handler_t* event_handler;
			ECAT_WORD nic0_slave_count;
			ECAT_WORD nic1_slave_count;
		};

		/**
		 * set up ecatmst parameters & initialize it
		 * @return		nullptr on success, ptr to string contains error message
		 * @exception	throws ssi::ecat_error on failure of KPA API
		 * 				throws ssi::runtime_error on fail
		 */
		const char* init(const mode_t mode, const callback_t callback, const char* const eni_file, const std::chrono::microseconds cycle_time, const std::chrono::microseconds sub_cycle_time) {
			ECAT_RESULT result;
			ECAT_WORD input_size;
			ECAT_WORD output_size;

			this->_clk = 0u;
			this->_tick = cycle_time;
			this->_mode = mode;
			this->_sync_cnt = 0;
			this->_sync_coef = 1;
			this->_callback = callback;
			this->_kpa.eni_file = std::string(eni_file);
			this->_kpa.cycle_time = static_cast<ECAT_DWORD>(std::chrono::microseconds(cycle_time).count());
			this->_kpa.sub_cycle_time = static_cast<ECAT_DWORD>(std::chrono::microseconds(sub_cycle_time).count());
			this->_kpa.handle = ECAT_NULL;
			this->_kpa.server = ECAT_NULL;
			this->_kpa.state = static_cast<ECAT_BYTE>(EcatState::EcatStateNotSet);
			this->_kpa.event_handler = ECAT_NULL;
			this->_kpa.nic0_slave_count = static_cast<ECAT_WORD>(0);
			this->_kpa.nic1_slave_count = static_cast<ECAT_WORD>(0);

			do {
				if(ECAT_FAILED(result = KPAPrintMasterVersion()))
					throw ssi::ecat_error("checking master version failed", result);
				if(ECAT_FAILED(result = KPAGetAdapterName(_def::primary_adapter_index, &_kpa.adapter_name[0])))
					throw ssi::ecat_error("cannot get primay network adapter name", result);
				if(ECAT_FAILED(result = KPAGetAdapterName(_def::redundancy_adapter_index, &_kpa.adapter_name[1])))
					throw ssi::ecat_error("cannot get redundancy network adapter name", result);
				if(ECAT_FAILED(result = KPACreateMaster(&_kpa.handle)))
					throw ssi::ecat_error("cannot create master instance", result);
				if(ECAT_FAILED(result = kpa_sync_start_sync_thread(_kpa.handle, &_kpa_sync_ctrl_handler, static_cast<ECAT_LPVOID>(this))))
					throw ssi::ecat_error("cannot start sync thread", result);
				if(ECAT_FAILED(result = KPAConnectMaster(_kpa.handle, static_cast<ECAT_DWORD>(ECAT_MASTER_REDUNDANCY_TYPE_REDUNDANCY), _kpa.adapter_name[0], _kpa.adapter_name[1], ECAT_NULL)))
					throw ssi::ecat_error("cannot connect master", result);
				if(ECAT_FAILED(result = KPALoadConfiguration(_kpa.handle, _kpa.eni_file.c_str())))
					throw ssi::ecat_error("cannot load configuration", result);
				if(ECAT_FAILED(result = KPAStartCyclicOperation(_kpa.handle, _kpa.cycle_time, _kpa.sub_cycle_time, static_cast<ECAT_DWORD>(ssi::priority::ecat_kpa_master))))
					throw ssi::ecat_error("cannot start cyclic operation", result);
				if(ECAT_FAILED(result = KPASetAutoRecoveryTimeout(_kpa.handle, static_cast<ECAT_DWORD>(KPA_MASTER_AUTORECOVERY_TIMEOUT_MS))))
					throw ssi::ecat_error("cannot set autorecovery timeout", result);
				if(ECAT_FAILED(result = KPAGetProcessImageSize(_kpa.handle, &input_size, &output_size)))
					throw ssi::ecat_error("could not get process image size", result);
				if(ECAT_FAILED(result = kpa_event_handler_create(_kpa.handle, &_kpa.event_handler, static_cast<void*>(this))))
					throw ssi::ecat_error("cannot create event handler object", result);
				// if(ECAT_FAILED(result = kpa_event_handler_add_event(_kpa.event_handler,
				// 													static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_TOPOLOGY_CHANGE(ECAT_MASTER_EVENT_SEVERITY_WARNING|ECAT_MASTER_EVENT_TOPOLOGY_CHANGE_ERROR)),
				// 													static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_MASK_EVENT),
				// 													&_kpa_event_handler_topology)))
				// 	throw ssi::ecat_error("cannot add event to listen", result);
				if(ECAT_FAILED(result = kpa_event_handler_add_event(_kpa.event_handler,
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_NIC_N_COUNT_CHANGE(_def::primary_adapter_index, ECAT_MASTER_EVENT_SEVERITY_INFO)),
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_MASK_EVENT),
																	&_kpa_event_handler)))
					throw ssi::ecat_error("cannot add event to listen", result);
				if(ECAT_FAILED(result = kpa_event_handler_add_event(_kpa.event_handler,
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_NIC_N_COUNT_CHANGE(_def::redundancy_adapter_index, ECAT_MASTER_EVENT_SEVERITY_INFO)),
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_MASK_EVENT),
																	&_kpa_event_handler)))
					throw ssi::ecat_error("cannot add event to listen", result);
				if(ECAT_FAILED(result = kpa_event_handler_add_event(_kpa.event_handler,
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_STATE_CHANGE(ECAT_MASTER_EVENT_SEVERITY_ERROR)),
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_MASK_EVENT),
																	&_kpa_event_handler)))
					throw ssi::ecat_error("cannot add event to listen", result);
				if(ECAT_FAILED(result = kpa_event_handler_add_event(_kpa.event_handler,
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_BUS_STATUS_CHANGE(ECAT_MASTER_EVENT_SEVERITY_ERROR)),
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_MASK_EVENT),
																	&_kpa_event_handler)))
					throw ssi::ecat_error("cannot add event to listen", result);
				if(ECAT_FAILED(result = kpa_event_handler_add_event(_kpa.event_handler,
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_ID_ALL),
																	static_cast<ECAT_DWORD>(ECAT_MASTER_EVENT_MASK_ALL),
																	ECAT_NULL)))
					throw ssi::ecat_error("cannot add event to listen", result);
				if(ECAT_FAILED(result = kpa_event_handler_start(_kpa.event_handler)))
					throw ssi::ecat_error("cannot start event handler", result);
			}while(false);

			try {
				(void)_pi.input.resize(static_cast<size_t>(input_size));
				(void)_pi.output.resize(static_cast<size_t>(output_size));
			} catch (const ssi::invalid_argument& e) {
				throw ssi::runtime_error("process image overflow");
			}

			_sync_pred = false;
			return nullptr;
		}

		/**
		 * internal EtherCAT master stack finalization function called by destructor or constructor facing an error.
		 * @return		nullptr on success, ptr to string contains error message
		 * @exception	throws ssi::ecat_error on failure of KPA API
		 */
		const char* fini() {
			if(_mode == mode_t::synchronous) {
				(void)bind(nullptr);
			} else {
				detach<isync_done>();
				detach<sync_done>();
				detach<event>();
			}

			// from now, all ecatmst::wait_for() returns immediately
			_sync_pred = true;
			if(_kpa.handle != ECAT_NULL) {
				ECAT_RESULT result = ECAT_S_OK;
				(void)transit(state_t::init);

				try { (void)rpcserver(false); }
				catch(...) { throw; }

				if(_kpa.event_handler != ECAT_NULL) {
					if(ECAT_FAILED(result = kpa_event_handler_stop(_kpa.event_handler)))
						throw ssi::ecat_error("cannot stop event handler", result);
					if(ECAT_FAILED(result = kpa_event_handler_destroy(_kpa.event_handler)))
						throw ssi::ecat_error("cannot destroy event handler", result);
				}

				if(ECAT_FAILED(result = kpa_sync_stop_sync_thread(_kpa.handle)))
					throw ssi::ecat_error("cannot stop sync thread", result);
				if(ECAT_FAILED(result = KPARequestMasterState(_kpa.handle, static_cast<ECAT_BYTE>(EcatState::EcatStateI))))
					throw ssi::ecat_error("cannot request master state", result);
				if(ECAT_FAILED(result = KPAStopCyclicOperation(_kpa.handle)))
					throw ssi::ecat_error("cannot stop cyclic operation", result);
				if(ECAT_FAILED(result = KPADisconnectMaster(_kpa.handle)))
					throw ssi::ecat_error("cannot disconnect master", result);
				if(ECAT_FAILED(result = KPAFreeMaster(_kpa.handle)))
					throw ssi::ecat_error("cannot free master", result);
			}
			// prevent finalizing twice
			_kpa.handle = ECAT_NULL;
			return nullptr;
		}

		/**
		 * get current EtherCAT master cycle counter
		 * @return		always _clk
		 * @exception	throws ssi::runtime_error on failure of KPA API
		 */
		inline uint64_t clk() const { return _clk; }

		enum struct epoch_t { posix, kpa };
		/**
		 * get current time from EtherCAT master stack
		 * @param		epoch time epoch
		 * @return		always clock counter of the EtherCAT master
		 * @exception	throws ssi::ecat_error on failure of KPA API
		 */
		inline uint64_t time(epoch_t epoch = epoch_t::posix) {
			ECAT_RESULT result;
			ECAT_UINT64 master_time = static_cast<uint64_t>(std::numeric_limits<uint64_t>::max());
			ECAT_WORD size=sizeof(master_time);
			if(_kpa.handle != ECAT_NULL && ECAT_FAILED(result = KPAGetMasterTime(_kpa.handle, reinterpret_cast<ECAT_BYTE*>(&master_time), &size)))
				throw ssi::ecat_error("cannot get master time", result);
			// convert time epoch
			// magic number 946684800 came from the calculation (60 * 60 * 24 * 365 * 30) + (60 * 60 * 24 * static_cast<int>(30/4))
			// and it means that converting the epoch from 2000/01/01 00:00:00 to 1970/01/01 00:00:00
			return static_cast<uint64_t>( (epoch == epoch_t::posix) ? master_time + (static_cast<uint64_t>(946684800) * 1000000000) : master_time);
		}

		/**
		 * get EtherCAT master tick cycle
		 * @warning		_tick and _kpa.cycle_time are always same, but their unit/data type are different from each other
		 * @return		always _tick
		 */
		std::chrono::microseconds tick() { return _tick; }

		/**
		 * bind callback function which is called at the beginning of every master cycle
		 * @param		callback which you want to be called
		 *				you can pass nullptr instead of callback function, if you want to detach callback
		 * @return		always 0
		 */
		int bind(const callback_t callback) {
			assert(_mode != mode_t::asynchronous);
			const std::lock_guard<std::mutex> lock(_callback_lock);
			this->_callback = callback;
			return 0;
		}

		/**
		 * wait for master cycles
		 * if the master' state is not operational, this function be blocked
		 * @param		ncycles how many cycles you wanna wait for
		 * @param		timeout is time allowed until the operation is completed
		 * @return		true on success, false on timeout
		 */
		inline bool wait_for(size_t ncycles, std::chrono::steady_clock::duration timeout = std::chrono::microseconds(100000)) override {
			bool ret = true;
			if(!_sync_pred) {
				std::mutex lock;
				while(ncycles-- > 0u) {
					std::unique_lock<std::mutex> lk(lock);
					if(this->_sync_cond.wait_for(lk, timeout) == std::cv_status::timeout) {
						ret = false;
						break;
					}
				}
			}
			return ret;
		}

		/**
		 * get the KPA structure
		 * @return		always reference to this->_kpa
		 */
		inline kpa_t& kpa() { return this->_kpa; }

		/**
		 * get the input process image to access data
		 * return		always reference to input process image
		 */
		virtual inline copi& pin() override { return this->_pi.input; }

		/**
		 * get the output process image to access adata
		 * return		always reference to output process image
		 */
		virtual inline copi& pout() override { return this->_pi.output; }

		/**
		 * @copydoc		ssi::comst::readpdo
		 */
		virtual ssize_t readpdo(copi& pi, uint8_t* dst, size_t bit_offset, size_t bit_size) override {
			ECAT_RESULT result;
			pi.rdlock();
			try {
#if defined(ECATMST_RESTRICT_PDO)
				if(bit_size > 64)
					throw ssi::invalid_argument("invalid bit_size");
				if(ECAT_FAILED(result = KPAGetVariable(static_cast<unsigned char*>(pi.pointer()), static_cast<unsigned char*>(dst), static_cast<ECAT_WORD>(bit_size), static_cast<ECAT_WORD>(bit_offset))))
					throw ssi::ecat_error("KPAGetVariable", result);
#else // !ECATMST_RESTRICT_PDO
				size_t s = bit_size;
				// KPA API seems not to allow a variable with size over 64-bits
				// if you pass a variable over 64-bits the API returns the error code 0x8002
				for(s; s >= 64u; s -= 64u, dst += 8, bit_offset += 64u) {
					if(ECAT_FAILED(result = KPAGetVariable(static_cast<unsigned char*>(pi.pointer()), static_cast<unsigned char*>(dst), static_cast<ECAT_WORD>(64), static_cast<ECAT_WORD>(bit_offset))))
						throw ssi::ecat_error("KPAGetVariable", result);
				}
				if( s > 0u &&
					ECAT_FAILED(result = KPAGetVariable(static_cast<unsigned char*>(pi.pointer()), static_cast<unsigned char*>(dst), static_cast<ECAT_WORD>(s), static_cast<ECAT_WORD>(bit_offset))) )
					throw ssi::ecat_error("KPAGetVariable", result);
#endif // ECATMST_RESTRICT_PDO
			} catch(...) {
				pi.unlock();
				throw;
			}
			// cmx_trace("copi::read(dst = %p, bit_offset = 0x%08x, bit_size = 0x%08x\n", dst, static_cast<uint32_t>(bit_offset), static_cast<uint32_t>(bit_size));
			pi.unlock();
			return static_cast<ssize_t>(bit_size);
		}

		/**
		 * @copydoc		ssi::comst::writepdo
		 */
		virtual ssize_t writepdo(copi& pi, uint8_t* const src, size_t bit_offset, size_t bit_size) override {
			ECAT_RESULT result;
			// cmx_trace("copi::writepdo(src = %p, bit_offset = 0x%08x, bit_size = 0x%08x)\n", src, bit_offset, bit_size);
			pi.wrlock();
			try {
#if defined(ECATMST_RESTRICT_PDO)
				if(bit_size > 64)
					throw ssi::invalid_argument("invalid bit_size");
				if(ECAT_FAILED(result = KPASetVariable(static_cast<unsigned char*>(pi.pointer()), static_cast<unsigned char*>(src), static_cast<ECAT_WORD>(bit_size), static_cast<ECAT_WORD>(bit_offset))))
					throw ssi::ecat_error("KPASetVariable", result);
#else // !ECATMST_RESTRICT_PDO
				size_t s = bit_size;
				// KPA API seems not to allow a variable with size over 64-bits
				// if you pass a variable over 64-bits the API returns the error code 0x8002
				for(s; s >= 64u; s -= 64u, src += 8, bit_offset += static_cast<size_t>(64)) {
					if(ECAT_FAILED(result = KPASetVariable(static_cast<unsigned char*>(pi.pointer()), static_cast<unsigned char*>(src), static_cast<ECAT_WORD>(64), static_cast<ECAT_WORD>(bit_offset))))
						throw ssi::ecat_error("KPASetVariable", result);
				}

				if( s > 0u &&
					ECAT_FAILED(result = KPASetVariable(static_cast<unsigned char*>(pi.pointer()), static_cast<unsigned char*>(src), static_cast<ECAT_WORD>(s), static_cast<ECAT_WORD>(bit_offset))) )
					throw ssi::ecat_error("KPASetVariable", result);
#endif // ECATMST_RESTRICT_PDO
			} catch(...) {
				pi.unlock();
				throw;
			}
			pi.unlock();
			return static_cast<ssize_t>(bit_size);
		}

		// for using template function
		using comst::readpdo;
		using comst::writepdo;

		/**
		 * read a SDO via EtherCAT
		 * @copydoc		ssi::comst::readsdo
		 */
		virtual ssize_t readsdo(uint16_t slave_id, uint16_t index, uint8_t sub_index, uint8_t* dst, size_t bit_size) override {
			std::lock_guard<std::mutex> lk(_coe_lock);
			ECAT_HANDLE req = _coe_req(coe_service_t::upload, slave_id, index, sub_index, dst, bit_size);
			return _coe_wait(coe_service_t::upload, req, dst, bit_size);
		}

		/**
		 * write a SDO via EtherCAT
		 * @copydoc		ssi::comst::writesdo
		 */
		virtual ssize_t writesdo(uint16_t slave_id, uint16_t index, uint8_t sub_index, uint8_t* src, size_t bit_size) override {
			std::lock_guard<std::mutex> lk(_coe_lock);
			ECAT_HANDLE req = _coe_req(coe_service_t::download, slave_id, index, sub_index, src, bit_size);
			return _coe_wait(coe_service_t::download, req, src, bit_size);
		}

		// for using template function
		using comst::readsdo;
		using comst::writesdo;

		/**
		 * get current EtherCAT master's real state by calling KAPGetMasterState()
		 * @return		always master state
		 * @exception	ssi::ecat_error on error from KPA API
		 */
		state_t state(const bool update_now = false) {
			if(update_now) {
				const ECAT_RESULT result = KPAGetMasterState(_kpa.handle, &_kpa.state);
				if(ECAT_FAILED(result))
					throw ssi::ecat_error("KPAGetMasterState", result);
			}
			return static_cast<state_t>(_kpa.state);
		}

		/**
		 * get EtherCAT slave's real state
		 * @return		always slave state
		 * @eception	ssi::ecat_error on error from KPA API
		 */
		state_t slave_state(const uint16_t slave_id) const {
			ECAT_BYTE state;
			const ECAT_RESULT result = KPAGetSlaveState(_kpa.handle, static_cast<ECAT_WORD>(slave_id), &state);
			if(ECAT_FAILED(result))
				throw ssi::ecat_error("KPAGetSlaveState", result);
			return static_cast<state_t>(state);
		}

		/**
		 * transit master state
		 * @param		state is target value to transit
		 * @return		always state after trying transit 
		 * @exeption	ssi::runtime_error on fail to transit
		 * 				ssi::ecat_error on error from KPA API
		 */
		state_t transit(const state_t state) {
			const EcatState target_state = EcatState(state);
			ECAT_RESULT result = KPARequestMasterState(_kpa.handle, static_cast<ECAT_BYTE>(target_state));
			if(ECAT_FAILED(result))
				throw ssi::ecat_error("cannot request master state", result);
			// wait for being changed master state Operational for 5 seconds
			for(int64_t i = 0; (i < 5) && (_kpa.state != static_cast<ECAT_BYTE>(target_state)); i++) {
				if(ECAT_FAILED(result = KPAGetMasterState(_kpa.handle, &_kpa.state)))
					throw ssi::ecat_error("cannot get master state", result);
				(void)::usleep(1000u * 1000u);
			}
			if(_kpa.state != static_cast<ECAT_BYTE>(target_state))
				throw ssi::runtime_error("cannot transit master state");
			return state;
		}

		/**
		 * transit slave state
		 * @param		state is target state
		 * @return		always state after trying transit
		 * @exeption	ssi::runtime_error on fail to transit
		 * 				ssi::ecat_error on error from KPA API
		 */
		state_t slave_transit(const uint16_t slave_id, const state_t state) {
			ECAT_BYTE current_state = EcatState::EcatStateNotSet;
			const EcatState target_state = EcatState(state);
			ECAT_RESULT result = KPARequestSlaveState(_kpa.handle, static_cast<ECAT_WORD>(slave_id), target_state);
			if(ECAT_FAILED(result))
				throw ssi::ecat_error("KPARequestSlaveState", result);
			// wait for being changed slave state for 5 seconds
			for(int64_t i = 0; (i < 5) && (current_state != target_state); i++) {
				if(ECAT_FAILED(result = KPAGetSlaveState(_kpa.handle, static_cast<ECAT_WORD>(slave_id), &current_state)))
					throw ssi::ecat_error("KPAGetSlaveState", result);
				(void)::usleep(1000 * 1000);
			}
			if(current_state != static_cast<ECAT_BYTE>(target_state))
				throw ssi::runtime_error("cannot transit slave state");
			return static_cast<state_t>(current_state);
		}

		enum slave_count_from_t
		{
			from_eni,
			from_nic0,
			from_nic1,
			from_nic
		};

		/**
		 * get the number of slaves
		 * @param		src count source where you want from
		 * @return		slaves count, on success
		 * 				-1, on fail
		 * @exeption 	ssi::ecat_error on error from KPA API
		 */
		int32_t slave_count(slave_count_from_t src = from_nic) {
			int32_t ret = -1;
			ECAT_WORD count;
			ECAT_RESULT result;
			switch(src) {
			case from_eni:
				if(ECAT_FAILED(result = KPAGetSlaveCount(_kpa.handle, &count)))
					throw ssi::ecat_error("KPAGetSlaveCount", result);
				ret = count;
				break;
			case from_nic0:
				ret = _kpa.nic0_slave_count;
				break;
			case from_nic1:
				ret = _kpa.nic1_slave_count;
				break;
			case from_nic:
				ret = _kpa.nic0_slave_count + _kpa.nic1_slave_count;
				break;
			default:
				// it will return -1
				break;
			}
			return ret;
		}

		/**
		 * check if the bus status is ok
		 * @return		true on bus status is ok, false on error or warning 
		 * @exception	ssi::ecat_error on error from KPA API
		 */
		bool bus_status() {
			ECAT_RESULT result;
			ECAT_DWORD status;
			if(ECAT_FAILED(result=KPAGetBusStatus(_kpa.handle, &status)))
				throw ssi::ecat_error("KPAGetBusStatus", result);

			return status == EcatMasterBusStatusOK;
		}

		/**
		 * enable rpc server
		 * @warning		running rpc server affects real-time performance widely
		 *				and it also damages ecatmst's fini() sequence
		 *				so you can use it for testing purpose only
		 * @return		true on success, false on fail
		 * @exception	ssi::ecat_error on error from KPA API
		 */
		bool rpcserver(bool en = true) {
			ECAT_RESULT result;

			if(_kpa.handle == ECAT_NULL)
				return false;

			if(en) {
				result = KPAMasterServerCreate(&_kpa.server, EcatMasterServerKernel, ECAT_TRUE, KPA_SERVER_PORT_NUMBER, ECAT_FALSE, _kpa.handle, ECAT_NULL);
				if(ECAT_FAILED(result)) { throw ssi::ecat_error("cannot start master server", result); }
			} else {
				if(_kpa.server != ECAT_NULL) {
					result = KPAMasterServerStop(_kpa.server);
					if(ECAT_FAILED(result)) { throw ssi::ecat_error("cannot stop master server", result); }
					result = KPAMasterServerDelete(_kpa.server);
					if(ECAT_FAILED(result)) { throw ssi::ecat_error("cannot delete master server", result); }
				}
			}

			return true;
		}

		/**
		 * create ecatmst singleton instance and initialize it
		 * @param		e is ssi environment to apply
		 * @return		always reference of the ecatmst singleton instance
		 */
		static ecatmst& create(ssi::env& e) try {
			mode_t mode;
			state_t state;
			std::string modestr = e.get<std::string>("eq.ssi.ecatmst.mode", "asynchronous");
			std::string statestr = e.get<std::string>("eq.ssi.ecatmst.state", "pre_operational");

			if(modestr.compare("synchronous") == 0)
				mode = mode_t::synchronous;
			else if(modestr.compare("asynchronous") == 0)
				mode = mode_t::asynchronous;
			else
				throw ssi::runtime_error("invalid environment");

			if(statestr.compare("init") == 0)
				state = state_t::init;
			else if(statestr.compare("pre_operational") == 0)
				state = state_t::pre_operational;
			else if(statestr.compare("safe_operational") == 0)
				state = state_t::safe_operational;
			else if(statestr.compare("operational") == 0)
				state = state_t::operational;
			else
				throw ssi::runtime_error("invalid environment");

			return create(mode, state, nullptr,
						  (e.get<std::string>("eq.ssi.ecatmst.eni_path") + "/" + TARGET_STRING + ".xml").c_str(),
						  std::chrono::microseconds(e.get<size_t>("eq.ssi.ecatmst.cycle_time_in_us")),
						  std::chrono::microseconds(e.get<size_t>("eq.ssi.ecatmst.sub_cycle_time_in_us")));
		} catch(...) {
			throw;
		}

		/**
		 * create ecatmst singleton instance and initialize it
		 * @copydoc		ccl::singleton
		 * @param		mode master mode
		 * @param		state master state to transit
		 * @param		callback function which is called at every master cycle
		 * @param		eni file path to load
		 * @param		cycle_time EtherCAT master transmission cycle time
		 * @param		sub_sycle_time EtherCAT mailbox update cycle in microseconds
		 * @return		always reference of the ecatmst singleton instance
		 * @exception	throws std::invalid_arguement when the argument value has not been accepted 
		 * 				throws std::system_error if you got bad return from POSIX API
		 * 				throws ssi::ecat_error on error
		 */
		static ecatmst& create(
				const mode_t mode = mode_t::asynchronous,
				const state_t state = state_t::pre_operational,
				const callback_t callback = nullptr,
				const char* const eni_file = _def::eni_file,
				const std::chrono::microseconds cycle_time = std::chrono::microseconds(_def::cycle_time_in_us),
				const std::chrono::microseconds sub_cycle_time = std::chrono::microseconds(_def::sub_cycle_time_in_us)) try {
			(void)ccl::singleton<ssi::ecatmst>::instance().init(mode, callback, eni_file, cycle_time, sub_cycle_time);
			(void)ccl::singleton<ssi::ecatmst>::instance().transit(state);
			return ccl::singleton<ssi::ecatmst>::instance();
		} catch(...) {
			throw;
		}

		static void destroy() try {
			ccl::singleton<ssi::ecatmst>::instance().fini();
		} catch(...) {
			throw;
		}

	private:
		/**
		 * default constructor defined in base class
		 */
		ecatmst() { }

		virtual ~ecatmst() {
			try {
				(void)fini();
			} catch (const ssi::ecat_error&) {
				// ignore it
			}
		}

		/**
		 * master clock counter
		 * every _sync() calling increase this variable by 1
		 */
		uint64_t _clk;

		/// master mode given from constructor
		mode_t _mode;

		/**
		 * master tick cycle
		 */
		std::chrono::microseconds _tick;

		/**
		 * synchronization predicate
		 * if the value is true, wait_for() returns immediately
		 */
		std::atomic<bool> _sync_pred;

		/**
		 * synchronization condvar
		 * ecatmst do notify_all() every master cycle,
		 * so you can do wait_for() to wait for next master cycle
		 */
		std::condition_variable _sync_cond;

		/**
		 * synchronization cycle counter
		 * _sync() function call always increase the counter
		 * the condition _sync_cnt >= _sync_coef triggers actual behavior of the _sync() function
		 * otherwise, _sync() increase the counter only
		 */
		int32_t _sync_cnt;

		/**
		 * master cycle coefficient value for ethercat master synchronous mode
		 * _sync() called at every ethercat master cycle_time * _sync_coef time
		 */
		int32_t _sync_coef;

		/**
		 * callback function which is called back by internal _sync_ctrl_task_handler()
		 * KPA gurantees being called _sync_ctrl_task_handler() every EtherCAT master cycle
		 * and the function calls this callback directly.
		 */
		callback_t _callback;

		/**
		 * mutex for binding callback and calling callback
		 */
		std::mutex _callback_lock;

		/**
		 * mutex for calling EtherCAT CoE functionalities
		 */
		std::mutex _coe_lock;

		/**
		 * process images '(input & output)'
		 */
		struct pi_t
		{
			copi input { 0, copi::access_t::mutex};
			copi output { 0, copi::access_t::mutex};
		} _pi;

		/**
		 * default values which is used for initializing KPA stack
		 */
		struct _def
		{
			static constexpr ECAT_WORD primary_adapter_index = 0u;
			static constexpr ECAT_WORD redundancy_adapter_index = 1u;
			static constexpr const char* eni_file = "/etc/eq/eni/" TARGET_STRING ".xml";
			static constexpr uint64_t cycle_time_in_us = 1000;
			static constexpr uint64_t sub_cycle_time_in_us = 5000;
			static constexpr uint64_t coe_operation_timeout_in_ms = 1000;
			static constexpr std::chrono::microseconds cycle_time = std::chrono::microseconds(cycle_time_in_us);
			static constexpr std::chrono::microseconds sub_cycle_time = std::chrono::microseconds(sub_cycle_time_in_us);
			static constexpr std::chrono::milliseconds coe_operation_timeout = std::chrono::milliseconds(coe_operation_timeout_in_ms);
		};

		kpa_t _kpa;

		/**
		 * internal EtherCAT sync function is called by _kpa_sync_ctrl_handler
		 * if the instance is in async mode, ccl::subject<ecatmst>::notify() is called
		 * otherwise callback is called every master cycle * _sync_coef
		 * @warning		DO NOT CHANGE THIS
		 * @return		nullptr on success, ptr to string contains error message
		 * @exception	throws ssi::runtime_error on internal error
		 */
		virtual const char* _sync() override {
			_clk++;
			_sync_cnt++;
			// _kpa_sync_ctrl_handler() calls this method when the master mode is operational
			if(_sync_cnt >= _sync_coef) {
				// for testing purpose
				/*
				try {
					static uint64_t _sync_time;
					const uint64_t cycle_time = (this->time() - _sync_time) / 1000u;
					_sync_time = this->time();
					if( (_clk != 1) && ((cycle_time < (this->tick().count() / 2)) || (cycle_time > (this->tick().count() * 3 / 2))) )
						::syslog(LOG_WARNING, " <warning> broken cycle detected: %dns", cycle_time);
				} catch (ssi::runtime_error) {
					// ignore it
				}
				*/
				_sync_cnt = 0;
				const std::lock_guard<std::mutex> lock(_callback_lock);
				ECAT_RESULT result;
				switch(_mode) {
				case mode_t::asynchronous: {
					_pi.input.wrlock();
					(void)KPADoneReadInputs(_kpa.handle);
					if(ECAT_FAILED(result = KPAStartReadInputs(_kpa.handle, static_cast<unsigned char*>(_pi.input.pointer()), static_cast<ECAT_WORD>(_pi.input.size()))))
						throw ssi::ecat_error("failed to read input pi", result);
					_pi.input.unlock();

					notify<isync_done>();

					_pi.output.rdlock();
					(void)KPADoneWriteOutputs(_kpa.handle, static_cast<unsigned char*>(_pi.output.pointer()), static_cast<ECAT_WORD>(_pi.output.size()));
					if(ECAT_FAILED(result = KPAStartWriteOutputs(_kpa.handle, static_cast<unsigned char*>(_pi.output.pointer()), static_cast<ECAT_WORD>(_pi.output.size()))))
						throw ssi::ecat_error("failed to write output pi", result);
					_pi.output.unlock();

					notify<sync_done>();
					comst::notify<sync_done>();
					break; }
				case mode_t::synchronous: {
					  _pi.input.wrlock();
					  if(ECAT_FAILED(result = KPAStartReadInputs(_kpa.handle, static_cast<unsigned char*>(_pi.input.pointer()), static_cast<ECAT_WORD>(_pi.input.size()))))
						  throw ssi::ecat_error("failed to read input pi", result);
					  _pi.input.unlock();

					  _pi.output.rdlock();
					  if(ECAT_FAILED(result = KPAStartWriteOutputs(_kpa.handle, static_cast<unsigned char*>(_pi.output.pointer()), static_cast<ECAT_WORD>(_pi.output.size()))))
						  throw ssi::ecat_error("failed to write output pi", result);
					  _pi.output.unlock();

					  if(this->_callback != nullptr)
						  (void)this->_callback(nullptr);

					  (void)KPADoneReadInputs(_kpa.handle);
					  (void)KPADoneWriteOutputs(_kpa.handle, static_cast<unsigned char*>(_pi.output.pointer()), static_cast<ECAT_WORD>(_pi.output.size()));
					  break; }
				default: {
					throw ssi::runtime_error("internal error"); }
				}
			}
			return nullptr;
		}

		/**
		 * internal EtherCAT event handler is called by _kpa_event_handler
		 * @warning		DO NOT CHANGE THIS
		 * @return		nullptr on success, ptr to string contains error message
		 * @exception	throws ssi::runtime_error on internal error
		 */
		virtual const char* _evnt() override {
			notify<event>();
			return nullptr;
		}

		/**
		 * internal EtherCAT callbak function is called by _kpa_update_process_image_handler
		 * @warning		this function does nothing for now
		 * @return		nullptr on success, ptr to string contains error message
		 */
		const char* _update() const {
			return nullptr;
		}

		/**
		 * create CoE request and send it via EtherCAT network
		 * @warning		this function can be called for internal use only
		 */
		inline ECAT_HANDLE _coe_req(const coe_service_t service, uint16_t slave_id, uint16_t index, uint8_t sub_index, uint8_t* data, const size_t bit_size, const ECAT_DWORD timeout = COE_OPERATION_TIMEOUT_MS) {
			ECAT_WORD fixed_addr = 0u;
			ECAT_DWORD length = static_cast<ECAT_DWORD>(bit_size);
			ECAT_RESULT result = ECAT_S_OK;
			ECAT_HANDLE request = ECAT_NULL;

			/**
			 * KPA API accepts the number begins from 0 for slave id
			 */
			if(slave_id == 0u)
				throw ssi::invalid_argument("invalid slave id");
			slave_id--;

			if(ECAT_FAILED(result = KPAGetSlaveFixAddress(_kpa.handle, slave_id, &fixed_addr)))
				throw ssi::ecat_error("KPAGetSlaveFixAddress", result);
			if(ECAT_FAILED(result = KPAMailboxCoERequestCreate(_kpa.handle, fixed_addr, index, sub_index, static_cast<ECAT_BYTE>(service), ECAT_NULL, &request)))
				throw ssi::ecat_error("KPAMailBoxCoERequestCreate", result);

			try {
				ECAT_RESULT retval = ECAT_S_OK;
				if(ECAT_FAILED(result = KPAMailboxSetTimeout(_kpa.handle, request, timeout)))
					throw ssi::ecat_error("KPAMailboxSetTimeout", result);
				if( (service == coe_service_t::upload) || (service == coe_service_t::caupload) ) {
					if(ECAT_FAILED(result = KPAMailboxWrite(_kpa.handle, request, ECAT_NULL, static_cast<ECAT_DWORD>(0), &length)))
						throw ssi::ecat_error("KPAMailboxWrite", result);
				} else if( (service == coe_service_t::download) || (service == coe_service_t::cadownload) ) {
					if(ECAT_FAILED(result = KPAMailboxWrite(_kpa.handle, request, data, length, &length)))
						throw ssi::ecat_error("KPAMailboxWrite", result);
				} else
					throw ssi::invalid_argument("invalid coe service type");
			} catch(const ssi::ecat_error& e) {
				if(request != ECAT_NULL)
					(void)KPAMailboxDestroy(_kpa.handle, request);
				throw;
			}

			return request;
		}

		/**
		 * wait for a CoE response and destroy the event created then
		 * @warning		this function can be called for internal use only
		 */
		inline ssize_t _coe_wait(const coe_service_t service, ECAT_HANDLE request, uint8_t* data, const size_t bit_size) {
			ECAT_RESULT result = ECAT_S_OK;
			ECAT_RESULT retval = ECAT_S_OK;
			ECAT_DWORD length = static_cast<ECAT_DWORD>(bit_size);

			if(request != ECAT_NULL) {
				if(ECAT_FAILED(result = KPAMailboxWait(_kpa.handle, &request, KPA_TIMEOUT_INFINITY, &retval)))
					throw ssi::ecat_error("KPAMailboxWait", result);
				if(ECAT_FAILED(retval))
					throw ssi::ecat_error("KPAMailboxWait output parameter error", retval);
				if( (service == coe_service_t::upload) || (service == coe_service_t::caupload) )
					if(ECAT_FAILED(result = KPAMailboxRead(_kpa.handle, request, data, bit_size, &length)))
						throw ssi::ecat_error("KPAMailboxRead", result);
				(void)KPAMailboxDestroy(_kpa.handle, request);
				return length;
			}
			return -1;
		}

		/**
		 * call back is called by KPA stack whenever one or more internal events is generated
		 * @see			ecatmst::init()
		 * @return		ECAT_S_OK always
		 */
		static ECAT_RESULT _kpa_event_handler(IN const ECAT_LPVOID arg, const ECAT_DWORD eid, const ECAT_DWORD param0, const ECAT_DWORD param1, const ECAT_DWORD param2) {
			static std::once_flag flag0;
			static std::once_flag flag1;
			ecatmst* mst = static_cast<ecatmst*>(arg);
			if(eid == ECAT_MASTER_EVENT_NIC0_COUNT_CHANGE) {
				std::call_once(flag0, [param1]() { std::cout << "Slaves count of primary interface : " << param1 << std::endl; });
				mst->kpa().nic0_slave_count = param1;
			} else if(eid == ECAT_MASTER_EVENT_NIC1_COUNT_CHANGE) {
				std::call_once(flag1, [param1]() { std::cout << "Slaves count of secondary interface : " << param1 << std::endl; });
				mst->kpa().nic1_slave_count = param1;
			}

			(void)mst->_evnt();
			return ECAT_S_OK;
		}

		/**
		 * callback is called by KPA stack for every master cycle
		 * you don't need to call this function implicitly, because KPA have the routine to callback this
		 * @warning		i'm not sure they gurantee synchronization for process image
		 * @return		ECAT_S_OK on success, others on error
		 */
		static ECAT_RESULT _kpa_sync_ctrl_handler(IN const ECAT_LPVOID arg)
		{
			const char* what = nullptr;
			ecatmst* mst = static_cast<ecatmst*>(arg);

			if(mst->state() == state_t::operational) {
				what = mst->_sync();
				mst->_sync_cond.notify_all();
			}

			return (what == nullptr) ? ECAT_S_OK : ECAT_E_INVALIDARG;
		}

		/**
		 * callback is called by KPA stack for every master cycle
		 * @warning		you need to care this function with KPA synchronous 2 mode only
		 *				but i didn't implement it yet
		 */
		static ECAT_RESULT _kpa_update_process_image_handler(IN const ECAT_LPVOID arg)
		{
			ecatmst* mst = static_cast<ecatmst*>(arg);
			static int64_t st;
			if(st == 0) {
				struct sched_param param;
				(void)sched_getparam(0, &param);
				param.sched_priority = ssi::priority::ecat_update_thread;
				(void)sched_setscheduler(0, SCHED_FIFO, &param);
				(void)pthread_setname_np(0, "ecatmst::update");
				st++;
				if( (mst->state() == state_t::operational) && (st == 0) ) {
					(void)pthread_setname_np(0, "ecatmst::update");
					st++;
				}
			}
			return (mst->_update() == nullptr) ? ECAT_S_OK : ECAT_E_INVALIDARG;
		}

		/**
		 * callback is called by KPA stack, but it seems not to work properly
		 * if you try to register this function as a callback by calling KPASetExtCtrlTaskHandler(),
		 * you'll always get the error code ECAT_E_NOTIMPL from KPA API
		 */
		static ECAT_RESULT ECATMKPA_CALLBACK _kpa_ext_ctrl_task_handler(IN const ECAT_LPVOID, IN ECAT_BYTE*, IN ECAT_BYTE*)
		{
			return ECAT_S_OK;
		}

		static ECAT_RESULT _kpa_read_write_slave_coe_object(IN const ECAT_HANDLE handle, IN ECAT_WORD slave_id, IN const ECAT_WORD index, IN const ECAT_BYTE sub_index, IN const CoEServices service, IN const ECAT_DWORD timeout, IN OUT ECAT_BYTE* data, IN OUT ECAT_DWORD* length) {
			ECAT_WORD fixed_addr = 0u;
			ECAT_HANDLE request = ECAT_NULL;
			ECAT_RESULT result = ECAT_S_OK;

			/**
			 * KPA API accepts the number begins from 0 for slave id
			 */
			if(slave_id == 0u)
				throw ssi::invalid_argument("invalid slave id");
			slave_id--;

			if(ECAT_FAILED(result = KPAGetSlaveFixAddress(handle, slave_id, &fixed_addr)))
				throw ssi::ecat_error("KPAGetSlaveFixAddress", result);
			if(ECAT_FAILED(result = KPAMailboxCoERequestCreate(handle, fixed_addr, index, sub_index, static_cast<ECAT_BYTE>(service), ECAT_NULL, &request)))
				throw ssi::ecat_error("KPAMailBoxCoERequestCreate", result);

			try {
				ECAT_RESULT retval = ECAT_S_OK;
				if(ECAT_FAILED(result = KPAMailboxSetTimeout(handle, request, timeout)))
					throw ssi::ecat_error("KPAMailboxSetTimeout", result);
				if( (service == coeServiceUpload) || (service == coeServiceCAUpload) ) {
					if(ECAT_FAILED(result = KPAMailboxWrite(handle, request, ECAT_NULL, static_cast<ECAT_DWORD>(0), length)))
						throw ssi::ecat_error("KPAMailboxWrite", result);
					if(ECAT_FAILED(result = KPAMailboxWait(handle, &request, KPA_TIMEOUT_INFINITY, &retval)))
						throw ssi::ecat_error("KPAMailboxWait", result);
					result = KPAMailboxRead(handle, request, data, *length, length);
				} else {
					if(ECAT_FAILED(result = KPAMailboxWrite(handle, request, data, *length, length)))
						throw ssi::ecat_error("KPAMailboxWrite", result);
					if(ECAT_FAILED(result = KPAMailboxWait(handle, &request, KPA_TIMEOUT_INFINITY, &retval)))
						throw ssi::ecat_error("KPAMailboxWait", result);
				}
			} catch(const ssi::ecat_error& e) {
				if(request != ECAT_NULL)
					(void)KPAMailboxDestroy(handle, request);
				throw;
			}

			if(request != ECAT_NULL)
				(void)KPAMailboxDestroy(handle, request);

			return result;
		}
	};
}

#endif // __SSI_ECATMST_H__

