#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

std::string str;


str = "error";
using namespace std::placeholders;

class Test
{
    public:
        void f(int a, int b){
            data= a;    
        }


        int data= 0;
};


void foo(int& a){ a = 20;}


int main()
{

    int n = 10;

    //std::bind(&foo,n)();
    //std::cout<< n <<std::endl;

    //std::bind(&foo,std::ref(n))();
    //std::cout<< n <<std::endl;


    Test t;
//    std::bind(&Test::f, std::ref(t), 1,2)();
//    std::cout<<t.data<<std::endl;

    
    //std::bind(&Test::f, std::ref(t), 1,2)();
    //std::bind(&Test::f, t, 1,2)();
    
    
   // std::bind(&Test::f, _1, 1,2)(t);
   
    //std::bind(&Test::data, t)() = 10;
    
    std::function <void(Test*, int)> f1;
    f1 = std::bind(&Test::f, _1, _2, 20);
    f1(&t, 100);
    std::cout<<t.data<<std::endl;


    std::function <void(Test, int)> f2;
    f2 = std::bind(&Test::f, _1, _2, 20);
    f2(t, 200); // t.f(100,20)
    std::cout<<t.data<<std::endl;



    //std::bind(&Test::data,std::ref(t))() = 10;

    
    //std::cout<<t.data<<std::endl;
    

    return 0;
}