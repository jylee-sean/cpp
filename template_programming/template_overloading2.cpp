

#include <iostream>
#include <concepts>

/* require 조건을 만족할 때만 적용*/
template<typename T> requires std::integral<T>
T square(T a)
{
	std::cout << "integral" << std::endl;
	return a * a;
}

template<typename T> requires (!std::integral<T>)
T square(T a)
{
	std::cout << "not integral" << std::endl;
	return a * a;
}

int main()
{
	square(3);  
	square(3.4);
}