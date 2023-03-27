class Object
{
	int value;
public:
	void mf()
	{
		*value = 10; // compile error
	}
};

int main()
{
	Object obj;
}


// 클래스 템플릿의 멤버함수는 사용된 것만 인스턴스화 됨