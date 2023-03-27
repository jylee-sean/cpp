#include <iostream>


using namespace std;


int main()
{
	int val = 10;

	int & ref1 = val;
	int const & ref2 = val;
	//int & const ref3 = val;

	// ref1 = 3;
	// ref2 = 6;
	// ref3 = 9;

	// val = 12;

	cout<< "val address: " <<&val << endl;
	cout<< "ref1 address: " <<&ref1 << endl;

	ref1 = 20;

	cout<< "val value: " <<val << endl;
	cout<< "ref1 value: " <<ref1 << endl;


	return 0;
}