#include <iostream>
#include <functional>
#include <tuple>

template <typename T, typename ...E>
class state_machine
{
    public:
        //using fp = void (T::*)(E...);
        using fp = std::function<void(T&, E...)>;

        fp state(){
           std::cout<<"state"<<std::endl;
           return this->_curr;
        }

        void step(E... args){
            //(static_cast<T*>(this)->*state())(args...);
            (static_cast<T*>(state()(*this,args...)));
        }
    
    protected:
        void transit(fp next){

            this->_curr = next;
        }
    private:
        fp _curr;

};

template<typename T, typename ...E>
class base : public state_machine<T, E...>
{
    public:
};

struct Sample
{

};
Sample s;


class A :public base<A, int, Sample, char>
{
    public:

    void run(){
        fp next = &A::func;
        fp next2 = &A::func;
        
        
        std::cout<<next.target_type().name()<<std::endl;
        std::cout<<next2.target_type().name()<<std::endl;
        if(next.target_type().name() ==next2.target_type().name()) {
            std::cout<<"same"<<std::endl;
        }

        //if(getAddress(next) == &A::func2){
        //    std::cout<<"Not same"<<std::endl;
        //}

        
        //transit(next);
        //(this->*state())(100,s,'c');
        state()(*this,100,s,'c');
    }
//    void run2(){
//        fp next = &A::func2;
//        transit(next);
//        state()(*this);
//    }
    void func(int num, Sample s, char c){
        //std::tuple<E...> tp(args...);
        std::cout<<num<<c<<std::endl;
    }

    //void func2(int num, Sample s, char c){
        //std::tuple<E...> tp(args...);
    //}
  
};
int main()
{
    A a;
    a.run();
    
    
    //a.run2();
    return 0;
}
