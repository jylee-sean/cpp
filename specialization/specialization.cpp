
#include <iostream>


class observer
{
    public:
    virtual void update() = 0;
};
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

    virtual void update() override {
        
        _update<0>();
        _update<1>();
    }

protected:
    
    template<int N>    
    void _update(){};

    template<>
    void _update<0>() {
        static constexpr size_t N = 0;
        std::cout << N  <<std::endl;
    }

    template<>
    void _update<1>() {
        static constexpr size_t N = 1;
        std::cout << N  <<std::endl;
    };
};


int main()
{

    input<int> i;

    i.update();

    return 0;
}