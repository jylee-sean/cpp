
#include <iostream>

using namespace std;

struct Point
{
    int x, y;

	Point()  { std::cout << "Basic constructor Point()" << std::endl; }
    Point(int a = 0, int b = 0):x(a),y(b) { std::cout << "Point()" << std::endl; }
    //Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
    
	//Point(const Point&) = delete;

	Point(const Point& pt)
	{ 
		this->x = pt.x;
		this->y = pt.y;
		std::cout << "copy constructor " <<this->x<<" "<<this->y << std::endl; 
	}
	
	//Point(const Point&) = delete;
	//Point(Point&& pt) = delete;
	//Point& operator=(Point&& pt) = delete;
	//Point& operator=(const Point& pt) = delete;
	Point(Point&& pt){ std::cout << "move constructor " << std::endl; }


	//constexpr Point& operator=(const Point&){ std::cout<<"called"<<std::endl; return *this; }
	~Point() { std::cout << "~Point()" << std::endl; }



	Point& operator=(const Point& pt) {cout<<"assign operator"<<endl; return *this;}
	Point& operator=(Point&& pt) {cout<<"move operator "<<endl; return *this;}

	// void show()
	// {
	// 	cout<< x<<" "<< y<<endl;	
	// }
	// const Point& foo()
	// {
	// 	//Point pt(1, 1);
	// 	return Point(1,1);
	// }


};



//https://dydtjr1128.github.io/cpp/2019/08/10/Cpp-RVO(Return-Value-Optimization).html



template<typename T>
class templateFoo
{
  private:
     std::string prev_name;
  public:

    templateFoo(const std::string& name): prev_name(name) {

        std::cout << "This is " << name << " constructor." << std::endl;
    }


  	templateFoo<T> handle(){
		return templateFoo<T>();
	}

};

class Foo {
public:
    Foo(const std::string& name) {
        this->name = name;
        std::cout << "This is " << name << " constructor." << std::endl;
    }
    ~Foo() {
        std::cout << "This is " << this->name << " desstructor." << std::endl;
	}

	//Foo(const Foo& rhs) = delete;
	//Foo& operator=(const Foo& rhs) = delete;


	// Foo(Foo&& rhs) {
  //       std::cout << "This is " << this->name << " move constructor." << std::endl;
	// };
    // Foo(const Foo& rhs) {
    //     this->name = rhs.name;
    //     std::cout << "This is " << rhs.name << " copy constructor." << std::endl;
    // }
    // Foo& operator=(const Foo& rhs) {
    //     std::cout << "This is " << this->name << " copy operator." << std::endl;
    //     return *this;
    // }


  template<typename T>
	templateFoo<T> handle(){
		return templateFoo<T>(name);
	}
	void getname()
	{
		cout<<"name: "<< name<<endl;
	}
private:
    std::string name;
};

//NRVO
Foo MakeFoo(const std::string& name) {
    Foo foo(name);
    return foo;
}

//RVO
Foo MakeFoo2(const std::string& name) {
    return Foo(name);
}



Point foof()
{
	Point res(123,456);   /* NRVO variable */
	cout<<"---"<<endl;
	return res;   // Point(static_cast<Point &&>(res));
}



int main()
{
	//dispatcher d{1};

	//d.handle().handle().handle();

	//Point p1(1,1);
	//Point p2(p1);

	//Point p1(Point(1,1));
	//Point p2 = p1;
 
	// Point p3(foof());  // Point p3(Point(123,456))
	// cout<<p3.x<<" "<<p3.y<<endl;

	auto foo = MakeFoo("foo1");
	//auto foo2 = MakeFoo2("foo2");
	//foo.handle().handle();
	// foo.getname();
	// foo2.getname();

    // std::cout << "---end---" << std::endl;


	return 0;
}