#include <iostream>
#include <functional>


void f1(int a, int b, int c){};

int main()
{

    std::function<void(int, int, int)> f;



    f = &f1;


    return 0;
}