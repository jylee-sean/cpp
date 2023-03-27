#include <iostream>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>

// 방법1 : 스레드동기화 https://m.blog.naver.com/sooftware/221424562029
// 방법2 : 상속 오버로딩


//thread sync. https://chrizog.com/cpp-thread-synchronization

using namespace std;
typedef std::chrono::steady_clock sclock;


class led;

class blinkmanager
{
    public:
 
        static blinkmanager& getInstance(){
            static blinkmanager bm;
            return bm;
        }
        void regist(led* instance)
        {
            
        }

        void run()
        {
            
        }

    private:
        blinkmanager(){ run(); }
        blinkmanager(const blinkmanager& ref){}
        blinkmanager& operator=(const blinkmanager& ref){return *this;}
        ~blinkmanager(){}



};

class blinker
{
    public:
        void blinkblink(){

        }
};
class led : blinker
{
    public:
        void set()
        {
            cout<<"set"<<endl;
        }

        void blink(std::string name)
        {   

            //blinkmanager& bm = blinkmanager::getInstance();
            //bm.regist(this);
            cout<<"blinking registed "<<name<<endl;

        }

    private:

};

int main()
{
    //Timer timer;
    //blinkmanager bm;

    //std::thread bm_thread([&]{bm.blinking();}); // or &blinkmanager::blinking ?


    led iled;
    led pled;

    iled.blink("iled");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    pled.blink("pled");

    cout<<"keep going"<<endl;
    
    
    //for(int i = 0 ; i < 2; i++)
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    //pled.blink();



    //blink_thread.join();
    return 0;
}