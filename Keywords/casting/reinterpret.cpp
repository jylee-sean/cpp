
#include <iostream>

int main()
{
    int Num = 5;
    float *p  = new float;

    // num 에 있는 데이터를 단순히 float 형 포인터가 가리키고 있는 메모리에 복사할 경우, 정상 출력 안됨
    // int 에서 5을 저장하는 방식과 float 에서 5를 저장하는 방식은 다르기 때문
    //memcpy(p &Num, sizeof(float) < sizeof(int) ? sizeof(float): sizeof(int));
    //std::cout<<*p <<std::endl;


    // 위 케이스와 완전히 동일한 동작
    float real;
    real = *(reinterpret_cast<float*>(&Num));
    std::cout<<real <<std::endl;




    delete p;
    return 0;
}