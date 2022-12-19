/**
 * @brief		elmo CAN DS-402 header
 * @details
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */

#ifndef __SSI_ELMO_OBJ_H__
#define __SSI_ELMO_OBJ_H__

#include <cstdint>
#include <cstddef>

#include <ssi/coobj.h>


namespace ssi
{
	namespace node
	{
		// namespace ds402
		class ds402
		{
		public:
			enum state_t
			{
				start,
				not_ready_to_switch_on,
				switch_on_disabled,
				ready_to_switch_on,
				switched_on,
				operation_enabled,
				quick_stop_active,
				fault_reaction_active,
				fault,
				unknown
			};

			class StatusWord : public coobj<uint16_t>
			{
			public:
				StatusWord() : coobj<uint16_t>(0x6041u, 0x00u, rdonly, yes) { }
				virtual ~StatusWord() { }

				struct flag {
					static constexpr uint16_t ready_to_switch_on = 0x0001u;
					static constexpr uint16_t switched_on = 0x0002u;
					static constexpr uint16_t operation_enabled = 0x0004u;
					static constexpr uint16_t fault = 0x0008u;
					static constexpr uint16_t voltage_enabled = 0x0010u;
					static constexpr uint16_t quick_stop = 0x0020u;
					static constexpr uint16_t switch_on_disabled = 0x0040u;
					static constexpr uint16_t warning = 0x0080u;
					static constexpr uint16_t manufacturer_specific0 = 0x0100u;
					static constexpr uint16_t remote = 0x0200u;
					static constexpr uint16_t target_reached = 0x0400u;
					static constexpr uint16_t internal_limit_active = 0x0800u;
					static constexpr uint16_t operation_mode_specific0 = 0x1000u;
					static constexpr uint16_t set_newpoint_acknowledge = operation_mode_specific0; // alias
					static constexpr uint16_t operation_mode_specific1 = 0x2000u;
					static constexpr uint16_t following_error = operation_mode_specific1; // alias
					static constexpr uint16_t manufacturer_specific1 = 0x4000u;
					static constexpr uint16_t manufacturer_specific2 = 0x8000u;
				};
			};

			class ControlWord : public coobj<uint16_t>
			{
			public:
				ControlWord() : coobj<uint16_t>(0x6040u, 0x00u, rdwr, yes) { }
				virtual ~ControlWord() { }

				struct flag {
					static constexpr uint16_t switch_on = 0x0001u;
					static constexpr uint16_t enable_voltage = 0x0002u;
					static constexpr uint16_t quick_stop = 0x0004u;
					static constexpr uint16_t enable_operation = 0x0008u;
					static constexpr uint16_t operation_mode_specific0 = 0x0010u;
					static constexpr uint16_t operation_mode_specific1 = 0x0020u;
					static constexpr uint16_t operation_mode_specific2 = 0x0040u;
					// aliases for elmo profiled position mode
					static constexpr uint16_t new_set_point = operation_mode_specific0;
					static constexpr uint16_t change_set_point_immediately = operation_mode_specific1;
					static constexpr uint16_t absolute_relative_movement = operation_mode_specific2;
					static constexpr uint16_t fault_reset = 0x0080u;
					static constexpr uint16_t halt = 0x0100u;
					static constexpr uint16_t reserved0 = 0x0200u;
					static constexpr uint16_t reserved1 = 0x0400u;
					static constexpr uint16_t manufacturer_specific0 = 0x0800u;
					static constexpr uint16_t manufacturer_specific1 = 0x1000u;
					static constexpr uint16_t manufacturer_specific2 = 0x2000u;
					static constexpr uint16_t manufacturer_specific3 = 0x4000u;
					static constexpr uint16_t manufacturer_specific4 = 0x8000u;
				};

				struct cmd {
					const static value_type shutdown = flag::quick_stop | flag::enable_voltage;
					const static value_type switch_on = flag::quick_stop | flag::enable_voltage | flag::switch_on;
					const static value_type switch_on_and_enable_operation = flag::enable_operation | flag::quick_stop | flag::enable_voltage | flag::switch_on;
					const static value_type disable_voltage = 0u;
					const static value_type quick_stop = flag::enable_voltage;
					const static value_type disable_operation = flag::quick_stop | flag::enable_voltage | flag::switch_on;
					const static value_type enable_operation = flag::enable_operation | flag::quick_stop | flag::enable_voltage | flag::switch_on;
					// fault reset is performed only at the positive edge of fault reset signal
					// thus another command with !fault_reset must sent before using this command
					const static value_type fault_reset = flag::fault_reset;
				};
			};

