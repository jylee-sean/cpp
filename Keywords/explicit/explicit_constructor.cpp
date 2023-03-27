#include <iostream>




class Foo{
    public:
        int m_foo;
        //Foo(int foo) : m_foo(foo){ std::cout<<"called"<<std::endl;}
        //Foo(){std::cout<<"this called"<<std::endl;}
        explicit Foo(int foo) : m_foo(foo){ std::cout<<"called"<<std::endl;}
};


class Goo{
    public:
        Foo f;
};
void print_foo(Foo foo){
    std::cout<<foo.m_foo <<std::endl;
}
int main()
{

    //int num = 43;
    //print_foo(num);

    Foo f;
    
    //Goo g;
    
    //Goo g::f(1);
    return 0;
}