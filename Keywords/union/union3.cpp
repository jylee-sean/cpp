#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
using namespace std;

#define data_size 4

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

    

    // union  __attribute__((packed)) data{
    //     uint64_t d64;
    //     uint32_t d32;
    // }d;

    union data{
        uint64_t d64;
        uint32_t d32;
    }d;
    int _size;
};

enum general_info
{
    serial_number,
    year,
    date
};

enum tunning_data
{
    uid1,
    uid2
};
class siis
{
    public:

        
        // _input{
        //         data[0] = 32u+ 3u; //0x00100011  // 0x23
        //         data[1] = 5u;      //0x00000101  // 0x05   // 0x2305 ==> 8965
        //         data[2] = 255u;    //0x11111111  // 0xFF
        //         data[3] = 65u;     //0x01000001  // 0x41
        // },
        // _output{},




        struct input_t
        {
            uint32_t data[data_size];
        };
        struct output_t
        {
            uint32_t data[data_size];
        };

		input_t& input() { return _input; }
		output_t& output() { return _output; }



        struct block
        {
            block(int name, uint64_t value)
            {
                //d.d64 = value;
                //_size = sizeof(value.second);
                //cout<<"block construct : 64 bit : "<< value.first <<" "<<_size <<endl;
                //using value_type = uint64_t;
            }
            block(int name, uint32_t value)
            {
             //   d.d32 = value;
                 //using value_type = uint32_t;
            }

            union  __attribute__((packed)) data{
                uint64_t d64;
                uint32_t d32;
            }d;

             
        };
 

        


        struct cache
        {
            std::vector<block> gi = 
            {
                (static_cast<uint64_t>(general_info::serial_number,0)),
                (static_cast<uint32_t>(general_info::year, 0)),
                (static_cast<uint32_t>(general_info::date, 0))
            };

            std::vector<block> td = 
            {
                (static_cast<uint64_t>(tunning_data::uid1,0)),
                (static_cast<uint64_t>(tunning_data::uid2,0))
            };
        };

 
        // struct general_info : public data{
        //     general_info(): serial_number{&d.d64[0]}, {&d.d32[2]},{&d.d32[3]}
        //     {}
        //     uint64_t* serial_number;
        //     uint32_t* year; 
        //     uint32_t* date;             
        // };
        // struct tunning_data : public data{
        //     uint64_t* uid1;
        //     uint64_t* uid2;
        // };



        template<typename T>
        void read(cache c, int index)
        {
            //std::vector<block> vec;

            
            //T t;

            
            cout<<"read function "<<endl;
            if (index == 0)
                uint32_t romdata[4] = {35u, 5u, 255u, 65u};
            else
                uint32_t romdata[4] = {125u, 51u, 47u, 13u};

            for(int i=0 ; i<4; i+=2)
            {
                //cout<<i<<endl;
                if(c.gi[idx].value_type == uint64_t)
                {
                    c.gi[idx].d.d64 = romdata[i]*256 + romdata[i+1];
                    
                }   
                else
                {
                    c.gi[idx].d.d32 = romdata[i];
                    c.gi[i+1].d.d32 = romdata[i+1];
                }
                // if(i==0){
                //     vec.emplace_back(block(static_cast<uint64_t>(romdata[i]*256 + romdata[i+1])));
                // }
                // else{
                //     vec.emplace_back(block(static_cast<uint32_t>(romdata[i])));
                //     vec.emplace_back(block(static_cast<uint32_t>(romdata[i+1])));
                // }
                d.d32[i]=romdata[i];
            }
            //cout<<d.d32[0]<<endl;
            //return vec;
            // if fail, return nullptr
        }

        cache load()
        {
            cache c;


            read<siis::general_info>(&c, 0);
            read<siis::tunning_data>(&c, 1);
            
            return c;
        } 
        bool read_data(const int arm_no)
        {
            _arm.emplace_back(load());
            // arm_no를 각각 부르는 것보다는 동시에 , 각 데이터는 사이클마다 수행하는 것이 효율적.
            // cout<<"read data"<<endl;
            // _arm[arm_no].emplace_back(read<siis::general_info>(0));
            // _arm[arm_no].emplace_back(read<siis::tunning_data>(1));

            //this->read<siis::general_info>(r1.data, info_idx::general_info);
            //this->read<siis::tunning_data>(r1.data, info_idx::general_info);

            return true;
        }

        

        void printout()
        {
            cout<<"printout"<<endl;
        }

        std::vector<std::vector<block>>& getMemory(const int arm_no){
            return _arm[arm_no];
        }


    private:

        //memory _mem;

        //vector<memory*> _v;
        //general_info _gi;
        //tunning_data _td;
    
        std::vector<siis::cache> _arm;        
    

        input_t _input;
        output_t _output;
   
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
    siis s;

    enum info_idx
    {
        general_info= 0,
        tunning_data= 1
    };


    s.read_data(0);
    //s.read_data(1);

    //cout<<   dynamic_cast<siis::general_info*>(s.getMemory(0)[0])->serial_number <<endl;

    cout<<"---------"<<endl;     
    //m.read<machine::general_info>(r1.data, info_idx::general_info);
    cout<<"---------"<<endl;     
    
   // m.read<machine::tunning_data>(r2.data, info_idx::tunning_data);
    cout<<"---------"<<endl;
   

    s.printout();

    cout<<s.getMemory(0)[info_idx::general_info].d.d64<<endl;
    cout<<s.getMemory(0)[info_idx::general_info].d.d32<<endl;
    cout<<s.getMemory(0)[info_idx::general_info].d.d32<<endl;
    return 0;
}