			class HaltOptionCode : public coobj<int16_t>
			{
			public:
				HaltOptionCode() : coobj<int16_t>(0x605du, 0x00u, rdwr, yes) { }
				virtual ~HaltOptionCode() { }
			};

			class ModesOfOperation : public coobj<int8_t>
			{
			public:
				ModesOfOperation() : coobj<int8_t>(0x6060u, 0x00u, rdwr, yes) { }
				virtual ~ModesOfOperation() { }

				enum value {
					can_encoder_mode = -3,
					profile_position_mode = 1,
					velocity = 2,
					profiled_velocity_mode = 3,
					torque_profiled_mode = 4,
					reserved = 5,
					homing_mode = 6,
					interpolated_position_mode = 7,
					cyclic_synchronous_position = 8,
					cyclic_synchronous_velocity = 9,
					cyclic_synchronous_torque = 10
				};
			};

			class ModesOfOperationDisplay : public coobj<int8_t>
			{
			public:
				ModesOfOperationDisplay() : coobj<int8_t>(0x6061u, 0x00u, rdonly, txmap) { }
				virtual ~ModesOfOperationDisplay() { }
			};

			class PositionDemandValue : public coobj<int32_t>
			{
			public:
				PositionDemandValue() : coobj<int32_t>(0x6062u, 0x00u, rdonly, yes) { }
				virtual ~PositionDemandValue() { }
			};

			class PositionActualValue : public coobj<int32_t>
			{
			public:
				PositionActualValue() : coobj<int32_t>(0x6064u, 0x00u, rdonly, yes) { }
				virtual ~PositionActualValue() { }
			};

			class VelocityDemandValue : public coobj<int32_t>
			{
			public:
				VelocityDemandValue() : coobj<int32_t>(0x606bu, 0x00u, rdonly, txmap) { }
				virtual ~VelocityDemandValue() { }
			};

			class VelocityActualValue : public coobj<int32_t>
			{
			public:
				VelocityActualValue() : coobj<int32_t>(0x606cu, 0x00u, rdonly, txmap) { }
				virtual ~VelocityActualValue() { }
			};

			class TargetTorque : public coobj<int16_t>
			{
			public:
				TargetTorque() : coobj<int16_t>(0x6071u, 0x00u, rdwr, yes) { }
				virtual ~TargetTorque() { }
			};

			class MaxTorque : public coobj<uint16_t>
			{
			public:
				MaxTorque() : coobj<uint16_t>(0x6072u, 0x00u, rdwr, no, 1, 50000, 50000) { }
				virtual ~MaxTorque() { }
			};

			class MaxCurrent : public coobj<uint16_t>
			{
			public:
				MaxCurrent() : coobj<uint16_t>(0x6073u, 0x00u, rdwr, no) { }
				virtual ~MaxCurrent() { }
			};

			class TorqueDemandValue : public coobj<int16_t>
			{
			public:
				TorqueDemandValue() : coobj<int16_t>(0x6074u, 0x00u, rdonly, txmap) { }
				virtual ~TorqueDemandValue() { }
			};

			class MotorRateCurrent : public coobj<uint32_t>
			{
			public:
				MotorRateCurrent() : coobj<uint32_t>(0x6075u, 0x00u, rdwr, no) { }
				virtual ~MotorRateCurrent() { }
			};

			class MotorRateTorque : public coobj<uint32_t>
			{
			public:
				MotorRateTorque() : coobj<uint32_t>(0x6076u, 0x00u, rdwr, no) { }
				virtual ~MotorRateTorque() { }
			};

			class TorqueActualValue : public coobj<int16_t>
			{
			public:
				TorqueActualValue() : coobj<int16_t>(0x6077u, 0x00u, rdonly, txmap) { }
				virtual ~TorqueActualValue() { }
			};

			class CurrentActualValue : public coobj<int16_t>
			{
			public:
				CurrentActualValue() : coobj<int16_t>(0x6078u, 0x00u, rdonly, txmap) { }
				virtual ~CurrentActualValue() { }
			};

			class TargetPosition : public coobj<int32_t>
			{
			public:
				TargetPosition() : coobj<int32_t>(0x607au, 0x00u, rdwr, txrxmap) { }
				virtual ~TargetPosition() { }
			};

			class PositionRangeLimit
			{
			public:
				class nentries : public coobj<int32_t>
				{
				public:
					nentries() : coobj<int32_t>(0x607bu, 0x00u, rdonly, no) { }
					virtual ~nentries() { }
				};
				class min : public coobj<int32_t>
				{
				public:
					min() : coobj<int32_t>(0x607bu, 0x01u, rdwr, no) { }
					virtual ~min() { }
				};
				class max : public coobj<int32_t>
				{
				public:
					max() : coobj<int32_t>(0x607bu, 0x02u, rdwr, no) { }
					virtual ~max() { }
				};
			};

