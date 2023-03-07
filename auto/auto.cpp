#include <iostream>

int main()
{

	int n = 10;
	int&r = n;
	const int c = n;
	const int& cr = c;

	/* auto 는 값 복사 방식 */

	//  auto 를 값 타입으로 사용할 때, 우변 수식이 가진 reference, const, volatile속성 제거하고 타입 결정
	auto a1 = n;    // int
	auto a2 = r;    // int
	auto a3 = c;    // int 
	auto a5 = cr;	// int

	//  auto를 참조 타입으로 사용할 때, 우변 수식이 가진 reference 속성만 제거되고 const, volatile 속성은 유지
	auto& a5 = n;
	auto& a6 = r;
	auto& a7 = c;
	auto& a8 = cr;

	// 변수 자체의 const 속성만 제거됨
	const char* s1 = "hello";    // s1 자체는 const 아님, s1을 따라가면 const
 	auto a9 = s1;      // const char*
	const char* const s2 = "hello";
	auto a10 = s2;     // const char*

	return 0;

}
