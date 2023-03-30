
#include <iostream>

class Point
{
private:
	int x, y;

public:	
	Point(int a = 0, int b= 0) : x(a), y(b) {}

	void set(int a, int b)
	{
		x= a;
		y= b;
	}
	void print() const // 상수 멤버 함수 : 안에서 모든 멤버를 상수처리
	{
		std::cout<< x << " , " << y <<std::endl;
	}
};

// 상수함수는 안정성때문에 필요한 것이 아님
// 상수 객체는 상수 멤버함수만 호출할 수 있음
// 상수 객체는 생각보다 많이 사용됨 
int main()
{
//	Point p(1,1);



	const Point p(1,1);
	// p.x = 10;    //error 값 바꿀 수 없음
	// p.set(10,20); //error 값 바꿀 수 없음
	p.print(); // error : 값을 변경하지 않음에도 error  호출 되게 하려면 반드시 상수함수로 선언해줘야함
	           //  (컴파일러에 함수 선언부분을 통해상수함수임을 알려줘야함)


	return 0;
}