

//#include <ccl/state_machine.h>
#include "state_machine.h"



class robot_machine_B : public ccl::state_machine<robot_machine_B, int, char>{
    public:
    robot_machine_B(){
    }
    void run() override{
        transit(&robot_machine_B::start);
        std::cout<<"run"<<std::endl;
    }
    //void run() {
    //    (this->*state())();
    //}

    
    void start(int v, char c){
        state_t next;
        once([&](){
            //m_t.where << "start::once,";
        });
        //if(m.msg == 1){
        next = &robot_machine_B::start; //}
        //else{ 
        //    next = &robot_machine_B::standby; }
        transit(next,[&](){
            //m_t.where << "start::transit,";
        });

        std::cout<<"start"<<std::endl;
    }
    void standby(int v, char c){
        once([&](){
            //m_t.where << "standby::once,";
        });
        //if(m.msg == 1)
        transit(&robot_machine_B::start);
        //else if(m.msg == 2)
         //   reenter(&robot_machine_B::standby);
        std::cout<<"standby"<<std::endl;
    } 
    //state_msg_B m_t;
};


int main()
{

    int data = 10;
    char cdata = 'c';

    robot_machine_B B;

    B.run();
    B.step(data, cdata);



    return 0;
}