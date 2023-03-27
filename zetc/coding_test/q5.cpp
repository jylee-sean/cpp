/*
 * Sort Array
 * Write a C++ function that takes a double pointer to an array of integers and 
 * its size as inputs, sorts the array in ascending order, and returns a vector 
 * of sorted integers.
 */

#include <iostream>
#include <vector>

using namespace std;
std::vector<int> sortArray(int** arr, int size) {
	// Write code here

	std::vector<int> res;

	for(int i = 0;i<size ; i++){
		cout<<*(arr[i])<<endl;
		for(int j= 0; j<5 ; j++){	
			res.push_back(*(arr[i]));
		}
	}
	return res;
}

int main() {
    int size = 5;
    int* arr[5] = {new int(3), new int(5), new int(1), new int(2), new int(4)};
    std::vector<int> sortedArray = sortArray(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << sortedArray[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}