
#include <iostream>

using namespace std;
using value_type =  uint32_t;

class jarvis_obj{
	public:
	class SubsystemStatus 
	{
	public:
		SubsystemStatus() { }
		~SubsystemStatus() { }


		union data{
			struct __attribute__ ((packed)) pack_t {
				value_type : 7;
				value_type pwr_con : 1;
				value_type : 4; 
				value_type emg_sts : 4;
				value_type bat_lvl : 8; 
				value_type : 8; 
			} pack;
			value_type command;
		};

	};
};


class jarvis{

	public:

	jarvis(){
		set.command = 0;
	}
	uint32_t battery_level(const uint32_t value){
		set.pack.bat_lvl = value;				
		//return this->output().subsystemStatus.write(set.command);
	}

	uint32_t emergency_status(const uint32_t value){
		set.pack.emg_sts = value;				
		//return this->output().subsystemStatus.write(set.command);
	}

	uint32_t power_connection(const uint32_t value){
		set.pack.pwr_con = value;				
		//return this->output().subsystemStatus.write(set.command);
	}

	uint32_t result(){
		return set.command;
	}

	private:
		jarvis_obj::SubsystemStatus::data set;
};
int main()
{
	jarvis jvs;

	jvs.battery_level(0xEF);
	jvs.emergency_status(0xD);
	jvs.power_connection(0x1);



	cout<<hex<<jvs.result()<<endl;


	return 0;
}