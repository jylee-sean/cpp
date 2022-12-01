



#include <iostream>

template<typename T>
class event
{
    public:
};


template<typename T>
class state_machine
{

};

template<typename T>
class core : public state_machine<core<T>>
{
    public:
    T* obj;

    class observer : public event<double>
    {
        public:
        observer(){
            std::cout<<"observer"<<std::endl;
        }
        T value;
    };
    
    
    void func()
    {
        observer();
    }
};



int main()
{

    core<int> c;

    c.func();
    
    return 0;
}


