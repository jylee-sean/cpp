
// 구현이 동일한 함수가 여러개 필요하면 함수를 만들지 말고 함수를 생성하는 틀(템플릿)을 만들자

// int square(int a)
// {
// 	return a * a;
// }

// double square(double a)
// {
// 	return a * a;
// }


template<typename T>
T square(T a)
{
    return a*a;
}
int main()
{
	//square(3);	
	//square(3.3);
    square<int> (3);
    square<double> (3);

}


/* 템플릿 함수 만드는 방법
 * 함수 앞에 template<typename T> 추가
 * int 를 T  로 변경
 */

/**
 *  template 을 이용해서 컴파일러가 실제 함수를 생성 (template 인스턴스화)
 * 
 */

/**
 * @ 타입 인자를 생략하면 컴파일러가 함수 인자를 보고 타입을 추론 (type deduction)
 * square(3.3);
 */

/***
 * 템플릿  인스턴스화 결과 확인 방법
 * 1. 어셈블리 코드 확인 : godbolt.org (compiler explorer)
 * 2. cppinsights.io
 * 3. 템플릿 인스턴스화의 결과로 생성된 함수 이름을 출력
 */
 
