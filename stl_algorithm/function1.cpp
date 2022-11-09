#include <iostream>
#include <functional>


template <typename T>
class state_machine
{
    public:
        //using fp = void (T::*)(int val);
        using fp = std::function<void(T&,int)>;

        void state(){
           std::cout<<"state"<<std::endl;
        }
};
template<typename T>
class base : public state_machine<T>
{
    public:

};

class A :public base<A>
{
    public:

    void run(){

        fp prev = &A::func;
        

        //(this->*state())();
        //(this->*prev)(100);
        //prev(*this, 100);

    }
    void func(int a){
        std::cout<<a<<"called"<<std::endl;
    }


};
int main()
{

    A a;

    a.run();


    return 0;
}