#include <iostream>

// 동일한 버전 함수와 템플릿이 있을때 함수가 우선된다
// 함수가 선언만 있다면? 함수 구현부가 없어서 링크 에러 발생

template<typename T> 
void fn(T a)   { std::cout << "T" << std::endl; }

void fn(int n);// { std::cout << "int" << std::endl;}

int main()
{
	fn(3);
}