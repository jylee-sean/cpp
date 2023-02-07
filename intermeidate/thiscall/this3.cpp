#include <iostream>

#include <pthread.h>

using namespace std;



class Thread
{
public:
	void run()
	{
		pthread_t thread;
		pthread_create(&thread, NULL, threadMain, (void*)this);
	}

	// 아래 함수가 반드시 static 이어야 할때, 함수 인자로 this를 전달하는 방법 -> 다른 Non-static 멤버함수(run)를 만들고 그안에서 스레드를 만들면서 인자로 this를 넘김
	static void* threadMain(void *p)
	{
		Thread* const self = static_cast<Thread*>(p);
		self->Main();
		return 0;
	}

	virtual void Main()
	{

	}
};


// 사용자 라이브러리 코드
class MyThread : public Thread
{
public:
	virtual void Main() {cout<< "thread task " << endl;}
};

int main()
{

	MyThread t;


	t.run();

	getchar();

	

	

	// pthread_t thread;
	// pthread_create(&thread, NULL, thread_routine, (void*)"A");

	return 0;
}




/***
 * 
 * int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
 * 
   1. thread : 성공적으로 함수가 호출되면 이곳에 thread ID가 저장됩니다. 이 인자로 넘어온 값을 통해서 pthread_join과 같은 함수를 사용할 수 있습니다.
   2. attr : 스레드의 특성을 정의합니다. 기본적으로 NULL을 지정합니다. 만약 스레드의 속성을 지정하려고 한다면 pthread_attr_init등의 함수로 초기화해야합니다.
   3. start_routine : 어떤 로직을 할지 함수 포인터를 매개변수로 받습니다. 
   4. arg : start_routine에 전달될 인자를 말합니다. start_routine에서 이 인자를 변환하여 사용합니다
*/