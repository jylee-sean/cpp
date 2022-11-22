

typedef int& LREF;
typedef int&& RREF;

template<typename T> void foo(T& a){}

int main()
{   int n = 10;

    //foo<int&>(n);
    
    LREF r1 = n;      
    RREF r2 = 10;   
    LREF& r3 = n;     // int& + int&
    RREF& r4 = n;      // int&& + int&
    LREF&& r5 = n;        // int& + int&&
    RREF&& r6 = 10;     // int&& + int&&
    //int& && r7; // error

    foo<int>(n);
    foo<int&>(n);
    foo<int&&>(n);


    //foo(10);

}
