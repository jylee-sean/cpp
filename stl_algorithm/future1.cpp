

/* t.join 을 수행하면서 다시 file_read 쓰레드를 실행??? */

#include <string>
#include <iostream>
#include <thread>
#include <algorithm>
#include <cstring>

using namespace std;
 
// Custom string class
class Mystring {
 
    // Initialise the char array
    char* str;
    int length;

 
public:
    // No arguments Constructor
    Mystring(): str{ nullptr }
    {
        str = new char[1];
        length = 0;
        str[0] = '\0';
    }
 
    // Constructor with 1 arguments

    Mystring(char* val)
    {
        if (val == nullptr) {
            str = new char[1];
            str[0] = '\0';
        }
        else {
            str = new char[strlen(val) + 1];
    
            // Copy character of val[]
            // using strcpy
            strcpy(str, val);
            str[strlen(val)] = '\0';

            length = strlen(val);
            cout << "The string passed is: " << str << endl;
        }
    }
    
    // Copy Constructor
    Mystring(const Mystring& source)
    {
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
        str[strlen(source.str)] = '\0';
    }
 
    // Move Constructor
    Mystring(Mystring&& source)
    {
        str = source.str;
        source.str = nullptr;
    }
    
    Mystring& operator+(const Mystring &val){
        int newSize = val.length + this->length;
        char* tmp = new char[newSize];
        snprintf(tmp, newSize, "%s%s", this->str, val.str);
        Mystring *ret = new class Mystring(tmp);
        return *ret;
    }

    Mystring& operator=(const Mystring &val){
        swap(val.str, str);
        this->length = val.length;
        return *this;
    }
    // Destructor
    ~Mystring() { delete str; }
};
 




Mystring& do_something_with_txt(Mystring& txt){
    Mystring res = txt + "_add";
    //cout<<res<<endl;
    return txt;
}


void do_other_computation(){
    cout<<"do other task"<<endl;
}


void file_read(Mystring* result) {
  //string txt = read("a.txt");  // (1)
  Mystring txt = "hello world";
  *result = do_something_with_txt(txt);
  //cout<<*result<<endl;
}
int main() {
  //string result2;
  Mystring result;

  //cout<<sizeof(result)<<" "<<sizeof(result2)<<endl;
  thread t(file_read, &result);
  do_other_computation();  // (2)
  t.join();
}
