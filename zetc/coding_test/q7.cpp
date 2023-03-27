#include <iostream>

int sumOfDigits(int n) {
	// Write code here
	if(n<10)
		return n;


	return (n%10) + sumOfDigits(n);
}

int main() {
    int n = 12345;
    std::cout << "The sum of the digits of " << n << " is " << sumOfDigits(n) << std::endl;
    return 0;
}