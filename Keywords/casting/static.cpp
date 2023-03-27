

#include <iostream>
#include <bitset>
using namespace std;

class MyFloat
{
    public:
        float real;

};
class MyDouble
{
    public:
        double dreal;

};



class MyInt
{
    public:
        int Num;
    operator MyFloat(void)
    {
        MyFloat real = {static_cast<float>(Num)};

        return real;
    };
    operator MyDouble(void)
    {
        MyDouble d = {static_cast<double>(Num)};

        return d;
    };
};

//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=wkdghcjf1234&logNo=220210906503

int main()
{
    // case 1. 정상동작 (static cast에서 정수->실수 변환에서 일어나는 비트 연산을 자동으로 수행해줌)
    
    //float real = 4123.1f;

    // cout<<hex<<num <<" "<<hex<<real <<endl;
    // real = static_cast<float>(num);
    // cout<<hex<<num <<" "<<hex<<real <<endl;
    

    // cout<<hex<<num<<endl;
    uint32_t num = 2946635;
    uint32_t *p32 = &num; // new uint32_t(6635);
    uint8_t *p8;

    uint8_t value8;
    int i;
    cout<<*p32<<endl;

// auto var = *addr;
// ld addr
// ldh 
// ldb addr
// ror val, 18
// and val, 0xff
p8 = reinterpret_cast<uint8_t*>(p32); // 비트를 유지


//int*(d) = static_cast<int>(d) 
// uint32 >> 8 & 0xff;

     cout<<hex<<p32<<endl;
     cout<<hex<<static_cast<long>(p8)<<endl;
    for(i=0; i<4; i++){
        //cout<<hex<< "num = " << &num+i<<endl;
        cout<<hex<< "char val = " << static_cast<int>(*(p8+i))<<endl;// " address: "<<hex<<static_cast<int>(p8+i) <<endl;
        
        value8 = static_cast<uint8_t>(*(p32+i)); /// 주소값 4바이트씩 증가..
        cout<<hex<<static_cast<int>(value8) <<" address: "<< (p32+i)<<endl;

        cout<<hex<<*(p32+i)<<endl;
        
    }

    // case2 . static_cast는 형변환 함수를 호출함

    // MyInt n = {100};
    // MyFloat r ={0.f};
    // MyDouble d;

    // d = static_cast<MyDouble>(n);

    // cout<<d.dreal<<endl;




    return 0;
}



