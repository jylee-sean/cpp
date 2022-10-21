#include <memory>

class Animal { int age; };

class Dog : public Animal {};

int main()
{
	std::shared_ptr<Dog> p1(new Dog);
	
	//파싱클래스의 주소는 기반 클래스 주소로 가리킬 수 잇어야함 
	std::shared_ptr<Animal> p2 = p1;// (shared ptr에 generic 생성자가 구현되어 있음)
}


/***
 * member function template 기본 모양
 * coercison by member template 기술
 * 
 */