			class HomeOffset : public coobj<int32_t>
			{
			public:
				HomeOffset() : coobj<int32_t>(0x607c, 0x00u, rdwr, no) { }
				virtual ~HomeOffset() { }
			};

			class SoftwarePositionLimit
			{
			public:
				class nentries : public coobj<int32_t>
				{
				public:
					nentries() : coobj<int32_t>(0x607du, 0x00u, rdonly, no) { }
					virtual ~nentries() { }
				};
				class min : public coobj<int32_t>
				{
				public:
					min() : coobj<int32_t>(0x607du, 0x01u, rdwr, no) { }
					virtual ~min() { }
				};
				class max : public coobj<int32_t>
				{
				public:
					max() : coobj<int32_t>(0x607du, 0x02u, rdwr, no) { }
					virtual ~max() { }
				};
			};

			class MaxProfileVelocity : public coobj<uint32_t>
			{
			public:
				MaxProfileVelocity() : coobj<uint32_t>(0x607f, 0x00u, rdwr, no) { }
				virtual ~MaxProfileVelocity() { }
			};

			class ProfileVelocity : public coobj<uint32_t>
			{
			public:
				ProfileVelocity() : coobj<uint32_t>(0x6081u, 0x00u, rdwr, yes) { }
				virtual ~ProfileVelocity() { }
			};

			class ProfileAcceleration : public coobj<uint32_t>
			{
			public:
				ProfileAcceleration() : coobj<uint32_t>(0x6083u, 0x00u, rdwr, yes) { }
				virtual ~ProfileAcceleration() { }
			};

			class ProfileDeceleration : public coobj<uint32_t>
			{
			public:
				ProfileDeceleration() : coobj<uint32_t>(0x6084u, 0x00u, rdwr, yes) { }
				virtual ~ProfileDeceleration() { }
			};

			class QuickStopDeceleration : public coobj<uint32_t>
			{
			public:
				QuickStopDeceleration() : coobj<uint32_t>(0x6085u, 0x00, rdwr, yes) { }
				virtual ~QuickStopDeceleration() { }
			};

			class TorqueSlope : public coobj<uint32_t>
			{
			public:
				TorqueSlope() : coobj<uint32_t>(0x6087u, 0x00u, rdwr, yes) { }
				virtual ~TorqueSlope() { }
			};

			class HomingMethod : public coobj<int8_t>
			{
			public:
				HomingMethod() : coobj<int8_t>(0x6098u, 0x00u, rdwr, no) { }
				virtual ~HomingMethod() { }
			};

			class HomingSpeeds
			{
			public:
				class nentries : public coobj<uint32_t>
				{
				public:
					nentries() : coobj<uint32_t>(0x6099u, 0x00u, rdonly, no) { }
					virtual ~nentries() { }
				};
				class for_switch : public coobj<uint32_t>
				{
				public:
					for_switch() : coobj<uint32_t>(0x6099u, 0x01u, rdwr, no) { }
					virtual ~for_switch() { }
				};
				class for_zero : public coobj<uint32_t>
				{
				public:
					for_zero() : coobj<uint32_t>(0x6099u, 0x02u, rdwr, no) { }
					virtual ~for_zero() { }
				};
			};

			class HomingAcceleration : public coobj<uint32_t>
			{
			public:
				HomingAcceleration() : coobj<uint32_t>(0x609au, 0x00u, rdwr, no) { }
				virtual ~HomingAcceleration() { }
			};

			class PositionOffset : public coobj<int32_t>
			{
			public:
				PositionOffset() : coobj<int32_t>(0x60b0u, 0x00u, rdwr, yes) { }
				virtual ~PositionOffset() { }
			};

			class VelocityOffset : public coobj<int32_t>
			{
			public:
				VelocityOffset() : coobj<int32_t>(0x60b1u, 0x00u, rdwr, yes) { }
				virtual ~VelocityOffset() { }
			};

			class TorqueOffset : public coobj<int16_t>
			{
			public:
				TorqueOffset() : coobj<int16_t>(0x60b2u, 0x00u, rdwr, yes) { }
				virtual ~TorqueOffset() { }
			};

			class MaxAcceleration : public coobj<uint32_t>
			{
			public:
				MaxAcceleration() : coobj<uint32_t>(0x60c5, 0x00u, rdwr, no) { }
				virtual ~MaxAcceleration() { }
			};

