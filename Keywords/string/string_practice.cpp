#include <iostream>


using std::cout;
using std::endl;

class String{

    char *str;
    int len;

    public:
        String(char c, int n); /* 문자 c 가 n개인 문자열로 정의 */
        String(const String &s);

        void add_string(const String &s); /* str 뒤에 s를 붙임 */
        void copy_string(const String &s);  /* s를 복사한 값을 str에 대입 */
        int strlen();
};


String::String(char c, int n){
    str = new char[n];
    len = n;
    for(int i=0;i<len;i++){
        str[i]=c;
    }
}

String::String(const String &s){
    cout<<"복사생성자"<<endl;
    str =s.str;
    len =s.len;
    
}

void String::add_string(const String &s)
{
    char *temp = new char[len+s.len];

    for(int i=0;i<len; i++){
        temp[i]=str[i];
    }
    for(int i=0;i<s.len;i++){
        temp[len+i]=s.str[i];
    }
    /* 함수 내부에서 동작할당한 메모리 반환하고 str 포인터를 재정의*/
    str = new char[len+s.len];
    str = temp;
    delete [] temp;
}

void String::copy_string(const String &s){
    if(len > s.len){
        str = s.str;
        len = s.len;
    }else{
        char *temp = new char[len];
        
        for(int i=0;i<len;i++){
            temp[i]= str[i];
        }

        len = s.len;
        str = new char[len];
        for(int i=0;i<len;i++){
            str[i]=s.str[i];
        }

    }

}

int String::strlen()
{
    return len;
}
int main(){

    String sc('c',15);
    String sa('a',10);

    String sd = sc;
    sa.add_string(sc);

    sa.copy_string(sc);



    return 0;
}



