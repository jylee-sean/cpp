/*중요한 예제*/


#include <iostream>

using std::cout;
using std::endl;

struct static_member
{
	static_member()  {  cout << "static_member()"  <<  endl;}
	~static_member() {  cout << "~static_member()" <<  endl;}
};
struct instance_member
{
	instance_member()  {  cout << "instance_member()" <<  endl;}
	~instance_member() {  cout << "~instance_member()" <<  endl;}
};

struct Object
{
	instance_member m1;
	static static_member m2; 
};
static_member Object::m2;
//instance_member Object::m1; (compile error)

int main()
{
	 cout << "--------" <<  endl;
	//Object obj;
	 cout << "--------" <<  endl;
}

// 클래스의 static 멤버 데이터는 객체를 생성하지 않아도 메모리에 놓인다(static member가 user type이면 생성자 호출)


// class A
// {

// }

// class B
// {
// 	public:
// 		int value;
// }

// A B::value;