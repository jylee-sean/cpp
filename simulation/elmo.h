/**
 * @brief		elmo drive base class
 * @details		it provides common elmo function like sdo communication and enable / disable
 *				and it also keeps its configuration like gear ratio, encoder resolutions and so on
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */

#ifndef __SSI_NODE_ELMO_H__
#define __SSI_NODE_ELMO_H__

#include <vector>

#include <ssi/comst.h>
#include <ssi/coobj.h>
#include <ssi/exception.h>
#include <ssi/node/base.h>
#include <ssi/node/elmo_obj.h>
#include <ssi/node/elmo_cfg.h>


namespace ssi
{
	/**
	 * defines a type of object to be thrown as an exception.
	 * it reports exceptional cases come from the elmo motion controller
	 * and mostly it can be recovered by elmo fault reset
	 */
	class elmo_fault : public ssi::runtime_error
	{
	public:
		typedef uint16_t id_type;
		typedef node::elmo_obj::ErrorCode::value_type code_type;
		elmo_fault(const std::string& w, id_type id, code_type code) noexcept : ssi::runtime_error(w, false), _id(id), _code(code) {
			::syslog(LOG_ERR, " <error> elmo_fault(%s, %d) has been created", w, code);
		}

		/**
		 * get the slave id from where
		 * @return		always slave id
		 */
		id_type id() const { return _id; }

		/**
		 * get the error code of an exception
		 * @return		always error code
		 */
		code_type code() const { return _code; }

	private:
		id_type _id;
		code_type _code;
	};

	namespace node
	{
		class elmo : public std::enable_shared_from_this<elmo>, public ssi::node::base
		{
		public:
			enum struct source_t { incremental, absolute };

			class profile
			{
			public:
				virtual ~profile() { } // to make this class polymorphic
			};

			/// default constructor is disallowed
			elmo() = delete;

			/**
			 * elmo class constructor
			 * @param		mst is the field-bus master
			 * @param		id is the slave id
			 * @param		status_word_addr is memory offset of StatusWord object in the input process image
			 * @param		control_word_addr is memory offset of ControlWord object in the output process image
			 * @param		cfg is elmo drive configuration 
			 */
			explicit elmo(comst& mst, const uint16_t id, const elmo_cfg& cfg = ssi::node::elmo_nocfg) :
				base(mst, id),
				_cfg(cfg),
				_sdo {
					cosdo<elmo_obj::StatusWord::value_type>(mst, id, elmo_obj::StatusWord()),
					cosdo<elmo_obj::ControlWord::value_type>(mst, id, elmo_obj::ControlWord()),
					cosdo<elmo_obj::HaltOptionCode::value_type>(mst, id, elmo_obj::HaltOptionCode()),
					cosdo<elmo_obj::TargetPosition::value_type>(mst, id, elmo_obj::TargetPosition()),
					cosdo<elmo_obj::TargetVelocity::value_type>(mst, id, elmo_obj::TargetVelocity()),
					cosdo<elmo_obj::TargetTorque::value_type>(mst, id, elmo_obj::TargetTorque()),
					cosdo<elmo_obj::ModesOfOperation::value_type>(mst, id, elmo_obj::ModesOfOperation()),
					cosdo<elmo_obj::ModesOfOperationDisplay::value_type>(mst, id, elmo_obj::ModesOfOperationDisplay()),
					cosdo<elmo_obj::TorqueActualValue::value_type>(mst, id, elmo_obj::TorqueActualValue()),
					cosdo<elmo_obj::CurrentActualValue::value_type>(mst, id, elmo_obj::CurrentActualValue()),
					cosdo<elmo_obj::MaxTorque::value_type>(mst, id, elmo_obj::MaxTorque()),
					cosdo<elmo_obj::MaxCurrent::value_type>(mst, id, elmo_obj::MaxCurrent()),
					cosdo<elmo_obj::MaxAcceleration::value_type>(mst, id, elmo_obj::MaxAcceleration()),
					cosdo<elmo_obj::MaxDeceleration::value_type>(mst, id, elmo_obj::MaxDeceleration()),
					cosdo<elmo_obj::MaxProfileVelocity::value_type>(mst, id, elmo_obj::MaxProfileVelocity()),
					cosdo<elmo_obj::MotorRateCurrent::value_type>(mst, id, elmo_obj::MotorRateCurrent()),
					cosdo<elmo_obj::MotorRateTorque::value_type>(mst, id, elmo_obj::MotorRateTorque()),
					cosdo<elmo_obj::SoftwarePositionLimit::min::value_type>(mst, id, elmo_obj::SoftwarePositionLimit::min()),
					cosdo<elmo_obj::SoftwarePositionLimit::max::value_type>(mst, id, elmo_obj::SoftwarePositionLimit::max()),
					cosdo<elmo_obj::ProfileVelocity::value_type>(mst, id, elmo_obj::ProfileVelocity()),
					cosdo<elmo_obj::ProfileAcceleration::value_type>(mst, id, elmo_obj::ProfileAcceleration()),
					cosdo<elmo_obj::ProfileDeceleration::value_type>(mst, id, elmo_obj::ProfileDeceleration()),
					cosdo<elmo_obj::QuickStopDeceleration::value_type>(mst, id, elmo_obj::QuickStopDeceleration()),
					cosdo<elmo_obj::TorqueSlope::value_type>(mst, id, elmo_obj::TorqueSlope()),
					cosdo<elmo_obj::ErrorCode::value_type>(mst, id, elmo_obj::ErrorCode()),
					cosdo<elmo_obj::FeedbackPosition::value_type>(mst, id, elmo_obj::FeedbackPosition()),
					cosdo<elmo_obj::AuxiliaryPositioninCounts::value_type>(mst, id, elmo_obj::AuxiliaryPositioninCounts()),
					cosdo<elmo_obj::AuxiliaryPositionActualValue::value_type>(mst, id, elmo_obj::AuxiliaryPositionActualValue())
				} { }

