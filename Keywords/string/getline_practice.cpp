#include <iostream>
#include <string>


/**
 * @brief std::getline() 함수의 세 번째 매개변수로 delim을 설정하면, 
 * 입력받을 문자열의 구분자(delimiter)를 지정할 수 있습니다. 만약 delim을 ,로 설정하면, 
 * 사용자가 쉼표(,)를 입력할 때마다 문자열이 구분되어 입력받아집니다.
 * 하지만 사용자가 Enter 키를 입력하면, std::getline() 함수는 해당 문자를 구분자로 인식하지 않고 문자열의 끝으로 처리합니다.
 * 따라서 사용자가 Enter 키를 입력하면 문자열 입력이 종료되는 것입니다.
 * Enter 키의 ASCII 코드는 10입니다. 이는 줄바꿈(Newline)을 의미합니다.
 * @return int 
 */
int main() {
    std::string input; // 문자열을 저장할 string 객체

    while (std::getline(std::cin, input, ',')) { // 여러 줄의 문자열 입력받기
        if (input == "EOF") { // 사용자가 EOF를 입력하면 종료
            break;
        }
        std::cout << "You entered: " << input << std::endl;
    }

    return 0;
}


