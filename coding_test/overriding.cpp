#include <iostream>

using namespace std;


template<typename T> class Base
{

	public:
		virtual void foo(const T a)
		{
			cout <<"base foo" <<endl;
		}
};

class Derived : public Base<int*>
{
	public:
		//가상함수 foo 재정의
		//derived foo 출력
		//override 사용 하지말 것
		virtual void foo(int* ptr) //override
		{
			cout<<"Derived foo"<<endl;
		}

};

class parent
{
	public:
		virtual void foo(int* ptr)
		{
			cout<<"parent"<<endl;
		}
};

class child : public parent
{
	public:
		virtual void foo(const int* ptr)
		{
			cout<<"child"<<endl;
		}
};


int main()
{
	// Base<int*> *p = new Derived;
	// p->foo(0); // "Derived foo"

	parent *p = new child;
	p->foo(0);

}