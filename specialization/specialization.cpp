
#include <iostream>

// template<int N> void _update() { }



template<typename T>
class input : public ccl::event::observer<ssi::ecatmst, ssi::ecatmst::sync_done>
{
public:
    using value_type = uint64_t;
    struct system {
        static constexpr size_t offset = 0;
        
    };

    struct subsystem {
        static constexpr size_t offset = 0;
        
    };

    input(T& target, messaging::sender sender) :
        _target(target), _sender(sender) {
        _prev[0] = _prev[1] = 0x0;
        _mask[0] = _mask[1] = std::numeric_limits<value_type>::max();
    }
    virtual ~input() { }

    template<int N>
    bool get(const std::size_t o) { return (_prev[N] >> o) & 0x01; }

    template<int N>
    value_type mask(value_type m) { return _mask[N] = m; }

    static constexpr value_type bitmask(const size_t offset) { return static_cast<value_type>(0x01) << offset; }

    virtual void update(ssi::ecatmst& m, const ssi::ecatmst::sync_done& e) override {
        _update0();
        _update1();
    }

protected:
    T& _target;
    messaging::sender _sender;
    std::array<std::atomic<value_type>, 2> _prev;
    std::array<std::atomic<value_type>, 2> _mask;


    // TODO:
    // it needs to apply template specialization
    void _update0() {
        static constexpr size_t N = 0;
        std::cout << N  <<std::endl;
    }

    void _update1() {
        static constexpr size_t N = 1;
        std::cout << N  <<std::endl;
    };
};


