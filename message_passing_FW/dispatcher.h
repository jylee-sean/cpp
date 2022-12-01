#pragma once

#include <system_error>

#include "TemplateDispatcher.h"

namespace messaging
{
	struct error {
		error(const std::error_code& e) : _error_code(e) { }
		const std::error_code error_code() const { return _error_code; }
	private:
		const std::error_code _error_code;
	};

    struct close_queue {
		close_queue(int code = 0) : _code(code) { }
		const int code() const { return _code; }
	private:
		const int _code;
	};

    class dispatcher
    {
		queue* q;
		bool chained;

		dispatcher(dispatcher const&)=delete;
		dispatcher& operator=(dispatcher const&)=delete;

		template<typename Dispatcher, typename Msg, typename Func>
		friend class TemplateDispatcher;

		void wait_and_dispatch() {
			for(;;) {
				auto msg=q->wait_and_pop();
				dispatch(msg);
			}
		}

		bool dispatch(std::shared_ptr<message_base> const& msg) {
			if(dynamic_cast<wrapped_message<messaging::error>*>(msg.get())) {
				throw messaging::error(dynamic_cast<wrapped_message<messaging::error>*>(msg.get())->contents);
			}
			if(dynamic_cast<wrapped_message<close_queue>*>(msg.get())) {
				throw close_queue(dynamic_cast<wrapped_message<close_queue>*>(msg.get())->contents.code());
			}
			return false;
		}

	public:
		dispatcher(dispatcher&& other) : q(other.q),chained(other.chained) {
			other.chained=true;
		}

		explicit dispatcher(queue* q_) : q(q_),chained(false) { }

		template<typename Message,typename Func>
		TemplateDispatcher<dispatcher,Message,Func> handle(Func&& f) {
			return TemplateDispatcher<dispatcher,Message,Func>(q,this,std::forward<Func>(f));
		}

		~dispatcher() noexcept(false) {
			if(!chained) {
				wait_and_dispatch();
			}
		}
	};
}
