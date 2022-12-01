#include <iostream>
#include <functional>
#include <vector>

using namespace std::placeholders;

void printout(int a, int b)
{
    std::cout<< a*b << std::endl;
}

void printout2(int b)
{
    int a = 10;
    std::cout<< a*b << std::endl;
}
int main()
{

    std::vector<int> vec = {1,2,3,4,5};
    

    //for_each(vec.begin(), vec.end(), std::bind(&printout,10,_1));

    for_each(vec.begin(), vec.end(), printout2);

    return 0;
}

/*단항 함수 이항 함수 등 함수 시그니쳐가 고정인 경우, 바인딩을 통해서 시그니쳐를 맞춰줄 수 있음*/