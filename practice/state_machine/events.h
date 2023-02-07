/**
 * @brief		auxiliary events gererator class
 * @details		
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */

#ifndef __CORE_EVENTS_H__
#define __CORE_EVENTS_H__

#include <ssi/runtime.h>

#include <messaging/sender.h>
#include <messaging/receiver.h>
#include <messaging/message_base.h>

#include <messages.h>

namespace core
{
	/// auxiliary events generator
	template<typename T>
	class events : public std::enable_shared_from_this<events<T>>
	{
	public:
		using code_type = uint64_t;

		explicit events(T& target, messaging::sender sender) : _code(0), _pulse(), _target(target), _sender(sender) { }

		/*
		template<typename F>
		explicit events(T& target, messaging::sender sender, const std::chrono::steady_clock::duration& interval, F&& f) : events(target, sender) {
			if(!reset<F>(interval, f))
				_loge << "events initialization fail";
		}
		*/

		virtual ~events() {
			reset();
		}

		template<typename F>
		bool reset(const std::chrono::steady_clock::duration& interval, F&& f, const code_type code) {
			_code = code;
			return reset(interval, f);
		}

		template<typename F>
		bool reset(const std::chrono::steady_clock::duration& interval, F&& f) {
			if(_pulse.init(interval) != nullptr)
				return false;
			_f = std::async(std::launch::async, [this, &f] {
				pthread_setname_np(pthread_self(), "core::events");
				_logd << "events thread is created";
				while(_pulse.wait(true))
					_code = f(_target, _sender, _code);
				_logd << "events thread is destroyed";
				return true;
			});
			return true;
		}

		bool reset() {
			_pulse.fini();
			if(_f.valid() && _f.wait_for(std::chrono::milliseconds(100)) == std::future_status::timeout) {
			_loge << "std::future error";
			return false;
			}
			return true;
		}

		code_type code() { return _code; }

	protected:
		T& _target;
		messaging::sender _sender;
		std::future<bool> _f;
		ssi::pulse _pulse;
		code_type _code;
	};
}

#endif // __CORE_EVENTS_H__