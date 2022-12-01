#include <iostream>
#include <algorithm>
#include <functional>
#include <string>



using namespace std::placeholders;

class Test
{
    public:
        void f(int a, int b){
            data= a;    
        }


        int data= 0;
};
using namespace std;

void foo(int&& val){

    cout<<val<<endl;
    val = 20;
    cout<<val<<endl;
}
int main()
{

    int n =10;

    foo(10);
    cout<<n<<endl<<"---------"<<endl;

    Test t;
    std::function<void(Test*)> func;

    func = std::bind(&Test::f, _1,1,2);
    func(&t);
    cout<<t.data<<endl;
    //std::bind(&Test::f, _1,1,2)(t);
    //cout<<t.data<<endl;

    std::function <void(Test*, int)> f1;
    f1 = std::bind(&Test::f, _1, _2, 20);
    f1(&t, 100);
    std::cout<<t.data<<std::endl;


    std::function <void(Test, int)> f2;
    f2 = std::bind(&Test::f, _1, _2, 20);
    f2(t, 200); // t.f(100,20)
    std::cout<<t.data<<std::endl;


    t.f(-100,0);
    std::cout<<t.data<<std::endl;
    //t.f(1,2);


    

    return 0;
}