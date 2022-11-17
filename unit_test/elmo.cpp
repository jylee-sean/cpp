


#include <string>
#include <vector>
#include <syslog.h>
#include "co.h"
#include "base.h"

class exception {};


class runtime_error : public exception
{
    public:

        runtime_error(){}// need to remove
        runtime_error(const char* w, const bool gen_log = true) noexcept : _what(w){  // 1. noexcept ??
            if(gen_log) ::syslog(LOG_ERR, "[erro]r runtime_error(%s) has been created", what().c_str()); 
        }
        runtime_error(const std::string& w, const bool gen_log = true) noexcept : runtime_error(w.c_str(), gen_log){}
        virtual ~runtime_error(){}
        virtual const std::string& what() const noexcept {return this->_what;}
    private:
        const std::string _what; // 1. why const ?  2. differences between string  and const char* ?
};

class elmo_fault : public runtime_error
{
    public:
        elmo_fault(){
          //  ::syslog(LOG_ERR, )
        }
    private:

};


class elmo_cfg
{

    enum type_t{

    };
    struct sensor_t{

    };
    struct elmo_sensor{
        static constexpr elmo_cfg::sensor_t unkown {-1};
    };
    static constexpr elmo_cfg elmo_nocfg{
     //   elmo_cfg::type_T::none,
	//		{ elmo_sensor::unknown, { 0, 0 }, { 0, 0 } },
    //    	{ elmo_sensor::unknown, { 0, 0 }, { 0, 0 } }
    };
};

class elmo : public std::enable_shared_from_this<elmo>, public base
{
    public:
    enum struct source_t { incremental , absolute};

    class profile
    {
        public:
            virtual ~profile() {} // what for ?
    };

    //elmo() = delete;
    elmo(){};
    //explicit elmo(comst& mst, const uint16_t id, const elmo_cfg& cfg = elmo_nocfg)
};

int main()
{


    return 0;
}