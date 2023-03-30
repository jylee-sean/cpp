/// @brief  book recommendation : modern c++ design 
/// @return 
#include <iostream>


class Mutexlock
{
	public:
		inline void lock() {std::cout <<"lock "<<std::endl; }
		inline void unlock() {std::cout << "unlock"<<std::endl; }
};

class Nolock
{
	public:
		inline void lock() { }
		inline void unlock() { }
};


template< typename T, typename policy = Nolock > 
class List
{
	private:

		policy p;
	public:
		void push(const T& data){
			p.lock();
			p.unlock();
		}

}; 


int main()
{

	Mutexlock ml;

	List<int> list;

	list.push(3);

	return 0;
}

