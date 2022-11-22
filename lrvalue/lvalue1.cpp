#include <iostream>




using namespace std;

void foo(int &a){
    cout<<"int &" <<endl;    
}
void foo(const int &a) {
    cout<<"const int &" <<endl;
}
void foo(int && a) {
    cout<<" int &&" <<endl;
}
int main()
{

    int n = 0;
    n= 10;


//    ++n = 20; // 

//    cout<<n<<endl;

    //cout<< &n <<endl;
    //cout<< &&10 <<endl;

    int&& r2 = 100;


    foo(static_cast<int&&>(r2));

    cout<< static_cast<int&&>(r2) <<endl;



    return 0;
}