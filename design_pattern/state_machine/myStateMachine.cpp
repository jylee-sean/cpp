
/*
* ref: https://daru-daru.tistory.com/70?category=788166
*/


#include <iostream>
#include "Hunter.h"


using namespace std;


class HunterState
{
    public:
        virtual void Move(Hunter* hunter) = 0;
        virtual void Eat(Hunter* hunter)= 0;
        virtual void Attack(Hunter* hunter)= 0;
        virtual void Idle(Hunter* hunter)=0;

    protected:
        void SetHunterState(Hunter* hunter, HunterState* state)
        {
            hunter->SetState(state);
        }
        


    
};



class HungryState : public HunterState
{

    static HungryState* instance;

    public:

        HungryState(){
            std::cout<<"hungry state costructor"<<endl;
        }

        static HungryState * GetInstance();


        void Move(Hunter* hunter){
            std::cout<<"(hungry) moving..."<<std::endl;
        };

        void Eat(Hunter * hunter){
            std::cout<<"(hungry) eating..."<<std::endl;
            SetHunterState(Hunter* hunter, HunterState Idlestate);
        };

        void Attack(Hunter* hunter){
            std::cout<<"(hungry) attack..."<<std::endl;
        };

        void Idle(Hunter* hunter){
            std::cout<<"(hungry) idling..."<<std::endl;
        };
};

class IdleState : public HunterState
{

    static IdleState* instance;

    public:

        static IdleState* GetInstance();

        void Move(Hunter* hunter){
            std::cout<<"moving..."<<std::endl;
        };

        void Eat(Hunter * hunter){
            std::cout<<"eating..."<<std::endl;
            SetHunterState(Hunter* hunter, HunterState Idlestate);
        };

        void Attack(Hunter* hunter){
            std::cout<<"attack..."<<std::endl;
        };

        void Idle(Hunter* hunter){
            std::cout<<"idling..."<<std::endl;
        };


};

class MoveState : public HunterState
{
    static MoveState* instance;

    public:
        static MoveState* GetInstance();

        void Move(Hunter* hunter){
            std::cout<<"moving..."<<std::endl;
        };

        void Eat(Hunter * hunter){
            std::cout<<"eating..."<<std::endl;
            SetHunterState(Hunter* hunter, HunterState Idlestate);
        };

        void Attack(Hunter* hunter){
            std::cout<<"attack..."<<std::endl;
        };

        void Idle(Hunter* hunter){
            std::cout<<"idling..."<<std::endl;
        };
};


HungryState* HungryState::instance;
IdleState* IdleState::instance;
MoveState* MoveState::instance;

HungryState* HungryState::GetInstance
{
    if(instance == nullptr)
    {
        instance = new HugryState();

    }

    return instance;
};

IdleState* IdleState::GetInstance
{
    if(instance == nullptr)
    {
        instance = new IdleState();

    }

    return instance;
};

MoveState* MoveState::GetInstance
{
    if(instance == nullptr)
    {
        instance = new MoveState();

    }
    return instance;
};


int main()
{
    Hunter hunter;






    return 0;
}