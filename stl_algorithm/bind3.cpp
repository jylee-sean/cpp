#include <iostream>
#include <algorithm>
#include <functional>

using namespace std::placeholders;
using namespace std;

void foo(int* a) { *a = 20; }

int main()
{
    int n= 10;
    //bind(&foo, n)();
    //cout<<n<< endl;

   bind(&foo, &n)();
   cout<<n<<endl;


//    reference_wrapper<int> r(n);
//    bind(&foo, r)();
//    cout<<n<<endl;

//    bind(&foo, ref(n))();
//    cout<<n<<endl;
}
