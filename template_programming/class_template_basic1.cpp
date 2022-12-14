#include <iostream>


/***
 * class를 class template으로 만드는 법
 * 1. class 앞에 template<typename T> 추가
 * 2. class 내부에서 필요한 곳을 T로 변경
 */
template<typename T>
class Vector
{
	T* ptr;
	std::size_t  size;
public:
	Vector(std::size_t sz) : size(sz)
	{
		ptr = new T[sz];
	}
	~Vector() { delete[] ptr; }

	T& operator[](std::size_t idx) { return ptr[idx];}
	
	Vector(const Vector&) = delete;
//	Vector(const Vector<T>&) = delete;  // 이게 맞지만, 멤버함수안에서는 위처럼 <T> 를 빼도 됨
};

//void fn(const Vector& v) {} // error
void fn(const Vector<int>& v) {} // ok

int main()
{
//	Vector v(10); // error
	Vector<int> v(10); // ok
	v[0] = 10;
	fn(v);
}