#include <iostream>



using namespace std;


void foo(int& a)
{
	a= 200;
}

template <typename T>
void call_foo(T arg)
{
	foo(arg);

	//cout<<arg<<endl;
}


template <typename T>
class ref_wrapper
{
	public:
		ref_wrapper(T* arg):obj(arg){}
	
		operator T&()
		{
			return *obj;
		}
	private:
		T* obj;
};

template<typename T>
ref_wrapper<T> myref(T& arg)
{

	return ref_wrapper<T>(&arg);
}
int main()
{

	int n = 0;

	//call_foo( ref(n));

	//call_foo( n);
	
	call_foo(myref(n));
	//call_foo(n);
	
	std::cout<< n <<std::endl; //200
	
	return 0;
}