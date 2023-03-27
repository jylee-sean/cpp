#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <deque>
#include <memory>
#include <iostream>

namespace messaging
{
    struct message_base
    {
        virtual ~message_base() { }
    };

    template<typename Msg>
    struct wrapped_message : message_base
    {
        Msg contents;
        explicit wrapped_message(Msg const& contents_) : contents(contents_) { }
    };

    class queue
    {
        std::mutex m;
        std::condition_variable c;
        std::deque<std::shared_ptr<message_base>> q;
    public:
		void clear() 
            std::lock_guard<std::mutex> lk(m);
			q.clear();
		}
			
        template<typename T>
        void push_back(T const& msg) {
            std::lock_guard<std::mutex> lk(m);
            q.push_back(std::make_shared<wrapped_message<T>>(msg));
            c.notify_all();
        }

		template<typename T>
		void push_front(T const& msg) {
            std::lock_guard<std::mutex> lk(m);
            q.push_front(std::make_shared<wrapped_message<T>>(msg));
            c.notify_all();
		}

        std::shared_ptr<message_base> wait_and_pop() {
			std::cout << "message_base::wait_and_pop()" << std::endl;
            std::unique_lock<std::mutex> lk(m);
            c.wait(lk,[&]{return !q.empty();});
            auto res=q.front();
            q.pop_front();
            return res;
        }
    };
}
