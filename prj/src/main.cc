


#include <getopt.h>
#include "../include/main.h"


//using namespace ssi;


int main(int argc, char* argv[])
{

	int option;
	int option_index;

	bool debug = false;
	

	std::cout << argv[1] <<" "<<*argv[2] <<std::endl;
	std::cout <<"count:"<< argc-1 <<std::endl;


	struct option long_options[] ={
		
		{"enrtry", required_argument, 0, 'e'},
		{"debug", no_argument, 0 ,'d'},
		{"version", no_argument, 0, 'v'}
	};

	while((option = getopt_long(argc,argv, "vve:", long_options, &option_index)) != -1)
	{
		switch(option)
		{
			case 'd':
				debug = true;
				break;
			case 'v':
				std::cout << "version:" ;
				exit(0);
				break;
		}
	}

	double dt = 0.0;

	//struct stat st;   stat ? pps ? ham ?


	std::cout<< "stat pps file" <<std::endl;
	std::cout<< "ham connect" <<std::endl;

	::pthread_setname_np( "main()");


	_runtime.init();



	return 0;
}
