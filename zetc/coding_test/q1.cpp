/* Q1.Reverse String
 * Write a function in C/C++ that takes in a string and reverses it. 
 * The function should return the reversed string as output.
 */

#include <iostream>
#include <string>

std::string reverse_string(const std::string &str) {
  // Write code here
  
  std::string res="";
  std::string::const_iterator it;
  for(it = str.end()-1; it != str.begin(); it--){
    //std::cout<< *it <<" ";
    res+=(*it);
  }
  res+=(*it);
  
  return res;
}

int main() {
  //std::string test_str = "Hello, World!";
  std::string test_str("Hello, World!");
  std::cout << reverse_string(test_str) << std::endl;
  return 0;
}

