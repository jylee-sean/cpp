#include <iostream>

struct static_member
{
	static_member()  { std::cout << "static_member()"  << std::endl;}
	~static_member() { std::cout << "~static_member()" << std::endl;}
};
struct instance_member
{
	instance_member()  { std::cout << "instance_member()" << std::endl;}
	~instance_member() { std::cout << "~instance_member()" << std::endl;}
};

template<typename T> 
struct Object
{
	instance_member m1;
	static static_member m2; 
};
template<typename T> static_member Object<T>::m2;

int main()
{
	std::cout << "--------" << std::endl;
	Object<int> obj;
//	obj.m2;
	std::cout << "--------" << std::endl;
}


// 템플릿 객체만 만들고 멤버함수 호출하지 않았을 때, static 멤버가 메모리에 올라갈까?
// obj.m2해야 static (멤버함수 뿐 아니라 static 멤버 데이터에도 접근하지 않으면, 메모리 안잡힘(생성자 안불림))

// template 클래스 static constructor로 초기화 하는것 주의