/**
 * @brief		core state machine implementation
 * @details		main controller class that handle business logic mainly
 *				and it contains sub-controllers including iarm, parm, cscope and vscope
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */

#ifndef __CORE_MAIN_H__
#define __CORE_MAIN_H__

#include <algorithm>

#include <ccl/state_machine.h>

#include <messaging/sender.h>
#include <messaging/receiver.h>
#include <messaging/message_base.h>

#include <phy/types.h>
#include <phy/mongolia.h>
#include <phy/jacobian.h>
#include <phy/vcontrol.h>

#include <ssi/runtime.h>

#include <timer.h>
#include <error.h>
#include <inputs.h>
#include <events.h>
#include <context.h>
#include <realtime.h>
#include <property.h>
#include <handctrl.h>
#include <messages.h>
#include <ecatevents.h>

#include <ctrl/iarm.h>
#include <ctrl/parm.h>
#include <ctrl/cscope.h>
#include <ctrl/vscope.h>



namespace core {
using namespace ssi;
using namespace ssi::node;
using namespace phy::units;
template<typename T>
class main : public ccl::state_machine<main<T>>
{
public:
	main(ssi::runtime& rt, T& t) :
		ccl::state_machine<main<T>>(),
		_rt(rt),
		_target(t),
		_context("/root/ssi/ram1/core_context"),
		_property("/etc/eq/cal.xml", "/etc/eq/profile/def.xml"),
		_larm(_context, _property, _incoming, t.left_iled, t.ltransl_brake, t.larm, phy::arm_t::left),
		_rarm(_context, _property, _incoming, t.right_iled, t.rtransl_brake, t.rarm, phy::arm_t::right),
		_parm(_context, _property, _incoming, t.pelev, t.pyaw, t.ppitch, t.ptransl, t.proll),
		_cscope(_context, _property, _incoming, t.cpitch, t.cyaw),
        _vscope(_context, _property, _incoming, t.vscope_led, t.vstransl_brake, t.vscope),
		_realtime(_incoming),
		_timer(_incoming), _inputs(t, _incoming), _events(t, _incoming), _ecatevents(_incoming, t), _handctrl(_incoming) {
	}

	~main() {
	}

	using state_t = void (main<T>::*)();

	using ccl::state_machine<main<T>>::prev;
	using ccl::state_machine<main<T>>::once;
	using ccl::state_machine<main<T>>::state;
	using ccl::state_machine<main<T>>::transit;

	/**
	 * internal messages
	 */
	struct shutdown_initiated { };
	struct heartbeat { };
	struct iarm_ready {};


	static constexpr double instrument_length_limit = -10.0; // (unit: mm)
	static constexpr size_t heartbeat_for_icalib = 10; //(unit: ms)
	static constexpr size_t operation_time = 100; //(unit: ms)
	static constexpr size_t fini_time = 10; //(unit: sec)
	virtual void run() override {
		run(&main<T>::init);
	}
	
	/**
	 * run the state machine
	 * @params		e is the entry state of the main controller class
	 */
	void run(state_t e) {
		_rt.ecatmst().attach(_inputs);
		_logd << "inputs is attached to the ecatmst";

		_rt.ecatmst().attach(_ecatevents);
		_logd << "ecatevents is attached to the ecatmst";

		_realtime.init();

		_rt.session().uuid(_uuid);
		static char buf[32 + 4 + 1];
		std::snprintf(buf, 36, "%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X",
					  _uuid[0], _uuid[1], _uuid[2], _uuid[3], _uuid[4], _uuid[5], _uuid[6], _uuid[7], 
					  _uuid[8], _uuid[9], _uuid[10], _uuid[11], _uuid[12], _uuid[13], _uuid[14], _uuid[15]);
		_uuidstr = std::string(buf);
		_logf << "core<" << _uuidstr << "> is running";

		_mode = e;
		transit(e);
		for( ;state() ; ) {
			try {
				(this->*state())();
			} catch(messaging::close_queue const& e) {
				_logi << "got an close_queue(" << e.code() << ")";
				transit(&main<T>::halt);
			}
		}
	}

