/* Q3.Replace Odd with Zero
 * Write a function in C/C++ that takes in a pointer to an array of integers 
 * and the size of the array, and replaces all odd elements in the array with 0. 
 * The function should modify the original array and return nothing.
 */

#include <iostream>

void replace_odd_with_zero(int *arr, int n) {
  // Write code here
  for(int i =0;i<n ; i++){
    // if(arr[i]%2 == 1){
    //   arr[i] = 0;
    // }
  
    if( *(arr+i)% 2== 1){
      *(arr+i) = 0;
    }
  }
}


// 배열 이름은 포인터 
int main() {
  int arr[] = {5, 3, 7, 1, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  replace_odd_with_zero(arr, n);

  for (int i = 0; i < n; i++) {
      std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

