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

    

    union  __attribute__((packed)) data{
        uint64_t d64;
        uint32_t d32;
    }d;

    int _size;
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

        struct memory{
            memory(){
                cout<<"memory construct"<<endl;
            }
            int _order;
            memory read(int val)
            {
                _order = val;
                cout<<"read function "<<endl;
                uint32_t romdata[4] = {35u, 5u, 255u, 65u};
                //uint32_t data[4] = {125u, 51u, 47u, 13u};

                for(int i=0 ; i<4; i++)
                {
                    d.d32[i]=romdata[i];
                }
                cout<<d.d32[0]<<endl;
                return *this;

                // if fail, return nullptr
            }

            virtual ~memory() {cout<<"destructed"<<endl;};

            union  __attribute__((packed)) data{
                uint64_t d64[2];
                uint32_t d32[4];
            }d;
        };

        struct general_info : public memory{
            
            general_info()//:_order{0}
            {
                cout<<"general info"<<endl;

            }
            ~general_info()
            {
                cout<<"general info destructed"<<endl;
            }
            // memorys* write()
            // {
            //     serial_number = &d.d64[0];
            //     year = &d.d32[1];
            //     date = &d.d32[2];

            //     return this;
            // }

            // void get_data()
            // {
            //     serial_number = &d.d64[0];
            //     year = &d.d32[1];
            //     date = &d.d32[2];

            // }
            uint64_t* serial_number; //= &d.d64[0];
            uint32_t* year; //= &d.d32[1];
            uint32_t* date; // = &d.d32[2];

        };
        struct tunning_data : public memory{
            tunning_data()//: _order{1}
            {cout<<"tunning data"<<endl;}


            // memory* write()
            // {
            //     uid1 =&d.d64[0]; 
            //     uid2 =&d.d64[1];
            // }
            uint64_t* uid1;
            uint64_t* uid2;
        };

        // template <typename T>
        // void read(uint32_t *arr, int info){

        //     //block* ptr;
        //     int idx = 0;


            
        //     vector<block>::iterator it;

        //     for(it =dynamic_cast<T*>(_v[info])->getVector().begin(); 
        //         it != dynamic_cast<T*>(_v[info])->getVector().end(); it++)
        //     {

        //         //cout<<(*it)._size<<endl;
                
                
        //         if(it->_size == sizeof(uint64_t))
        //         {
        //             it->d.d64 = arr[idx]*256 + arr[idx+1];
        //             idx+=2;
        //             cout<<it->d.d64<<endl;
        //         }
        //         else
        //         {
        //             it->d.d32 = arr[idx];
        //             idx++;                
        //             cout<<it->d.d32<<endl;
        //         }
        //     }
        // }


        bool read_data(const int arm_no)
        {

            cout<<"read data"<<endl;
            _arm[arm_no].emplace_back(siis::general_info().read(0));

            cout<<"++++++++"<<endl;
            _arm[arm_no].emplace_back(siis::tunning_data().read(1));

            //this->read<siis::general_info>(r1.data, info_idx::general_info);
            //this->read<siis::tunning_data>(r1.data, info_idx::general_info);

            return true;
        }


        void printout()
        {

            cout<<_arm[0][0].d.d32[0]<<endl;

        }

        vector<memory>& getMemory(const int arm_no){
            return _arm[arm_no];
        }


    private:

        //memory _mem;

        //vector<memory*> _v;
        //general_info _gi;
        //tunning_data _td;

        std::array<vector<memory>, 4> _arm;        



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

    // enum info_idx
    // {
    //     general_info= 0,
    //     tunning_data= 1
    // };


    s.read_data(0);
    //s.read_data(1);

    //cout<<   dynamic_cast<siis::general_info*>(s.getMemory(0)[0])->serial_number <<endl;

    cout<<"---------"<<endl;     
    //m.read<machine::general_info>(r1.data, info_idx::general_info);
    cout<<"---------"<<endl;     
    
   // m.read<machine::tunning_data>(r2.data, info_idx::tunning_data);
    cout<<"---------"<<endl;
   
    //cout<<s.getMemory(0)[0]->d.d64[0] <<endl;
    //
    //cout<<s.getMemory(0)[0]->d.d64[1] <<endl;

    s.printout();

    cout<<s.getMemory(0)[0].d.d32[0] <<endl;
    cout<<s.getMemory(0)[0].d.d32[1] <<endl;
    cout<<s.getMemory(0)[0].d.d32[2] <<endl;

    cout<<s.getMemory(0)[0]._order <<endl;
    cout<<s.getMemory(0)[1]._order <<endl;
    //cout<<s.getMemory(0)[0]->d <<endl;
    // cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[0].d.d64<<endl;
    // cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[1].d.d32<<endl;
    // cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[2].d.d32<<endl;

    // cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->_bv[0].d.d64<<endl;
    // cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->_bv[1].d.d64<<endl;


    return 0;
}
