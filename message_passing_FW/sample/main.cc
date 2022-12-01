#include "sender.h"
#include "receiver.h"

int main(void)
{
	struct my_message0 { };
	struct my_message1 { };
	struct my_message2 { };
	struct my_message3 { };
	struct my_message4 { };
	struct my_message5 { };
	
	messaging::receiver _incoming;
	messaging::sender _sender = _incoming;
	_sender.send(my_message3());

	_incoming.wait()
		.template handle<my_message0>([&](my_message0 const& msg) {
				std::cout << "got my_message0" << std::endl;
		})
		.template handle<my_message1>([&](my_message1 const& msg) {
				std::cout << "got my_message1" << std::endl;
		})
		.template handle<my_message2>([&](my_message2 const& msg) {
				std::cout << "got my_message2" << std::endl;
		})
		.template handle<my_message3>([&](my_message3 const& msg) {
				std::cout << "got my_message3" << std::endl;
		})
		.template handle<my_message4>([&](my_message4 const& msg) {
				std::cout << "got my_message4" << std::endl;
		})
		.template handle<my_message5>([&](my_message5 const& msg) {
				std::cout << "got my_message5" << std::endl;
		});



	return 0;
}

