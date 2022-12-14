
#include "co.h"
#include "base.h"

class led : public base
{
    public:
    enum color_t
    {
        off = 0,
        on =1 ,
        white = 2,
        invalid = -1
    };
    static constexpr std::chrono::steady_clock::duration default_interval(){return std::chrono::milliseconds(500);}

    led() = delete;

    explicit led(comst& mst, const coraw& o, const int32_t prio = -1): base(mst), _output(o){
        std::cout<< "led constructor 1st called" <<std::endl;
    }
    explicit led(comst& mst, const uint32_t addr, const uint32_t size, const int32_t prio = -1):
        led(mst, {mst, comst::out, addr, size}, prio){ 
        std::cout<< "led constructor 2nd called" <<std::endl;
    }

    virtual ~led(){
        std::cout<<"led destructor"<<std::endl;
        set(color_t::off);
    }

    bool set(const color_t color, 
             const std::chrono::steady_clock::duration interval = std::chrono::milliseconds(0), 
             bool sync = false){
        
        {
            std::lock_guard<std::mutex> lk(_lock);
            _pred = true;
        }
        if(_future.valid()){
            _condvar.notify_all();
            if(_future.wait_for(std::chrono::milliseconds(1000)) != std::future_status::ready){ // check: need to understand
                throw ;// runtime_error("std::future error");
            }
        }
   
        this->_color.store(color);
        this->_interval.store(interval);
        (void)_output.write(reinterpret_cast<uint8_t*>(&(this->_color))); // check: reinterpret_cast

        if( (interval > std::chrono::milliseconds(0)) && (this->_color != color_t::off) ){
            

            _future = std::async(std::launch::async,[]{});
            //_future = std::async(std::launch::async, [this, sync, interval]() {
            /*
                _pred = false;
                if(this->_prio != -1){
                    struct sched_param s;
                    //(void)::sched_getparam(0,&s);
                    s.sched_priority = this->_prio;
                    //(void)::sched_setscheduler(0,SCHED_RR, &s);
                }
                //(void)::pthread_setname_np(0,"led::blink");
                color_t c = this->_color.load();

                std::chrono::steady_clock::duration delay ((std::chrono::steady_clock::now().time_since_epoch().count() % interval.count())+1);

            });
            
            */

        }

        return true;
    }


    inline bool blink() try {return this->set(this->_color, default_interval()); } catch(...) {throw;}
    inline bool blink(const color_t color)  { return this->set(color , default_interval()); } 

    private:
    coraw _output;
    std::mutex _lock;
    std::atomic<bool> _pred; // check
    std::future<bool> _future; // check
    std::condition_variable _condvar; // check

    std::atomic<color_t> _color;
    std::atomic<std::chrono::steady_clock::duration> _interval;

    int32_t _prio; 
};




int main()
{


    child_of_comst child;
    coraw o(child, comst::out, 0xffu, 0xffu);


    std::cout<<"--construct---"<<std::endl;
    led myled(child, o);

    myled.set(led::color_t::on);
    myled.set(led::color_t::white);


    std::cout<<"--construct2---"<<std::endl;

    led myled2(child, 0x00u,0xffu, 100);

    std::cout<<"--set---"<<std::endl;
    myled2.set(led::color_t::white);

    std::cout<<"--blink1---"<<std::endl;
    myled2.blink(led::color_t::white);
    
    std::cout<<"--blink2---"<<std::endl;
    myled2.blink();

    std::cout<<"-----"<<std::endl;

    //std::cout<< myled.default_interval().count() <<" "<<std::endl;;


    return 0;
}