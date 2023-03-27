#include <string>
#include <type_traits>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}


    /* u type이  T type으로 변환 가능할 때만 사용 가능*/
	template<typename U> 
	requires std::is_convertible_v<U, T>
	Point(const Point<U>& p) : x(p.x), y(p.y) {} // std::string 객체가 int로 복사될 수 없으므로 error

	template<typename> friend class Point;
};

int main()
{

	Point<std::string> p1("1", "2");  

    // std::string 객체가 int로 복사될 수 없으므로 error
	Point<int> p2 = p1;
}

