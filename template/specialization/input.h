#include <iostream>

class observer
{
    public:
    virtual void update() = 0;
};

namespace core{

    template<typename T>
    class input : public observer
    {
    public:
        using value_type = uint64_t;
        struct system {
            static constexpr size_t offset = 0;
            
        };

        struct subsystem {
            static constexpr size_t offset = 0;
            
        };

        input()  {    }
        virtual ~input() { }

        template<int N>
        void get(const std::size_t o){  std::cout<< N << o <<std::endl; };

        template<int M>
        void set(const std::size_t o){  std::cout<< M << o <<std::endl; };
        
        virtual void update() override {
            
            //_update<0>();
            //_update<1>();
            iupdate<int,0>();
            iupdate<int,1>();
        }

    protected:
        
        template<typename T,size_t value>    
        struct iupdate;

        template<typename T>    
        struct iupdate<int, 0>{
            void operator()(){
                static constexpr size_t N = 0;
                std::cout << N  <<std::endl;
            }
        };

        template<typename T>    
        struct iupdate<int, 1>{
            void operator()(){
            static constexpr size_t N = 1;
            std::cout << N  <<std::endl;
            }
        };
        
        //template<size_t num>
        //using _update = iupdate<int,num>;
    };
}