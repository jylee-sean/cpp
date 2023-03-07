#include <iostream>

// https://www.devoops.kr/57


/**
 * @brief 
 * 여기서 추가로 생각해볼 부분이 바로 virtual 함수다.
https://stdbc.tistory.com/124

클래스에 가상함수를 선언하면 가상함수테이블이 생성되고(어디에? 아마 코드영역..??) 클래스 내부적으로 가상함수테이블을 가리키는 포인터를 갖는다. (4 or 8바이트)
가상함수의 개수에 관계없이 포인터의 개수는 1개고, 클래스의 크기에 영향을 준다. (가상함수 개수 증가에 따른 클래스 크기 증가는 없음)
가상함수테이블은 클래스단위로 생성되고, 가상함수테이블 포인터는 인스턴스단위로 생성된다.
 */
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



class AA
{
public:

	virtual void Func1()
	{
		cout<<" A func1" << endl;
	}

	// virtual void Func2()
	// {
	// 	cout<<" A func2" << endl;
	// }

	// virtual void Func3()
	// {
	// 	cout<<" A func3" << endl;
	// }
};
/**
 * @brief 
 * 
 * @return int 
 */
int main()
{


	A* temp  = new B();

	temp->Func1();
	temp->Func2();


	A a;
	AA aa;


	cout<<sizeof(a)<<endl;	
	cout<<sizeof(aa)<<endl;

	return 0;
}