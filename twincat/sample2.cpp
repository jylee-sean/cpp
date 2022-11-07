
// ref: https://coder-in-war.tistory.com/entry/C-13-%ED%95%A8%EC%88%98-%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%B0%B0%EC%97%B4-%ED%99%9C%EC%9A%A9%ED%95%98%EA%B8%B0


#include <iostream>



using namespace std;
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
int i=10;
int j=20;
int k=30;
int *arr[3] = {&i, &j, &k};

//int *ptr;



class A
{
    typedef  bool (A::*fp)(void);  

    private:
        fp fparr[3] = {&A::f1, &A::f2, &A::f3};
    protected:
        int b;

        fp* execute;
        fp* execute2;
    public:

        A()
        {
            execute = fparr;
            //execute2 = fparr+1;
            //execute = *fparr;
            //execute2 = *(fparr+1); //(this->*(fparr+1));
        }
        inline bool f1()
        {
            std::cout<<"f1"<<std::endl;
            b = b*b;
            return true;
        };


        inline bool f2()
        {
            std::cout<<"f2"<<std::endl;
            return true;
        };

        inline bool f3()
        {
            std::cout<<"f3"<<std::endl;
            return true;
        };


        void func(){


            //CALL_MEMBER_FN(*this, fparr[0])();

            //(*this.*fparr[0])();


            //(*this.**execute)();
            (this->**execute)();
            //*(*this.*execute)();

            execute= execute+1;
            //(*this.**execute2)();
            //(*this.*execute)();
            //(*this.*execute2)();



        }
};


bool f4()
{
    std::cout<<"f4"<<std::endl;
    return true;
}


bool f5()
{
    std::cout<<"f5"<<std::endl;
    return true;
}


//bool (*fparr2[5])(void) = {f2, f4};
int main(void)
{

    A a;

    //bool (*fparr[3])(void) = {a.f1, a.f2, a.f3};

    //sCALL_MEMBER_FN(a,fparr[0])();

    a.func();
    a.func();
    a.func();
    //e = fparr[0];


    //e();
   //std::cout<<reinterpret_cast<fp>(fparr)<<std::endl;
   //std::cout<<reinterpret_cast<fp>(fparr[0])<<std::endl;
   //std::cout<< fparr[0] <<std::endl;
    //e = *(fparr[0]);


    //e;
    //e[0];

    //*fparr[0];



//    a.fparr[0]();
//    a.fparr[1]();
//    a.fparr[2]();
    return 0;
}