#include <iostream>


using namespace std;



using value_type = uint32_t;
uint32_t driving_system_status = 0xF123D580;



// speed = 0xF123
// stb_sts = 0xD
// dri_dir = 2u
// dri_act = 3u

class cartControlWord 
{
public:
	cartControlWord() { }
	virtual ~cartControlWord() { }
	using value_type = uint32_t;
	union data{
		struct __attribute__((packed)) pack_t {
			value_type stb_ctrl : 2;
			value_type : 5;
			value_type rcy : 1;
			value_type : 4;
			value_type rmt_dir : 2;
			value_type rmt_act : 1;
			value_type : 1;
			value_type dri_max_spd : 16;
		} pack;
		value_type command;
	};

	struct stabillizer_command{
		static constexpr value_type up = 2u;
		static constexpr value_type down = 1u;
		static constexpr value_type neutral = 0u;

	};
	struct cart_command{
		static constexpr value_type forward = 2u;
		static constexpr value_type backward = 1u;
		static constexpr value_type neutral = 0u;
		static constexpr value_type activate = 1u;
		static constexpr value_type deactivate = 0u;
		static constexpr value_type max_speed = 10u;
	};

};

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


		cartControlWord::value_type remote_cart_control(const cartControlWord::value_type value) 
		{
			cartControlWord::data set;
			set.command = 0;
			// priority stabilizer > remote drive ?
			//if(stabilizer_status()){
				//throw  ;
			//}
			if(value){
				set.pack.dri_max_spd = cartControlWord::cart_command::max_speed;
				set.pack.rmt_act = cartControlWord::cart_command::activate;
				set.pack.rmt_dir = value;
			}
			cout<<hex<<set.command<<endl;
			return true;//cart_control_word().write(set.command);
		}


		cartControlWord::value_type recovery() 
		{
			bool ret = false;
			bool flag = false;
			cartControlWord::data set;
			set.command = 0;
			set.pack.rcy = 1u;
			//cart_control_word().write(set.command);

			cout<<hex<<set.command<<endl;
			// int32_t i;
			// for(i=0; i< timeout; i++){
				
			// 	mst().wait_for(1u);
			// 	// TBD
			// 	if(emergency_status() ){
			// 		flag = true;
			// 	}else{
			// 		ret = true;
			// 	}
			// 	if(flag){
			// 		cart_control_word().write(0);
			// 	}
			// }
			return  ret;
		}

		cartControlWord::value_type stabilizer_control(const cartControlWord::value_type value) 
		{
			cartControlWord::data set;
			set.command = 0;

			set.pack.stb_ctrl = value;
			cout<<hex<<set.command<<endl;
			return true; //cart_control_word().write(set.command);
		}



};


			
			



int main()
{

	//spider spd;

	// uint32_t status = 0x000000F0;

	// bool ret= false;

	// ret = !status;
	// cout<<ret<<endl;

	// ret = status; 
	// cout<<ret<<endl;
	spider spd;

	spd.recovery();


	spd.remote_cart_control(cartControlWord::cart_command::forward);
	spd.remote_cart_control(cartControlWord::cart_command::backward);
	spd.remote_cart_control(cartControlWord::cart_command::neutral);

	cout<<"================="<<endl;
	spd.stabilizer_control(cartControlWord::stabillizer_command::up);
	spd.stabilizer_control(cartControlWord::stabillizer_command::down);
	spd.stabilizer_control(cartControlWord::stabillizer_command::neutral);
	

	// cout<<hex<<spd.driving_max_speed()<<endl;
	
	// cout<<(int)spd.dridir()<<endl;
	// cout<<spd.driact()<<endl;
	// cout<<(int)spd.stabillizer()<<endl;

	return 0;
}
