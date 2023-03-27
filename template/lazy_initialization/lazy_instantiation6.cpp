template<typename T> 
void fn(T value)
{
//	if ( false )   :: if(false) 이므로 실행은 안되지만, 인스턴스화 됨(컴파일 에러 발생)
	if constexpr ( false ) // constexpr compile 시간 if 문 (컴파일 에러 없음)
		*value = 10;
}

int main()
{
	int n = 10;
	fn(n);
}
