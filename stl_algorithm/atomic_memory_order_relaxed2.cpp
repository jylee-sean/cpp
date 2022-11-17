
/*
memory_order_relaxed 를 사용할 수 있었던 이유는, 
다른 메모리 연산들 사이에서 굳이 counter 를 증가시키는 작업을 재배치 못하게 막을 필요가 없기 때문
비록 다른 메모리 연산들 보다 counter ++ 이 늦게 된다고 하더라도 결과적으로 증가 되기만 하면 문제 될게 없기 때문
*/

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_relaxed;

void worker(std::atomic<int>* counter) {
  for (int i = 0; i < 10000; i++) {
    // 다른 연산들 수행

    counter->fetch_add(1, memory_order_relaxed);
  }
}
int main() {
  std::vector<std::thread> threads;

  std::atomic<int> counter(0);

  for (int i = 0; i < 4; i++) {
    threads.push_back(std::thread(worker, &counter));
  }

  for (int i = 0; i < 4; i++) {
    threads[i].join();
  }

  std::cout << "Counter : " << counter << std::endl;
}