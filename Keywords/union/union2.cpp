#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



struct block
{
    block(std::pair<std::string, uint64_t> value)
    {
        _size = sizeof(value.second);
        //cout<<"block construct : 64 bit : "<< value.first <<" "<<_size <<endl;

    }
    block(std::pair<std::string, uint32_t> value)
    {
        _size = sizeof(value.second);
        //cout<<"block construct : 32 bit : "<< value.first <<" "<<_size <<endl;
    }

    

    union  __attribute__((packed)) data{
        uint64_t d64;
        uint32_t d32;
    }d;

    int _size;
};

class machine
{
    public:

        machine():_gi(0),_td(1)
        {
            cout<<"machine construct"<<endl;
            _v ={ &_gi, &_td};
        }


        struct memory{
            memory(){
                cout<<"memory construct"<<endl;
            }
            int _order;
            virtual ~memory() {};
        };

   
        struct general_info : public memory{
            
            
            general_info(int order)
            {   
                _order = order;
                cout<<"general_info construct"<<endl;

                _bv.emplace_back(block( std::pair<string,uint64_t>("serial_number", 0)  )   );
                _bv.emplace_back(block( std::pair<string,uint32_t>("year", 0)  )   );
                _bv.emplace_back(block( std::pair<string,uint32_t>("date", 0)  )   );
            }

            vector<block>& getVector() { return _bv; }
            vector<block> _bv;
        };
        struct tunning_data : public memory{

            tunning_data(int order)
            {
                 _order = order;

                cout<<"tunning data construct"<<endl;

                _bv.emplace_back(block( std::pair<string,uint64_t>("uid1", 0)  )   );
                _bv.emplace_back(block( std::pair<string,uint64_t>("uid2", 0)  )   );


            }
            vector<block>& getVector() { return _bv; }

            vector<block> _bv;


        };

        template <typename T>
        void read(uint32_t *arr, int info){

            //block* ptr;
            int idx = 0;


            
            vector<block>::iterator it;

            for(it =dynamic_cast<T*>(_v[info])->getVector().begin(); 
                it != dynamic_cast<T*>(_v[info])->getVector().end(); it++)
            {

                //cout<<(*it)._size<<endl;
                
                
                if(it->_size == sizeof(uint64_t))
                {
                    it->d.d64 = arr[idx]*256 + arr[idx+1];
                    idx+=2;
                    cout<<it->d.d64<<endl;
                }
                else
                {
                    it->d.d32 = arr[idx];
                    idx++;                
                    cout<<it->d.d32<<endl;
                }
            }


        }


        vector<memory*>& getMemory(){
            return _v;
        }


    private:

        //memory _mem;

        vector<memory*> _v;
        general_info _gi;
        tunning_data _td;

        
   
};




class ROM
{
    public:
        ROM(int val){
            if(val ==1){
                data[0] = 32u+ 3u; //0x00100011  // 0x23
                data[1] = 5u;      //0x00000101  // 0x05   // 0x2305 ==> 8965
                data[2] = 255u;    //0x11111111  // 0xFF
                data[3] = 65u;     //0x01000001  // 0x41
            }else{
                data[0] = 125u;    //0x01111101   // 0x7D
                data[1] = 51u;     //0x00110011  // 0x33   // 0x7d33 ==> 32051
                data[2] = 47u;    //0x00101111   // 0x2F
                data[3] = 13u;     //0x00001101  // 0x0D   // 0x2F0D ==> 12045

            }
        }
        //4 byte = 32 bit
        uint32_t data[4];
};

int main()
{

    ROM r1(1);
    ROM r2(2);

    cout<<"---------"<<endl;
    machine m;

    enum info_idx
    {
        general_info= 0,
        tunning_data= 1
    };
   cout<<"---------"<<endl;     

    m.read<machine::general_info>(r1.data, info_idx::general_info);
    cout<<"---------"<<endl;     
    
    m.read<machine::tunning_data>(r2.data, info_idx::tunning_data);
    //m.read<machine::general_info>(r1.data);
    cout<<"---------"<<endl;
    //m.read2(r2.data);
    //m.read<machine::tunning_data>(r2.data);

    

    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[0].d.d64<<endl;
    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[1].d.d32<<endl;
    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[2].d.d32<<endl;

    cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->_bv[0].d.d64<<endl;
    cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->_bv[1].d.d64<<endl;


    return 0;
}
