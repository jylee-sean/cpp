#include <vector>
#include <queue>

template<typename T, typename C> class queue
{
	C c;
public:
	void push(const T& a) {	c.push_back(a);	}
	void pop() 			  {	c.pop_front();	}
};

int main()
{
//	queue<int, std::vector<int>> q;
	std::queue<int, std::vector<int>> q;
	q.push(10);
	q.pop(); // error
}


// vector는 앞쪽으로 push /pop 할 수 없음

// std::queue에 std::vector 쓰지말라고 가이드

// pop이 호출될때 (instatiation될때) error