	state_t mode() {
		return _mode;
	}

	state_t safe_mode() {
		return &main<T>::init;
	}

	state_t normal_mode() {
		return &main<T>::init;
	}

	state_t restore_mode() {
		return &main<T>::init;
	}

	/**
	 * get the message sender to deliver an event to main controller class
	 * @return		always sender instance
	 */
	messaging::sender get_sender() {
		return _incoming;
	}

	/**
	 * stop the state machine
	 */
	void done() {
		_logf << "core<" << _uuidstr << "> is shutting down";
		_cv.notify_all();
		_timer.reset();
		_events.reset();
		_rt.ecatmst().detach(_inputs);
		_logd << "inputs is detached from the ecatmst";
		_rt.ecatmst().detach(_ecatevents);
		_logd << "ecatevents is detached from the ecatmst";
		get_sender().send(messaging::close_queue());
	}

	class iarmevents: public ccl::event::observer<ssi::ecatmst, ssi::ecatmst::sync_done>
	{
		public:
			 explicit iarmevents(messaging::sender sender, T& t) : _sender(sender), _target(t) {
			 	_logd << "iarmevents is created";
			}
			void update(ssi::ecatmst& m, const ssi::ecatmst::event& e) override{
				do{			
					double left_inst_length = _target.ltransl.length().value();
					double right_inst_length = _target.rtransl.length().value();
					if((left_inst_length <= instrument_length_limit) && (right_inst_length <= instrument_length_limit)){
						_sender.send(iarm_ready());
						break;
					}
					if( instrument_length_limit < left_inst_length){ 
						_target.left_iled.set(led::color_t::white);
					}else{
						_target.left_iled.set(led::color_t::red);
					}
					if( instrument_length_limit < right_inst_length){ 
						_target.right_iled.set(led::color_t::white);
					}else{
						_target.right_iled.set(led::color_t::red);
					}
				}while(false);
			}
		private:
			messaging::sender _sender;
			T& _target;
	};


private:
	state_t _mode = &main<T>::init;
	messaging::receiver _incoming;

	std::future<bool> _future;

	ssi::runtime& _rt;

	T& _target;
	// do not change below order
	// sub-controller classes have dependencies on _context, _property and _realtime
	context _context;
	property _property;
	realtime _realtime;

	// ctrl::iarm _harm; // head arm 
	ctrl::iarm _larm; // left arm
	ctrl::iarm _rarm; // right arm
	ctrl::parm _parm;
	ctrl::cscope _cscope;
    ctrl::vscope _vscope;

	timer _timer;
	inputs<T> _inputs;
	events<T> _events;
	ecatevents<T> _ecatevents;

	ssi::session::uuid_t _uuid;
	std::string _uuidstr;
	
	handctrl _handctrl;

	// motion control convention for instrument arms
	phy::scheme::jacobian _jacobian;
	phy::scheme::mongolia _mongolia[2] { {"scheme::mongolia(left)"}, {"scheme::mongolia(right)"} }; // mongolia scheme has internal state so the instance cannot be shared with left arm and right arm
	phy::scheme::vcontrol _vcontrol;

	// condition variable for timeout and it can be canceled immediately by calling notify()
	std::condition_variable _cv;

	

	void init() {
        state_t next = &main<T>::init;
        once([&]() {
            _logd << "core state is transitted to init";
            _target.left_pled.blink(led::color_t::blue);
            _target.right_pled.blink(led::color_t::blue);
            _target.left_iled.blink(led::color_t::blue);
            _target.right_iled.blink(led::color_t::blue);

			// both hand ctrl initilize
			_handctrl.init();
			_target.init();
			

			//_target.ltransl.sdo().modesOfOperation.write(elmo_obj::ModesOfOperation::profile_position_mode);
			//_target.rtransl.sdo().modesOfOperation.write(elmo_obj::ModesOfOperation::profile_position_mode);


			_logd <<"modesOfOperationDisplay(expected: 1) :  "
			<<  _target.ltransl.sdo().modesOfOperationDisplay.read() <<", "
			<<  _target.rtransl.sdo().modesOfOperationDisplay.read();

        });

        _incoming.wait()
            .template handle<target::pwr_button_pressed>([&](target::pwr_button_pressed const& msg) {
                _timer.reset<shutdown_initiated>(std::chrono::seconds(3), true);
            })
            .template handle<target::pwr_button_released>([&](target::pwr_button_released const& msg) {
                _timer.reset();                
                _logd << "under 3 seconds";
            })
            .template handle<shutdown_initiated>([&](shutdown_initiated const& msg){
                next = &main<T>::prepare;
            })
			.template handle<target::emo_button_pressed>([&](target::emo_button_pressed const& msg){
                next = &main<T>::emergency;
            })
			.template handle<target::epo_button_pressed>([&](target::epo_button_pressed const& msg){
                next = &main<T>::emergency;
            });



        transit(next, [&] {
            _timer.reset();
            _logd << "transit";
        });	
	}

