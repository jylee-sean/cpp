
//#include "interface_machine.h"

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>
#include <string>
#include <iostream>
#include <thread>
using namespace std;


struct digit_pressed
{
    
};

struct withdraw
{
    
};

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
			std::mutex m;
			std::condition_variable c;
			//std::queue<std::shared_ptr<message_base>> q;
            std::queue<std::shared_ptr<message_base>> q;

		public:


            // queue(){

            //     cout<<"q constructed" << &q <<endl;
            // }


//			void print_queue()
//			{
//                //cout<<q.front()<<endl;
//                cout<< "queue is empty?"<< q.empty()<<endl;
//				while(!q.empty())
//				{
//					cout<< q.front() << " ";
//					q.pop();
//				}
//			}

			 template<typename T>
			 void push(T const& msg)
			 {
			 	std::lock_guard<std::mutex> lk(m);
			 	q.push(std::make_shared<wrapped_message<T>>(msg));
			 	
                 //c.notify_one();
                 c.notify_all();
			 }

			 std::shared_ptr<message_base> wait_and_pop(){

			 	std::unique_lock<std::mutex> lk(m);

                // cout<<"wait and pop  "<< q.empty()<<endl;
			 	// queue가 비어 있다면 condition_variable을 통해서 대기
			 	
                cout<<"wait"<<endl;
                 c.wait(lk, [&]{ return !q.empty();} );
                cout<<"pop"<<endl;
			 	auto res = q.front();
			 	q.pop();
                 
                
                // cout<<"wait and pop  "<< q.empty()<<endl;
			 	return res;
			 }
	};

       template<typename PreviousDispatcher,typename Msg,typename Func>
    class TemplateDispatcher
    {
        queue* q;
        PreviousDispatcher* prev;
        Func f;
        bool chained;

        TemplateDispatcher(TemplateDispatcher const&)=delete;
        TemplateDispatcher& operator=(TemplateDispatcher const&)=delete;

        template<typename Dispatcher,typename OtherMsg,typename OtherFunc>
        friend class TemplateDispatcher;

        void wait_and_dispatch()
        {

            std::cout<<"wait and dispatch"<<std::endl;
            for(;;)
            {
                auto msg=q->wait_and_pop();
                if(dispatch(msg))
                    break;
            }

            
        }

        bool dispatch(std::shared_ptr<message_base> const& msg)
        {
            if(wrapped_message<Msg>* wrapper=
               dynamic_cast<wrapped_message<Msg>*>(msg.get()))
            {
                std::cout<<"template dispatch!!"<<std::endl;
                f(wrapper->contents);
                return true;
            }
            else
            {
                return prev->dispatch(msg);
            }
        }
    public:
        TemplateDispatcher(TemplateDispatcher&& other):
            q(other.q),prev(other.prev),f(std::move(other.f)),
            chained(other.chained)
        {
            other.chained=true;
        }

        TemplateDispatcher(queue* q_,PreviousDispatcher* prev_,Func&& f_):
            q(q_),prev(prev_),f(std::forward<Func>(f_)),chained(false)
        {
            std::cout<<"template dispatcher generated"<<std::endl;
            prev_->chained=true;
        }

        template<typename OtherMsg,typename OtherFunc>
        TemplateDispatcher<TemplateDispatcher,OtherMsg,OtherFunc>
        handle(OtherFunc&& of)
        {

            std::cout<<"handle in template disaptcher"<<std::endl;
            return TemplateDispatcher<
                TemplateDispatcher,OtherMsg,OtherFunc>(
                    q,this,std::forward<OtherFunc>(of));
        }

        ~TemplateDispatcher() noexcept(false)
        {
            std::cout<<"template dispacher destroyed"<<std::endl;
            if(!chained)
            {
                wait_and_dispatch();
            }
        }
    };

    	struct error {
		error(const std::error_code& e) : _error_code(e) { }
		const std::error_code error_code() const { return _error_code; }
	private:
		const std::error_code _error_code;
	};

    struct close_queue {
	// [custom implementation]
	// 	close_queue(int code = 0) : _code(code) { }
	// 	const int code() const { return _code; }
	// private:
	// 	const int _code;
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
			// if(dynamic_cast<wrapped_message<messaging::error>*>(msg.get())) {
			// 	throw messaging::error(dynamic_cast<wrapped_message<messaging::error>*>(msg.get())->contents);
			// }
			// if(dynamic_cast<wrapped_message<close_queue>*>(msg.get())) {
			// 	//custom: throw close_queue(dynamic_cast<wrapped_message<close_queue>*>(msg.get())->contents.code());
			// 	throw close_queue();
			// }
			return false;
		}

	public:
		dispatcher(dispatcher&& other) : q(other.q),chained(other.chained) {
			other.chained=true;
		}

		explicit dispatcher(queue* q_) : q(q_),chained(false) { }

		template<typename Message,typename Func>
		TemplateDispatcher<dispatcher,Message,Func> handle(Func&& f) {
			std::cout<<"handle in disaptcher"<<std::endl;
			return TemplateDispatcher<dispatcher,Message,Func>(q,this,std::forward<Func>(f));
		}

		~dispatcher() noexcept(false) {
			std::cout<<"dispatcher destroyed"<<std::endl;
			if(!chained) {
				wait_and_dispatch();
			}
		}
	};

	class sender
	{
         public:


        sender() : _q(nullptr) {}

        explicit sender(queue *q) : _q(q) {cout<<"called"<<endl;}
            
         template <typename Message>
         void send(Message const& msg){
             if(_q){
                 _q->push(msg);
                 cout<<"pushed"<<endl;
             }
        }
    //         void send(int data){
    //             if(q)
    //                 q->push(data);
    //         }
         private:
            //int a;
            messaging::queue *_q;
	};


	class receiver
	{

        public:

        messaging::queue q;

		//receiver(){ cout<<"receiver constructed"<<endl;}
         operator sender()
         {
		 	cout<<"implicitly type conversion"<<endl;
             return sender(&q);
         }


		//~receiver(){cout<<"receiver destroyed "<<endl;}
        //		messaging::queue getqueue(){
        //			return q;
        //		}
         dispatcher wait()
         {
             return dispatcher(&q);
         }
	};

}