			virtual ~elmo() { }

			virtual copdo<elmo_obj::StatusWord::value_type>& status_word() = 0;
			virtual copdo<elmo_obj::ControlWord::value_type>& control_word() = 0;

			const char* init() override { return nullptr; }
			const char* fini() override { return nullptr; }

			/**
			 * convert the encoder value to angle in turns
			 * @ingroup		async-function realtime-feature
			 * @param		val is the encoder value to convert
			 * @param		src is encoder source type
			 * @return		always converted angle
			 * @exception	throws ssi::invalid_argument, in case of the elmo is not rotation type
			 */
			template<typename T, typename std::enable_if<std::is_same<T, phy::units::turn>::value, T>::type* = nullptr>
			T conv(elmo_obj::PositionActualValue::value_type val, const source_t src = source_t::incremental) {
				if(cfg().type != elmo_cfg::rotation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				return phy::units::turn(ssi::node::elmo_cfg::decode(src == source_t::incremental ? cfg().inc_encoder : cfg().abs_encoder, val));
			}

			/**
			 * convert the encoder value to length in SI units(millimeter)
			 * @ingroup		async-function realtime-feature
			 * @param		val is the encoder value to convert
			 * @param		src is encoder source type
			 * @return		always converted length
			 * @exception	throws ssi::invalid_argument, in case of the elmo is not translation type
			 */
			template<typename T, typename std::enable_if<std::is_same<T, phy::units::millimeter>::value, T>::type* = nullptr>
			T conv(elmo_obj::PositionActualValue::value_type val, const source_t src = source_t::incremental) {
				if(cfg().type != elmo_cfg::translation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				return phy::units::millimeter(ssi::node::elmo_cfg::decode(src == source_t::incremental ? cfg().inc_encoder : cfg().abs_encoder, val));
			}

			/**
			 * convert units::angle<> to position actual value of elmo encoder
			 * @ingroup		async-function realtime-feature
			 * @param		a is the angle you want to convert
			 * @param		src is encoder source type
			 * @return		always converted value
			 * @exception	throws ssi::invalid_argument, in case of the elmo is not rotation type
			 */
			template<typename T, typename U>
			elmo_obj::PositionActualValue::value_type conv(const phy::units::angle<T, U>& a, const source_t src = source_t::incremental) {
				if(cfg().type != elmo_cfg::rotation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				return ssi::node::elmo_cfg::encode(src == source_t::incremental ? cfg().inc_encoder : cfg().abs_encoder,
												   phy::units::angle_cast<phy::units::turn>(a).value());
			}

			/**
			 * convert units::length<> to position actual value of elmo encoder
			 * @ingroup		async-function realtime-feature
			 * @param		l is the length you want to convert
			 * @param		src is encoder source type
			 * @return		always converted value
			 * @exception	throws ssi::invalid_argument, in case of the elmo is not translation type
			 */
			template<typename T, typename U>
			elmo_obj::PositionActualValue::value_type conv(const phy::units::length<T, U>& l, const source_t src = source_t::incremental) {
				if(cfg().type != elmo_cfg::translation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				return ssi::node::elmo_cfg::encode(src == source_t::incremental ? cfg().inc_encoder : cfg().abs_encoder,
												   phy::units::length_cast<phy::units::millimeter>(l).value());
			}


			/**
			 * reset the fault state on an elmo with given timeout
			 * @param		en is the flag which means the caller intend to enable the drive after fault reset
			 * @param		timeout is ecmatmst cycles allowed to complete the operation
			 * @return		nullptr on success, error string on error
			 */
			const char* reset(const bool en = false, int32_t timeout = 200) {
				for(int i = 0; (i < timeout) || (timeout == -1); i++) {
					switch(state()) {
					case elmo_obj::state_t::fault:
						(void)control_word().write(elmo_obj::ControlWord::cmd::fault_reset);
						break;
					case elmo_obj::state_t::switch_on_disabled:
						if(en)
							return this->enable(timeout == -1 ? -1 : timeout - i);
						else
							return nullptr;
						break;
					case elmo_obj::state_t::ready_to_switch_on:
					case elmo_obj::state_t::switched_on:
					case elmo_obj::state_t::operation_enabled:
						(void)control_word().write(elmo_obj::ControlWord::cmd::disable_voltage);
						break;
					default:
						return "elmo reset error";
					}
					(void)mst().wait_for(1u);
				}
				return "elmo reset timeout";
			}

			/**
			 * enable elmo drive - transit elmo state to operation_enabled
			 * @param		timeout is ecmatmst cycles allowed to complete the operation
			 * @return		nullptr on success, error string on error
			 */
			const char* enable(const int32_t timeout = 100) {
				for(int i = 0; (i < timeout) || (timeout == -1); i++) {
					switch(state()) {
					case elmo_obj::state_t::start:
					case elmo_obj::state_t::not_ready_to_switch_on:
						break;
					case elmo_obj::state_t::switch_on_disabled:
						(void)control_word().write(elmo_obj::ControlWord::cmd::shutdown);
						break;
					case elmo_obj::state_t::ready_to_switch_on:
						(void)control_word().write(elmo_obj::ControlWord::cmd::switch_on);
						break;
					case elmo_obj::state_t::switched_on:
						(void)control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
						break;
					case elmo_obj::state_t::operation_enabled:
						return nullptr;
					default:
						return "elmo enable error";
					}
					mst().wait_for(1u);
				}
				return "elmo enable timeout";
			}

			/**
			 * disable elmo drive - transit elmo state to disabled_voltage
			 * @param		timeout is ecmatmst cycles allowed to complete the operation
			 * @return		nullptr on success, error string on error
			 */
			const char* disable(const int32_t timeout = 100) {
				for(int i = 0; (i < timeout) || (timeout == -1); i++) {
					switch(state()) {
					case elmo_obj::state_t::switch_on_disabled:
						return nullptr;
					default:
						(void)control_word().write(elmo_obj::ControlWord::cmd::disable_voltage);
						break;
					}
					(void)mst().wait_for(1u);
				}
				return "elmo disable timeout";
			}

			/**
			 * halt elmo drive - doesn't change elmo state by default
			 * @warning		this method just change the control value in the process image
			 *				and it means that the method doesn't guarantee real operation
			 *				you can call wait() after calling this method to solve the issue
			 * @param		en is enable flag to halt the elmo drive
			 * @return		nullptr on success, error string on error
			 */
			const char* halt(const bool en = true) {
				const char* ret = nullptr;
				if(state() != elmo_obj::state_t::operation_enabled)
					ret = "invalid elmo state on halt";
				(void)control_word().write( elmo_obj::ControlWord::cmd::enable_operation | (en ? elmo_obj::ControlWord::flag::halt : 0) );
				(void)mst().wait_for(1u);
				return ret;
			}

			/**
			 * wait for being elmo's state to target reached
			 * @ingroup     sync-function nonrealtime-feature
			 * @warning     this function takes at least 1 master cycles at the beginning of the function
			 * @param       timeout is number of master cycles allowed, -1 for infinity
			 * @return      nullptr on success, error string on error or timeout
			 */
			const char* wait(int32_t timeout = -1) {
				for(int32_t i = 0; (i < timeout) || (timeout == -1); i++) {
					(void)_mst.wait_for(1u);
					if( status_word().read() &
						(elmo_obj::StatusWord::flag::internal_limit_active | elmo_obj::StatusWord::flag::operation_mode_specific1) )
						return "elmo state error";
					if(target_reached())
						return nullptr;
				}
				return "wait timeout";
			}

			/**
			 * get current elmo's state by reading elmo StatusWord
			 * @return		always current state
			 */
			inline elmo_obj::state_t state() { return elmo_obj::next_state(status_word().read()); }

			inline bool target_reached() { return status_word().read() & elmo_obj::StatusWord::flag::target_reached; }
			inline bool internal_limit_active() { return status_word().read() & elmo_obj::StatusWord::flag::internal_limit_active; }
			inline bool operation_mode_specific1() { return status_word().read() & elmo_obj::StatusWord::flag::operation_mode_specific1; }

			struct sdo_t {
				cosdo<elmo_obj::StatusWord::value_type> statusWord;
				cosdo<elmo_obj::ControlWord::value_type> controlWord;
				cosdo<elmo_obj::HaltOptionCode::value_type> haltOptionCode;
				cosdo<elmo_obj::TargetPosition::value_type> targetPosition;
				cosdo<elmo_obj::TargetVelocity::value_type> targetVelocity;
				cosdo<elmo_obj::TargetTorque::value_type> targetTorque;
				cosdo<elmo_obj::ModesOfOperation::value_type> modesOfOperation;
				cosdo<elmo_obj::ModesOfOperationDisplay::value_type> modesOfOperationDisplay;
				cosdo<elmo_obj::TorqueActualValue::value_type> torqueActualValue;
				cosdo<elmo_obj::CurrentActualValue::value_type> currentActualValue;
				cosdo<elmo_obj::MaxTorque::value_type> maxTorque;
				cosdo<elmo_obj::MaxCurrent::value_type> maxCurrent;
				cosdo<elmo_obj::MaxAcceleration::value_type> maxAcceleration;
				cosdo<elmo_obj::MaxDeceleration::value_type> maxDeceleration;
				cosdo<elmo_obj::MaxProfileVelocity::value_type> maxProfileVelocity;
				cosdo<elmo_obj::MotorRateCurrent::value_type> motorRateCurrent;
				cosdo<elmo_obj::MotorRateTorque::value_type> motorRateTorque;
				cosdo<elmo_obj::SoftwarePositionLimit::min::value_type> softwarePositionLimitMin;
				cosdo<elmo_obj::SoftwarePositionLimit::max::value_type> softwarePositionLimitMax;
				cosdo<elmo_obj::ProfileVelocity::value_type> profileVelocity;
				cosdo<elmo_obj::ProfileAcceleration::value_type> profileAcceleration;
				cosdo<elmo_obj::ProfileDeceleration::value_type> profileDeceleration;
				cosdo<elmo_obj::QuickStopDeceleration::value_type> quickStopDeceleration;
				cosdo<elmo_obj::TorqueSlope::value_type> torqueSlope;
				cosdo<elmo_obj::ErrorCode::value_type> errorCode;
				cosdo<elmo_obj::FeedbackPosition::value_type> feedbackPosition;
				cosdo<elmo_obj::AuxiliaryPositioninCounts::value_type> auxiliaryPositioninCounts;
				cosdo<elmo_obj::AuxiliaryPositionActualValue::value_type> auxiliaryPositionActualValue;
			};

			/**
			 * get the reference of sdo structure of the elmo drive
			 * @return		always reference of the sdo
			 */
			sdo_t& sdo() { return _sdo; }

			/**
			 * get the Elmo drive configuration
			 * @return		always reference of the elmo drive configuration
			 */
			const elmo_cfg& cfg() const { return _cfg; }

			/**
			 * reset the fault state on elmos with given timeout
			 * @param		agg is elmo drive's vector
			 * @param		en is the flag which means the caller intend to enable the drive after fault reset
			 * @param		timeout is ecatmst cycles allowed to complete the operation
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			template<typename T = ssi::node::elmo>
			static T* reset(const std::vector<T*>& agg, const bool en = false, const int32_t timeout = 200) {
				std::vector<T*> copy = agg;
				int i;
				if(agg.size() > 0) {
					for(i = 0; copy.size() > 0 && ((i < timeout) || (timeout == -1)); i++) {
						for(auto it = copy.begin(); it != copy.end(); ) {
							if((*it)->state() == elmo_obj::state_t::switch_on_disabled)
								it = copy.erase(it);
							else {
								switch((*it)->state()) {
								case elmo_obj::state_t::fault:
									(void)(*it)->control_word().write(elmo_obj::ControlWord::cmd::fault_reset);
									break;
								case elmo_obj::state_t::ready_to_switch_on:
								case elmo_obj::state_t::switched_on:
								case elmo_obj::state_t::operation_enabled:
									(void)(*it)->control_word().write(elmo_obj::ControlWord::cmd::disable_voltage);
									break;
								default:
									return *it;
								}
								++it;
							}
						}
						(*agg.begin())->mst().wait_for(1u);
					}
					if(copy.size() > 0)
						return *copy.begin();
					if(en)
						return elmo::enable(agg, (timeout == -1) ? -1 : timeout - i);
				}
				return nullptr;
			}

			/**
			 * enable elmos - transit elmos' state to operation_enabled
			 * @param		agg is elmo drive's vector
			 * @param		timeout is ecatmst cycles allowed to complete the operation
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			template<typename T = ssi::node::elmo>
			static T* enable(const std::vector<T*>& agg, const int32_t timeout = 100) {
				std::vector<T*> copy = agg;
				if(agg.size() > 0) {
					for(int i = 0; copy.size() > 0 && ((i < timeout) || (timeout == -1)); i++) {
						for(auto it = copy.begin(); it != copy.end(); ) {
							if((*it)->state() == elmo_obj::state_t::operation_enabled)
								it = copy.erase(it);
							else {
								switch((*it)->state()) {
								case elmo_obj::state_t::start:
								case elmo_obj::state_t::not_ready_to_switch_on:
									break;
								case elmo_obj::state_t::switch_on_disabled:
									(void)(*it)->control_word().write(elmo_obj::ControlWord::cmd::shutdown);
									break;
								case elmo_obj::state_t::ready_to_switch_on:
									(void)(*it)->control_word().write(elmo_obj::ControlWord::cmd::switch_on);
									break;
								case elmo_obj::state_t::switched_on:
									(void)(*it)->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
									break;
								default:
									return *it;
								}
								++it;
							}
						}
						(void)(*agg.begin())->mst().wait_for(1u);
					}
					if(copy.size() > 0)
						return *copy.begin();
				}
				return nullptr;
			}

			/**
			 * disable elmos - transit elmos' state to disabled_voltage
			 * @param		agg is elmo drive's vector
			 * @param		timeout is ecatmst cycles allowed to complete the operation
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			template<typename T = ssi::node::elmo>
			static T* disable(const std::vector<T*>& agg, const int32_t timeout = 100) {
				std::vector<T*> copy = agg;
				if(agg.size() > 0) {
					for(int i = 0; copy.size() > 0 && ((i < timeout) || (timeout == -1)); i++) {
						for(auto it = copy.begin(); it != copy.end(); ) {
							if((*it)->state() == elmo_obj::state_t::switch_on_disabled)
								it = copy.erase(it);
							else {
								(void)(*it)->control_word().write(elmo_obj::ControlWord::cmd::disable_voltage);
								++it;
							}
						}
						(void)(*agg.begin())->mst().wait_for(1u);
					}
					if(copy.size() > 0)
						return *copy.begin();
				}
				return nullptr;
			}

			/**
			 * halt elmo drives - doesn't change elmo state by default
			 * @ingroup     sync-function realtime-feature
			 * @warning		this method just change the control value in the process image
			 *				and it means that the method doesn't guarantee real operation
			 *				you can call wait() after calling this method to solve the issue
			 * @param		agg is elmo drive's vector
			 * @param		en is enable flag to halt the elmo drive
			 * @return		nullptr on success, error string on error
			 */
			template<typename T = ssi::node::elmo>
			static T* halt(const std::vector<T*>& agg, bool en = true) {
				T* ret = nullptr;
				for(auto it : agg) {
					if(it->state() != elmo_obj::state_t::operation_enabled)
						ret = it;
					else
						it->control_word().write( elmo_obj::ControlWord::cmd::enable_operation | (en ? elmo_obj::ControlWord::flag::halt : 0) );
				}
				(void)(*agg.begin())->mst().wait_for(1u);
				return ret;
			}
			
			/**
			 * wait for being elmos' state to target reached
			 * @ingroup     sync-function nonrealtime-feature
			 * @warning     this function takes at least 1 master cycles at the beginning of the function
			 * @param		agg is elmo drive's vector
			 * @param       timeout is number of master cycles allowed, -1 for infinity
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			template<typename T = ssi::node::elmo>
			static T* wait(const std::vector<T*>& agg, int32_t timeout = -1) {
				std::vector<T*> copy = agg;
				if(agg.size() > 0) {
					for(int i = 0; copy.size() > 0 && ((i < timeout) || (timeout == -1)); i++) {
						(void)(*agg.begin())->mst().wait_for(1u);
						for(auto it = copy.begin(); it != copy.end(); ) {
							if( (*it)->status_word().read() &
								(elmo_obj::StatusWord::flag::internal_limit_active | elmo_obj::StatusWord::flag::operation_mode_specific1) )
								return *it;
							if((*it)->status_word().read() & elmo_obj::StatusWord::flag::target_reached)
								it = copy.erase(it);
							else
								++it;
						}
					}
					if(copy.size() > 0)
						return *copy.begin();
				}
				return nullptr;
			}

		protected:
			sdo_t _sdo;
			const elmo_cfg _cfg;

			/**
			 * workaround for elmo parameter problem that causes motion failure
			 * and it calls elmo "LD" command implicitly by writing to the object 0x1011
			 * @ingroup		sync-function nonrealtime-feature
			 * @see			"Command Reference for Gold Line Drives Ver. 1.512" page 208
			 *				"Gold DS-301 Implementation Guide Ver. 1.018" chap 16.11.
			 * @return		always nullptr
			 */
			const char* _load() try {
				std::array<uint8_t, 4> cmd = { 'l', 'o', 'a', 'd' };
				this->mst().writesdo(this->id(), 0x1011, 0x1, cmd.data(), sizeof(uint8_t) * cmd.size());
				return nullptr;
			} catch(...) {
				throw;
			}
			
			/**
			 * set the feedback position of an elmo drive by reading auxiliary position actual value(absolute encoder)
			 * @ingroup     sync-function nonrealtime-feature
			 * @warning		this method must be called before enabling the elmo drive
			 * @return      always nullptr
			 * @exception   throws ssi::instance_error in case that elmo_cfg is unacceptable
			 */
			const char* _feed() try {
				if(cfg().abs_encoder.sensor.resolution == -1)
					throw ssi::instance_error("invalid elmo_cfg");
				elmo_obj::AuxiliaryPositionActualValue::value_type pos = this->sdo().auxiliaryPositionActualValue.read();
				// in case of the elmo is not in the angular position within -180 degree and 180 degree
				if(cfg().type == elmo_cfg::rotation) {
					elmo_obj::AuxiliaryPositionActualValue::value_type boundary = cfg().abs_encoder.sensor.resolution / 2;
					pos +=
						(pos < -boundary) ? boundary :
						(pos > boundary) ? -boundary : 0;
					// overwrite auxiliary position in counts
					(void)this->sdo().auxiliaryPositioninCounts.write(pos);
				}
				pos = elmo_cfg::convert(cfg().abs_encoder, cfg().inc_encoder, pos);
				(void)this->sdo().feedbackPosition.write(pos);
				return nullptr;
			} catch(...) {
				throw;
			}

			/**
			 * set the feedback position of an elmo drive by value of summation of current incremental encoder's value and offset value
			 * @ingroup		sync-function nonrealtime-feature
			 * @warning		this method must be called before enabling the elmo drive
			 * @return		always nullptr
			 * @exception	throws ssi::runtime_error on unacceptable elmo state(operation_enabled)
			 */
			const char* _feed(elmo_obj::FeedbackPosition::value_type off) try {
				if(state() == elmo_obj::state_t::operation_enabled)
					throw runtime_error("setting feedback position fail: unacceptable elmo state");
				elmo_obj::FeedbackPosition::value_type pos = this->sdo().feedbackPosition.read();
				(void)this->sdo().feedbackPosition.write(pos + off);
				return nullptr;
			} catch(...) {
				throw;
			}

			/**
			 * create an elmo_fault exception and throw it
			 * @exception	always throws ssi::elmo_fault with its error code
			 */
			inline void _fault() {
				throw ssi::elmo_fault(this->info(), this->id(), this->sdo().errorCode.read());
			}
		};
	}
}

#endif // __SSI_NODE_ELMO_H__
