

#include <iostream>


using namespace std;

enum Color
{
    red = 111,
    blue = 222,
    green = 333
};
class A
{
    public:

    enum class Color
    {
        red = 1,
        blue = 2,
        green = 3
    };

    enum class AdvancdedColor
    {
        red = 100,
        ablue = 200,
        agreen = 300
    };
    
    void funcA()
    {
        cout<< static_cast<int>(Color::red) <<" "<< static_cast<int>(AdvancdedColor::red) <<endl;
    }
};

class B
{
    public:

    enum Color
    {
        red = 11,
        blue = 22,
        green = 33
    };
    
    void funcB()
    {
        cout<< Color::red <<" "<< Color::blue <<" "<<Color::green <<endl;
    }
};

int main()
{
    A a;
    B b;
    a.funcA();
    //b.funcB();
    

    return 0;
}