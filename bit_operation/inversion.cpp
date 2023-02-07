

#include <iostream>
#include <bitset>

using namespace std;

// typedef T value_type;
// in(comst& mst, const uint32_t addr, T inversion = 0) : base(mst), _addr(addr), _inversion(inversion) { }
// in(comst& mst, const uint16_t id, const uint32_t addr, T inversion = 0) : base(mst, id), _addr(addr), _inversion(inversion) { }
// virtual ~in() { }


// inline T read() { return _mst.readpdo<T>(comst::in, _addr) ^ _inversion; }


int main()
{
	

	uint8_t inv = 0xf0;

	uint8_t dat = 0x24;



	// 1111 0000 (f0)
	// 0010 0100 (24)
	// 0010 1011 (2B)
	
	uint8_t e = inv ^ dat;
	cout<<bitset<8>(inv)<<endl;
	cout<<bitset<8>(dat)<<endl;


	cout<<hex<<   bitset<8>(e) <<endl;

	return 0;
}