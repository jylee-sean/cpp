/**
 * @brief		elmo drive derived class targeting to profiled position mode
 * @details
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */

#ifndef __SSI_NODE_ELMOPP_H__
#define __SSI_NODE_ELMOPP_H__

#include <ratio>
#include <vector>

#include <phy/units.h>
#include <ssi/comst.h>
#include <ssi/config.h>
#include <ssi/node/elmo.h>

// #define PDOMAP_REV 'a'
#define PDOMAP_REV 'b'

namespace ssi
{
	namespace node
	{
		class elmopp final : public ssi::node::elmo
		{
		public:
			class profile : public ssi::node::elmo::profile
			{
			public:
				explicit profile(const elmo_obj::ProfileAcceleration::value_type acc = 0u, const elmo_obj::ProfileDeceleration::value_type dec = 0u, const elmo_obj::ProfileVelocity::value_type vel = 0u) :
					elmo::profile(), _acc(acc), _dec(dec), _vel(vel) { }
				elmo_obj::ProfileAcceleration::value_type acc() const { return _acc; }
				elmo_obj::ProfileDeceleration::value_type dec() const { return _dec; }
				elmo_obj::ProfileVelocity::value_type vel() const { return _vel; }
			private:
				elmo_obj::ProfileAcceleration::value_type _acc;
				elmo_obj::ProfileDeceleration::value_type _dec;
				elmo_obj::ProfileVelocity::value_type _vel;
			};

			class position_limits : public ssi::node::elmo::profile
			{
			public:
				using value_type = elmo_obj::SoftwarePositionLimit::min::value_type;
				explicit position_limits(const value_type min = std::numeric_limits<value_type>::min(), const value_type max = std::numeric_limits<value_type>::max()) :
					_min(min), _max(max) { }
				value_type min() const { return _min; }
				value_type max() const { return _max; }
			private:
				value_type _min;
				value_type _max;
			}; 

			/// input PDO map
			struct input_t
			{
#if (PDOMAP_REV == 'a')
				copdo<elmo_obj::StatusWord::value_type> statusWord;
				copdo<elmo_obj::DigitalInputs::value_type> digitalInputs;
				copdo<elmo_obj::PositionActualValue::value_type> positionActualValue;
				copdo<elmo_obj::VelocityActualValue::value_type> velocityActualValue;
				copdo<elmo_obj::AuxiliaryPositionActualValue::value_type> auxiliaryPositionActualValue;
#elif (PDOMAP_REV == 'b')
				copdo<elmo_obj::StatusWord::value_type> statusWord;
				copdo<elmo_obj::PositionActualValue::value_type> positionActualValue;
				copdo<elmo_obj::VelocityActualValue::value_type> velocityActualValue;
				copdo<elmo_obj::DigitalInputs::value_type> digitalInputs;
				copdo<elmo_obj::AuxiliaryPositionActualValue::value_type> auxiliaryPositionActualValue;
				copdo<elmo_obj::CurrentActualValue::value_type> currentActualValue;
#endif
			};

			/// output PDO map
			struct output_t
			{
#if (PDOMAP_REV == 'a')
				copdo<elmo_obj::ControlWord::value_type> controlWord;
				copdo<elmo_obj::DigitalOutputs::value_type> digitalOutputs;
				copdo<elmo_obj::TargetPosition::value_type> targetPosition;
#elif (PDOMAP_REV == 'b')
				copdo<elmo_obj::ControlWord::value_type> controlWord;
				copdo<elmo_obj::TargetPosition::value_type> targetPosition;
				copdo<elmo_obj::DigitalOutputs::value_type> digitalOutputs;
#endif
			};

			/// preserved variables to future use
			struct preserved_t {
				elmo_obj::MaxTorque::value_type maxTorque;
				elmo_obj::ProfileAcceleration::value_type profileAcceleration;
				elmo_obj::ProfileDeceleration::value_type profileDeceleration;
				elmo_obj::ProfileVelocity::value_type profileVelocity;
				elmo_obj::MotorRateCurrent::value_type motorRateCurrent;
			};

			elmopp() = delete;

