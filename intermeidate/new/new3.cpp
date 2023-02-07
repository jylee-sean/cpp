#include <iostream>

/**
 * @brief 
 * operator new - overriding
 * 
 */


using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void* operator new(size_t sz)
{
	cout << "my new" << endl;
	return malloc(sz);
}

void* operator new(size_t sz, const char* s, int n)
{
	cout << "my new2" << endl;
	return malloc(sz);
}

void operator delete(void* p) noexcept
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	//Point* p = new Point; // operator new( sizeof(Point))	
	Point* p = new("AA", 2) Point; // operator new( sizeof(Point), "AA", 2)	
	
	//Point* p = static_cast<Point*>(operator new(sizeof(Point),"aa",3));
	//Point* p = static_cast<Point*>(new(sizeof(Point),"aa",3));
	delete p;
}