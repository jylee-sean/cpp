#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
using namespace std;


class led;

struct Subject
{
    vector<led*> v;
    virtual ~Subject() {}
};

class led 
{
    std::string _name;
    int _color;

public:
    bool _blinking;

    led():_blinking(false){}

    int GetColor() { return _color;}
    std::string GetName() { return _name;}

    void SetData(std::string s, int c)
    {
        _name = s;
        _color = c;
    }

    void blink()
    {
        _blinking = true;

    }

    void set()
    {
        _blinking = false;
        
    }

    void update()
    {
        if(_blinking){
            cout << "blinking:" << _name <<endl;
        }
    }

};



class BlinkManager : public Subject
{
public:
    void attach(led* led_instance)
    {
        v.push_back(led_instance);    
    }

    void run()
    {
        while(true){
            int n;
            cin>> n;
            for(auto p:v ){
                p->update();
            }
        }
        
    }
};

int main()
{
    BlinkManager bm;

    led iled;
    iled.SetData("iled",2);
    //iled.attach( &bm);
    bm.attach(&iled);
    led pled;
    pled.SetData("pled",4);
    //pled.attach( &bm);
    bm.attach(&pled);
    led gled;
    gled.SetData("gled",6);
    bm.attach(&gled);
    
    //gled.attach( &bm);


    std::thread bm_thread([&]{bm.run();});


    gled.blink();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    pled.blink();
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    iled.blink();


    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout<<"-------iled off-------"<<endl;
    iled.set();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout<<"-------pled off-------"<<endl;
    pled.set();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout<<"-------gled off-------"<<endl;
    gled.set();



    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //pled.blink();
    //std::this_thread::sleep_for(std::chrono::seconds(1));

    bm_thread.join();
    cout<<"end"<<endl;
    //gled.set();

    return 0;
}