			elmopp(comst& mst, const uint16_t id, const uint32_t input_addr, const uint32_t output_addr, const elmo_cfg& cfg) :
				ssi::node::elmo::elmo(mst, id, cfg),
				_input {
#if (PDOMAP_REV == 'a')
					copdo<elmo_obj::StatusWord::value_type>(mst, comst::in, input_addr + 0x00u),
					copdo<elmo_obj::DigitalInputs::value_type>(mst, comst::in, input_addr + 0x10u),
					copdo<elmo_obj::PositionActualValue::value_type>(mst, comst::in, input_addr + 0x30u),
					copdo<elmo_obj::VelocityActualValue::value_type>(mst, comst::in, input_addr + 0x50u),
					copdo<elmo_obj::AuxiliaryPositionActualValue::value_type>(mst, comst::in, input_addr + 0x70u)
#elif (PDOMAP_REV == 'b')
					copdo<elmo_obj::StatusWord::value_type>(mst, comst::in, input_addr + 0x00u),
					copdo<elmo_obj::PositionActualValue::value_type>(mst, comst::in, input_addr + 0x10u),
					copdo<elmo_obj::VelocityActualValue::value_type>(mst, comst::in, input_addr + 0x30u),
					copdo<elmo_obj::DigitalInputs::value_type>(mst, comst::in, input_addr + 0x50u),
					copdo<elmo_obj::AuxiliaryPositionActualValue::value_type>(mst, comst::in, input_addr + 0x70u),
					copdo<elmo_obj::CurrentActualValue::value_type>(mst, comst::in, input_addr + 0x90u)
#endif
				},
				_output {
#if (PDOMAP_REV == 'a')
					copdo<elmo_obj::ControlWord::value_type>(mst, comst::out, output_addr + 0x00u),
					copdo<elmo_obj::DigitalOutputs::value_type>(mst, comst::out, output_addr + 0x10u),
					copdo<elmo_obj::TargetPosition::value_type>(mst, comst::out, output_addr + 0x30u)
#elif (PDOMAP_REV == 'b')
					copdo<elmo_obj::ControlWord::value_type>(mst, comst::out, output_addr + 0x00u),
					copdo<elmo_obj::TargetPosition::value_type>(mst, comst::out, output_addr + 0x10u),
					copdo<elmo_obj::DigitalOutputs::value_type>(mst, comst::out, output_addr + 0x30u)
#endif
				} { }

			virtual ~elmopp() { }

			virtual copdo<elmo_obj::StatusWord::value_type>& status_word() override { return this->input().statusWord; }
			virtual copdo<elmo_obj::ControlWord::value_type>& control_word() override { return this->output().controlWord; }

			/**
			 * initialize elmo drive after setting its profile an operation mode
			 * @ingroup		sync-function nonrealtime-feature
			 * @warning		it takes additional time to apply profile & change its mode
			 * @param		prof is an elmo profile for profiled position mode
			 * @param		fen is the enable flag parameter means whether you want to adjust it's feedback position by reading absolute encoder
			 * @return		nullptr on success, error string on error
			 */
			const char* init(const profile& prof, bool fen = true) try {
				const char* what;
				_load();
				_preserved.maxTorque = sdo().maxTorque.read();
				_preserved.motorRateCurrent = sdo().motorRateCurrent.read();
				if( fen && ((what = _feed()) != nullptr) )
					return what;
				return _mode(prof);
			} catch(...) {
				throw;
			}

			const char* init(const profile& prof, const position_limits& lim, bool fen = true) try {
				_limit(lim);
				return init(prof, fen);
			} catch(...) {
				throw;
			}
			
			/**
			 * finalize elmo drive
			 * this method does nothing
			 * @return		always nullptr
			 */
			const char* fini() { return nullptr; }

			/**
			 * @see			ssi::node::elmo::feed
			 */
			const char* feed() try { return _feed(); } catch(...) { throw; }

			/**
			 * @see			ssi::node::elmo::feed
			 */
			const char* feed(elmo_obj::FeedbackPosition::value_type off) try { return _feed(off); } catch(...) { throw; }

			/**
			 * get the target position in the process image
			 * @ingroup		async-function realtime-feature
			 * @return		always the target position
			 */
			elmo_obj::TargetPosition::value_type target() {
				return this->output().targetPosition.read();
			}
			
