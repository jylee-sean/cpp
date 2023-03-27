#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



// struct custom_container
// {
//     private:
//         template <typename T>
//         static std::unordered_map<const custom_container*, std::vector<T>> items;
//     public:
//         template <typename T>
//         void push_back(const T& _t)
//         {
//             items<T>[this].push_back(_t);
//         }

//         template<class T>
//         std::unordered_map<const custom_container*, std::vector<T>> custom_container::items;
// };
//https://gieseanw.wordpress.com/2017/05/03/a-true-heterogeneous-container-in-c/

enum data_type
{
    _UINT64 = 0,
    _UINT32 = 1,
};
struct linkedlist
{
 
    int _dt;
    union data{
        uint64_t d64;
        uint32_t d32;
    }d;

    linkedlist *link;
};

class machine
{
    public:

        machine()
        {
            cout<<"machine construct"<<endl;
            _v ={ &_gi, &_td};
        }
        union data{
            uint64_t d1[2];
            uint32_t d2[4];
        }ud;

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

                head.link = &serial_number;
                head._dt = data_type::_UINT64;

                serial_number.link = &year;
                serial_number._dt = data_type::_UINT64;
                
                year.link = &date;
                year._dt = data_type::_UINT32;
                
                date.link = nullptr;
                date._dt = data_type::_UINT32;
                
               
                
            }

            linkedlist head;
            linkedlist serial_number;
            linkedlist year;
            linkedlist date;
            
            
            // serial_number;
            // year;
            // date;

        }_gi;
        struct tunning_data : public memory{

            static const int order = 1;
            tunning_data()
            {
                cout<<"tunning data construct"<<endl;

                head.link = &uid1;
                head._dt = data_type::_UINT64;

                uid1.link = &uid2;
                uid1._dt = data_type::_UINT64;
                
                uid2.link = nullptr;
                uid2._dt = data_type::_UINT64;

            }
            linkedlist head;
            linkedlist uid1;
            linkedlist uid2;

        }_td;

        template <typename T>
        void read(uint32_t *arr){

            linkedlist* ptr;
            int idx = 0;
            for(ptr = dynamic_cast<T*>(_v[T().order])->head.link; ptr != nullptr; ptr = ptr->link)
            {
                if((*ptr)._dt == data_type::_UINT64)
                {
                    (*ptr).d.d64 = arr[idx]*256 + arr[idx+1];
                    idx+=2;
                }
                else
                {
                    (*ptr).d.d32 = arr[idx];
                    idx++;                
                }
            }
            

            // (*ptr).d.d64 = arr[0]*256 + arr[1];

            // ptr = ptr->link;
            // (*ptr).d.d32 = arr[2];

            // ptr = ptr->link;
            // (*ptr).d.d32 = arr[3];
        }



        void read2(uint32_t *arr){
            //dynamic_cast<tunning_data*>(_v[1])->uid1 = arr[0]*256 + arr[1];
            //dynamic_cast<tunning_data*>(_v[1])->uid2 = arr[2]*256 + arr[3];

            //_mem._td.uid1 = arr[0]*256 + arr[1];
            //_mem._td.uid2 = arr[2]*256 + arr[3];
            // ud.d1[0] = 
            // ud.d1[1] = 
            // cout<<ud.d1[0]<<endl;
            // cout<<ud.d1[1]<<endl;
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




    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->serial_number.d.d64<<endl;
    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->year.d.d32<<endl;
    cout<<dynamic_cast<machine::general_info*>(m.getMemory()[0])->date.d.d32<<endl;

    cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->uid1.d.d64<<endl;
    cout<<dynamic_cast<machine::tunning_data*>(m.getMemory()[1])->uid2.d.d64<<endl;


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
