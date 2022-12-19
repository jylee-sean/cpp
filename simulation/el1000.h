/**
 * @brief		EL1000 the next geration surgical robot class that contains all its substructures
 * @details		the target system is forked from el301
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	ENDOQEUST ROBOTICS, Inc. All rights reserved.
 */

#ifndef __TARGET_EL1000_H__
#define __TARGET_EL1000_H__

#include <fstream>
#include <iostream>

#include <ssi/runtime.h>
#include <ssi/target/base.h>
#include <ssi/target/el1000_ecs.h>
#include <ssi/sim/io.h>
#include <ssi/sim/led.h>
#include <ssi/sim/brake.h>
#include <ssi/sim/elmopp.h>
#include <ssi/node/io.h>
#include <ssi/node/led.h>
#include <ssi/node/esc.h>
#include <ssi/node/siis.h>
#include <ssi/node/actr.h>
#include <ssi/node/relay.h>
#include <ssi/node/brake.h>
#include <ssi/node/friday.h>
#include <ssi/node/elmopp.h>
#include <ssi/node/elmo_cfg.h>
#include <ssi/common/protocol.h>

#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace ssi
{
	namespace target
	{
		class el1000 final : public ssi::target::base
		{
		public:
			el1000() = delete;
			explicit el1000(comst& m, env& e);

			virtual ~el1000();

			const char* init();
			const char* fini();

			static constexpr std::size_t num_slaves = 48;
			static constexpr std::size_t num_slaves_standalone = 8;

			struct {
				const node::elmo_cfg NA { node::elmo_cfg::type_t::none,
					{ node::elmo_sensor::unknown, { 1, 1 }, { 1, 1 } },
					{ node::elmo_sensor::unknown, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg IB { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::enx_16_easy_1024, { 57, 13 }, { 1, 2 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg IR { node::elmo_cfg::type_t::rotation,
					{ node::elmo_sensor::mile_1024_cpt, { 13, 3 }, { 72, 24 } },
					{ node::elmo_sensor::ac36_dynapar_absolute_magnetic_encoder, { 1, 1 }, { 120 * 24 * 24, 65 * 65 * 65 } } };
				const node::elmo_cfg IT { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::mile_1024_cpt, { 1, 1 }, { 1, 4 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg PT { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::mile_512_4096_cpt, { 10, 1 }, { 1, 5 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg PR { node::elmo_cfg::type_t::rotation,
					{ node::elmo_sensor::mile_2048_cpt, { 343, 8 }, { 5, 1 } },
					{ node::elmo_sensor::aksim_off_axis_rotary_absolute_encoder, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg CY { node::elmo_cfg::type_t::rotation,
					{ node::elmo_sensor::enx_16_easy_1024, { 111, 1 }, { 10, 1 } },
					{ node::elmo_sensor::re22_rotary_magnetic_shaft_encoder, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg CP { node::elmo_cfg::type_t::rotation,
					{ node::elmo_sensor::enx_16_easy_1024, { 111, 1 }, { 10, 1 } },
					{ node::elmo_sensor::re22_rotary_magnetic_shaft_encoder, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg FC { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::enx_16_easy_1024, { 66, 10 }, { 1000000, 15 * 3141592 } },
					{ node::elmo_sensor::unknown, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg AY { node::elmo_cfg::type_t::rotation,
					{ node::elmo_sensor::enx_16_easy_1024, { 4554, 130 }, { 1, 1 } },
					{ node::elmo_sensor::re22_rotary_magnetic_shaft_encoder, { 1, 1 }, { 1, 1 } } };
				const node::elmo_cfg AP { node::elmo_cfg::type_t::rotation,
					{ node::elmo_sensor::enx_16_easy_1024, { 4554, 130 }, { 1, 1 } },
					{ node::elmo_sensor::re22_rotary_magnetic_shaft_encoder, { 1, 1 }, { 1, 1 } } };
				// display elevation
				const node::elmo_cfg DE { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::enx_16_easy_1024, { 357075 * 1, 3211 * 3}, { 1, 5 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
				// handctrl translation
				const node::elmo_cfg HT { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::enx_16_easy_1024, { 357075 * 1, 3211 * 1}, { 1, 10 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
				// handctrl elevation
				const node::elmo_cfg HE { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::mile_512_4096_cpt, { 20, 1 }, { 1, 10 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
				// armrest elevation
				const node::elmo_cfg AE { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::mile_512_4096_cpt, { 20, 1 }, { 1, 10 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
				// footrest translation
				const node::elmo_cfg FT { node::elmo_cfg::type_t::translation,
					{ node::elmo_sensor::enx_16_easy_1024, { 357075 * 1, 3211 * 1}, { 1, 10 } },
					{ node::elmo_sensor::la11_absolute_magnetic_encoder, { 1, 1 }, { 1, 1 } } };
			} elmocfg;

			node::in<bool> left_clutch;			// left finger clutch input from haptic device
			node::in<bool> right_clutch;		// right finger clutch input from haptic device
			node::in<bool> cscope_pedal;		// colubriscope pedal
			node::in<bool> homing_pedal;
			node::in<bool> vscope_pedal;		// videoscope pedal
			node::in<bool> clutch_pedal;
			node::in<bool> cut_pedal;
			node::in<bool> coag_pedal;
			node::in<bool> suction_pedal;
			node::in<bool> insufflation_pedal;
			node::in<bool> rcy_button;			// recovery button on the surgeon console
			node::in<bool> pwr_button;			// power button on the surgeon console
			node::in<bool> emo_button;			// software emergency button on the surgeon console
			node::in<bool> epo_button;			// hardware emergency button on the patient cart
			node::in<bool> ptpos_touch;			// touch screen input of PT positive direction from the patient cart
			node::in<bool> ptneg_touch;			// touch screen input of PT negative direction from the patient cart
			node::in<bool> prpos_touch;			// touch screen input of PR positive direction from the patient cart
			node::in<bool> prneg_touch;			// touch screen input of PR negative direction from the patient cart
			node::in<bool> left_pbutton;		// left positioning arm button
			node::in<bool> right_pbutton;		// right positioning arm button
			node::in<bool> left_ibutton;		// left instrument arm button
			node::in<bool> right_ibutton;		// right instrument arm button
			node::in<uint16_t> left_gripper;	// left gripper value from haptic device
			node::in<uint16_t> right_gripper;	// right gripper value from haptic device

			node::in<uint16_t> surgeon_inputs;	// surgeon console's input matrix
			node::in<uint8_t> patient_inputs;	// patient cart's input matrix

			node::led pwr_led;					// 1-bit led on the surgeon console's power button
			node::led emo_led;					// 1-bit led on the surgeon console's software emergency button
			node::led left_pled;				// 3-bits led on the positioning arm
			node::led right_pled;				// 3-bits led on the positioning arm
			node::led left_iled;				// 3-bits led on the left instrument arm
			node::led right_iled;				// 3-bits led on the right instrument arm

			static constexpr size_t num_paxes = 5;
			static constexpr size_t num_bullets = 10;
			static constexpr size_t num_vbullets = 4;

			node::actr pelev;						// positioning arm's elevation: J1
			node::actr ppitch;						// positioning arm's pitch: J3
			node::elmopp ptransl;					// positioning arm's translation: J4
			node::elmopp proll;						// positioning arm's roll: J5
			node::elmopp cpitch;					// colubriscope's pitch
			node::elmopp cyaw;						// colubriscope's yaw
			node::elmopp fctrl[2];					// colubriscope's suction & insufflation flow control
			node::elmopp ayaw;                      // trans-anal modulized videoscope's yaw
            node::elmopp apitch;                    // trans-anal modulized videoscope's pitch
			node::elmopp lbullets[num_bullets];		// left instrument arm's bullets
			node::elmopp lroll;						// left instrument arm's roll
			node::elmopp ltransl;					// left instrument arm's translation
			node::elmopp rbullets[num_bullets];		// right instrument arm's bullets
			node::elmopp rroll;						// right instrument arm's roll
			node::elmopp rtransl;					// right instrument arm's translation

			node::brake ptransl_brake;
			node::brake proll_brake;
			node::brake ltransl_brake;
			node::brake rtransl_brake;

			node::esc esc;
			node::siis siis;

			// software signals for compatibility with el301
			sim::in<bool> vascope_detect { 0, 1 };  // trans-anal modulized videoscope detection(always true)
			sim::in<bool> voscope_detect { 0, 0 };  // trans-oral modulized videoscope detection(always false)

			// software signals for testing cscope 
			sim::in<bool> cscope_drape { 0, 1 };	// videoscope drape adapter signal(always true)
			sim::in<bool> cscope_detect { 0, 1 };	// videoscope detection signal(always true)
			sim::in<bool> cyaw_engage { 0, 1 };		// engagement signal of colubriscope yaw clutch(always true)
			sim::in<bool> cpitch_engage { 0, 1 };	// engagement signal of colubriscope pitch clutch(always true)

			sim::led vscope_led { 0x100 };					// 3-bits led on the vscope arm
			sim::brake vstransl_brake { 0x101, true };		// vscope translation brake
			sim::in<bool> vscope_button { 0x102, 0, 0 };	// vscope arm button
			sim::elmopp pyaw { 0x105, elmocfg.NA };			// positioning arm's yaw: J2
			sim::elmopp vsbullets[num_vbullets] { { 0x110, elmocfg.IB }, { 0x111, elmocfg.IB }, { 0x112, elmocfg.IB }, { 0x113, elmocfg.IB } }; // vscope arm's bullets
			sim::elmopp vsroll { 0x114, elmocfg.IR };		// vscope arm's roll
			sim::elmopp vstransl { 0x115, elmocfg.IT };		// vscope arm's translation
			std::vector<ssi::sim::elmopp*> vscope;			// video scope
			std::vector<ssi::sim::elmopp*> vscopeb;			// video scope bullets

			// for elmo aggregated API
			std::vector<ssi::node::elmopp*> all;			// all elmos with profiled position mode
			std::vector<ssi::node::elmopp*> parm;			// positioning arm
			std::vector<ssi::node::elmopp*> iarm;			// instrument arms
			std::vector<ssi::node::elmopp*> larm;			// left instrument arm
			std::vector<ssi::node::elmopp*> rarm;			// right instrument arm
			std::vector<ssi::node::elmopp*> iarmb;			// instrument arms' bullets
			std::vector<ssi::node::elmopp*> larmb;			// left instrument arm's bullets
			std::vector<ssi::node::elmopp*> rarmb;			// right instrument arm's bullets
			std::vector<ssi::node::elmopp*> cscope;			// colubriscope
			std::vector<ssi::node::elmopp*> insufflator;	// flow controller

			ssi::node::elmo* elmo(uint16_t slvid) { return (slvid == 0 || slvid > num_slaves) ? nullptr : elmotbl[slvid-1]; }

			struct atx_relay_t : public node::relay {
				atx_relay_t(node::in<bool>& st, node::out<bool>& pwr) : _st(st), _pwr(pwr) { }
				virtual bool on() override {
					if(!_st) _toggle();
					return true;
				}
				virtual bool off() override {
					if(_st) _toggle();
					return true;
				}
				virtual bool status() override {
					return _st;
				}
				void forced(bool val) { _pwr = val; }
			private:
				void _toggle() {
					_pwr = false;
					::sleep(2);
					_pwr = true;
					::sleep(2);
					_pwr = false;
				}
				node::in<bool>& _st;
				node::out<bool>& _pwr;
			} atx_relay;

			struct esu_relay_t {
			public:
				esu_relay_t(node::esc& e) : _esc(e) { }
				bool cut() {
					return _esc.output().cutOutput.read();
				}
				bool cut(bool val) {
					return _esc.output().cutOutput.write(val ? node::esc_obj::CutOutput::enable : node::esc_obj::CutOutput::disable);
				}
				bool coag() {
					return _esc.output().coagOutput.read();
				}
				bool coag(bool val) {
					return _esc.output().coagOutput.write(val ? node::esc_obj::CoagOutput::enable : node::esc_obj::CoagOutput::disable);
				}
				uint16_t status() {
					return _esc.input().statusWord.read();
				}
			private:
				node::esc& _esc;
			} esu_relay;

			struct safety_relay_t : public node::relay {
			safety_relay_t(node::out<bool>& pwr, node::out<bool>& rcy, node::out<bool>& saf1, node::out<bool>& saf2) :
				_pwr(pwr), _rcy(rcy), _saf1(saf1), _saf2(saf2) { }
				virtual bool on() override {
					_pwr = true, _saf1 = true, _saf2 = true;
					::sleep(1);
					_rcy = true;
					::sleep(1);
					// _logi << "safety_relay is on";
					return true;
				}
				virtual bool off() override {
					_pwr = false, _rcy = false, _saf1 = false, _saf2 = false;
					// _logi << "safety_relay is off";
					return true;
				}
				virtual bool status() override {
					return _pwr.read() && _rcy.read() && _saf1.read() && _saf2.read();
				}
			private:
				node::out<bool>& _pwr;
				node::out<bool>& _rcy;
				node::out<bool>& _saf1;
				node::out<bool>& _saf2;
			} safety_relay;

			class monitor : public ccl::event::observer<ssi::ecatmst, ssi::ecatmst::sync_done>
			{
			public:
				monitor() = delete;
				monitor(ssi::target::el1000& t) : _tgt(t) { }
				virtual ~monitor() { }

				virtual void update(ssi::ecatmst& m, const ssi::ecatmst::sync_done& e) override {
					static std::once_flag _once;
					std::call_once( _once, [&]() { _ts = m.time() - 1000 * 1000; } );

					switch(__builtin_ctz(m.clk())) {
					case 7:
						if(m.slave_count(ssi::ecatmst::from_eni) != m.slave_count(ssi::ecatmst::from_nic))
							_loge << "ecat network's topology has been changed(slave_count = #" << m.slave_count(ssi::ecatmst::from_nic) << ")";
					case 4:
					case 3:
					case 2:
					case 1:
					default: // every cycles
						uint64_t diff = m.time() - _ts;
						_ts = m.time();
						// if(diff < (m.tick().count() * 500) || diff > (m.tick().count() * 1500))
						if(diff > (m.tick().count() * 2500))
							_logw << "broken ecatmst cycle(" << diff / 1000 << "us) detected";
						break;
					}
				}

			private:
				uint64_t _ts;
				ssi::target::el1000& _tgt;
			};
			
		private:
			env& _env;
			comst& _mst;

			monitor _mon;

			// hidden input cannot be referred directly
			node::in<bool> atx_status;

			// hidden output which have its own control sequence
			node::out<bool> atx_power;
			node::out<bool> safety_power;
			node::o1018
			ut<bool> safety_recovery;
			node::out<bool> safety1;
			node::out<bool> safety2;

			const std::array<node::elmo*, num_slaves> elmotbl { {
				nullptr, nullptr, nullptr, nullptr, nullptr, 
				nullptr, nullptr, nullptr, nullptr, nullptr, 
				nullptr, nullptr, nullptr, nullptr, nullptr,
				&ptransl, &proll, &cpitch, &cyaw, &fctrl[0], &fctrl[1], &ayaw, &apitch,
				&lbullets[0], &lbullets[1], &lbullets[2], &lbullets[3], &lbullets[4], &lbullets[5], &lbullets[6], &lbullets[7], &lbullets[8], &lbullets[9], &lroll, &ltransl,
				&rbullets[0], &rbullets[1], &rbullets[2], &rbullets[3], &rbullets[4], &rbullets[5], &rbullets[6], &rbullets[7], &rbullets[8], &rbullets[9], &rroll, &rtransl,
				nullptr }
			};
		};

		el1000::el1000(comst& m, env& e) :
			_mst(m),
			_env(e),
			_mon(*this),
			left_clutch(m, Slave_2__EL1808__Channel_1_Input_Addr + 0),
			right_clutch(m, Slave_2__EL1808__Channel_1_Input_Addr + 1),
			cscope_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 4),
			homing_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 5),
			vscope_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 6),
			clutch_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 7),
			cut_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 8),
			coag_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 9),
			suction_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 10),
			insufflation_pedal(m, Slave_2__EL1808__Channel_1_Input_Addr + 11),
			rcy_button(m, Slave_2__EL1808__Channel_1_Input_Addr + 12),
			atx_status(m, Slave_2__EL1808__Channel_1_Input_Addr + 13),
			pwr_button(m, Slave_2__EL1808__Channel_1_Input_Addr + 14),
			emo_button(m, Slave_2__EL1808__Channel_1_Input_Addr + 15, true),
			epo_button(m, Slave_11__EL1808__Channel_1_Input_Addr + 0, true),
			ptpos_touch(m, Slave_11__EL1808__Channel_1_Input_Addr + 1, true),
			ptneg_touch(m, Slave_11__EL1808__Channel_1_Input_Addr + 2, true),
			prpos_touch(m, Slave_11__EL1808__Channel_1_Input_Addr + 3, true),
			prneg_touch(m, Slave_11__EL1808__Channel_1_Input_Addr + 4, true),
			left_pbutton(m, Slave_34__Elmo_Drive___Inputs_Digital_Inputs_Addr + 16),
			right_pbutton(m, Slave_46__Elmo_Drive___Inputs_Digital_Inputs_Addr + 16),
            ayaw { m, 22, Slave_22__Elmo_Drive___Inputs_Status_word_Addr, Slave_22__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.AY },
            apitch { m, 23, Slave_23__Elmo_Drive___Inputs_Status_word_Addr, Slave_23__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.AP },
			left_ibutton(m, Slave_35__Elmo_Drive___Inputs_Digital_Inputs_Addr + 16),
			right_ibutton(m, Slave_47__Elmo_Drive___Inputs_Digital_Inputs_Addr + 16),
			left_gripper(m, Slave_6__EL3162__Channel_1_Value_Addr),
			right_gripper(m, Slave_6__EL3162__Channel_2_Value_Addr),
			surgeon_inputs(m, Slave_2__EL1808__Channel_1_Input_Addr, static_cast<uint16_t>(0x8000)),
			patient_inputs(m, Slave_11__EL1808__Channel_1_Input_Addr, static_cast<uint8_t>(0x1f)),
			atx_power(m, Slave_5__EL2624__Channel_1_Output_Addr),
			safety_power(m, Slave_14__EL2624__Channel_1_Output_Addr),
			safety_recovery(m, Slave_14__EL2624__Channel_2_Output_Addr),
			safety1(m, Slave_14__EL2624__Channel_3_Output_Addr),
			safety2(m, Slave_14__EL2624__Channel_4_Output_Addr),
			pwr_led(m, Slave_4__EL2828__Channel_1_Output_Addr, 1),
			emo_led(m, Slave_4__EL2828__Channel_2_Output_Addr, 1),
			left_pled(m, Slave_34__Elmo_Drive___Outputs_Digital_Output_Addr + 17, 3),
			right_pled(m, Slave_46__Elmo_Drive___Outputs_Digital_Output_Addr + 17, 3),
			left_iled(m, Slave_35__Elmo_Drive___Outputs_Digital_Output_Addr + 17, 3),
			right_iled(m, Slave_47__Elmo_Drive___Outputs_Digital_Output_Addr + 17, 3),
			pelev { m, 100, 0x0, 0x0 },
			ppitch { m, 101, 0x0, 0x0 },
			ptransl { m, 16, Slave_16__Elmo_Drive___Inputs_Status_word_Addr, Slave_16__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.PT },
			proll { m, 17, Slave_17__Elmo_Drive___Inputs_Status_word_Addr, Slave_17__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.PR },
			cpitch { m, 18, Slave_18__Elmo_Drive___Inputs_Status_word_Addr, Slave_18__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.CP },
			cyaw { m, 19, Slave_19__Elmo_Drive___Inputs_Status_word_Addr, Slave_19__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.CY },
			fctrl {
				{ m, 20, Slave_20__Elmo_Drive___Inputs_Status_word_Addr, Slave_20__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.FC },
				{ m, 21, Slave_21__Elmo_Drive___Inputs_Status_word_Addr, Slave_21__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.FC } },
			lbullets {
					{ m, 24, Slave_24__Elmo_Drive___Inputs_Status_word_Addr, Slave_24__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 25, Slave_25__Elmo_Drive___Inputs_Status_word_Addr, Slave_25__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 26, Slave_26__Elmo_Drive___Inputs_Status_word_Addr, Slave_26__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 27, Slave_27__Elmo_Drive___Inputs_Status_word_Addr, Slave_27__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 28, Slave_28__Elmo_Drive___Inputs_Status_word_Addr, Slave_28__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 29, Slave_29__Elmo_Drive___Inputs_Status_word_Addr, Slave_29__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 30, Slave_30__Elmo_Drive___Inputs_Status_word_Addr, Slave_30__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 31, Slave_31__Elmo_Drive___Inputs_Status_word_Addr, Slave_31__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 32, Slave_32__Elmo_Drive___Inputs_Status_word_Addr, Slave_32__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 33, Slave_33__Elmo_Drive___Inputs_Status_word_Addr, Slave_33__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB } },
			lroll { m, 34, Slave_34__Elmo_Drive___Inputs_Status_word_Addr, Slave_34__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IR },
			ltransl { m, 35, Slave_35__Elmo_Drive___Inputs_Status_word_Addr, Slave_35__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IT },
			rbullets {
					{ m, 36, Slave_36__Elmo_Drive___Inputs_Status_word_Addr, Slave_36__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 37, Slave_37__Elmo_Drive___Inputs_Status_word_Addr, Slave_37__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 38, Slave_38__Elmo_Drive___Inputs_Status_word_Addr, Slave_38__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 39, Slave_39__Elmo_Drive___Inputs_Status_word_Addr, Slave_39__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 40, Slave_40__Elmo_Drive___Inputs_Status_word_Addr, Slave_40__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 41, Slave_41__Elmo_Drive___Inputs_Status_word_Addr, Slave_41__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 42, Slave_42__Elmo_Drive___Inputs_Status_word_Addr, Slave_42__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 43, Slave_43__Elmo_Drive___Inputs_Status_word_Addr, Slave_43__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 44, Slave_44__Elmo_Drive___Inputs_Status_word_Addr, Slave_44__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB },
					{ m, 45, Slave_45__Elmo_Drive___Inputs_Status_word_Addr, Slave_45__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IB } },
			rroll { m, 46, Slave_46__Elmo_Drive___Inputs_Status_word_Addr, Slave_46__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IR },
			rtransl { m, 47, Slave_47__Elmo_Drive___Inputs_Status_word_Addr, Slave_47__Elmo_Drive___Outputs_Control_word_Addr, elmocfg.IT },
			esc(m, 15, Slave_15__CMX_ESC__Input_process_data_mapping_Status_word_Addr, Slave_15__CMX_ESC__Output_process_data_mapping_Control_word_Addr),
			siis(m, 48, Slave_48__CMX_SIIS_EtherCAT_slave__SPI___Status_Word_i_Status_Word_Addr, Slave_48__CMX_SIIS_EtherCAT_slave__SPI___Control_Word_o_Control_Word_Addr),
			ptransl_brake(m, Slave_16__Elmo_Drive___Outputs_Digital_Output_Addr + 16, false, ptransl.input().velocityActualValue),
			proll_brake(m, Slave_17__Elmo_Drive___Outputs_Digital_Output_Addr + 16, true, proll.input().velocityActualValue),
			ltransl_brake(m, Slave_35__Elmo_Drive___Outputs_Digital_Output_Addr + 16, false, ltransl.input().velocityActualValue),
			rtransl_brake(m, Slave_47__Elmo_Drive___Outputs_Digital_Output_Addr + 16, false, rtransl.input().velocityActualValue),
			atx_relay(atx_status, atx_power), 
			esu_relay(esc),
			safety_relay(safety_power, safety_recovery, safety1, safety2) {
			parm.push_back(&ptransl);
			parm.push_back(&proll);
			cscope.push_back(&cpitch);
			cscope.push_back(&cyaw);
			insufflator.push_back(&fctrl[0]);
			insufflator.push_back(&fctrl[1]);

			for(int i = 0; i < num_vbullets; i++) {
				vscope.push_back(&vsbullets[i]);
				vscopeb.push_back(&vsbullets[i]);
			}
            vscope.push_back(&vsroll);
            vscope.push_back(&vstransl);
			for(int i = 0; i < num_bullets; i++) {
				larmb.push_back(&lbullets[i]);
				rarmb.push_back(&rbullets[i]);
			}
			for(auto& it : larmb) {
				larm.push_back(it);
				iarmb.push_back(it);
			}
			for(auto& it : rarmb) {
				rarm.push_back(it);
				iarmb.push_back(it);
			}
			larm.push_back(&lroll);
			larm.push_back(&ltransl);
			rarm.push_back(&rroll);
			rarm.push_back(&rtransl);
			for(auto& it : larm) iarm.push_back(it);
			for(auto& it : rarm) iarm.push_back(it);
			for(auto& it : parm) all.push_back(it);
			for(auto& it : iarm) all.push_back(it);
			for(auto& it : cscope) all.push_back(it);
			//TODO:
			// for(auto& it : vscope) all.push_back(it);
			for(auto& it : insufflator) all.push_back(it);

			// _logi << "target::el1000 has been created";
		}

		el1000::~el1000() {
			all.clear();
			parm.clear();
			iarm.clear();
			larm.clear();
			rarm.clear();
			cscope.clear();
			vscope.clear();
			insufflator.clear();
			// _logi << "target::el1000 has been destroyed";
		}

		const char* el1000::init() try {
			if(dynamic_cast<ssi::ecatmst*>(&_mst))
				dynamic_cast<ssi::ecatmst*>(&_mst)->attach(_mon);
			_mst.attach(siis);

			proll_brake.on();
            vstransl_brake.on();
			ltransl_brake.on();
			rtransl_brake.on();
			const boost::property_tree::ptree& pt = _env.tree();
			for(auto &i : pt.get_child("eq.ssi.target.el1000.elmo_profile")) {
				if(i.first.compare("element") == 0) {
					const char* ret = nullptr;
					std::string mode = i.second.get<std::string>("<xmlattr>.mode");
					bool feed = boost::lexical_cast<bool>(i.second.get<std::string>("<xmlattr>.feed"));
					uint16_t slave_id = boost::lexical_cast<uint16_t>(i.second.get<std::string>("<xmlattr>.slave_id"));
					double acc = boost::lexical_cast<double>(i.second.get<std::string>("<xmlattr>.profile_acceleration"));
					double dec = boost::lexical_cast<double>(i.second.get<std::string>("<xmlattr>.profile_deceleration"));
					double vel = boost::lexical_cast<double>(i.second.get<std::string>("<xmlattr>.profile_velocity"));
					double min = std::numeric_limits<double>::quiet_NaN();
					double max = std::numeric_limits<double>::quiet_NaN();

					if(mode.compare("pp") == 0 && dynamic_cast<node::elmopp*>(elmo(slave_id))) {
						min = boost::lexical_cast<double>(i.second.get<std::string>("<xmlattr>.software_position_limit_min"));
						max = boost::lexical_cast<double>(i.second.get<std::string>("<xmlattr>.software_position_limit_max"));
						ret = dynamic_cast<node::elmopp*>(elmo(slave_id))->init(
								node::elmopp::profile(
									node::elmo_cfg::encode(elmo(slave_id)->cfg().inc_encoder, acc),
									node::elmo_cfg::encode(elmo(slave_id)->cfg().inc_encoder, dec),
									node::elmo_cfg::encode(elmo(slave_id)->cfg().inc_encoder, vel)),
								node::elmopp::position_limits(
									node::elmo_cfg::encode(elmo(slave_id)->cfg().inc_encoder, min),
									node::elmo_cfg::encode(elmo(slave_id)->cfg().inc_encoder, max)), feed);
					} else
						throw ssi::runtime_error("invalid env");

					if(ret != nullptr) {
						_loge << "error on #" << slave_id << ": " << ret;
						return ret;
					} else {
						_logv << "elmo #" << slave_id << " loads the profile(" << mode
								<< "/" << static_cast<const char*>(elmo(slave_id)->cfg().type == ssi::node::elmo_cfg::rotation ? "rot" : "transl")
								<< "): { " << acc << ", " << dec << ", " << vel << " }, { " << min << ", " << max << " }";
					}
				}
			}

			/// adjust scopes' and bullets' maximum hot plug in speed in order to enable the elmos that is affected by external force
			/// @see        "Command Reference for Gold Line Drives Ver 1.512" p.246 Extra Parameters
			/// @warning    the parameter "Maximum hot plug in speed" is non-volatile, so these must be moved to bootstrap sequence later
			_mst.writesdo<int32_t>(cpitch.id(), node::elmo_obj::index("XA"), 2u, 500);
			_mst.writesdo<int32_t>(cyaw.id(), node::elmo_obj::index("XA"), 2u, 500);
			_mst.writesdo<int32_t>(apitch.id(), node::elmo_obj::index("XA"), 2u, 500);
			_mst.writesdo<int32_t>(ayaw.id(), node::elmo_obj::index("XA"), 2u, 500);
            // TODO(vscope): add missing vscope nodes
			for(auto it : lbullets) _mst.writesdo<int32_t>(it.id(), node::elmo_obj::index("XA"), 2u, 500);
			for(auto it : rbullets) _mst.writesdo<int32_t>(it.id(), node::elmo_obj::index("XA"), 2u, 500);
			_mst.writesdo<int32_t>(ltransl.id(),node::elmo_obj::index("XA"), 2u, 500);
			_mst.writesdo<int32_t>(rtransl.id(),node::elmo_obj::index("XA"), 2u, 500);
			_mst.writesdo<int32_t>(lroll.id(),node::elmo_obj::index("XA"), 2u, 500);
			_mst.writesdo<int32_t>(rroll.id(),node::elmo_obj::index("XA"), 2u, 500);
			_logv << "elmos' maximum hot plug in speed is adjusted";
			_logd << "el1000 is initialized";
			return nullptr;
		} catch(...) {
			throw;
		}

		const char* el1000::fini() {
			pwr_led.set(node::led::color_t::off);
			emo_led.set(node::led::color_t::off);
			left_pled.set(node::led::color_t::off);
			right_pled.set(node::led::color_t::off);
			left_iled.set(node::led::color_t::off);
			right_iled.set(node::led::color_t::off);

			if(dynamic_cast<ssi::ecatmst*>(&_mst))
				dynamic_cast<ssi::ecatmst*>(&_mst)->detach(&_mon);
			_mst.detach(siis);
			// _logi << "target el1000 is finalized";
			return nullptr;
		}
	}
}

#endif // __TARGET_EL1000_H_