class bank_machine
{
    private:
    messaging::receiver incoming;
    public:
    messaging::sender get_sender()
    {
        return incoming;
    }
};

class interface_machine
{
    private:
    messaging::receiver incoming;
    public:
    messaging::sender get_sender()
    {
        return incoming;
    }
    
};

class atm
{

    public:

    messaging::receiver incoming;
    messaging::sender _bank;
    messaging::sender _interface_hardware;
    
    atm(messaging::sender bank, messaging::sender interface_hardware): _bank(bank),_interface_hardware(interface_hardware) {}
    
    messaging::sender get_sender()
    {
        return incoming;
    }

    
    void waiting_for_card()
    {
        cout<<"here"<<endl;
        
        incoming.wait().handle<digit_pressed>([&]{cout<<"======digit pressed msg======"<<endl;})
                        .handle<withdraw>([&]{cout<<"======withdraw msg======"<<endl;});
        
        cout<<"done"<<endl;
    }
    
    void run()
    {
        while(1){
            waiting_for_card();
        }
    }

	// messaging::receiver get_receiver(
    //){
		
	// 	return incoming;
	// }
};

int main() 
{

    //messaging::sender s;
    //messaging::receiver r;

    
    bank_machine bank;
    interface_machine interface_hardware;

    atm machine(bank.get_sender(),interface_hardware.get_sender());
    messaging::sender atmqueue(machine.get_sender());
    
    //messaging::sender s = r;
	//atm m;

    //machine.run();
    bool flag = true;
    
    std::thread t(&atm::run, &machine);

    int n=1;
    while(flag)
    {
        cout<<"input: ";
        cin>>n;
        
        switch(n)
        {
            case 1:
                atmqueue.send(withdraw());
                break;
            case 2:
                atmqueue.send(digit_pressed());
                break;
            case 3:
                flag = false;
                break;
        }
        
    }
    
    
    t.join();
    
//    r.getqueue().push(10);
//    r.getqueue().push(20);
//    r.getqueue().push(30);
//
//
//    r.getqueue().print_queue();
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
