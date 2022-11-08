#include <iostream>
#include <stack>



int main()
{
    int y = 32;

    auto ans = [y]()constexpr{
        int x = 10;
        return x+y;
    };

    int ret = ans();

    std::cout<<ret<<std::endl;

    return 0;
}