#include <iostream>


using std::cout;
using std::endl;

class String{

    private:
        char *str;
        int len;

    public:
        String(char c, int n); /* 문자 c 가 n개인 문자열로 정의 */
        String(const String &s); // 대입 연산자?

        void add_string(const String &s); /* str 뒤에 s를 붙임 */
        void copy_string(const String &s);  /* s를 복사한 값을 str에 대입 */
        int strlen(){
            return this->len;
        }

        void printout(){
            cout<<str<<endl;
        }
};

String::String(char c, int n)
{
    this->str = new char[n];
    this->len = n;

    for(int i=0; i< n; i++){
        str[i]=c;
    }
}

String::String(const String &s)
{
    this->str = s.str;
}

void String::add_string(const String &s)
{

    //this->str = s.str;

    for(int i=0; i< s.len ;i++){
        this->str[this->len+i] = s.str[i];
    }



}

void String::copy_string(const String &s)
{
    this->str = s.str;
    this->len = s.len;


}

int main(){

    String sc('c',15);
    //sc.printout();
    String sa('a',10);

    //String sd(sc);
    sa.printout();
    sa.add_string(sc);
    sa.printout();
    sc.copy_string(sa);
    sc.printout();


    

    return 0;
}



