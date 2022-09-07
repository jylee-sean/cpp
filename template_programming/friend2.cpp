#include <iostream>

template<typename T>
class Point
{
	T x, y;
public:
	Point(T a, T b) : x(a), y(b) {}

	//												const Point<T>& pt); // 클래스 템플릿의 파라미터이므로 템플릿 함수가 아님 (일바함수임))
	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
	// 일종의 함수 선언이므로 선언밖에 없다는 링크에러 발생함 
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