

#include <iostream>
using namespace std;

class Base
{
public:
//	Base()      { cout << "B()"    << endl; }
	Base(int a) { cout << "B(int)" << endl; }
	~Base()     { cout << "~B()" << endl; }
};
class Derived : public Base
{
public:
	Derived() : Base()
	{
		cout << "D()" << endl; 
	}
	Derived(int a) : Base(a)
	{ 
		cout << "D(int)" << endl; 
	}
	~Derived()      { cout << "~D()" << endl; }
};

int main()
{
	Derived d(5);
}