	void manual(){

		state_t next = &main<T>::manual;
		

		once([&]() { 
            _logd << "core state is transitted to manual";
            _target.left_iled.set(led::color_t::white);
            _target.right_iled.set(led::color_t::white);
            _target.left_pled.set(led::color_t::white);
            _target.right_pled.set(led::color_t::white);

			_target.ltransl_brake.off();
			_target.rtransl_brake.off();
			_timer.reset<heartbeat>(std::chrono::milliseconds(heartbeat_for_icalib), false);	
			//_rt.ecatmst().attach(iarmevents(_incoming, _target));

		});
		//if(next != &main<T>::ready)
		//	get_sender().send(heartbeat());		
		 _incoming.wait()
            .template handle<heartbeat>([&](heartbeat const& msg){
				do{
					double left_inst_length = _target.ltransl.length().value();
					double right_inst_length = _target.rtransl.length().value();
					if((left_inst_length <= instrument_length_limit) && (right_inst_length <= instrument_length_limit)){
						next = &main<T>::ready;
						break;
					}
					if( instrument_length_limit < left_inst_length){ 
						_target.left_iled.set(led::color_t::white);
					}else{
						_target.left_iled.set(led::color_t::red);
					}
					if( instrument_length_limit < right_inst_length){ 
						_target.right_iled.set(led::color_t::white);
					}else{
						_target.right_iled.set(led::color_t::red);
					}
				}while(false);
			})
            .template handle<target::emo_button_pressed>([&](target::emo_button_pressed const& msg) {
                next = &main<T>::fini;
            });
		    	

		
        transit(next, [&] {
			_timer.reset();
	        _target.left_iled.set(led::color_t::off);
            _target.right_iled.set(led::color_t::off);
            _target.left_pled.set(led::color_t::off);
            _target.right_pled.set(led::color_t::off);
            _logd << "transit";
			//_rt.ecatmst().detach(iarmevents(_incoming, _target));
        });	
	}

