
#include "sender.h"
#include "receiver.h"
#include "atm_messages.h"
#include <iostream>
#include <thread>


class bank_machine
{
        messaging::receiver incoming;
        unsigned balance;
    public:
        bank_machine():balance(199){ }
        messaging::sender get_sender()
        {
            return incoming;
        }
        void done()
        {
            get_sender().send(messaging::close_queue());
        }
        void run()
        {
            try{
                for(;;){
                    incoming.wait()
                    .handle<verify_pin>([&](verify_pin const& msg)
                                        {
                                            if(msg.pin =="1937")
                                                msg.atm_queue.send(pin_verified());
                                            else
                                                msg.atm_queue.send(pin_incorrect());
                                        })
                    .handle<withdraw>([&](withdraw const&msg)
                                        {
                                            if(balance >= msg.amount)
                                            {
                                                msg.atm_queue.send(withdraw_ok());
                                                balance-=msg.amount;
                                            }        
                                            else
                                            {
                                                msg.atm_queue.send(withdraw_denied());
                                            }
                                        });
                }
            }
            catch(messaging::close_queue const&)
            {

            }
        }
};
class interface_machine
{
        messaging::receiver incoming;
    public:

        messaging::sender get_sender()
        {
            return incoming;
        }
        void done()
        {
            get_sender().send(messaging::close_queue());
        }
        void run()
        {
            //try{
                for(;;){
                    //incoming.wait()
                }
            //}
            //catch(){

            //}
        }
};
class atm
{
    messaging::receiver incoming;
    messaging::sender bank;
    messaging::sender interface_hardware;

    public:
    atm(messaging::sender bank_, messaging::sender interface_hardware_)
    : bank(bank_),interface_hardware(interface_hardware_) {}

    messaging::sender get_sender()
    {
        return incoming;
    }

    void done()
    {
        get_sender().send(messaging::close_queue());
    }

    void run()
    {

    }


};


int main()
{
    bank_machine bank;
    interface_machine interface_hardware;
    atm machine(bank.get_sender(), interface_hardware.get_sender());

    std::thread bank_thread(&bank_machine::run, &bank);
    std::thread if_thread(&interface_machine::run, &interface_hardware);
    std::thread atm_thread(&atm::run, &machine);

    messaging::sender atmqueue(machine.get_sender()); // sender queue init
    bool quit_pressed = false;

    messaging::sender s;
    s = bank.get_sender();


/*
    while(!quit_pressed)
    {
        char c = getchar();
        switch(c)
        {
            case '9':
                atmqueue.send(digit_pressed(c));
                break;
            
        }
    }
*/
    bank.done();
    machine.done();
    interface_hardware.done();
    atm_thread.join();
    bank_thread.join();
    if_thread.join();

    return 0;
}

