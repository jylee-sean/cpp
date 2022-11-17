


#include <string>
#include <vector>
#include <syslog.h>


class exception {};


class runtime_error : public exception
{
    public:
        runtime_error(const char* w, const bool gen_log = true) noexcept : _what(w){  // 1. noexcept ??
            if(gen_log) ::syslog(LOG_ERR, "[erro]r runtime_error(%s) has been created", what().c_str()); 
        }
        runtime_error(const std::string& w, const bool gen_log = true) noexcept : runtime_error(w.c_str(), gen_log){}
        virtual ~runtime_error(){}
        virtual const std::string& what() const noexcept {return this->what;}
    private:
        const std::string _what; // 1. why const ?  2. differences between string  and const char* ?
};

class elmo_fault : public runtime_error
{



    public:
        elmo_fault(){
          //  ::syslog(LOG_ERR, )
        }
};


int main()
{


    return 0;
}