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
	 Point(){ cout<<"constructed"<<endl;}
	 //Point() = delete;
	 ~Point(){ cout<<"destroyed"<<endl;}


	 void run()
	 {
		cout<<"run"<<endl;
	 }
};


// override
// void* operator new(size_t sz)
// {
// 	cout<< "my new  " << sz<< endl;

// 	return malloc(sz);
// }

// override
// void operator delete(void *p ) noexcept
// {
// 	cout <<"my delete" <<endl;
// 	free(p);
// }
int main()
{

	Point* p1;


	//p1 = new(Point);   
	//p1 = new Point;
	p1 = static_cast<Point*>(operator new (sizeof(Point)));
	//p1 = operator new(Point);
	cout<<p1<<endl;
	p1->run();

	//delete(p1);
	delete p1;
	return 0;
}