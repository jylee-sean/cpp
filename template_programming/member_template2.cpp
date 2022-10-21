
#include <iostream>
#include <string>

using std::cout;
using std::endl;
/*멤버함수 템플릿 사용 예제*/


template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

//	Point(const Point& p) {} : 복사 생성자 (자신과 동일한 타입만 받을 수 있음)
//	Point(const Point<T>& p) {} : 복사 생성자 (자신과 동일한 타입만 받을 수 있음)
//	Point(const Point<int>& p) {}

    /* T가 U로 복사(대입) 가능하다면, point<T>도 point<U> 로 복사 (대입) 가능해야 함*/
	template<typename U>   // generic (복사) 생성자 : 임의 타입을 받을 수 있음 "coercion by member template"
	Point(const Point<U>& p) : x(p.x), y(p.y) {}

	template<typename> friend class Point;  // 다른 type 객체에 private 접근 (typename 변수 사용되지 않고 1개인것만 알려주므로 변수 선언 굳이 x)

	void print();
};

template<typename T>
void Point<T>::print()
{
	cout<<"x:"<<x<<"y:"<<y<<endl;
}

int main()
{
	// Point<int> p1(1, 2);  // ok
	// Point<int> p2 = p1;   // ok 복사 생성자

	// Point<double> p3 = p1;// error(타입 다름) 복사 생성자는 같은 타입에서만 동작
	// Point<double> p3 = p1; // int를 double 에 대입하려면, 다른 타입을 받는 생성자 정의&구현



/******************************************************/
	Point<double> p1(1.5, 2);  // ok
	//Point<int> p2 = p1;   // ok 복사 생성자

	//Point<double> p3 = p1;// error(타입 다름) 복사 생성자는 같은 타입에서만 동작
	Point<std::string> p3 = p1; // int를 double 에 대입하려면, 다른 타입을 받는 생성자 정의&구현

	cout<<"p1:";
	p1.print();
	cout<<"p3:";
	p3.print();

}