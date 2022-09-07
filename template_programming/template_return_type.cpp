#include <iostream>

// template<typename T>
// T add(const T& a, const T& b)
// {
// 	return a + b;
// }

// int main()
// {
// 	std::cout << add(3, 4) 		<< std::endl;
// 	std::cout << add(3.1, 4.3) 	<< std::endl;

// //	std::cout << add(3, 4.3) << std::endl  ;  // error
// 	std::cout << add<double>(3, 4.3) << std::endl;  
// }



/***
 * add return type
 * 1. 사용자가 직접 템플릿 인자로 전달
 * 2. auto, decltype사용
 * 3. type_traits 기술 사용 (std::common_type )
 */


// template<typename R, typename T1, typename T2>
// R add(const T1& a, const T2& b)
// {
// 	return a + b;
// }

// int main()
// {
// //	std::cout << add<int, double>(3, 4.3) << std::endl;
// //	std::cout << add(3, 4.3) << std::endl;

// 	std::cout << add<double, int, double>(3, 4.3) << std::endl;
// 	std::cout << add<double>(3, 4.3) << std::endl;
// }



template<typename T1, typename T2>
//decltype(a + b) add(const T1& a, const T2& b)
//auto add(const T1& a, const T2& b) -> decltype(a + b) // C++11
auto add(const T1& a, const T2& b)  // C++14
{
	return a + b;
}

int main()
{
	std::cout << add(3, 4.3) << std::endl;
}