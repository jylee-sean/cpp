#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
using namespace std;

#define data_size 4



class siis_obj
{
    public:
    
    enum memid_t
    {
        // info = 1 << 0,
        // tune = 1 << 2,
        // lifespan = 1 << 4,
        // triangulation = 1 << 6,
        // hysteresis = 1 << 8
        general_info = 0,
        tunning_data = 1
    };
    
    struct data{
  
        struct __attribute__((packed)) generalinfo_t {

            static const uint8_t a = 0;
            uint64_t serial_number;
            uint32_t year;
            uint32_t date;

            static void func()
            {
                cout<<"called"<<endl;
            }
        
            void set()
            {
                uint64_t value = 0x0000000000000000;
                value |= ((serial_number & 0x00000000ffffffff)<<32);
                value |= ((serial_number & 0xffffffff00000000)>>32);

                serial_number  = value;                 
                //cout<<hex<<serial_number<<endl;
                
            }
        } generalinfo;
        struct __attribute__((packed)) tunningdata_t {
            static const uint8_t a = 1;
            uint64_t uid1;
            uint64_t uid2;
             static void func()
            {
                cout<<"called2"<<endl;
            }           
            void set()
            {
                uint64_t value = 0x0000000000000000;
                value |= ((uid1 & 0x00000000ffffffff)<<32);
                value |= ((uid1 & 0xffffffff00000000)>>32);

                uid1 = value;       
                
                value = 0x0000000000000000;
                value |= ((uid2 & 0x00000000ffffffff)<<32);
                value |= ((uid2 & 0xffffffff00000000)>>32);    

                uid2 = value;
                //cout<<hex<<serial_number<<endl;
                
            }
        } tunningdata;
    };

};



class siis
{
    public:


        struct input_t
        {
            uint32_t data[data_size];
        };
        struct output_t
        {
            uint32_t data[data_size];
        };


        struct cache_t {
            siis_obj::data::generalinfo_t gi;
            siis_obj::data::tunningdata_t td;

        };
		input_t& input() { return _input; }
		output_t& output() { return _output; }

        bool load(const uint32_t arm_no) {
    

            read<siis_obj::data::generalinfo_t>(arm_no, (&_arm[arm_no].gi), 0);
            read<siis_obj::data::tunningdata_t>(arm_no, (&_arm[arm_no].td), 1);
            // if(read(arm_no, siis_obj::memid_t::general_info, reinterpret_cast<siis_obj::data*>(&_arm[arm_no].gi)) < 0
            //     /*|| read(arm_no, siis_obj::memid_t::tunning_data, reinterpret_cast<siis_obj::data*>(&_arm[arm_no].td)) < 0*/)
            //      { return false; }

            // if(read(arm_no, siis_obj::memid_t::general_info, &(_arm[arm_no].gi)) < 0)
            //      { return false; }

            return true;
        }

        template<typename T>
        void read(const uint32_t arm_no,  T* dst, int val, const int32_t timeout = 1000) {
            //ssize_t ret = sizeof(siis_obj::data);

            uint8_t b = T::a;
            cout<<b<<endl;
            //cout<<"value: "<<T::a<<endl;
            uint32_t romdata[4] ={};
            if(val ==0){
                romdata[0] = 32u+ 3u; //0x00100011  // 0x00000023
                romdata[1] = 5u;      //0x00000101  // 0x00000005   // 0x0000002300000005 ==> 8965
                romdata[2] = 255u;    //0x11111111  // 0x000000FF
                romdata[3] = 65u;     //0x01000001  // 0x00000041
            }else{
                romdata[0] = 123245235u;    //0x01111101   // 0x7D
                romdata[1] = 51u;     //0x00110011  // 0x33   // 0x7d33 ==> 32051
                romdata[2] = 47u;    //0x00101111   // 0x2F
                romdata[3] = 13u;     //0x00001101  // 0x0D   // 0x2F0D ==> 12045
            }
            
            for(int32_t j = 0; j < 4;j++ )
            {

                *(reinterpret_cast<uint32_t*>(dst) + j) =romdata[j];
                
                cout<<*(reinterpret_cast<uint32_t*>(dst) + j)<<endl;

            }

            dst->set();
            
            // cout<<hex<<dst->serial_number<<endl;
            // cout<<hex<<dst->year<<endl;
            // cout<<hex<<dst->date<<endl;



            //return true;
        }
        void printout()
        {
            cout<<"printout"<<endl;
        }

        cache_t& cache(const uint32_t arm_no) { return _arm[arm_no]; }


    private:

        //memory _mem;

        //vector<memory*> _v;

        std::array<siis::cache_t,4> _arm;        
    

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
                data[0] = 136357625u;    //0x01111101   // 0x7D
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

    // enum info_idx
    // {
    //     general_info= 0,
    //     tunning_data= 1
    // };


    s.load(0);
    //s.read_data(1);

    //cout<<   dynamic_cast<siis::general_info*>(s.getMemory(0)[0])->serial_number <<endl;
    // cout<<s.getMemory(0).gi[0].d.d64<<endl;
    // cout<<s.getMemory(0).gi[1].d.d32<<endl;
    // cout<<s.getMemory(0).gi[2].d.d32<<endl;
    cout<<"---------"<<endl;     
    //m.read<machine::general_info>(r1.data, info_idx::general_info);
    cout<<"---------"<<endl;     
    
   // m.read<machine::tunning_data>(r2.data, info_idx::tunning_data);
    cout<<"---------"<<endl;
   

    //s.printout();


    cout<<typeid(uint64_t).name() <<endl;
    cout<<typeid(uint32_t).name() <<endl;
    cout<<hex<<s.cache(0).gi.serial_number<<endl;
    cout<<hex<<s.cache(0).gi.year<<endl;
    cout<<hex<<s.cache(0).gi.date<<endl;

    cout<<hex<<s.cache(0).td.uid1<<endl;
    cout<<hex<<s.cache(0).td.uid2<<endl;
    // cout<<s.getMemory(0)[info_idx::general_info].d.d32<<endl;
    // cout<<s.getMemory(0)[info_idx::general_info].d.d32<<endl;
    return 0;
}