	void ready(){
		state_t next = &main<T>::ready;
		once([&]() {
			_logd << "core state is transitted to ready";
			_target.left_iled.set(led::color_t::green);
            _target.right_iled.set(led::color_t::green);
            _target.left_pled.set(led::color_t::green);
            _target.right_pled.set(led::color_t::green);
			//_timer.reset<heartbeat>(std::chrono::milliseconds(heartbeat_for_icalib), false);			
			//_rt.ecatmst().attach(iarmevents(_incoming, _target));	

			_target.ltransl.sdo().profileVelocity.write(_target.ltransl.convert(phy::units::millimeter(5)) );
			_target.ltransl.sdo().profileAcceleration.write(_target.ltransl.convert(phy::units::millimeter(50.0)));
			_target.ltransl.sdo().profileDeceleration.write(_target.ltransl.convert(phy::units::millimeter(50.0)));

			_target.rtransl.sdo().profileVelocity.write(_target.rtransl.convert(phy::units::millimeter(5)) );
			_target.rtransl.sdo().profileAcceleration.write(_target.rtransl.convert(phy::units::millimeter(50.0)));
			_target.rtransl.sdo().profileDeceleration.write(_target.rtransl.convert(phy::units::millimeter(50.0)));
			
			// cosdo::read => comst::readsdo<T> val ?? => ecatmst::readsdo return coe_wait(length)??

			_logd <<"ltransl profile(expected: 5 , 50.0, 50.0) :  "
			<<  ssi::node::elmo_cfg::decode(_target.ltransl.cfg().inc_encoder,_target.ltransl.sdo().profileVelocity.read()) <<", "
			<<  ssi::node::elmo_cfg::decode(_target.ltransl.cfg().inc_encoder,_target.ltransl.sdo().profileAcceleration.read()) << ", "
			<<  ssi::node::elmo_cfg::decode(_target.ltransl.cfg().inc_encoder,_target.ltransl.sdo().profileDeceleration.read());

			_logd <<"rtransl profile(expected: 5 , 50.0, 50.0) :  "
			<< ssi::node::elmo_cfg::decode(_target.rtransl.cfg().inc_encoder,_target.rtransl.sdo().profileVelocity.read()) <<", "
			<<  ssi::node::elmo_cfg::decode(_target.rtransl.cfg().inc_encoder,_target.rtransl.sdo().profileAcceleration.read()) << ", "
			<<  ssi::node::elmo_cfg::decode(_target.rtransl.cfg().inc_encoder,_target.rtransl.sdo().profileDeceleration.read());


			// hand ctrl regulation & move to Cartesian coordinate {0,0,0}
			phy::cartesian_t nullPos = { 0.0, 0.0, 0.0 };
			_handctrl.regulate(true, true, true);
			_handctrl.moveto(&nullPos, &nullPos, false);
		});

		_incoming.wait()
			.template handle<target::pwr_button_pressed>([&](target::pwr_button_pressed const& msg) {
                _timer.reset<shutdown_initiated>(std::chrono::seconds(3), true);
            })
            .template handle<target::pwr_button_released>([&](target::pwr_button_released const& msg) {
                _timer.reset();                
                _logd << "under 3 seconds";
            })
			.template handle<shutdown_initiated>([&](shutdown_initiated const& msg){
				next = &main<T>::shutdown;
			})
            .template handle<target::cscope_pedal_pressed>([&](target::cscope_pedal_pressed const& msg){
				//if(_target.cscope_pedal != true) { get_sender.send(target::cscope_pedal_pressed)} 
				_logd << "scsope_pedal_pressed";
			})
            .template handle<target::cscope_pedal_released>([&](target::cscope_pedal_released const& msg){
				_logd << "scsope_pedal_released";
				if(!(_target.clutch_pedal)){
					_target.left_iled.blink(led::color_t::cyan);
					_target.right_iled.blink(led::color_t::cyan);
				}
			})
            .template handle<target::clutch_pedal_released>([&](target::clutch_pedal_released const& msg){
				_logd << "clutch_pedal_released";
				if(!(_target.cscope_pedal)){
					_target.left_iled.blink(led::color_t::green);
					_target.right_iled.blink(led::color_t::green);
				}
				// if handctrl position range -5~5  -- transit to operation()
				if(_handctrl.inRange(-5, 5))	
					next = &main<T>::operation;
			})
			.template handle<target::emo_button_pressed>([&](target::emo_button_pressed const& msg){
                next = &main<T>::emergency;
            })
			.template handle<target::epo_button_pressed>([&](target::epo_button_pressed const& msg){
                next = &main<T>::emergency;
            });

        transit(next, [&] {
			_timer.reset();
	        _target.left_iled.set(led::color_t::off);
            _target.right_iled.set(led::color_t::off);
            _target.left_pled.set(led::color_t::off);
            _target.right_pled.set(led::color_t::off);
            _logd << "transit";
			//_rt.ecatmst().detach(iarmevents(_incoming, _target));
        });	
	}

