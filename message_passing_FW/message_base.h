#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>
#include <deque>
#include <memory>
#include <string>
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

	class message_handler
	{
	public:
		message_handler(std::shared_ptr<message_base> const& ref) : _ref(ref) { }
		~message_handler() { }

		//TODO:
		// i wanted to delete copy constructor because of its performance
		// message_handler(message_handler const&) = delete;
		// message_handler& operator=(message_handler const&) = delete;

		template<typename T, typename F>
		message_handler handle(F&& f) {
			if(wrapped_message<T>* wrapper = dynamic_cast<wrapped_message<T>*>(_ref.get()))
				f(wrapper->contents);
			return message_handler(_ref);
		}
	private:
		std::shared_ptr<message_base> const& _ref;
	};

    class queue
    {
        std::mutex m;
        std::condition_variable c;
        std::deque<std::shared_ptr<message_base>> q;
    public:
		void clear() {
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
            std::unique_lock<std::mutex> lk(m);
            c.wait(lk,[&]{return !q.empty();});
            auto res=q.front();
            q.pop_front();
            return res;
        }
    };
}
