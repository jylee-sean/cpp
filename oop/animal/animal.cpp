#include "animal.h"


template<typename T>
void cryout(T *pA)  // void cryout(Animal *pA)
{
    dynamic_cast<Animal*>(pA)->cry();
}

int main()
{

    Dog *pDog = new Dog();
    Cat *pCat = new Cat();

    cryout(pDog);
    cryout(pCat);
 
    return 0;
}