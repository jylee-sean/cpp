
/*
* ref: https://daru-daru.tistory.com/70?category=788166
*/

#pragma once
#include <iostream>
#include "Hunter.h"


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
        
}
int main()
{

    return 0;
}