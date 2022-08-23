#include "animal.h"



void cryout(Animal *pA)
{
    pA->cry();
}

int main()
{

    Dog *pDog = new Dog();
    Cat *pCat = new Cat();

    cryout(pDog);
    cryout(pCat);
 
    return 0;
}