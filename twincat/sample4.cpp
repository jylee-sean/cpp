#include <iostream>


typedef struct _struct_data{

        int d1;
        int d2;
        std::string s;

}struct_data;

class A
{
    public:

        void *ptr;

        bool func1_inA(){
            return true;
        }


        void update(struct_data sd){
            std::cout<<sd.d1<<sd.d2<<sd.s<<std::endl;
        }

};
class B;
typedef bool (B::*fp) (void);

class B
{
    public:        

        fp parr[3] = {&B::func1, &B::func2, &B::func3};

        struct_data d;


        B(){
            d.d1 = 3;
            d.d2 = 5;
            d.s = "hello";
        };


        A a;

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

        void func(){
            a.update(d);
        }


};

int main()
{

    
    B b;

    b.func();

    //fp* exe;

    //exe = b.parr;


    //*(b.parr[0])();

    //fp* exe = b.parr[0];


    //b.parr[0]();

    //std::cout<<&(b.parr[0])<std::endl;
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