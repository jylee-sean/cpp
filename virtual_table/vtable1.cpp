#include <iostream>

// https://www.devoops.kr/57
using namespace std;

class A
{
public:
	virtual void Func1()
	{
		cout<<" A func1" << endl;
	}

	virtual void Func2()
	{
		cout<<" A func2" << endl;
	}
};
/**
 *  virtual table
 *      KEY            |    Value(address)
 *  void A::Func1()    |    0x1024
 *  void A::Func2()    |    0x2048
 */


class B : public A
{
public:
	virtual void Func1()
	{
		cout<<" B func1" << endl;
	}

	void Func3()
	{
		cout<<" B func3" << endl;
	}

};

/**
 *  virtual table
 *      KEY            |    Value(address)
 *  void B:;Func1()    |    0x3072     ---> replaced (override)
 *  void A::Func2()    |    0x2048
 *  void B::Func3()    |    0x4096
 */


int main()
{
	A* temp  = new B();

	temp->Func1();
	temp->Func2();

	return 0;
}