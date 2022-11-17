


#include <chrono>
#include <iostream>
#include <future>
#include "ccl_event.h"

class copi
{

};

class comst : public ccl::event::subject<comst>
{
    public:
    comst() {std::cout<<"comst constructor called"<<std::endl;}
    enum map_t{ in , out };
    static constexpr uint16_t invalid_slave_id = std::numeric_limits<uint16_t>::max();
    class event : public ccl::event::base {};
    class sync_done : public ccl::event::base {};
    
    virtual ~comst() {}

    virtual copi& pin()  = 0;
    virtual copi& pout()  = 0;
    virtual ssize_t readpdo(copi& pi, uint8_t* dst, size_t bit_offset, size_t bit_size) = 0;
    virtual ssize_t writepdo(copi& pi, uint8_t* const src, size_t bit_offset, size_t bit_size) = 0;

};

class child_of_comst : public comst
{
   copi& pin(){ std::cout<<"pin function in temp class"<<std::endl; return _pi;}
   copi& pout(){ std::cout<<"pout function in temp class"<<std::endl; return _pi;}


    ssize_t readpdo(copi& pi, uint8_t* dst, size_t bit_offset, size_t bit_size) {
        std::cout<<"read pdo function called"<<std::endl; return 0;
    }
    ssize_t writepdo(copi& pi, uint8_t* const src, size_t bit_offset, size_t bit_size){
        std::cout<<"write pdo function called"<<std::endl; return 0;
    }

   private:
   copi _pi;
};
class coobj
{
   
    public:
    typedef uint16_t index_type;


    virtual ~coobj(){}
    
    protected:
    comst* _mst;
    index_type _index;

    explicit coobj(comst* mst, const index_type index = 0u) : _mst(mst), _index(index)
        {std::cout<<"coobj constructor called"<<std::endl;}
};

class coraw : public coobj
{
    public:
    coraw(comst& mst, comst::map_t map, const size_t bit_addr, const size_t bit_size):
        coobj(&mst), _pi(map == comst::in? mst.pin() : mst.pout()),_bit_addr(bit_addr), _bit_size(bit_size){
            std::cout<<"coraw constructor called"<<std::endl;
        }
    ~coraw(){}


    inline ssize_t read(uint8_t* dst) { return _mst->readpdo(_pi, dst, _bit_addr, _bit_size);}
    inline ssize_t write(uint8_t* src){ std::cout<<"write called"<<std::endl; return _mst->writepdo(_pi, src, _bit_addr, _bit_size); }
    
    
    private:
    copi& _pi;
    uint32_t _bit_addr;
    uint32_t _bit_size;

    using coobj::_mst;

};
