#include <iostream>


class comst
{
    public: 
    virtual void call() = 0;
    void foo(){};
};

class ecatmst: public comst
{
    public: 
    void call(){std::cout<<"called"<<std::endl;};

};

int main()
{

    //A a;
    ecatmst e;
    
    
    comst *c = &e;





    c->call();

    



    return 0;
}