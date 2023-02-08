/*
 * Q4. Fibonacci Numbers
 * 
 * Fibonacci numbers are a sequence of whole numbers arranged as 
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,... 
 * Every number is the sum of the preceding two numbers.
 * 
 * Write a recursive function in C/C++ that takes in an integer 
 * and return the n-th Fibonacci number. 
 */

#include <iostream>

using namespace std;

int getNext(int n1, int n2)
{
    return n1 + n2;
}
int Fibonacci(int n) {
    // Write code here

    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if (n==3)
        return 0 + 1;


    return Fibonacci(n-2) + Fibonacci(n-1);

}

int main() {
    int n;
    cout << "The nth Fibonacci number to find: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << Fibonacci(n) << endl;
    return 0;
}
