#include <chrono>  // std::chrono::miliseconds
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>


void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, int index){

    for(int i=0; i<5 ; i++){

        // assumption for downloading web pages (it takes different time for each pages)
        std::this_thread::sleep_for(std::chrono::milliseconds(100*index));
        std::string content = "webpage: "+ std::to_string(i) + " from thread( "+std::to_string(index)+" )\n";
        
        // data is shared with all of threads, which means mutex is necessary
        //downloaded_pages 에 접근하는 쓰레드들 사이에 race condition 이 발생할 수 있음
        m->lock();
        downloaded_pages->push(content);
        m->unlock();
    }
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed){

    while(*num_processed <25){

        m->lock();

        if(downloaded_pages->empty()){
            m->unlock(); // if this instruction doesn't exist, it could cause deak lock.
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        std::string content = downloaded_pages->front();
        downloaded_pages->pop();

        (*num_processed)++;
        m->unlock();

        std::cout<< content;
        std::this_thread::sleep_for(std::chrono::microseconds(80));
    }


}


int main(){

    // 실행 흐름 ? main stream은 그대로 가는건지..(main흐름은 thread가 아닌건가? 이것도 실행흐름 아닌가)
    std::queue<std::string> downloaded_pages;
    std::mutex m;

    std::vector<std::thread> producers;
    for(int i=0;i<5;i++){
        producers.push_back(std::thread(producer, &downloaded_pages, &m, i+1));
    }

    int num_processed = 0;

    std::vector<std::thread> consumers;
    for(int i= 0; i<3; i++){
        consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_processed));
    }

    for(int i=0;i<5;i++){
        producers[i].join();
    }
    for(int i=0;i<3;i++){
        consumers[i].join();
    }

    



    return 0;
}