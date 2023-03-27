#include <memory>
#include <iostream>

struct Node {
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    int value;
    Node(int val): value(val) {
        std::cout << "Node " << value << " created." << std::endl;
    }
    ~Node() {
        std::cout << "Node " << value << " destroyed." << std::endl;
    }
};

int main() {
    std::shared_ptr<Node> head = std::make_shared<Node>(1);
    std::shared_ptr<Node> second = std::make_shared<Node>(2);
    std::shared_ptr<Node> third = std::make_shared<Node>(3);
    
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = head; // 순환 참조
    
	std::cout
	<< head.use_count()  <<" "
	<< second.use_count() << " "
	<< third.use_count()  << std::endl;
    
	return 0;
}