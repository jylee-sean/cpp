#include <iostream>

using namespace std;
class Point
{	
	int x;
	int y;
	public:
		 Point() : x(0), y(0) {cout<<"default constructor"<<endl;}
		 Point(int a) : x(a), y(0) { cout<<"conversion constructor1"<<endl;}
		 Point(int a, int b ) : x(a), y(b) { cout<<"conversion constructor2"<<endl;}

		Point(const Point& p)
		{
			cout<<"copy constructor"<<endl;
		}

		// Point(const Point& p, int a)
		// {
		// 	cout<<"copy constructor"<<endl;
		// }


		Point& operator =(const Point& ref)
		{
			cout<<"assign operator"<<endl;
			return *this;
		}
		// explicit Point() : x(0), y(0) {cout<<"default constructor"<<endl;}
		// explicit Point(int a) : x(a), y(0) { cout<<"conversion constructor1"<<endl;}
		// explicit Point(int a, int b ) : x(a), y(b) { cout<<"conversion constructor2"<<endl;}
		//explicit Point(const Point& p) {cout<<"copy"<<endl;}

};
int main()
{

	Point p1(5);  // Point p1 = Point(5);
	Point p2 = 5; // Point p2 = Point(Point(5))		// 복사 생성자 호출 할 때, int -> Point type conversion (변환 생성자 호출)
													// explicit 인 경우, int-> Point type conversion 안됨 (명시적 형변환 해줘야함) -- Point p2 = Point(Point(5)) 이렇게 써주는건 상관없음

	// 궁금한것은 왜 복사 생성자 로깅이 안되는건가?
	//Point p2 = Point(Point(5));
	//Point p3 = p2; // p3.operator=(p2)


	// Point(5);
	// Point(Point(5));
	//Point(Point(5), 5);
	//Point();
	// Point();
	// Point(Point());
	//Point p22 = Point(Point(5)); 
	//Point();
	
	// Point p1 = Point(5);
	// Point p2 = Point(Point(5));
	// Point p3 = Point(p2);
	// p3 = p2;


	// Point p3(1,1);
	// //Point p4 = (1,1)  // error
	
	// Point p5{1,1};   // ok
	Point p6 = {1,1};  // ok (expicit -> error)

	// Point p7;
	// Point p8{};  // direct
	//Point p9 = {}; // copy. error


	return 0;

}