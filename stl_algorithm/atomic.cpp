



#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


int counter;

void worker(/*std::atomic<int>& int& counter*/)
{
    for(int i=0;i <10000; i++){
        counter++;
    }
}


int main()
{
    //std::atomic<int> counter{0};

    //int counter = 0;

    std::vector<std::thread> workers;

    for(int i= 0;i <4 ; i++){
        //workers.push_back(std::thread(worker, std::ref(counter)));

        workers.push_back(std::thread(worker));
    }

    //for(int i=0; i<4 ; i++){
    //    workers[i].join();
    //}
    for(auto& worker: workers)
        worker.join();    

    std::cout<< counter <<std::endl;
    return 0;
}