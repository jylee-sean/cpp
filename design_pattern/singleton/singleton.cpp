#include <iostream>
#include <future>


// struct singleton_t
// {

//   static
//   singleton_t &
//   instance()
//   {
//     static singleton_t s;
//     return s;
//   } // instance

//   singleton_t(const singleton_t &) = delete;
//   singleton_t & operator = (const singleton_t &) = delete;

// private:

//   singleton_t() {}
//   ~singleton_t() {}

// }; // struct singleton_t



// thread safe singleton
// class singleton
// {
// 	private:
// 		singleton(){}
// 		~singleton(){}
// 	public:
// 		singleton(const singleton& ) = delete;
// 		singleton& operator=(const singleton&) = delete;
// 		static singleton& getinstance()
// 		{ 
// 			try
// 			{
// 				static singleton _instance;
// 				return _instance;
// 			}
// 			catch(...)
// 			{
// 				throw;
// 			}
// 		}
// };

//https://nerdooit.github.io/2020/06/17/design_pattern_sigleton_2.html

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds


// class MySingleton
// {
// private:
//   MySingleton() {/*std::cout<<"thread"<<std::endl;*/}
//   //MySingleton(const MySingleton&) = delete;
//   //void operator=(const MySingleton&) = delete;

//   static MySingleton* pInstance;
// public:

//   static MySingleton& getInstance()
//   {
//     if(pInstance == 0){
// 	  //std::cout<< t <<" seconds wait"<<std::endl;
// 	  //std::this_thread::sleep_for (std::chrono::seconds(t));	
	

// 	  pInstance = new MySingleton;
// 	}
//     return *pInstance;
//   }
// };

// MySingleton* MySingleton::pInstance = 0;



class MySingleton
{
private:
  MySingleton() {std::cout<<"thread"<<std::endl;}
  //MySingleton(const MySingleton&) = delete;
  //void operator=(const MySingleton&) = delete;
public:
  static MySingleton& getInstance()
  {
	static MySingleton pInstance;
    return pInstance;
  }
};








//C++11에서 정적 지역변수의 초기화는 멀티스레드 환경에서도 한 번만 수행됨이 보장
//https://stackoverflow.com/questions/72132929/how-to-test-a-singleton-generic-template-to-be-thread-safe


#include <iostream>
#include <thread>
#include <vector>
//#include "MySingleton.h" // include your Singleton class header file

#include <string>
#include <array>
void testSingleton()
{
    std::cout << "Testing Singleton..." << std::endl;
    // get the Singleton instance from multiple threads
    std::vector<std::thread> threads;

	std::vector<MySingleton*> vec;
    //std::vector<std::string> vec;

    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&]{
            MySingleton* instance = &MySingleton::getInstance();
            std::cout<< instance <<std::endl;
            //arr[i] = std::move(instance);

            //std::string str = std::to_string(instance);
            vec.emplace_back(instance);

			//
			//vec.emplace_back(std::to_string( static_cast<uint64_t>(instance)));
			// do something with the Singleton instance
            // ...
        });
    }


    for (auto& thread : threads) {
        thread.join();
    }

    int i=0;


    MySingleton* instance = &MySingleton::getInstance();

    for(auto& item : vec){
        std::cout<<"["<< i <<"] "<<instance <<", "<< item <<std::endl;
        i++;
        if(instance != item ){
            std::cout<<" different " << std::endl;
            break;
        }
        std::cout<<" all are same " << std::endl;
    }
	std::cout<<"--"<<std::endl;

	// for (auto instance : vec){
	// 	std::cout<<std::hex<<&instance << " "<< std::hex<< &MySingleton::getInstance() <<std::endl;
	// 	if (&instance != &MySingleton::getInstance()) {
    //     	std::cerr << "ERROR: Singleton instances do not match!" << std::endl;
    // 	}
	// }
    // check that the Singleton instance is the same for all threads
    // MySingleton* instance1 = &MySingleton::getInstance();
	// MySingleton* instance2 = &MySingleton::getInstance();
	// std::cout<< instance1 <<" "<< instance2 <<std::endl;
	// if (&instance1 != &instance2) {
    //     std::cerr << "ERROR: Singleton instances do not match!" << std::endl;
    // }

}

int main()
{
    testSingleton();
    return 0;
}
