// memory_order_seq_cst: 메모리 명령의 순차적 일관성 보장 - 명령 재배치x


#include <atomic>
#include <iostream>
#include <thread>

std::atomic<bool> x(false);
std::atomic<bool> y(false);
std::atomic<int> z(0);


/*일단, write_x 와 read_x_then_y 사이의 release - acquire 동기화와, 
write_y 와 read_y_then_x 사이의 release - acquire 동기화가 이루어지고 있음을 알 수 있습니다.
그렇다고 해서, read_x_then_y 와 read_y_then_x 두 쓰레드가 같은 순서로 
x.store 와 y.store 를 관찰한다는 보장이 없습니다. 
다시 말해 read_x_then_y 의 입장에서는 x.store 가 y.store 보다 먼저 발생해도 되고, 
read_y_then_x 입장에서는 y.store 가 x.store 보다 먼저 발생해도 된다는 것입니다.
이 경우 두 if 문 안의 load 가 false 가 되어서 z 가 0 이 되겠지요.
*/
/*case1 : z가 0이 나올 수도 있음 */
// void write_x() { x.store(true, std::memory_order_release); }
// void write_y() { y.store(true, std::memory_order_release); }

// void read_x_then_y() {
//   while (!x.load(std::memory_order_acquire)) {
//   }
//   if (y.load(std::memory_order_acquire)) {
//     ++z;
//   }
// }

// void read_y_then_x() {
//   while (!y.load(std::memory_order_acquire)) {
//   }
//   if (x.load(std::memory_order_acquire)) {
//     ++z;
//   }
// }


/*memory_order_seq_cst 를 사용하게 된다면, 
해당 명령을 사용하는 메모리 연산들 끼리는 모든 쓰레드에서 동일한 연산 순서를 관찰할 수 있도록 보장해줍니다. 
참고로 우리가 atomic 객체를 사용할 때, memory_order 를 지정해주지 않는다면 
디폴트로 memory_order_seq_cst 가 지정이 됩니다. 
예컨대 이전에 counter ++ 은 사실 counter.fetch_add(1, memory_order_seq_cst) 와 동일한 연산입니다.

문제는 멀티 코어 시스템에서 memory_order_seq_cst 가 꽤나 비싼 연산이라는 것입니다. 
인텔 혹은 AMD 의 x86(-64) CPU 의 경우에는 사실 거의 순차적 일관성이 보장되서 memory_order_seq_cst 를 강제하더라도 
그 차이가 그렇게 크지 않습니다. 
하지만 ARM 계열의 CPU 와 같은 경우 순차적 일관성을 보장하기 위해서는 CPU 의 동기화 비용이 매우 큽니다. 
따라서 해당 명령은 정말 꼭 필요 할 때만 사용해야 합니다

x.store 와 y.store 가 모두 memory_order_seq_cst 이므로, 
read_x_then_y 와 read_y_then_x 에서 관찰했을 때 x.store 와 y.store 가 같은 순서로 발생해야 합니다. 
따라서 z 의 값이 0 이 되는 경우는 발생하지 않습니다

*/
/*case2 : z = 0 미발생 */


void write_x() { x.store(true, memory_order_seq_cst); }

void write_y() { y.store(true, memory_order_seq_cst); }

void read_x_then_y() {
  while (!x.load(memory_order_seq_cst)) {
  }
  if (y.load(memory_order_seq_cst)) {
    ++z;
  }
}

void read_y_then_x() {
  while (!y.load(memory_order_seq_cst)) {
  }
  if (x.load(memory_order_seq_cst)) {
    ++z;
  }
}

int main() {
  thread a(write_x);
  thread b(write_y);
  thread c(read_x_then_y);
  thread d(read_y_then_x);
  a.join();
  b.join();
  c.join();
  d.join();
  std::cout << "z : " << z << std::endl;
}


/*결론
C++ 에서 atomic 연산들에 대해 memory_order 을 지정하는 방법에 대해 알아보았습니다. 
C++ atomic 객체들의 경우 따로 지정하지 않는다면 기본으로 memory_order_seq_cst 로 설정되는데, 
이는 일부 CPU 에서 매우 값비싼 명령 입니다. 만약에 제약 조건을 좀 더 느슨하게 할 수 있을 때 
더 약한 수준의 memory_order 을 사용한다면 프로그램의 성능을 더 크게 향상 시킬 수 있습니다.

*/