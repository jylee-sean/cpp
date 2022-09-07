
#include <iostream>


/*
* animal class를 정의하시오.
* animal을 상속받아 dog class를 정의하시오
* dog class에 bark method를 정의하시오.
* animal을 상속받아 cat class를 정의하시오
* cat class에 meow method를 정의하시오.
* cryout 함수를 cat pointer가 전달되는 경우 meow()를 dog pointer가 전달되는 경우 bark()를 호출되도록 구현하시오.
* dynamic_cast 적용
*/

class Animal
{
    public:
        //virtual void cry()=0;
        void cry(){
            std::cout<<"animal"<<std::endl;
        }
};



class Dog : private Animal
{
    public:
        void cry(){ std::cout<<"bark"<<std::endl;}
    
};


class Cat : public Animal
{
    public:
        void cry(){std::cout<<"meow"<<std::endl;}
    
};




