#include <iostream>


class CWinApp;


CWinApp* gptr;

class CWinApp
{
	public:
		CWinApp() { std::cout<<"global constructor" <<std::endl; gptr = this;}
		virtual bool init() { return false;}
		virtual bool fini() { return false;}

};


class MyApp: public CWinApp
{

	public:
		virtual bool init() override {
			std::cout << "init" <<std::endl;

			return true;
		}
		// bool run(){
		// 	std::cout <<" run " <<std::endl;
		// }
		virtual bool fini() override {
			std::cout << "fini" <<std::endl;
			return true;
		}

};



MyApp app;

int main()
{
	gptr->init();

	gptr->fini();	
	return 0;
}

