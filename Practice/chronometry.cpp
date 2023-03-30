#include <iostream>
#include <thread>
#include <string>
#include <functional>

using namespace std::literals;


/**
 * 가변인자 template
 * decltype(auto)
 * r value reference
 * invoke
 * perfect  forward
 * 멤버함수 포인터와 this
 * 임시객체
 * 사용자 정의 literal
*/

class stop_watch
{

	std::string message;
	std::chrono::high_resolution_clock::time_point start;

	public:
	inline stop_watch(std::string msg =""): message(msg){start = std::chrono::high_resolution_clock::now();}
	inline ~stop_watch()
	{
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end-start);
		std::cout<< message << " " <<time_span.count() << " seconds" << std::endl;
	}
};
template<typename F, typename ...A>
decltype(auto) chronometry(F&& f, A&& ... args)
{
	stop_watch sw;
	return std::invoke(std::forward<F>(f), std::forward<A>(args)...);
}

class Hello
{
	std::string msg;
	public:
		Hello(std::string s) : msg(s){}
		void Say()
		{
			std::cout<< msg <<std::endl;
			std::this_thread::sleep_for(3s);
			std::cout << "bye..." <<std::endl;
		}
};

int main()
{
	chronometry(&Hello::Say, Hello("hello"s));

	return 0;
}
