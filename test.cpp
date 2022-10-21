

#include <cctype>
#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template<typename T, typename U>
struct Angle
{
    public:
        T x;
        U y;
};

template<typename T, typename U>
struct Length
{
    public:
        T x;
        U y;
};

// template<typename T, typename std::enable_if<std::is_same<T, int>::value, T>::type* = nullptr>
// T conv() {
//     cout<<"3.0"<<endl;
    
//     return 3;
// }

// template<typename T, typename std::enable_if<std::is_same<T, double>::value, T>::type* = nullptr>
// T conv() {
    
//     cout<<"4.0"<<endl;
//     return 4.0;
// }


// template<typename T, typename U>
// double conv(const Angle<T, U>& a) {


//     double value = 1.0;
//     cout<<"1.0"<<endl;
//     return value;
// }

// template<typename T, typename U>
// double conv(const Length<T, U>& l) {
//     double value = 1.0;
//     cout<<"2.0"<<endl;
//     return value;
// }
int main() 
{
    //conv();
    for(int i=0; i<10; i++){
        cout<<"print"<<endl;
        cout<<i<<endl;
    }
    return 0;
}