#include <iostream>


// https://welikecse.tistory.com/69
// https://huiyu.tistory.com/entry/C-%EB%B3%B5%EC%82%AC-%EC%83%9D%EC%84%B1%EC%9E%90%EC%9D%98-%ED%98%B8%EC%B6%9C%EC%8B%9C%EC%A0%90


using namespace std;
class Point
{	
	int x;
	int y;
	public:
		// explicit Point() : x(0), y(0) {cout<<"default constructor"<<endl;}
		// explicit Point(int a) : x(a), y(0) { cout<<"conversion constructor1"<<endl;}
		// explicit Point(int a, int b ) : x(a), y(b) { cout<<"conversion constructor2"<<endl;}
		Point(){}

		Point& operator =(const Point& ref)
		{
			cout<<"assign operator"<<endl;
			return *this;
		}
		Point( const Point& point) //= delete;
		{
			cout<<"copy constructor"<<endl;
		}


		// Point(Point&& point) //= delete;
		// {
		// 	cout<<"move constructor"<<endl;
		// }


		Point& foo()
		{
			return *this;
		}

		Point foo2(Point p2)
		{
			//Point p;
			cout<<"======"<<endl;
			return p2;
		}
};

Point p;
Point func()
{

    // return Point();
	
	//Point p;
	return p;
}
int main()
{

	//Point p;

    //Point pp = Point();
    Point p3;
	Point pp;
	p3.foo2(pp);

	//func();

	return 0;
}