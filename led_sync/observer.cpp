#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
using namespace std;


class led;

struct Observer
{
    vector<led*> v;

    virtual void update(led*) = 0;
    virtual ~Observer() {}
};


// class Subject
// {
//     Observer* o;
// public:
//     void attach(Observer* p) { o = p; }

//     void notify()
//     {
//         o->update(this);           
//         //cout<<"called"<<endl;
//     }
// };

class led //: public Subject
{
    std::string _name;
    int _color;
    Observer* o;
public:
    void attach(Observer* p) {o = p;}
    void notify()
    {
        o->update(this);
    }

    int GetColor() { return _color;}
    std::string GetName() { return _name;}

    void SetData(std::string s, int c)
    {
        _name = s;
        _color = c;
    }

    void blink()
    {
        notify();
        cout<<"notify "<<endl;
    }

    void set()
    {
        
    }

};



class BlinkManager : public Observer
{
public:
    virtual void update(led* p)
    {
        v.push_back(p);
        
        
        cout<<"update"<<endl;
        //run();

    }

    void run()
    {

        while(true){
                int n;
                cout<<"block:";
                cin>> n;
                //std::lock_guard<std::mutex> lock_guard(m);
                for(auto p:v ){
                    //std::string s = static_cast<led*>(p)->GetName();
                    std::string s = p->GetName();
                    cout << "blinking:" << s <<endl;
                }
        }
            
        // _future = std::async(std::launch::async,[&]{
        //     while(true){
        //         int n;
        //         cout<<"block:";
        //         cin>> n;
        //         //std::lock_guard<std::mutex> lock_guard(m);
        //         for(auto p:v ){
        //             //std::string s = static_cast<led*>(p)->GetName();
        //             std::string s = p->GetName();
        //             cout << "blinking:" << s <<endl;
        //         }
        //     }
        //     return true;
        // });
    }

private:
    std::future<bool> _future;



};

int main()
{
    BlinkManager bm;

    led iled;
    iled.SetData("iled",2);
    iled.attach( &bm);

    led pled;
    pled.SetData("pled",4);
    pled.attach( &bm);

    led gled;
    gled.SetData("gled",6);
    gled.attach( &bm);



    gled.blink();

    std::thread bm_thread([&]{bm.run();});

    std::this_thread::sleep_for(std::chrono::seconds(4));
    pled.blink();
    
    std::this_thread::sleep_for(std::chrono::seconds(4));
    iled.blink();

    std::this_thread::sleep_for(std::chrono::seconds(4));
    iled.set();



    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //pled.blink();
    //std::this_thread::sleep_for(std::chrono::seconds(1));

    bm_thread.join();
    cout<<"end"<<endl;
    //gled.set();

    return 0;
}