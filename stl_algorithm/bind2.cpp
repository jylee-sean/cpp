#include <iostream>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

class Test
{
    public:
        void f(int a, int b){
            data= a;    
        }


        int data= 0;
};


int main()
{


    Test t;
    std::function<int()> f1;

    f1 = std::bind(&Test::data, &t);

    std::cout<<f1()<<std::endl;;

    std::function<int&()> f2;

    f2 = std::bind(&Test::data, &t);

    f2() = 20;

    std::cout<<t.data<<std::endl;


    std::function<int&(Test*)> f3;

    f3 = std::bind(&Test::data,_1);

    f3(&t) = 50;

    std::cout<<t.data<<std::endl;


    return 0;
}
