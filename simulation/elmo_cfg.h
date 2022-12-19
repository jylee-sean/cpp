/**
 * @brief		elmo servo drive's configuration specs
 * @warning		most of the API can be replaced to a single multiplication
 *				so it's highly recommended not to use this API for your control loop
 * @details
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved
 */

#ifndef __SSI_ELMO_CFG_H__
#define __SSI_ELMO_CFG_H__

#include <cstdint>
#include <cstddef>

#include <ratio>

namespace ssi
{
	namespace node
	{
		struct elmo_cfg
		{
			enum type_t
			{
				none = 0,
				rotation = 1,
				translation = 2
			};

			struct sensor_t {
				constexpr sensor_t(const int64_t r) : resolution(r) { }
				const int64_t resolution;
			};

			struct reduction_t {
				constexpr reduction_t(const uint64_t n, const uint64_t d) : num(n), den(d) { }
				const int64_t num;
				const int64_t den;
			};

			struct encoder_t {
				constexpr encoder_t(const sensor_t s, const reduction_t ri, const reduction_t re) :
					sensor(s), internal(ri), external(re) { }
				const sensor_t sensor;
				const reduction_t internal;
				const reduction_t external;
			};

			const type_t type;
			const encoder_t inc_encoder;
			const encoder_t abs_encoder;

			/**
			 * convert the position value from the encoder to another encoder's position value
			 * @param		from encoder configuration to convert the position
			 * @param		to target encoder configuration 
			 * @param		pos position value in the 'from' encoder
			 * @return		always position value converted
			 */
			static inline constexpr int32_t convert(const encoder_t& from, const encoder_t& to, const int32_t pos) {
				return pos
					* (to.sensor.resolution * to.internal.num * to.external.num * from.internal.den * from.external.den)
					/ (from.sensor.resolution * from.internal.num * from.external.num * to.internal.den * to.external.den);
			}

			/**
			 * convert the position value in the given encoder to the value in metric or angle measurement units
			 * in case of translation motion, the granularity is 1 milli-meters
			 * in case of rotation motion, the granularity is 1 revolution(360 degree)
			 * @param		from encoder configuration to convert the position
			 * @param		pos position value in the encoder
			 * @return		always measurement value converted
			 */
			static inline constexpr double decode(const encoder_t& from, const int32_t pos) {
				return static_cast<double>(pos) /
					(static_cast<double>(from.sensor.resolution)
					 * (static_cast<double>(from.internal.num) * static_cast<double>(from.external.num))
					 / (static_cast<double>(from.internal.den) * static_cast<double>(from.external.den)) );
			}

			/**
			 * convert the actual length or angle in granularity unit to the position value in the elmo's encoder
			 * in case of translation motion, the granularity is 1 milli-meters
			 * in case of rotation motion, the granularity is 1 revolution(360 degree)
			 * @param		to target encoder configuration 
			 * @param		val is length in millimeters or angle in turns to convert
			 * @return		always measurement value caculated
			 */
			static inline constexpr int32_t encode(const encoder_t& to, const double val) {
				return static_cast<int32_t>(
						(val) *
						(static_cast<double>(to.sensor.resolution)
						 * (static_cast<double>(to.internal.num) * static_cast<double>(to.external.num))
						 / (static_cast<double>(to.internal.den) * static_cast<double>(to.external.den))) );
			}
		};

		struct elmo_sensor {
			static constexpr elmo_cfg::sensor_t unknown { -1 };
			static constexpr elmo_cfg::sensor_t enx_16_easy_1024 { 4096 };
			static constexpr elmo_cfg::sensor_t mile_1024_cpt { 4096 };
			static constexpr elmo_cfg::sensor_t mile_2048_cpt { 8192 };
			static constexpr elmo_cfg::sensor_t mile_512_4096_cpt { 16384 };

			static constexpr elmo_cfg::sensor_t la11_absolute_magnetic_encoder { 4096 };
			static constexpr elmo_cfg::sensor_t re22_rotary_magnetic_shaft_encoder { 8192 };
			static constexpr elmo_cfg::sensor_t ac36_dynapar_absolute_magnetic_encoder { 524288 };
			static constexpr elmo_cfg::sensor_t aksim_off_axis_rotary_absolute_encoder { 524288 };
		};

		static constexpr elmo_cfg elmo_nocfg {
			elmo_cfg::type_t::none,
				{ elmo_sensor::unknown, { 0, 0 }, { 0, 0 } },
				{ elmo_sensor::unknown, { 0, 0 }, { 0, 0 } }
		};
	}
}

#endif // __SSI_ELMO_CFG_H__
