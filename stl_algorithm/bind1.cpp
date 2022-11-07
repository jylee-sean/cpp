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
    //std::bind(&Test::f, std::ref(t), 1,2)();
    //std::bind(&Test::f, &t, 1,2)();
    std::bind(&Test::data,std::ref(t))() = 10;

    
    std::cout<<t.data<<std::endl;


    return 0;
}