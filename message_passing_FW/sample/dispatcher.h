#pragma once

#include "TemplateDispatcher.h"

namespace messaging
{
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

        template<
            typename Dispatcher,
            typename Msg,
            typename Func>
        friend class TemplateDispatcher;

        void wait_and_dispatch()
        {
			std::cout << "dispatcher::wait_and_dispatch()" << std::endl;
            for(;;)
            {
                auto msg=q->wait_and_pop();
                dispatch(msg);
            }
        }

        bool dispatch(
            std::shared_ptr<message_base> const& msg)
        {
			std::cout << "dispatcher::dispatch()" << std::endl;
            if(dynamic_cast<wrapped_message<close_queue>*>(msg.get()))
            {
                throw close_queue(dynamic_cast<wrapped_message<close_queue>*>(msg.get())->contents.code());
            }
            return false;
        }
    public:
        dispatcher(dispatcher&& other):
            q(other.q),chained(other.chained)
        {
			std::cout << "dispatcher::dispatcher()" << std::endl;
            other.chained=true;
        }

        explicit dispatcher(queue* q_):
            q(q_),chained(false)
        {
			std::cout << "dispatcher::dispatcher(*)" << std::endl;
		}

        template<typename Message,typename Func>
        TemplateDispatcher<dispatcher,Message,Func>
        handle(Func&& f)
        {
			std::cout << "dispatcher::handle<>()" << std::endl;
            return TemplateDispatcher<dispatcher,Message,Func>(
                q,this,std::forward<Func>(f));
        }

        ~dispatcher() noexcept(false)
        {
			std::cout << "dispatcher::~dispatcher()" << std::endl;
            if(!chained)
            {
                wait_and_dispatch();
            }
        }
    };
}
