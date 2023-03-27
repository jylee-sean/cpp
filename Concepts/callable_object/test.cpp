


#include <functional>
#include <iostream>

using namespace std;


void f1(int a ){cout << a <<endl; }
void f2(int a, int b, int c ){cout << a <<b << c<<endl; }
int main()
{
    //std::function<void(int)> f;
    //f = &f1;
    //f(10);
    //f = bind(&f2, 1,2, std::placeholders::_1);
    //f(3);

    std::function<void(int,int, int)> f;

    f = &f2;
    f(1,2,3);

    //f = bind(&f1,1);

    bind(&f1,1)();


}