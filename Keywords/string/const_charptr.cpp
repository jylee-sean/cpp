

#include <iostream>

using namespace std;


const char* f(){

    return "hello world!";
}
int main()
{

    const char *ptr;

    ptr = f();

    cout<<ptr<<endl;


    return 0;
}