#include <iostream>
#include <chrono>
#include <thread>
using namespace std::literals;


// std::this_thread::yield() : 다른 스레드에 실행 흐름을 양보(yield)
void mysleep(std::chrono::microseconds us)
{
    auto target = std::chrono::high_resolution_clock::now() + us;

    while (std::chrono::high_resolution_clock::now() < target)
        std::this_thread::yield();   //양보
} 

int main()
{
    mysleep(1s);
}