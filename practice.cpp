

#include <iostream>
#define TEXT "hello"

using namespace std;

void foo(int &a)
{
    cout<<a<<endl;
    a=3;
//    cout<<a<<endl;
}


void foo2(int &&a)
{
    cout<<a<<endl;

    

}

int main()
{

    int b =5;
    //foo(b);
    //cout<<b<<endl;
    
    foo2(5);

    return 0;

}

