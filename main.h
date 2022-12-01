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
	static constexpr const size_t heartbeat_for_icalib = 10; //(unit: ms)
	static constexpr const size_t fini_time = 10; //(unit: sec)
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

	class iarmevents: public ccl::event::observer<ssi::ecatmst, ssi::ecatmst::event>
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
                next = &main<T>::manual;
            });



        transit(next, [&] {
            _timer.reset();
            _target.left_iled.blink(led::color_t::off);
            _target.right_iled.blink(led::color_t::off);
            _target.left_pled.set(led::color_t::off);
            _target.right_pled.set(led::color_t::off);
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

			
			//iarmevents i = iarmevents(_incoming, _target);
			_rt.ecatmst().attach(iarmevents(_incoming, _target));

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
            .template handle<iarm_ready>([&](iarm_ready const& msg){
                next = &main<T>::ready;
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
			//_rt.ecatmst().detach(_iarmevents);
			_rt.ecatmst().detach(iarmevents(_incoming, _target));
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
			_timer.reset<heartbeat>(std::chrono::milliseconds(heartbeat_for_icalib), false);
			_rt.ecatmst().attach(iarmevents(_incoming, _target));	
		});

		_incoming.wait()
		 	.template handle<heartbeat>([&](heartbeat const& msg){
				double left_inst_length = _target.ltransl.length().value();
				double right_inst_length = _target.rtransl.length().value();
				if((left_inst_length > instrument_length_limit) || (right_inst_length > instrument_length_limit))
					next = &main<T>::ready;
		 	})
            .template handle<target::cscope_pedal_pressed>([&](target::cscope_pedal_pressed const& msg){
				//if(_target.cscope_pedal != true) { get_sender.send(target::cscope_pedal_pressed)} 
			})
            .template handle<target::cscope_pedal_released>([&](target::cscope_pedal_released const& msg){
				if(_target.cscope_pedal && !(_target.clutch_pedal)){
					_target.left_iled.blink(led::color_t::cyan);
					_target.right_iled.blink(led::color_t::cyan);
				}
			})
            .template handle<target::clutch_pedal_pressed>([&](target::clutch_pedal_pressed const& msg){
				//if(_target.clutch_pedal_pressed != true) { get_sender.send(target::clutch_pedal_pressed)} 
			})
            .template handle<target::clutch_pedal_released>([&](target::clutch_pedal_released const& msg){
				if(_target.clutch_pedal && !(_target.cscope_pedal)){
					_target.left_iled.blink(led::color_t::green);
					_target.right_iled.blink(led::color_t::green);
				}
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
			_rt.ecatmst().detach(iarmevents(_incoming, _target));
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
				//if( _target.rcy_button != true){get_sender.send(target::rcy_button_pressed)};
				state_t next = &main<T>::manual;
			})
			.template handle<target::rcy_button_released>([&](target::rcy_button_released const& msg) {
				//if( _target.rcy_button == true){get_sender.send(target::rcy_button_released)};
			})
			.template handle<heartbeat>([&](heartbeat const& msg) {
				_target.left_iled.set(led::color_t::off);
				_target.right_iled.set(led::color_t::off);
				_target.left_pled.set(led::color_t::off);
				_target.right_pled.set(led::color_t::off);
				_target.ltransl_brake.on();
				_target.rtransl_brake.on();
				done();
				state_t next = &main<T>::halt;
			});
        transit(next, [&] {
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
};
}

#endif // __CORE_MAIN_H__
