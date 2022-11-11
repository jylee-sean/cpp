#include <iostream>


template<typename T, int I>
class A
{
    public:

    void update();


};
template<typename T>
void A<T,0>::update(){

    std::cout<<"0"<<std::endl;
}

//template<typename T, int N>

template<typename T>
void A<T,1>::update(){

    std::cout<<"1"<<std::endl;
}

int main()
{

    A<int> a;

    a.update<int,1> u1;
    a.update<int,2> u2;

    return 0;
}