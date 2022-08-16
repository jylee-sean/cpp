

#include <iostream>
#define TEXT "hello"

using namespace std;


void Swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a= b;
    b = tmp;

}

void Swap2(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a= *b;
    *b = tmp;

}


int main()
{

    int c = 2;
    int d = 3;

    cout << "c : " << c << ", d : " << d << endl;

    Swap(c, d);

    cout << "c : " << c << ", d : " << d << endl;


    Swap2(&c, &d);

    cout << "c : " << c << ", d : " << d << endl;

    return 0;
}

