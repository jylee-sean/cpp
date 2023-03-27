#include <iostream>

using namespace std;

class parent
{
    public:
        virtual void print()
        {
            std::cout<<"parnet"<<std::endl;
        }

        void print_parent()
        {
            std::cout<<"parnet"<<std::endl;
        }
};  

class child : public parent
{
    public:
        virtual void print() override
        {
            std::cout<<"child"<<std::endl;
        }

        void print_child()
        {
            std::cout<<"child"<<std::endl;
        }


};

class A
{
        void print_A()
        {
            std::cout<< "A" <<std::endl;
        }
};

class B
{
    public:
        void print_B()
        {
            std::cout<< "B" <<std::endl;
        }
};

int main()
{

    parent *p = new child();


    //p->print_parent();
    //p->print_child();

    child *c;


    //c = dynamic_cast<child*>(p);

    //c->print();
    //c->print_child();
    
    A *a = new A();
    B *b;

    b = reinterpret_cast<B*>(a);

    b->print_B();

    return 0;
}