			/**
			 * change target position in the process image
			 * @ingroup		async-function realtime-feature
			 * @warning		this function doesn't update elmo state
			 * @param		t is target position you want to change to
			 */
			void target(const elmo_obj::TargetPosition::value_type t) {
				(void)this->output().targetPosition.write(t);
			}

			/**
			 * change target position in the process image to the value in turns
			 * @ingroup		async-function realtime-feature
			 * @warning		this function doesn't update elmo state
			 * @param		a is target position angle you want to change to
			 */
			template<typename T, typename U>
			void target(const phy::units::angle<T, U>& a) try {
				(void)this->output().targetPosition.write(this->convert(a));
			} catch(...) { throw; }

			/**
			 * change target position in the process image to the value in millimeters
			 * @ingroup		async-function realtime-feature
			 * @warning		this function doesn't update elmo state
			 * @param		l is target position length you want to change to
			 */
			template<typename T, typename U>
			void target(const phy::units::length<T, U>& l) try {
				(void)this->output().targetPosition.write(this->convert(l));
			} catch(...) { throw; }

			/**
			 * convert units::angle<> to position actual value of elmo incremental encoder
			 * @ingroup		async-function realtime-feature
			 * @param		a is the angle you want to convert
			 * @return		always converted value
			 * @exception	throws ssi::invalid_argument, in case of the elmo is not rotation type
			 */
			template<typename T, typename U>
			elmo_obj::PositionActualValue::value_type convert(const phy::units::angle<T, U>& a) {
				if(cfg().type != elmo_cfg::rotation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				return ssi::node::elmo_cfg::encode(cfg().inc_encoder, phy::units::angle_cast<phy::units::turn>(a).value());
			}

			/**
			 * convert units::length<> to position actual value of elmo incremental encoder
			 * @ingroup		async-function realtime-feature
			 * @param		l is the length you want to convert
			 * @return		always converted value
			 * @exception	throws ssi::invalid_argument, in case of the elmo is not translation type
			 */
			template<typename T, typename U>
			elmo_obj::PositionActualValue::value_type convert(const phy::units::length<T, U>& l) {
				if(cfg().type != elmo_cfg::translation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				return ssi::node::elmo_cfg::encode(cfg().inc_encoder, phy::units::length_cast<phy::units::millimeter>(l).value());
			}

			/**
			 * get current actual position from the process image
			 * @ingroup		async-function realtime-feature
			 * @param		src is the encoder source which encoder you want to read(incremental or absolute)
			 * @return		always encoder's value from the process image
			 */
			elmo_obj::PositionActualValue::value_type position(source_t src = source_t::incremental) {
				if(src == source_t::incremental)
					return this->input().positionActualValue.read();
				else if(src == source_t::absolute)
					return this->input().auxiliaryPositionActualValue.read();
				else
					throw ssi::invalid_argument("invalid encoder source type");
			}

			/**
			 * get current velocity value from the process image
			 * @ingroup		async-function realtime-feature
			 * @return		always velocity actual value
			 */
			elmo_obj::VelocityActualValue::value_type velocity() {
				return this->input().velocityActualValue.read();
			}

			/**
			 * get current elmo's angle in turns
			 * @warning		same methods is in elmopv class
			 * @ingroup		async-function realtime-feature
			 * @param		src is the encoder source which encoder you want to read(incremental or absolute)
			 * @return		always current position calculated
			 */
			inline phy::units::turn angle(source_t src = source_t::incremental) {
				if(cfg().type != elmo_cfg::rotation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				if(src == source_t::incremental)
					return phy::units::turn(ssi::node::elmo_cfg::decode(cfg().inc_encoder, input().positionActualValue.read()));
				else if(src == source_t::absolute)
					return phy::units::turn(ssi::node::elmo_cfg::decode(cfg().abs_encoder, input().auxiliaryPositionActualValue.read()));
				else
					throw ssi::invalid_argument("invalid encoder source type");
			}
			
			/**
			 * get current position in SI units(milli meters)
			 * @warning		same methods is in elmopv class
			 * @ingroup		async-function realtime-feature
			 * @param		src is the encoder source which encoder you want to read(incremental or absolute)
			 * @return		always current position calculated
			 */
			inline phy::units::millimeter length(source_t src = source_t::incremental) {
				if(cfg().type != elmo_cfg::translation)
					throw ssi::invalid_argument("elmo motion type mismatched");
				if(src == source_t::incremental)
					return phy::units::millimeter(ssi::node::elmo_cfg::decode(cfg().inc_encoder, input().positionActualValue.read()));
				else if(src == source_t::absolute)
					return phy::units::millimeter(ssi::node::elmo_cfg::decode(cfg().abs_encoder, input().auxiliaryPositionActualValue.read()));
				else
					throw ssi::invalid_argument("invalid encoder source type");
			}

			/**
			 * get actual current of the elmo drive
			 * @ingroup		async-function realtime-feature
			 * @param		actual is the flag designates what you want to get
			 *				if the parameter is true, the method returns the value from current actual value
			 *				otherwise, the method returns current actual value / 1000 * motor rate current and the value is in mA
			 * @return		always current actual value
			 */
#if (PDOMAP_REV == 'b')
			inline double current(bool actual = false) {
				return actual ?
					static_cast<double>(input().currentActualValue.read()) :
					static_cast<double>(input().currentActualValue.read()) * preserved().motorRateCurrent / 1000;
			}
#endif

			/**
			 * set the elmo to move to the target position and wait for the set new point acknowledgement of elmo
			 * and you can wait for target_reached after calling the method
			 * the sequence is written in 12.16. Functional Description of "CAN DS-402 Implementation Guide Ver. 1.016)
			 * @ingroup		sync-function realtime-feature
			 * @warning		this function takes at least 2 master cycles(in most case, it take 6 cycles)
			 * @param		imm is the flag for operation_mode_specific1, true for single set-point and false for set of set-points
			 * @param		timeout is number of master cycles allowed for waiting the acknowledgement from elmo
			 * @return		true on success, false on timeout
			 */
			inline bool move(bool imm = true, int32_t timeout = 10) try {
				if(state() != elmo_obj::state_t::operation_enabled)
					this->_fault();
				this->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
				this->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
				(void)_mst.wait_for(1u);
				this->control_word().write(elmo_obj::ControlWord::cmd::enable_operation | elmo_obj::ControlWord::flag::operation_mode_specific0 |
										   (imm ? elmo_obj::ControlWord::flag::operation_mode_specific1 : 0));

				for(int32_t i = 0; i < timeout; i++) {
					if(this->status_word().read() & elmo_obj::StatusWord::flag::operation_mode_specific0) {
						this->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
						(void)_mst.wait_for(1u);
						return true;
					}
					(void)_mst.wait_for(1u);
				}
				return false;
			} catch (...) { throw; }

			/**
			 * set the elmos to move to the target position and wait for the set new point acknowledgement of elmo
			 * and you can wait for target_reached after calling the method
			 * the sequence is defined in 12.16. Functional Description of "CAN DS-402 Implementation Guide Ver. 1.016)
			 * @ingroup		sync-function realtime-feature
			 * @warning		this function takes at least 2 master cycles(in most case, it take 6 cycles)
			 * @param		agg is array of the elmopp's ptr for applying the command
			 * @param		imm is the flag for operation_mode_specific1, true for single set-point and false for set of set-points
			 * @param		timeout is number of master cycles allowed for waiting the acknowledgement from elmo
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			inline static ssi::node::elmopp* move(const std::vector<ssi::node::elmopp*>& agg, bool imm = true, int32_t timeout = 10) try {
				std::vector<ssi::node::elmopp*> copy = agg;
				if(agg.size() > 0) {
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) {
						if(e->state() != elmo_obj::state_t::operation_enabled)
							e->_fault();
					});
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) {
						(void)e->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
					});
					(*agg.begin())->mst().wait_for(1u);
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) {
						(void)e->control_word().write( elmo_obj::ControlWord::cmd::enable_operation | elmo_obj::ControlWord::flag::operation_mode_specific0 |
													   (imm ? elmo_obj::ControlWord::flag::operation_mode_specific1 : 0) );
					});
					for(int i = 0; (i < timeout) || (timeout == -1); i++) { 
						for(auto it = copy.begin(); it != copy.end(); ) {
							if((*it)->status_word().read() & elmo_obj::StatusWord::flag::operation_mode_specific0) {
								(*it)->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
								it = copy.erase(it);
							} else {
								++it;
							}
						}
						(*agg.begin())->mst().wait_for(1u);
					}
				}
				if(copy.size() > 0)
					return *copy.begin();
				return 0;
			} catch (...) { throw; }

			/**
			 * set the elmo to move to the target position
			 * @ingroup		sync-function realtime-feature
			 * @warning		this function takes 2 master cycles and return before receiving acknowledge from elmo drive 
			 */
			inline void trymove() try {
				if(state() != elmo_obj::state_t::operation_enabled)
					this->_fault();
				this->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
				(void)_mst.wait_for(1u);
				this->control_word().write(elmo_obj::ControlWord::cmd::enable_operation | elmo_obj::ControlWord::flag::operation_mode_specific0 | elmo_obj::ControlWord::flag::operation_mode_specific1);
				(void)_mst.wait_for(1u);
				this->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
			} catch(...) { throw; }

			/**
			 * set the elmos to move
			 * @ingroup		sync-function realtime-feature
			 * @warning		this function takes 2 master cycles and return before receiving acknowledge from elmo drive 
			 * @param		agg is array of the elmopp's ptr for applying the command
			 */
			inline static void trymove(const std::vector<ssi::node::elmopp*>& agg) try {
				if(agg.size() > 0) {
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) {
						if(e->state() != elmo_obj::state_t::operation_enabled)
							e->_fault();
					});
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) {
						(void)e->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
					});
					(*agg.begin())->mst().wait_for(1u);
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) {
						(void)e->control_word().write(elmo_obj::ControlWord::cmd::enable_operation | elmo_obj::ControlWord::flag::operation_mode_specific0 | elmo_obj::ControlWord::flag::operation_mode_specific1); });
					(*agg.begin())->mst().wait_for(1u);
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) {
						(void)e->control_word().write(elmo_obj::ControlWord::cmd::enable_operation);
					});
				}
			} catch(...) { throw; }

			/**
			 * move elmo to the position and wait for the acknowledgement
			 * @ingroup		sync-function realtime-feature
			 * @param		t is target position you want to move to
			 * @param		imm is the flag for operation_mode_specific1, true for single set-point and false for set of set-points
			 * @param		timeout is number of master cycles allowed, -1 for infinity
			 * @return		always positionActualValue from the process image
			 */
			template<typename T, typename std::enable_if<!std::is_same<T, std::vector<ssi::node::elmopp*>>::value, T>::type* = nullptr>
			elmo_obj::PositionActualValue::value_type moveto(const T t, bool imm = true, int32_t timeout = 10) try {
				target(t); move(imm, timeout);
				return position(); 
			} catch (...) {
				throw;
			}

			/**
			 * move elmos to the position and wait for the acknowledgement
			 * @ingroup		sync-function realtime-feature
			 * @param		agg is array of the elmopp's ptr for applying the command
			 * @param		t is target position you want to move to
			 * @param		imm is the flag for operation_mode_specific1, true for single set-point and false for set of set-points
			 * @param		timeout is number of master cycles allowed, -1 for infinity
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			template<typename T>
			inline static ssi::node::elmopp* moveto(std::vector<ssi::node::elmopp*>& agg, const T t, bool imm = true, int32_t timeout = 10) try {
				ssi::node::elmopp* ret = nullptr;
				if(agg.size() > 0) {
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) { e->target(t); });
					ret = elmopp::move(agg, imm, timeout);
				}
				return ret;
			} catch (...) {
				throw;
			}

			/**
			 * move elmo to the position
			 * @ingroup		sync-function realtime-feature
			 * @warning		this function takes at least 2 master cycles
			 * @param		t is target position you want to move to
			 * @return		always positionActualValue from the process image
			 */
			template<typename T>
			elmo_obj::PositionActualValue::value_type trymoveto(const T t) try {
				target(t); trymove();
				return position();
			} catch (...) {
				throw;
			}

			/**
			 * move elmos to the position
			 * @ingroup		sync-function realtime-feature
			 * @param		agg is array of the elmopp's ptr for applying the command
			 * @param		t is target position you want to move to
			 */
			template<typename T>
			inline static void trymoveto(const std::vector<ssi::node::elmopp*>& agg, const T t) try {
				if(agg.size() > 0) {
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) { e->target(t); });
					elmopp::trymove(agg);
				}
				return ;
			} catch (...) {
				throw;
			}

			/**
			 * stick to the current position and wait for reaching the target position
			 * @ingroup		sync-function nonrealtime-feature
			 * @warning		this method may cause counter-force
			 * @param		agg is array of the elmopp's ptr for applying the command
			 * @param		timeout is number of master cycles allowed, -1 for infinity
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			inline static ssi::node::elmopp* stick(const std::vector<ssi::node::elmopp*>& agg, int32_t timeout = -1) try {
				ssi::node::elmopp* ret = nullptr;
				if(agg.size() > 0) {
					if( (ret = elmopp::trystick(agg)) != nullptr )
						return ret;
					ret = elmopp::wait(agg, timeout);
				}
				return ret;
			} catch (...) {
				throw;
			}

			/**
			 * stick to the current position
			 * @ingroup		sync-function realtime-feature
			 * @warning		this method may cause counter-force
			 * 				and it takes at least 2 master cycles
			 * @return		nullptr on success, first fault slave ptr on error
			 */
			inline static ssi::node::elmopp* trystick(const std::vector<ssi::node::elmopp*>& agg) try {
				ssi::node::elmopp* ret = nullptr;
				if(agg.size() > 0) {
					std::for_each(agg.begin(), agg.end(), [&](ssi::node::elmopp* e) { e->target(e->position()); });
					if( (ret = elmopp::move(agg)) != nullptr )
						return ret;
				}
				return ret;
			} catch (...) {
				throw;
			}

			/**
			 * suppress max velocity with given ratio
			 */
			template<typename R = std::ratio<1, 1>>
			inline bool suppress(R r) {
				return sdo().profileVelocity.write(preserved().profileVelocity * r.num / r.den) > 0;
			}

			/**
			 * get the difference of incremantal encoder and absolute encoder in turn
			 * @return		always the difference
			 */
			inline phy::units::turn following_error_angle() try {
				return phy::units::turn(angle(source_t::incremental).value() - angle(source_t::absolute).value());
			} catch(...) { }

			/**
			 * get the difference of incremantal encoder and absolute encoder in SI units(millimeters)
			 * @return		always the difference
			 */
			inline phy::units::millimeter following_error_length() try {
				return phy::units::millimeter(length(source_t::incremental).value() - length(source_t::absolute).value());
			} catch(...) { }

			input_t& input() { return _input; }
			output_t& output() { return _output; }
			preserved_t& preserved() { return _preserved; }

		private:
			input_t _input;
			output_t _output;
			preserved_t _preserved;

			/**
			 * set the elmo's profile and change its mode to profiled position mode
			 * @ingroup		sync-function nonrealtime-feature
			 * @param		prof is the profile to apply
			 * @param		timeout number of retrying allowed
			 * @return		nullptr on success, error string on error
			 */
			const char* _mode(const profile& prof, const size_t nretry = 3) try {
				(void)this->sdo().profileAcceleration.write(prof.acc());
				(void)this->sdo().profileDeceleration.write(prof.dec());
				(void)this->sdo().profileVelocity.write(prof.vel());
				(void)this->sdo().modesOfOperation.write(elmo_obj::ModesOfOperation::profile_position_mode);

				for(size_t i = 0; i < nretry; i ++) {
					if(this->sdo().modesOfOperationDisplay.read() == elmo_obj::ModesOfOperation::profile_position_mode) {
						this->_preserved.profileAcceleration = prof.acc();
						this->_preserved.profileDeceleration = prof.dec();
						this->_preserved.profileVelocity = prof.vel();
						return nullptr;
					}
				}
				return "changing mode fail";
			} catch (...) {
				throw;
			}

			/**
			 * set the elmo's software position limit profile
			 * @ingroup     sync-function nonrealtime-feature
			 * @param       l is the position limit profile to apply
			 * @return      always nullptr
			 */
			const char* _limit(const position_limits& l) try {
				if(this->sdo().softwarePositionLimitMin.write(l.min()) <= 0 ||
				   this->sdo().softwarePositionLimitMax.write(l.max()) <= 0)
					return "sdo error";
				return nullptr;
			} catch (...) {
				throw;
			} 
		};
	}
}

#endif // __SSI_NODE_ELMOPP_H__
