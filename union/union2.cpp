#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



enum data_type
{
    _UINT64 = 0,
    _UINT32 = 1,
};

struct block
{
    int _dt;
    union data{
        uint64_t d64;
        uint32_t d32;
    }d;
};

class machine
{
    public:

        machine()
        {
            cout<<"machine construct"<<endl;
            _v ={ &_gi, &_td};
        }


        struct memory{
            memory(){
                cout<<"memory construct"<<endl;
            }     
            virtual ~memory() {};
        };
      

        struct general_info : public memory{
            
            static const int order = 0;
            general_info()
            {   
                cout<<"general_info construct"<<endl;

                serial_number._dt = data_type::_UINT64;
                year._dt = data_type::_UINT32;
                date._dt = data_type::_UINT32;
            
                _bv={serial_number, year, date};

            }

            vector<block>& getVector() { return _bv; }
            vector<block> _bv;

            block serial_number;
            block year;
            block date;
        
        }_gi;
        struct tunning_data : public memory{

            static const int order = 1;
            tunning_data()
            {
                cout<<"tunning data construct"<<endl;

                uid1._dt = data_type::_UINT64;
                uid2._dt = data_type::_UINT64;

                _bv = {uid1, uid2};
            }
            vector<block>& getVector() { return _bv; }

            vector<block> _bv;
            block uid1;
            block uid2;

        }_td;

        template <typename T>
        void read(uint32_t *arr){

            //block* ptr;
            int idx = 0;


            
            vector<block>::iterator it;
            for(it =dynamic_cast<T*>(_v[T().order])->getVector().begin(); 
                it != dynamic_cast<T*>(_v[T().order])->getVector().end(); it++)
            {
                if((*it)._dt == data_type::_UINT64)
                {
                    (*it).d.d64 = arr[idx]*256 + arr[idx+1];
                    idx+=2;
                    cout<<(*it).d.d64<<endl;
                }
                else
                {
                    (*it).d.d32 = arr[idx];
                    idx++;                
                    cout<<(*it).d.d32<<endl;
                
                
                }
            }


        }


        vector<memory*>& getMemory(){
            return _v;
        }


    private:

        //memory _mem;

        vector<memory*> _v;
        
       
    //map< string, map<std::string,double> > map_data;
  
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

    machine m;


    m.read<machine::general_info>(r1.data);
    m.read<machine::tunning_data>(r2.data);
    //m.read<machine::general_info>(r1.data);
    cout<<"---------"<<endl;
    //m.read2(r2.data);
    //m.read<machine::tunning_data>(r2.data);



    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[0].d.d64<<endl;
    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[1].d.d32<<endl;
    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->_bv[2].d.d32<<endl;

    cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->_bv[0].d.d64<<endl;
    cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->_bv[1].d.d64<<endl;


    // for(vector<machine::memory*>::iterator it = m.getMemory().begin(); m.getMemory.end(); it++ )
    // {
    //     cout<<(*it)<<endl;
    // }
    //cout<<m.getMemory()._gi.serial_number<<endl;
    //cout<<m.getMemory()._gi.year<<endl;
    // cout<<m.getMemory()._gi.date<<endl;
    // cout<<m.getMemory()._td.uid1<<endl;
    // cout<<m.getMemory()._td.uid2<<endl;

    return 0;
}
