
/* ref: https://modoocode.com/271 */


#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


using std::memory_order_relaxed;
using namespace std;

void t1(std::atomic<int>* a, std::atomic<int>* b){

    b->store(1, memory_order_relaxed);
    int x = a->load(memory_order_relaxed);

    cout<< x <<endl;

}

void t2(std::atomic<int>* a, std::atomic<int>* b){

    a->store(1, memory_order_relaxed);
    int y = b->load(memory_order_relaxed);

    cout<< y <<endl;

}


int main()
{
    int i=0;
    while(i<1000){
    std::vector<std::thread> threads;

    std::atomic<int> a(0);
    std::atomic<int> b(0);

    threads.push_back(std::thread(t1, &a, &b));  
    threads.push_back(std::thread(t2, &a, &b)); 

    for(auto& thread : threads){
        thread.join();
    }
    i++;
    }

    return 0;
}