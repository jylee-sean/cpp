
#include <iostream>
#include <stdio.h>
// case1 mutable 사용
// class Point
// {
// private:
// 	int x, y;
// 	// mutable 멤버 변수 : 상수 멤버함수 안에서도 값 변경 가능
// 	mutable char cache[16];
// 	mutable bool cache_valid = false;

// public:	
// 	Point(int a = 0, int b= 0) : x(a), y(b) {}

// 	const char* toString() const// 상수 멤버함수여야 하는 이유
// 	{
// 		//static char s[16];
// 		//sprintf(s, "%d, %d", x, y);  오버헤드가 크다고 가정 --> cache 도입
		
// 		if(cache_valid == false){
// 			sprintf(cache,"%d, %d", x,y );  // 멤버함수(cache, cache_valid를 변경할 수 없음)
// 			cache_valid = true;
// 		}
// 		return cache; 
// 	}
// };

// case 2
// x,y : 상수 멤버 함수에서 변하지 않은 멤버
// cache, cache_valid : 상수 멤버함수에서 변하는 멤버

// pCache 가 변하는 멤버 클래스를 가리키는 형태
struct Cache
{
	char cache[16];
	bool cache_valid = false;
};
class Point
{
private:
	int x, y;
	Cache* pCache;
public:	
	Point(int a = 0, int b= 0) : x(a), y(b) {
		pCache = new Cache;
	}
	~Point(){
		delete pCache;
	}
	const char* toString() const// 상수 멤버함수여야 하는 이유
	{
 		if(pCache->cache_valid == false){
			sprintf(pCache->cache,"%d, %d", x,y );  // 멤버함수(cache, cache_valid를 변경할 수 없음)
			pCache->cache_valid = true;
		}
		return pCache->cache; 
	}
};
int main()
{
	Point p1(1,1);

	std::cout <<p1.toString() <<std::endl;
	std::cout <<p1.toString() <<std::endl;



	return 0;
}