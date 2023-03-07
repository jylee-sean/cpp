
#include <iostream>

using namespace std;

struct Point
{
    int x, y;
    Point(int a = 0, int b = 0):x(a),y(b) { std::cout << "Point()" << std::endl; }
    Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
    
	//Point(const Point&) = delete;

	Point(Point&& instance){ std::cout << "conversion constructor " << std::endl; }


	//constexpr Point& operator=(const Point&){ std::cout<<"called"<<std::endl; return *this; }
	~Point() { std::cout << "~Point()" << std::endl; }


	void show()
	{
		cout<< x<<" "<< y<<endl;	
	}
	const Point& foo()
	{
		//Point pt(1, 1);
		return Point(1,1);
	}


};



int main()
{
	Point ret{0, 0};

	//ret.show();
	//Point pt;

	// cout<<pt.foo().x<<endl;
	//const Point &ref = pt.foo();

	
	//Point pt{0,0};
	
	Point pt{Point{1,1}};

	//pt.foo();

	//cout<<ref.x<<" "<<ref.y<<endl;

	//ret = pt.foo();
	//cout<<ret.x<<" "<<ret.y<<endl;


	//cout << endl;
    cout << "end" << endl;

	return 0;
}