#include <iostream>

// 객체의 상태를 변경하지 않는 '모든' 멤버함수는 (getXXX 류),
// 반드시 const 멤버함수가 되어야 한다

struct Rect
{
	int ox, oy, width, height;

	Rect(int x= 0, int y= 0, int w= 0, int h = 0): ox(x), oy(y), width(w), height(h){}

	int getArea() const { return width*height;}
};


void foo(const Rect& r) // call by value overhaed --> const & 가 좋음
{
	int n = r.getArea();  
}
int main()
{

	Rect r(0,0, 10, 10);

	int n= r.getArea();

	foo(r);
	return 0;
}