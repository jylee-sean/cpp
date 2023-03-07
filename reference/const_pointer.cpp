#include <iostream>


using namespace std;


int main()
{


	int val = 10;

	const int *a = &val;
	int const *b = &val;
	int* const c = &val;

	int other = 15;


	cout<< "pointer a address: " <<a << endl;
	a = &other;
	cout<< "pointer a address: " <<a << endl;


	//*a = 20;


	cout<< "pointer c address: " <<c << endl;

	//c = &other; //impossible

	*c = 20;

	// cout<< "val address: " <<&val << endl;
	// cout<< "ref1 address: " <<&ref1 << endl;


	// cout<< "val value: " <<val << endl;
	// cout<< "ref1 value: " <<ref1 << endl;


	return 0;
}