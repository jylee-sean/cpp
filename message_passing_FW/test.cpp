



#include <iostream>
#include <queue>
#include <deque>

class sender
{
    std::deque<int> *q;

    public:
    sender(): q(nullptr){}
    explicit sender(std::deque<int>*q_): q(q_){}



};

class receiver
{
    std::deque<int> q;
    
    public:
    receiver(){ q.push_back(2); }
    operator sender()
    {
        return sender(&q);
    }
};

class machine
{
    receiver incoming;

    public:
        sender get_sender()
        {
        
            return incoming;
        }
};


int main()
{
    receiver r;
    sender s;
    machine m;

    m.get_sender();



    return 0;
}