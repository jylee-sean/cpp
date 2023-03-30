#include <iostream>
#include <cstring>

int main()
{
	const char* str = "Hello";
//	const char* str = "Hello, world!";

	int length = strlen(str); // 13

	std::cout<< length <<std::endl;
	return 0;
}