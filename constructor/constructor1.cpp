#include <iostream>

using namespace std;


class Point
{
	private:
		int _x;
		int _y;
	public:
		Point(){};
		Point(int x, int y) : _x(x), _y(y)
		{
			cout<<"constructor"<<endl;
		}
		Point(Point& cls)
		{
			this->_x = cls._x;
			this->_y = cls._y;
			cout<<"copy"<<endl;
		}

		//Point& 
		void operator=(Point& cls)
		{
			cout<<"assign"<<endl;
		
			this->_x = cls._x;
			this->_y = cls._y;

			//return *this;
		}

		void print()
		{

			cout<< _x <<" "<< _y <<endl;
		}

};
int main()
{

	Point p(1,2);
	
	Point p2 = p;

	Point p3;
	//p3.operator=(p2);

	cout<<"===="<<endl;
	Point p4 = p3 = p2;

	p.print();
	p2.print();
	p3.print();
	p4.print();
	return 0;
}