			class MaxDeceleration : public coobj<uint32_t>
			{
			public:
				MaxDeceleration() : coobj<uint32_t>(0x60c6, 0x00u, rdwr, no) { }
				virtual ~MaxDeceleration() { }
			};

			class DigitalInputs : public coobj<uint32_t>
			{
			public:
				DigitalInputs() : coobj<uint32_t>(0x60fdu, 0x00u, rdonly, yes) { }
				virtual ~DigitalInputs() { }
			};

			// object DigitalOutputs has 2 sub entries
			// i'm not sure but sub index 1 is capable for PDO mapping
			class DigitalOutputs : public coobj<uint32_t>
			{
			public:
				DigitalOutputs() : coobj<uint32_t>(0x60feu, 0x01u, rdwr, rxmap) { }
				virtual ~DigitalOutputs() { }
			};

			class TargetVelocity : public coobj<int32_t>
			{
			public:
				TargetVelocity() : coobj<int32_t>(0x60ffu, 0x00u, rdwr, yes) { }
				virtual ~TargetVelocity() { }
			};

			class ErrorCode : public coobj<uint16_t>
			{
			public:
				ErrorCode() : coobj<uint16_t>(0x603fu, 0x00u, rdonly, no) { }
				virtual ~ErrorCode() { }
			};

			class FeedbackPosition : public coobj<int32_t>
			{
			public:
				FeedbackPosition() : coobj<int32_t>(0x3091u, 0x01u, rdwr, yes) { }
				virtual ~FeedbackPosition() { }
			};

			class AuxiliaryPositioninCounts : public coobj<int32_t>
			{
			public:
				AuxiliaryPositioninCounts() : coobj<int32_t>(0x319eu, 0x01u, rdwr, yes) { }
				virtual ~AuxiliaryPositioninCounts() { }
			};

			// same as AuxiliaryPositioninCounts
			class AuxiliaryPositionActualValue : public coobj<int32_t>
			{
			public:
				AuxiliaryPositionActualValue() : coobj<int32_t>(0x20a0u, 0x00u, rdwr, yes) { }
				virtual ~AuxiliaryPositionActualValue() { }
			};

			static constexpr uint16_t index(const char* elmo_command) {
				return static_cast<uint16_t>(0x3000) + 26 * (elmo_command[0] - 65) + (elmo_command[1] - 65);
			}
			
			static const uint16_t index(const std::array<char, 2>& elmo_command) {
				return static_cast<uint16_t>(0x3000) + 26 * (elmo_command[0] - 65) + (elmo_command[1] - 65);
			}

			const static state_t next_state(StatusWord::value_type const status)
			{
				state_t ret =unknown;

				static const StatusWord::value_type r = StatusWord::flag::ready_to_switch_on;
				static const StatusWord::value_type s = StatusWord::flag::switched_on;
				static const StatusWord::value_type o = StatusWord::flag::operation_enabled;
				static const StatusWord::value_type f = StatusWord::flag::fault;
				static const StatusWord::value_type q = StatusWord::flag::quick_stop;
				static const StatusWord::value_type d = StatusWord::flag::switch_on_disabled;

				switch(status & (d | q | f | o | s | r))
				{
					case 0:					// '0 | 0 | 0 | 0 | 0 | 0:'
					case q:					// '0 | q | 0 | 0 | 0 | 0:'
						{
							ret = not_ready_to_switch_on;
							break;
						}
					case d:					// 'd | 0 | 0 | 0 | 0 | 0:'
					case d | q:				// 'd | q | 0 | 0 | 0 | 0:'
						{
							ret = switch_on_disabled;
							break;
						}
					case q | r:				// '0 | q | 0 | 0 | 0 | r:'
						{
							ret = ready_to_switch_on;
							break;
						}
					case q | s | r:			// '0 | q | 0 | 0 | s | r:'
						{
							ret = switched_on;
							break;
						}
					case q | o | s | r:		// '0 | q | 0 | o | s | r:'
						{
							ret = operation_enabled;
							break;
						}
					case s | r:				// '0 | 0 | 0 | o | s | r:'
						{
							ret = quick_stop_active;
							break;
						}
					case f | s | r:			// '0 | 0 | f | o | s | r:'
					case q | f | o | s | r:	// '0 | q | f | o | s | r:'
						{
							ret = fault_reaction_active;
							break;
						}
					case f:					// '0 | 0 | f | 0 | 0 | 0:'
					case q | f:				// '0 | q | f | 0 | 0 | 0:'
						{
							ret = fault;
							break;
						}
					default:
						{
							// the return value keeps 'unknown'
							break;
						}
				}

				return ret;
			}
		};

		using elmo_obj = ds402;
	}
}
 
#endif // __SSI_ELMO_OBJ_H__
