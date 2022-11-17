
/*to check function over*/

#include <iostream>

//typedef unsigned char uint8_t;


class copi
{
public:

};
class comst
{

public:
    virtual double readpdo(copi& pi, uint8_t* dst, size_t bit_offset, size_t bit_size)=0;



    template<typename T>
    inline T readpdo(copi& pi, const size_t bit_offset){
        T val = 0 ; //T(0);
        //(void)readpdo(pi, reinterpret_cast<uint8_t*>(&val), bit_offset, 1);

        std::cout<<"inline readpdo function called"<<std::endl;
        return val;
    }
};


class child_of_comst: public comst
{
    public:
        double readpdo(copi& pi, uint8_t* dst, size_t bit_offset, size_t bit_size){
            

            std::cout<<bit_offset<<" "<<bit_size<<std::endl;
            std::cout<<"child readpdo function called"<<std::endl;
            return 1.0;
        };
};


int main()
{

    //comst mst;
    copi pi;

    size_t bit_addr = 0x0;

    child_of_comst ccomst;
    comst* pmst = &ccomst;

    pmst->template readpdo<int>(pi, bit_addr);
    
    //pmst->readpdo(pi,0,0,0,0);

    //ccomst.readpdo(pi,0,0,0);

    return 0;
}