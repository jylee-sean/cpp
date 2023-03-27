
#include <iostream>
#include <type_traits>


using std::cout;
using std::endl;


template<typename T> struct is_pointer 
{
//    enum {value = false};
    static constexpr bool value = false;
};


template<typename T> struct is_pointer<T*> 
{
//    enum {value = true};
    static constexpr bool value = true;
};


template<typename T> void foo(T v)
{
    if(is_pointer<T>::value)
    {
        cout<<"pointer"<<endl;
    }
    else
    {
        cout<<"not poitner"<<endl;
    }
}


int main()
{
    int n = 7;
    double pi = 3.141591;


    foo(n);
    foo(&n);


    return 0;

}