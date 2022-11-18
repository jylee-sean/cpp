
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


    /* Implementation that make it sleep until downloaded_pages.empty() is not true */
    for(int i=0; i< 3; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100*index));
        std::string content = "webpage: "+ std::to_string(i) + " from thread( "+std::to_string(index)+" )\n";

        //cout<<"producer called"<<endl;
        
        m->lock();
        downloaded_pages->push(content);
        m->unlock();

        //wake one of threads that are in sleep state. Nothing happended when all of threads are on working.
        cv->notify_one();
    }
}


/*
 * Basically 'unique_lock' is quite similar with 'lock_guard' 
 * different thing is that lock guard cannot make lock with its constructor only,
 * but unique_lock can make it lock again after unlock 
 */
void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
              int* num_processed, std::condition_variable* cv) {

    while(*num_processed<15){
        std::unique_lock<std::mutex> lk(*m);  // mutex's pointer ?


        // try to thinking about the reason why "*num_processed" needs to be checked. 
        cv->wait(lk, [&m, &downloaded_pages, num_processed]{
            return !downloaded_pages->empty(); /*|| *num_processed ==15;*/ });

        
        //if( *num_processed ==15 ){
        //    lk.unlock();
        //    return;
        //}

        std::string content = downloaded_pages->front();
        downloaded_pages->pop();

        (*num_processed)++;
        lk.unlock();
        std::cout<< (*num_processed) <<" "<<content;

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
    cv.notify_all();
    for(auto &thread:consumers){
        thread.join();
    }
}