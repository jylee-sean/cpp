#include <iostream>

using namespace std;

template <typename T>
class myreference_wrapper
{
    public:
       myreference_wrapper(T& t) : obj(&t) { }
       operator T&( ) { return *obj; };
   private:
      T *obj; 
}; 


/*
template <typename T> reference_wrapper<T> ref(T& obj)
{
    return reference_wrapper<T>(obj);
}; 
*/


int main()
{
    int n = 0;
    myreference_wrapper<int> rw(n);
    int& r = rw;
    r = 100;
    std:: cout<< n <<std::endl;
}
