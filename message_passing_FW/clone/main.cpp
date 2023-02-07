
//#include "interface_machine.h"

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>
#include <string>
#include <iostream>

using namespace std;


namespace messaging
{

	struct message_base
	{

	};

	template<typename Msg>
	struct wrapped_message : message_base
	{
		Msg contents;
		explicit wrapped_message(Msg const& contents_) : contents(contents_){}
	};

	class queue
	{
		private:
			//std::mutex m;
			//std::condition_variable c;
			//std::queue<std::shared_ptr<message_base>> q;
            std::queue<int> q;

		public:


            queue(){

                cout<<"q constructed" << &q <<endl;
            }
			void push(int data) 
			{
				//std::lock_guard<std::mutex> lk(m);

                cout<<"q address" << &q <<endl;
				q.push(data);


                //cout<<q.front()<<endl;
				//c.notify_all();
			}

			void print_queue()
			{
                //cout<<q.front()<<endl;
                cout<< "queue is empty?"<< q.empty()<<endl;
				while(!q.empty())
				{
					cout<< q.front() << " ";
					q.pop();
				}
			}

			// template<typename T>
			// void push(T const& msg)
			// {
			// 	std::lock_guard<std::mutex> lk(m);
			// 	q.push(std::make_shared<wrapped_message<T>>(msg));
			// 	c.notify_all();
			// }

			// std::shared_ptr<message_base> wait_and_pop(){

			// 	std::unique_lock<std::mutex> lk(m);

			// 	// queue가 비어 있다면 condition_variable을 통해서 대기
			// 	c.wait(lk, [&]{ return !q.empty();});
			// 	auto res = q.front();
			// 	q.pop();
			// 	return res;
			// }




	};


	// class sender
	// {
    //     public:


    //         sender() : q(nullptr) 
	// 		{
	// 			cout<<"sender constructed"<<endl;
	// 		}

    //         explicit sender(queue *q_) : q(q_) 
	// 		{
	// 			cout<<"explicit constructor(sender) called"<<endl;
	// 		}
            
    //         //template <typename Message>
    //         //void send(Message const& msg){
    //         //    if(q)
    //         //        q->push(msg);
    //         //}

    //         void send(int data){
    //             if(q)
    //                 q->push(data);
    //         }
    //     private:
    //         messaging::queue *q;     
	// };


	class receiver
	{

        public:

        messaging::queue q;

		receiver(){ cout<<"receiver constructed"<<endl;}
        // operator sender()
        // {
		// 	cout<<"implicitly type conversion"<<endl;
        //     return sender(&q);
        // }


		~receiver(){
			cout<<"receiver destroyed "<<endl;
		}
		messaging::queue getqueue(){
			return q;
		}
            // dispatcher wait()
            // {
            //     return dispatcher(&q);
            // }
	};

}

class bank_machine
{

};

class interface_hardware
{

};

class atm
{




    public:

    messaging::receiver incoming;
    //messaging::sender bank;
    //messaging::sender interface_hardware;


    // messaging::sender get_sender()
    // {
	// 	cout<<"get sender function called"<<endl;
    //     return incoming;
    // }

	// messaging::receiver get_receiver(){
		
	// 	return incoming;
	// }
};

int main() 
{

    //messaging::sender s;
    messaging::receiver r;

	//atm m;


    r.getqueue().push(10);
    r.getqueue().push(20);
    r.getqueue().push(30);


    r.getqueue().print_queue();
	// s = m.get_sender();

    
	// s.send(100);
	// s.send(200);
	// s.send(300);

	// //m.incoming.operator messaging::receiver

	// r = m.incoming;
    //.getqueue().print_queue();

	// m.get_receiver();
	//m.get_receiver(); //.getqueue().print_queue();

    // bank_machine bank;
    // interface_machine interface_hardware;

    // atm machine(bank.get_sender(),interface_hardware.get_sender());
    // std::thread bank_thread(&bank_machine::run,&bank);
    // std::thread if_thread(&interface_machine::run,&interface_hardware);
    // std::thread atm_thread(&atm::run,&machine);
    // messaging::sender atmqueue(machine.get_sender());
    // bool quit_pressed=false;
    // while(!quit_pressed)
    // {
    //     char c=getchar();
    //     switch(c)
    //     {
    //     case '0':
    //     case '1':
    //     case '2':
    //     case '3':
    //     case '4':
    //     case '5':
    //     case '6':
    //     case '7':
    //     case '8':
    //     case '9':
    //         atmqueue.send(digit_pressed(c));
    //         break;
    //     case 'b':
    //         atmqueue.send(balance_pressed());
    //         break;
    //     case 'w':
    //         atmqueue.send(withdraw_pressed(50));
    //         break;
    //     case 'c':
    //         atmqueue.send(cancel_pressed());
    //         break;
    //     case 'q':
    //         quit_pressed=true;
    //         break;
    //     case 'i':
    //         atmqueue.send(card_inserted("acc1234"));
    //         break;
    // } }
    // bank.done();
    // machine.done();
    // interface_hardware.done();
    // atm_thread.join();
    // bank_thread.join();
    // if_thread.join();
}