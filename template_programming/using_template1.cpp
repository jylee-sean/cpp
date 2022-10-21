#include <unordered_set>

//typedef std::unordered_set<int> SET;
//typedef std::unordered_set<double> SETD;

// type alias
// using SET = std::unordered_set<int>;


// c++11 부터 typedef 대신 using 사용
// 타입 별칭 (alias) 만드는 방법
// 1. c style : typedef std::unordered_set<int> SET;
// 2. c++ style : using SET = std::unordered_set<int>;

template<typename T> 
using SET = std::unordered_set<T>;


int main()
{
//	std::unordered_set<int> s1;
//	std::unordered_set<double> s2;

	SET<int> s1;
	SET<double> s2;
}