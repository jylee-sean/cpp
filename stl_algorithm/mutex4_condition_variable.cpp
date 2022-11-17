
/*ref:  https://modoocode.com/270 */
#include <chrono>              // std::chrono::miliseconds
#include <condition_variable>  // std::condition_variable
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

using namespace std;
void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int index, std::condition_variable* cv) {

    for(int i=0; i< 3; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100*index));
        std::string content = "webpage: "+ std::to_string(i) + " from thread( "+std::to_string(index)+" )\n";

        //cout<<"producer called"<<endl;
        
        m->lock();
        downloaded_pages->push(content);
        m->unlock();
    }



}


void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int* num_processed, std::condition_variable* cv) {


    m->lock();
    while(*num_processed<15){
        if(downloaded_pages->empty()){

            m->unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        std::string content = downloaded_pages->front();
        downloaded_pages->pop();

        (*num_processed)++;
        m->unlock();
        std::cout<<content;

        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }

}


int main()
{
    std::queue<std::string> downloaded_pages;
    std::mutex m;
    std::condition_variable cv;

    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    int index;
    int num_processed = 0;
    for(int i=0; i<5; i++){
        index = i+1;
        producers.push_back(std::thread(producer,&downloaded_pages, &m,index, &cv));
    }

    for(int i=0; i<4; i++){
        consumers.push_back(std::thread(consumer,&downloaded_pages, &m,&num_processed, &cv ));
    }

    for(auto &thread:producers){
        thread.join();
    }
    for(auto &thread:consumers){
        thread.join();
    }
}