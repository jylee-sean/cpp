

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>


using namespace std;
using namespace std::chrono_literals;


class spider
{
public:
    int data;
    
    void setdata(int value)
    {
        data =value;
    }
    
    int getdata()
    {
        return data;
//        std::this_thread::sleep_for(500ms);
//        cout<<"\t data2: "<< data<<endl;
    }
    
    void increase(){
        data++;
    }
    
    std::mutex m;
}s;
void while_loop()
{
    int cnt = 0;
    while(true)
    {
        
        std::this_thread::sleep_for(300ms);
        //cout<< "cnt : " << cnt << endl;
        
        //s.setdata(cnt);
        s.increase();
        cout<<"data1:"<< s.getdata()<<endl;
        
        cnt++;
        if(cnt==1000)
            break;
    }
    
}

void while_loop2()
{
    int cnt = 0;
    while(true)
    {
        
        std::this_thread::sleep_for(900ms);
        //cout<< "cnt : " << cnt << endl;
        
        //s.setdata(cnt);
        s.increase();

        cout<<"\t data2:"<< s.getdata()<<endl;

        cnt++;
        if(cnt==1000)
            break;
    }
    
}


int main()
{
    
    //spider s;
    std::thread t(&while_loop);
    std::thread t2(&while_loop2);
    
    while(true)
    {
        std::this_thread::sleep_for(600ms);
        
        s.increase();
        //s.print(1);
        cout<<"\t\t data3:"<< s.getdata()<<endl;

        std::cout<<"\t\t data" << std::endl;
    }
    
    
    t.join();
    
    return 0;
}
