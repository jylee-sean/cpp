#pragma once

#include "message_base.h"
#include "dispatcher.h"

namespace messaging
{
    class receiver
    {
        queue q;
    public:
        operator sender()
        {
            return sender(&q);
        }
        dispatcher wait()
        {
            return dispatcher(&q);
        }

        //custom
    	// void flush() {
		// 	q.clear();
		// }

    };
}


