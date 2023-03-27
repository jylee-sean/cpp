
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