	void fini(){
		state_t next = &main<T>::fini;
		once([&]() {
			_logd << "core state is transitted to fini";
	        _target.left_iled.blink(led::color_t::blue);
            _target.right_iled.blink(led::color_t::blue);
            _target.left_pled.blink(led::color_t::blue);
            _target.right_pled.blink(led::color_t::blue);
			_timer.reset<heartbeat>(std::chrono::seconds(fini_time), false);	
		});
		_incoming.wait()
			.template handle<target::rcy_button_pressed>([&](target::rcy_button_pressed const& msg) {
				//_timer.reset();
				_logd << "rcy button pressed";
				next = &main<T>::manual;
			})
			.template handle<target::rcy_button_released>([&](target::rcy_button_released const& msg) {
				_logd << "rcy button released";
			})
			.template handle<heartbeat>([&](heartbeat const& msg) {
				_target.left_iled.set(led::color_t::off);
				_target.right_iled.set(led::color_t::off);
				_target.left_pled.set(led::color_t::off);
				_target.right_pled.set(led::color_t::off);
				_target.ltransl_brake.on();
				_target.rtransl_brake.on();
				state_t next = &main<T>::halt;
			});
        transit(next, [&] {
			_timer.reset();
	        _target.left_iled.set(led::color_t::off);
            _target.right_iled.set(led::color_t::off);
            _target.left_pled.set(led::color_t::off);
            _target.right_pled.set(led::color_t::off);
            _logd << "transit";
        });	
	}

	void halt() {
		once([&]() {
			_logd << "core state is transitted to halt";
		});

		if(_future.valid() && _future.wait_for(std::chrono::seconds(1)) == std::future_status::timeout)
			_loge << "cannot terminate a future";

		_logi << "disable all elmos";
		elmopp::disable(_target.all);
		elmopp::disable(_target.parm);

		_logi << "lock all external brakes";
		_target.proll_brake.on();
		_target.ptransl_brake.on();
		_target.vstransl_brake.on();
		_target.ltransl_brake.on();
		_target.rtransl_brake.on();

		_target.safety_relay.off();
		_logi << "safety relay is off";

		_target.fini();
		_logi << "target<" << _rt.env().spec() << "> is finalized";

		_realtime.fini();
		_logi << "realtime is finalized";

		transit(nullptr);
	}



