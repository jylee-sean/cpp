
#include <iostream>
#include <bitset>

using namespace std;

struct siis_obj
{

    struct general_info
    {
        uint64_t serial_number;
        uint32_t year;
        uint32_t date;  
    }_gi;
};

struct siis{

    struct data
    {
        siis_obj::general_info _gi;
    };
    struct write
    {
        write(const uint32_t arm_no, const uint32_t value)
        {

            cout<<"32bit "<<arm_no<<" "<<value<<endl;
        }

        write(const uint32_t arm_no, const uint64_t value)
        {

            cout<<"64bit "<<arm_no<<" "<<value<<endl;
        }
    };

    private:
        write w;

};



int main()
{
    uint32_t d32 = 0xf1234567;
    uint64_t d64 = 0xf123456788881111;

    uint32_t value = 77;

    siis s;
    siis_obj so;
    siis::write(3, , value);

    return 0;
}
