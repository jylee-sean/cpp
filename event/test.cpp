

#include "event.h"

class comst : public event::subject<comst>
{   
    public:
        class evt : public event::base {};
        class sync_done : public event::base{};
};
class master :public event::subject<master>
{
    public:
        
        //using comst::evt;
        //using comst::sync_done;
        //class evt{};
        class sync_done : public event::base{};
        class isync_done : public event::base {};
};
class ob1 : public event::observer<master, master::sync_done>
{
    public:
    virtual void update(master& m, const master::sync_done& e) override
    {
        std::cout<<"observe1 - sync done"<<std::endl;
    }

};

class ob2 : public event::observer<master, master::isync_done>
{
    public:
    virtual void update(master& m, const master::isync_done& e) override
    {
        std::cout<<"observe2 - isync done"<<std::endl;
    }
};

class ob3 : public event::observer<master, master::sync_done>
{
    public:
    virtual void update(master& m, const master::sync_done& e) override
    {
        std::cout<<"observe3 - sync done"<<std::endl;
    }

};


class led_master :public event::subject<led_master>
{
    public:
    
        class sync_done : public event::base{};
        class isync_done : public event::base {};
};

class led : public event::observer<led_master, led_master::sync_done>
{
    public:
    virtual void update(led_master& m, const led_master::sync_done& e) override
    {
        std::cout<<"led - sync done"<<std::endl;
    }
    void blink()
    {

    }
};

int main()
{

    led_master m;
    ob1 _ob1;
    ob2 _ob2;
    ob3 _ob3;
    led iled;
    led pled;
    led gled;


    led *ptr = new led();

    m.attach(iled);
    m.attach(pled);
    m.attach(gled);

    m.attach(ptr);

    // m.notify<master::isync_done>();
    // std::cout<<"-------"<<std::endl;
    // m.notify<master::sync_done>();

    // iled.blink();
    // pled.blink();

    // int n;
    // while(1){
    //     std::cin>>n;
    //     m.notify<led_master::blink>();
    // }



    return 0;
}