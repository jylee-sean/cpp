#pragma once

#include "message_base.h"

namespace messaging
{
    class sender
    {
    public:
        sender() : q(nullptr) { }

        explicit sender(queue*q_) : q(q_) { }

        template<typename Message>
        void send(Message const& msg) {
            if(q)
                q->push_back(msg);
        }

		template<typename Message>
		void raise(Message const& msg) {
			if(q)
				q->push_front(msg);
		}

	private:
        queue* q;
    };
}
