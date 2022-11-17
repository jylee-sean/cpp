#include <iostream>
#include <functional>


template <typename T>
class state_machine
{
    public:
        //using fp = void (T::*)(int val);
        using fp = std::function<void(T&,int)>;

        fp state(){
           std::cout<<"state"<<std::endl;
           return this->_curr;
        }
    
    protected:
        void transit(fp next){

            this->_curr = next;
        }
    private:
        fp _curr;

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
        fp next = &A::func;
        transit(next);        
        //(this->*state())(100);
        state()(*this,100);
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