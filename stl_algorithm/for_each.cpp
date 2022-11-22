
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Show
{
    int sum= 0;
    void operator()(int a){
        //std::cout<< a <<", ";
        sum+=a;

        cout<<sum<<",";
    }
};
void foo(int a)
{
    std::cout<< a <<", ";
}


void print(int n)
{
    //n = n*10;
    cout<< n <<",";
}

void print2(int n)
{

    cout <<n*10<<",";
}
int main()
{
    std::vector<int> v = {1,2,3,4,5};
    Show s;


    //Show tmp =for_each(begin(v),end(v),s);    
    
    //cout<<tmp.sum<<endl;

    auto pr = for_each(begin(v),end(v),print);

    pr(6);


    pr = &print2;

    pr(7);

    cout<<endl;

    //for_each(begin(v),end(v),foo);
    //cout<<endl;
    //auto pr = for_each(begin(v),end(v),[](int a) {cout<<a<<", ";});
    //cout<<endl;

    std::less<int> l;

    return 0;
}

