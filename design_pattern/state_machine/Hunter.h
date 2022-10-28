#pragma once

class HunterState;
class Hunter
{
    HunterState* state;

    public:
        Hunter()
        {
            state = IdleState::GetInstance;
        }

        void SetState(HunterState* state){
            this->state = state;
        }

        void move(){
            state->Move(this);
        }

        void eat(){
            state->eat(this);
        }
        void attack(){
            state->attack(this);
        }
        void idle(){
            state->idle(this);
        }
        

}