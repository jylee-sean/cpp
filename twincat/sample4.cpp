#include <iostream>


class A
{
    public:

        void *ptr;

        bool func1_inA(){
            return true;
        }

};
class B;
typedef bool (B::*fp) (void);

class B
{
    public:        

        fp parr[3] = {&B::func1, &B::func2, &B::func3};

        bool func1(){
            std::cout<<"f1"<<std::endl;
            return true;
        }

        bool func2(){
            std::cout<<"f2"<<std::endl;
            return true;
        }

        bool func3(){
            std::cout<<"f3"<<std::endl;
            return true;
        }


};

int main()
{

    B b;

    b.func1();

    //fp* exe;

    //exe = b.parr;


    //*(b.parr[0])();

    //fp* exe = b.parr[0];


    //b.parr[0]();

    std::cout<<&(b.parr[0])<std::endl;
    //std::cout<<reinterpret_cast<fp>(b.func1)<<std::endl;
   //std::cout<<reinterpret_cast<fp>(b.parr[0])<<std::endl;
    
    //*b.parr[0]();
    //(**exe)();
    //*(b.parr[0])();
    //b.(*parr[0])();

    
    //A a;


    //a.ptr =(cast) b.parr;






    return 0;
}