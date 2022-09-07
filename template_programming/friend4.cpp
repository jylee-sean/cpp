#include <iostream>

template<typename T>
class Point
{
	T x, y;
public:
	Point(T a, T b) : x(a), y(b) {}

//	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
//	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Point<U>& pt); // U가 임의의 타입이므로 모든 타입과 ㄹ갸둥 관계가 됨
	// 하지만, point<int> 는 operator<<(Point<int>) 만 friend 관계이면 됨
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& pt)
{
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}

int main()
{
	Point<int> p(1,2);
	std::cout << p << std::endl;
}
