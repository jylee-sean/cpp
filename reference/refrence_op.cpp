#include <iostream>


/**
 * @brief 
 * https://stdbc.tistory.com/114
참조자(Reference)
할당된 하나의 메모리 공간에 다른 이름을 붙이는 것, 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름 (=별명)
포인터와의 차이
- 이미 선언되어 있는 변수에 대해서만 참조자 선언이 가능 = 참조자 선언과 동시에 누군가를 참조해야 한다.  = NULL값이 없다
- 한번 지정한 객체를 변경할 수 없다 
 */


int x = 10;
int& f2() 
{

	return x;
}
int main()
{

	int a = 10;

	int &r = a;


	std::cout << a <<std::endl;
	std::cout << r<<std::endl;


	std::cout<<	f2() <<std::endl;
	f2() = 20;

	std::cout<< f2() <<std::endl;

	return 0;
}