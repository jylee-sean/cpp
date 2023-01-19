#include <iostream>
#include <bitset>

using namespace std;
int main()
{

    uint32_t status = 0xFFFF;

    static constexpr uint32_t forward = 1u<<13;
    static constexpr uint32_t backward = 1u<<12;
    static constexpr uint32_t neutral = ~(3u<<12) ;


    cout<<forward<<endl;
    cout<<bitset<32>(forward)<<endl;
    cout<<hex<<forward<<endl;
    

    cout<<sizeof(unsigned int)<<endl;
    cout<<sizeof(int)<<endl;

    cout<<sizeof(uint16_t)<<endl;

    cout<<sizeof(size_t)<<endl;

    cout<<hex<<255u<<endl;

    //uint16_t val = 0x1010 & 255u;

    //uint16_t val = 10u & 255u;
    //cout<<hex<<val<<endl;


    //uint16_t val = 0x0000000100000001;

    //cout<val<<endl;
    //cout<< bitset<32>(status)  <<endl;

    //status &= ~(1u<<12)  ;


    //status &= neutral  ;

    //cout<<hex<< backward  <<endl;
    //cout<<bitset<32>(status) <<endl;

    




    return 0;
}