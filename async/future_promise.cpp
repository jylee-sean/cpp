
#include <iostream>
#include <future>
#include <thread>

using namespace std;

int main()
{
	int res;	
	// std::promise<bool> exitsignal;
	// std::future<bool> ft = exitsignal.get_future();

	//exitsignal.set_value(true);

	std::atomic<bool> flag{true};



	std::thread t([&] 
		{	while(flag)
			{

				int rmt_dir_data =1;
				int rmt_act_data =2;

				std::cout<< "Remote Driving Activation: ";
				if(rmt_dir_data == 1){
					std::cout<< "Activated \t";
				}
				else{
					std::cout<< "Deactivated \t";
				}
				std::cout<< "Remote Driving Direction:";
				if(rmt_dir_data == 0){
					 std::cout << "Neutral "<<std::endl;
				}else if(rmt_dir_data ==1){
					  std::cout << "Backward "<<std::endl;
				}else if(rmt_dir_data ==2){
					  std::cout << "Forward "<<std::endl;
				}else{
					  std::cout << "Undefined "<<std::endl;
				}
			} 
			std::cout<<"---loop end---"<<std::endl;
		});



	std::cin>>res;	
	std::cout<<"seg value"<<std::endl;
	flag = false;
	//exitsignal.set_value(false);

	std::cout<<"put value"<<std::endl;
	std::cin>>res;	
	return 0;
}

	
