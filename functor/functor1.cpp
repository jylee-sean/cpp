

#include <random>
#include <iostream>

using namespace std;

class Urandom
{
    std::bitset<10> bs;
    bool recycle;

    std::mt19937 randgen{std::random_device{}()};
    std::uniform_int_distribution<int> dist{0,9};
  public:
    Urandom(bool recycle = false) : recycle(recycle){
        bs.set();
     }
     int operator()(){
        int k = -1; 
        while( !bs.test(k=dist(randgen) )) ;
        bs.reset(k);
        cout<<bs<<endl;
        return k;
    }     
};
Urandom urand;



int main()
{

    for (int i= 0; i< 10; i++)                    
       std::cout << urand() <<endl;; 
    
    //std::cout<<std::endl;

    return 0;
}
