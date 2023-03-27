

#include <iostream>

using namespace std;

class A
{
    A() = delete;
    A(int a){
        cout<<"generated"<<endl;
    }
};

struct B
{
    A a;
};
int main()
{

    B b;
    uint8_t val8 = 100;

    uint16_t val16= 100;


    uint32_t val32 = 200;

    uint64_t val64 = 300;


    // cout<<"uint32 "<< &val32 <<"  "<<&val32+1<<"  "<<&val32+2<<endl; // 4(4byte = 32/8) 씩 증가
    // cout<<"uint32 "<< &val32 <<"  "<<&val32+4<<"  "<<&val32+8<<endl; // 16 증가 , 32 증가
    // cout<<"uint32 "<< &val32 <<"  "<<&val32+16<<"  "<<&val32+32<<" "<< &val32+48 <<endl; // 16바이트 증가 , 32바이트 증가
    // cout<<"uint32 "<< &val32 <<"  "<<&val32+0x10u<<"  "<<&val32+0x20u<<"  "<<&val32+0x30u<<endl; // 16 증가 , 32 증가, 48 증가


    uint32_t arr[3] = {0,1,2};


    cout<<"arr[0] "<< &arr[0] << "  arr[1] "<< &arr[1] << "  arr[2] "<<&arr[2]<<endl; 
    // 0x00100000
    // cout<<"uint64 "<< &val64 <<"  "<<&val64+1<<"  "<<&val64+2<<endl;

    
    // cout<<"uint64 "<< &val64 <<"  "<<&val64+0x01u<<"  "<<&val64+0x02u<<endl;

    // cout<<"uint16 "<< &val16 <<"  "<<&val16+0x20u<<"  "<<&val16+0x02u<<endl;

    // cout<<"uint16 "<< &val16 <<"  "<<&val16+0x01u<<"  "<<&val16+0x02u<<endl;


    return 0;
}