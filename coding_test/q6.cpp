/*
 * Swap
 * Write a function swap in C/C++ that takes two integer pointers as arguments 
 * and swaps the values of the two integers. 
 */

#include <iostream>

void swap(int* a, int* b) {
	// Write code here  

	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp; 

}

void swapByRef(int* &p1, int* &p2) {
	// Write code here  

	std::cout<< *p1 << " "<< *p2 <<std::endl;
	int tmp;
	
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main() {
    int x = 5;
    int y = 10;
    int* px = &x;
    int* py = &y;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    swapByRef(px, py);
    std::cout << "After swapByRef: x = " << x << ", y = " << y << std::endl;
    return 0;
}