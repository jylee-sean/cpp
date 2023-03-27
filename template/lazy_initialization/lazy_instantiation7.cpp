template<typename T> void fn(T value, int)
{
	*value = 10;
}

template<typename T> void fn(T value, double)
{
}

int main()
{
//	fn(1, 3);
	fn(1, 3.4);
}

// 동일한 이름이 함수(템플릿)이 여러개 있을때 
// 어느 함수를 사용할지 컴파일 시간에 결정됨
// 선택되지 않은 함수가 템플릿인 경우 인스턴스화 되지 않음