	void prepare()
	{
		state_t next = &main<T>::prepare;
		static const int maxInstLen = -45;
		static const size_t prepare_period = 100;
		static bool vibrating[2] = {false};

		once([&]() {
			_logd << "core state is transitted to prepare";
			_target.safety_relay.on();
	        _target.left_iled.set(led::color_t::white);
            _target.right_iled.set(led::color_t::white);
            _target.left_pled.set(led::color_t::white);
            _target.right_pled.set(led::color_t::white);


			_target.ltransl.sdo().profileVelocity.write(_target.ltransl.convert(phy::units::millimeter(1)) );
			_target.ltransl.sdo().profileAcceleration.write(_target.ltransl.convert(phy::units::millimeter(10.0)));
			_target.ltransl.sdo().profileDeceleration.write(_target.ltransl.convert(phy::units::millimeter(10.0)));
			
			_target.rtransl.sdo().profileVelocity.write(_target.rtransl.convert(phy::units::millimeter(1)) );
			_target.rtransl.sdo().profileAcceleration.write(_target.rtransl.convert(phy::units::millimeter(10.0)));
			_target.rtransl.sdo().profileDeceleration.write(_target.rtransl.convert(phy::units::millimeter(10.0)));


			_logd <<"ltransl profile(expected: 1 , 10.0, 10.0) :  "
			<<  ssi::node::elmo_cfg::decode(_target.ltransl.cfg().inc_encoder,_target.ltransl.sdo().profileVelocity.read()) <<", "
			<<  ssi::node::elmo_cfg::decode(_target.ltransl.cfg().inc_encoder,_target.ltransl.sdo().profileAcceleration.read()) << ", "
			<<  ssi::node::elmo_cfg::decode(_target.ltransl.cfg().inc_encoder,_target.ltransl.sdo().profileDeceleration.read());

			_logd <<"rtransl profile(expected: 1 , 10.0, 10.0) :  "
			<< ssi::node::elmo_cfg::decode(_target.rtransl.cfg().inc_encoder,_target.rtransl.sdo().profileVelocity.read()) <<", "
			<<  ssi::node::elmo_cfg::decode(_target.rtransl.cfg().inc_encoder,_target.rtransl.sdo().profileAcceleration.read()) << ", "
			<<  ssi::node::elmo_cfg::decode(_target.rtransl.cfg().inc_encoder,_target.rtransl.sdo().profileDeceleration.read());

			_target.ltransl_brake.off();
			_target.rtransl_brake.off();

			_target.ltransl.enable();
			_target.rtransl.enable();

			_timer.reset<heartbeat>(std::chrono::milliseconds(prepare_period), false);
		});

		if(vibrating[0]) _handctrl.vibrate(0);
		if(vibrating[1]) _handctrl.vibrate(1);

		_incoming.wait()
			.template handle<target::left_ibutton_pressed>([&](target::left_ibutton_pressed const& msg) {
				_target.ltransl.disable();
				_logd << "left clutch button pressed";
			})
			.template handle<target::left_ibutton_released>([&](target::left_ibutton_released const& msg) {
				_target.ltransl.enable();
				if(_target.ltransl.length().value() > -10){
					_target.ltransl.moveto(phy::units::millimeter(0.0));
				}
				_logd << "left clutch button released";
			})
			.template handle<target::right_ibutton_pressed>([&](target::right_ibutton_pressed const& msg) {
				_target.rtransl.disable();
				_logd << "right clutch button pressed";
			})
			.template handle<target::right_ibutton_released>([&](target::right_ibutton_released const& msg) {
				_target.rtransl.enable();
				if(_target.rtransl.length().value() > -10){
					_target.rtransl.moveto(phy::units::millimeter(0.0));
				}
				_logd << "right clutch button released";
			})
		 	.template handle<heartbeat>([&](heartbeat const& msg){
				double left_inst_length = _target.ltransl.length().value();
				double right_inst_length = _target.rtransl.length().value();
				if(left_inst_length > -10){;
			        _target.left_iled.set(led::color_t::white);
				}else if(left_inst_length<=-10 && left_inst_length >-45){
			        _target.left_iled.set(led::color_t::yellow);
				}else{
					_target.left_iled.set(led::color_t::green);
				}

				if(right_inst_length > -10){
			        _target.right_iled.set(led::color_t::white);
				}else if(right_inst_length<=-10 && right_inst_length >-45){
			        _target.right_iled.set(led::color_t::yellow);
				}else{
					_target.right_iled.set(led::color_t::green);
				}
		 	})
			.template handle<target::homing_pedal_pressed>([&](target::homing_pedal_pressed const& msg){
				// vibration on
				if(_target.ltransl.length().value() > maxInstLen)
				{
					vibrating[0] = true;
					_logd << "left vibration on";
				}
				if(_target.rtransl.length().value() > maxInstLen)
				{
					vibrating[1] = true;
					_logd << "right vibration on";
				}
			})
			.template handle<target::homing_pedal_released>([&](target::homing_pedal_released const& msg){
				if((_target.ltransl.length().value() <= -45) && (_target.rtransl.length().value() <= -45))
					next = &main<T>::ready;
				_incoming.flush();
				// vibration off
				vibrating[0] = false;
				vibrating[1] = false;
				
            })
			.template handle<target::emo_button_pressed>([&](target::emo_button_pressed const& msg){
                next = &main<T>::emergency;
            })
			.template handle<target::epo_button_pressed>([&](target::epo_button_pressed const& msg){
                next = &main<T>::emergency;
            });

		transit(next, [&]{ _timer.reset();});	
	}

