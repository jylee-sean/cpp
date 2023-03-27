
#include <iostream>

using namespace std;
class A
{
    public:
    
    A()
    {
        cout<<"generated"<<endl;
        
    }
    void set()
    {
        cout<<"set in A"<<endl;
    }


}a;

struct general_info
{
    uint64_t serial_number;
    uint32_t year;
    uint32_t date;
};
int main()
{

    general_info gi;
    uint32_t romdata[4] ={35u, 5u, 255u, 65u};
    // gi ={0x0000000012345678<<32u | 0x87654321,
    //      0x12345678,0x12345678};

    gi ={romdata[0]<<16u | romdata[1] ,
         romdata[3],romdata[4]};


    cout<<hex<<gi.serial_number<<endl;
    cout<<hex<<gi.year<<endl;
    cout<<hex<<gi.date<<endl;




    // A b;    
    // b.set();

    // a.set();


    return 0;
}