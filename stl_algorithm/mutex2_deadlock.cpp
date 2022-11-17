#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
#include <thread>

void worker1(std::mutex& m1, std::mutex& m2) {
  for (int i = 0; i < 10; i++) {
    m1.lock();
    m2.lock();
    std::cout << "Worker1 Hi! " << i << std::endl;

    m2.unlock();
    m1.unlock();
  }
}

void worker2(std::mutex& m1, std::mutex& m2) {

    while(true){
        if(m1.try_lock()){
            std::cout << "m1 locked!!! " <<  std::endl;            
            break;
        }        
    }
    for(int i=0;i< 10 ; i++){
        m2.lock();

        std::cout << "Worker2 Hi! " << i << std::endl;
        m2.unlock();
        m1.unlock();
    }

    
}


int main() {
  std::mutex m1, m2;  // 우리의 mutex 객체

  std::thread t1(worker1, std::ref(m1), std::ref(m2));
  std::thread t2(worker2, std::ref(m1), std::ref(m2));

  t1.join();
  t2.join();

  std::cout << "끝!" << std::endl;
}
