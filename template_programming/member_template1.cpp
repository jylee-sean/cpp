

#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;
template<typename T>
class Object
{
public:
	void mf1(int n) {cout<< "mf1: "<<typeid(n).name()<<n <<endl;}
	void mf2(T   n) {cout<< "mf2: "<<typeid(n).name()<<n <<endl;}  // 함수 템플릿이 아님: 클래스 템플릿의 멤버함수

	template<typename U> // 멤버 함수 템플릿(함수 자체가 템플릿)
	void mf3(U n);
};


/*멤버함수 템플릿의 외부 구현*/
template<typename T> template<typename U> 
void Object<T>::mf3(U n)
{
	cout<< "mf3: "<<typeid(n).name()<<n <<endl;
}


int main()
{
	Object<int>    obj1;
	Object<double> obj2;

	obj1.mf1(3);
	obj2.mf1(3);

	obj1.mf2(3);
	obj2.mf2(3.4);

	obj1.mf3(3);
	obj1.mf3(3.4);
}