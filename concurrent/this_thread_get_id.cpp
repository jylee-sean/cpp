#include <iostream>
#include <thread>

int main()
{
    std::cout << std::this_thread::get_id() << std::endl;

    std::thread::id tid1 = std::this_thread::get_id();
    std::thread::id tid2 = std::this_thread::get_id();
  
    tid1 == tid2;
    tid1 < tid2;

    std::hash<std::thread::id> h;

    std::cout << h(tid1) << std::endl;
}

// std::this_thread::id get_id() noexcept;
// 실행중인 현재 스레드 ID를 반환


// std::thread:id
// 스레드id 를 나타내는 가벼운 구조체
// cout으로 출력 가능하고 비교 연산 가능
// 정수로 변환 안됨
// std::hash<std::thread::id> 함수 객체 제공 - unordered 컨테이너에 키 값으로 사용가능

