#include <iostream>
#include <memory>

class Hi : public std::enable_shared_from_this<Hi> {
public:
	Hi() {
		std::cout << "construct\n";
	}
	~Hi() {
		std::cout << "destruct\n";
	}
   	std::shared_ptr<Hi> getptr() {
		return shared_from_this();
	}
};


int main() {
	Hi* h = new Hi;
	std::shared_ptr<Hi> ptr(h);
    
	std::shared_ptr<Hi> ptr2 = ptr->shared_from_this();
	return 0;	
}

