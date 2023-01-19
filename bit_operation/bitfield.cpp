

#include <iostream>

using namespace std;


using value_type  = uint32_t;


union data {
    struct __attribute__((packed)) pack_t {
        value_type reserved : 20;
        value_type ergo1 : 2;
        value_type ergo2 : 2;
        value_type ergo3 : 2;
        value_type ergo4 : 2;
        value_type ergo5 : 2;
        value_type self_test : 2;
    } pack;
    value_type value;
};
static constexpr value_type ergo_stop = 0x0;
static constexpr value_type ergo_positive = 0x1;
static constexpr value_type ergo_negative = 0x2;
static constexpr value_type selftest_initiated = 0x1;

struct __attribute__((packed)) A
{
    uint16_t d16 : 2;
    uint32_t d32 : 4;


};

int main()
{


    data d;


    A a;
   
   a.d16 = 3;

   cout<<a.d16<<endl;
   // cout<<sizeof(a)<<endl;
   // cout<<sizeof(a.d16)<<endl;
   // cout<<sizeof(a.d32)<<endl;

    //cout<<sizeof(d.pack)<<endl;


    return 0;
}