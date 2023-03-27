#include <iostream>

/**
 * @brief 
 * operator new 와 new 는 다름 
 *  - new : 메모리 할당 + 생성자 호출
 *  - operator new : 메모리 할당(only)
 * 객체를 생성하되, 생성자를 호출하지 않을 수 있음
 * 
 */
using namespace std;
class Point
{
	 int x, y;

	 public:
	 //Point(){ cout<<"constructed"<<endl;}
	 Point() = delete;
	 ~Point(){ cout<<"destroyed"<<endl;}


	 void run()
	 {
		cout<<"run"<<endl;
	 }
};
int main()
{

	Point* p1;


	//p1 = new Point;   

	//객체를 생성하되, 생성자를 호출하지 않을 수 있음
	p1 = static_cast<Point*>(operator new(sizeof(Point)));

	cout<<p1<<endl;

	p1->run();
	return 0;
}