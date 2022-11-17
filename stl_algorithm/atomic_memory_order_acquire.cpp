/* 
1. memory_order_release 는 해당 명령 이전의 모든 메모리 명령들이 해당 명령 이후로 재배치 되는 것을 금지
2. 또한, 만약에 같은 변수를 memory_order_acquire 으로 읽는 쓰레드가 있다면, 
    memory_order_release 이전에 오는 모든 메모리 명령들이 해당 쓰레드에 의해서 관찰 될 수 있어야 함

즉, is_ready->store(true, std::memory_order_release); 밑으로 *data = 10 이 올 수 없게됨

3. cosnumer 쓰레드에서 is_ready 를 memory_order_acquire 로 load 하고 있기에, 
  is_ready 가 true 가 된다면, data 는 반드시 10 이어야 함
4. memory_order_acquire 의 경우, 
   release 와는 반대로 해당 명령 뒤에 오는 모든 메모리 명령들이 해당 명령 위로 재배치 되는 것을 금지 
*/

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_release;
using std::memory_order_acquire;

void producer(std::atomic<bool>* is_ready, int* data) {
  *data = 10;
  is_ready->store(true, memory_order_release);
}

void consumer(std::atomic<bool>* is_ready, int* data) {
  // data 가 준비될 때 까지 기다린다.
  while (!is_ready->load(memory_order_acquire)) {
  }

  std::cout << "Data : " << *data << std::endl;
}

int main() {
  std::vector<std::thread> threads;

  std::atomic<bool> is_ready(false);
  int data = 0;

  threads.push_back(std::thread(producer, &is_ready, &data));
  threads.push_back(std::thread(consumer, &is_ready, &data));

  for (int i = 0; i < 2; i++) {
    threads[i].join();
  }
}