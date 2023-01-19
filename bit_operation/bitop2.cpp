#include <iostream>


using namespace std;



using value_type = uint32_t;
uint32_t driving_system_status = 0xF123D580;



// speed = 0xF123
// stb_sts = 0xD
// dri_dir = 2u
// dri_act = 3u

class drivingsystemStatus
{
public:

    union data{
        struct __attribute__((packed)) pack_t {
            value_type : 2;
            value_type dri_act : 1;
            value_type : 3;
            value_type dri_dir : 2;
            value_type : 4;
            value_type stb_sts : 4;
            value_type dri_max_spd : 16;
        } pack;
        value_type value;
    };
private:
    drivingsystemStatus(){};
    static drivingsystemStatus instance;
    

};

class spider
{
    public:
        drivingsystemStatus::data drivingsystemstatus(){
            
            static drivingsystemStatus::data drivingsystemstatusdata;
            drivingsystemstatusdata.value = driving_system_status;
            return drivingsystemstatusdata; //&drivingsystemstatusdata;
        }

        uint16_t driving_max_speed()
        {

            return drivingsystemstatus().pack.dri_max_spd;
        }

        uint8_t stabillizer()
        {
            return static_cast<uint8_t>(drivingsystemstatus().pack.stb_sts);
        }

        bool driact()
        {
            return drivingsystemstatus().pack.dri_act;
        }

        uint8_t dridir()
        {
            return static_cast<uint8_t>(drivingsystemstatus().pack.dri_dir);
        }

        static spider getInstance(){
            return _instance;
        }       
    private:
        spider(){}
        static spider _instance;
             

};


			
			



int main()
{

    //spider spd;

    uint32_t status = 0x000000F0;

    bool ret= false;

    ret = !status;
    cout<<ret<<endl;

    ret = status; 
    cout<<ret<<endl;
    // cout<<hex<<spd.driving_max_speed()<<endl;
    
    // cout<<(int)spd.dridir()<<endl;
    // cout<<spd.driact()<<endl;
    // cout<<(int)spd.stabillizer()<<endl;

    return 0;
}
