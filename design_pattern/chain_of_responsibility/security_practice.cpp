#include <iostream>
#include <vector>


class SecurityCheck
{
	public:
	virtual void check(const std::string& f) const = 0;
};

class VrirusCheck : public SecurityCheck
{
	public:
	virtual void check(const std::string& f) const override {
		std::cout<<"virus check"<<std::endl;
	}


};

class ExtensionCheck : public SecurityCheck
{
	public:
	virtual void check(const std::string& f) const override {
		std::cout<<"file extension check"<<std::endl;		
	}

};

class SecuritySystem
{
	public:
	void addCheck(SecurityCheck* p){
		v.push_back(p);
	}

	void runCheck(const std::string& f){
		for(auto item : v)
			item->check(f);
	}
	private:
	std::vector<SecurityCheck*> v;
};

int main()
{
	SecuritySystem system;

	system.addCheck(new VrirusCheck());
	system.addCheck(new ExtensionCheck());

    std::string filename = "example.txt";


	system.runCheck(filename);

	return 0;
}