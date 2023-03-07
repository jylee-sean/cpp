
#include <iostream>
class Child
{
public:
    int age;
    void run() {
        std::cout << "자식 run" << std::endl;

		std::cout<< this << std::endl;
    }

    virtual void run2() {
        std::cout << "자식 run" << std::endl;
    }
};

int main(void)
{	

	// case 1 non-virtual 함수 : 실행됨
	Child *temp = nullptr;
	temp->run();


	Child c;
	c.run();
	// // case 2 virtual 함수 : segfualt
	// Child *temp2 = NULL;
	// temp2->run2();

	// // case3 멤버변수 : segfault
	// Child *temp3 = NULL;
	// std::cout << temp3->age << std::endl;



}


