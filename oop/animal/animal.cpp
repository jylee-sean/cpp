#include "animal.h"


template<typename T>
void cryout(T *pA)  // void cryout(Animal *pA)
{
    dynamic_cast<Animal*>(pA)->cry();
}

int main()
{

    // Dog *pDog = new Dog();
    // Cat *pCat = new Cat();

    // cryout(pDog);
    // cryout(pCat);

    // Animal *pA;

    // pA = pDog;

    // pA->cry();

    // pA = pCat;
    // pA->cry();


    //Animal *pA = new Dog();

    // Dog *pDog;

    // pDog = dynamic_cast<Dog*>(pA);

    // pDog->cry();


    //Cat cat;
    Dog dog;

    dog.cry();


    return 0;
}