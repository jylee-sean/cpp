#include <iostream>
#include <cstdlib> /* it contains abort() function */

double hmean(double a, double b);

int main()
{   
    double x, y, z;
    std::cout<<"두수를 입력:"<<std::endl;

    while(std::cin>>x>>y)
    {
        z = hmean(x,y);
        std::cout<<x<<","<<y<<"의 조화평균"<<":"<<z<<std::endl;

        std::cout<<"두 수입력하세요(종료하려면 q)"<<std::endl;
    }
    return 0;


}

double hmean(double a, double b)
{
    if (a==-b)
    {
        std::cout<<"매개변수들을 hmean()에 전달할 수 없습니다"<<std::endl;
        std::abort();
    }
    return 2.0*a*b/(a+b);
}