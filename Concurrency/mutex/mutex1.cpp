#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
#include <thread>
#include <vector>


using namespace std;

void worker(int& cnt, std::mutex& m)
{
    for(int i=0;i<10000; i++){
        //m.lock();
        
        std::lock_guard<std::mutex> lock(m);
        cnt++;
        //m.unlock();
    }

}


int main()
{

    int counter = 0;
    std::mutex m;

    std::vector<std::thread> workers;

    for(int i=0 ;i<4 ; i++){
        workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)) );
    }

    for(int i=0;i<4 ; i++){
        workers[i].join();
    }

    cout<< counter <<endl;

    return 0;
}