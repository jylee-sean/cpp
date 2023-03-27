//#include "input.h"
#include <iostream>
class observer
{
    public:
    virtual void update() = 0;
};

template<typename Ty>
class input : public observer
{

  public:
    input(){};
    virtual ~input(){};
  
    virtual void update() override{

        //iupdate<int,0>()();
        //iupdate<int,1>()();
        std::cout<<"call update()"<<std::endl;

        _update<0>();
        _update<1>();
    }

  protected:

    template<typename T>
    void _update<bool>()
    { 
        static constexpr size_t N = 0;
        std::cout << N  <<std::endl;
        std::cout<<"call update<T,0>"<<std::endl;
    };

    template<typename T>
    void _update<std::enable_if<T==1>>()
    { 
        static constexpr size_t N = 1;
        std::cout << N  <<std::endl;
        std::cout<<"call update<T,1>"<<std::endl;
    };

    //template<int num>
    //using _update = input<Ty>::iupdate<num>

};



int main()
{

//    Object<int, 1> obj1;
//    Object<int, 2> obj2;

    input<double> i;
    i.update();

    // core::input<int> i;
    // i.get<1>(2);
    // i.set<3>(4);
    // i.update();

    return 0;
}