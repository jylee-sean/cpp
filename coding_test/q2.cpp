/* Q2.Second Largest  
 * Write a function in C/C++ that takes in an array of integers 
 * and returns the second largest element. 
 * You can assume the array has at least two elements.
 */

#include <iostream>

int second_largest(int arr[], int n) {
  // Write code here  
  int sorted[n] ={0,};
  int tmp;
  //int max = 0;
  for(int i=0;i<n; i++){
    int max = 0;
    for(int j=i; j<n;j++){
      if(max < arr[j] ){
        tmp = max;
        max = arr[j];
        arr[j] = tmp;
        

//        std::cout<<max<<std::endl;
      }
    }
    sorted[i] =max;
  }  

  for(int i=0;i<n ;i++){
    std::cout<< sorted[i] <<" ";
  }
  std::cout<<" "<<std::endl;
  return sorted[1];
}

int main() {
    int arr[] = {5, 3, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << second_largest(arr, n) << std::endl;
    return 0;
}

