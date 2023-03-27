
/**
 * C++ template 종류
 * 
 * 1. function template
 * 2. class template
 * 3. variable template
 * 4. using template (template alias)
 */
#include <iostream>

//constexpr double pi = 3.141592; ( 전역 변수(상수))

template<typename T>
constexpr T pi = static_cast<T>(3.141592); // T type의 pi라는 이름의 상수

int main()
{
//	double area1 = 3 * 3 * pi;

	double area1 = 3 * 3 * pi<double>;
					//static_cast<double>(3.141592);

	double area2 = 3 * 3 * pi<float>;
}

//왜 언제 쓰는가
// template specialization 문법과 같이 사용
// type_traits구현의 핵심 문법
// 실제 STL 구현에서 다양하게 활용되고 있음