	void operation()
	{
		state_t next = &main<T>::operation;
		static double left_inst_length;
		static double right_inst_length; 

		once([&]() {
			_logd << "core state is transitted to operation";
	        _target.left_iled.blink(led::color_t::green);
            _target.right_iled.blink(led::color_t::green);
            _target.left_pled.blink(led::color_t::green);
            _target.right_pled.blink(led::color_t::green);

			left_inst_length = _target.ltransl.length().value();
			right_inst_length = _target.rtransl.length().value();

			// both hand ctrl regulation close
			_handctrl.regulate(false, false, false);

			_timer.reset<heartbeat>(std::chrono::milliseconds(operation_time), false);
		});
		
		_incoming.wait()
		.template handle<heartbeat>([&](heartbeat const& msg){
			// set the force on the hand ctrl proportional to its gap between the instrument and the hand ctrl
			left_inst_length = _target.ltransl.length().value();
			right_inst_length = _target.rtransl.length().value();

			double p[3] ={0,};
			double p2[3] ={0,};
			dhdGetPosition(&(p[0]),&(p[1]),&(p[2]),static_cast<char>(0));
			dhdGetPosition(&(p2[0]),&(p2[1]),&(p2[2]),static_cast<char>(1));

			_target.ltransl.moveto(phy::units::millimeter(left_inst_length - p[0]*1000 ));
			_target.rtransl.moveto(phy::units::millimeter(right_inst_length - p2[0]*1000));

			_handctrl.setForceOnHand(left_inst_length, right_inst_length);
		})
		.template handle<target::clutch_pedal_released>([&](target::clutch_pedal_released const& msg){
			next = &main<T>::ready;
		})		
		.template handle<target::emo_button_pressed>([&](target::emo_button_pressed const& msg){
			next = &main<T>::emergency;
		})
		.template handle<target::epo_button_pressed>([&](target::epo_button_pressed const& msg){
			next = &main<T>::emergency;
		});
		transit(next, [&]{
			 _timer.reset();
 	        _target.left_iled.set(led::color_t::off);
            _target.right_iled.set(led::color_t::off);
            _target.left_pled.set(led::color_t::off);
            _target.right_pled.set(led::color_t::off);
			// remove the force applied
			_handctrl.setForceOnHand(0,0,0);
            _logd << "transit";
		});	
	}

	void emergency()
	{
		state_t next = &main<T>::emergency;
		once([&]() {
			_logd << "core state is transitted to emergency";
			_target.emo_led.set(led::color_t::on);
			_target.safety_relay.off();
            _target.left_pled.set(led::color_t::yellow);
            _target.right_pled.set(led::color_t::yellow);
		});

		_incoming.wait()
		.template handle<target::epo_button_pressed>([&](target::epo_button_pressed const& msg){
			_target.emo_led.set(led::color_t::on);
		})
		.template handle<target::epo_button_released>([&](target::epo_button_released const& msg){
			_target.emo_led.set(led::color_t::off);
		})
		.template handle<target::emo_button_pressed>([&](target::emo_button_pressed const& msg){
			_target.emo_led.set(led::color_t::on);
		})
		.template handle<target::emo_button_released>([&](target::emo_button_released const& msg){
			_target.emo_led.set(led::color_t::off);
		})
		.template handle<target::rcy_button_released>([&](target::rcy_button_released const& msg){
			if(!(_target.emo_button) && !(_target.epo_button)){
				next = &main<T>::init;
			}
		});

		transit(next, [&]{ 
					_target.emo_led.set(led::color_t::off);
				});	
	}

	void shutdown()
	{
		state_t next = &main<T>::shutdown;
		once([&]() {
			_logd << "core state is transitted to shutdown";
	        _target.left_iled.blink(led::color_t::blue);
            _target.right_iled.blink(led::color_t::blue);
            _target.left_pled.blink(led::color_t::blue);
            _target.right_pled.blink(led::color_t::blue);
			_timer.reset<heartbeat>(std::chrono::seconds(fini_time), false);	
		});

		_incoming.wait()
			.template handle<target::pwr_button_released>([&](target::pwr_button_released const& msg) {
				//_timer.reset();
				_logd << "pwr button released";
				next = &main<T>::ready;
			})
			.template handle<heartbeat>([&](heartbeat const& msg) {
				_target.left_iled.set(led::color_t::off);
				_target.right_iled.set(led::color_t::off);
				_target.left_pled.set(led::color_t::off);
				_target.right_pled.set(led::color_t::off);
				_target.safety_relay.off();
				_target.ltransl_brake.off();
				_target.rtransl_brake.off();
				state_t next = &main<T>::halt;
			});


		transit(next, [&]{ _timer.reset(); });	
	}
};
}

#endif // __CORE_MAIN_H__