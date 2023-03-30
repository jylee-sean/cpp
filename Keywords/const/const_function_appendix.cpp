#include <iostream>

struct Test
{
	void foo() { std::cout<<"foo() "<< std::endl;} // 1
	void foo() const { std::cout<<"foo() const"<< std::endl;} // 2


	void goo() const;
};

void Test::goo() const // 반드시 const 키워드 붙여야함
{
	
}
int main()
{


	Test t1;
	t1.foo(); // 1 , 없으면 2

	const Test t2;
	t2.foo(); // 2, 없으면 error


	return 0;
}