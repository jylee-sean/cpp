
// ref: https://coder-in-war.tistory.com/entry/C-13-%ED%95%A8%EC%88%98-%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%B0%B0%EC%97%B4-%ED%99%9C%EC%9A%A9%ED%95%98%EA%B8%B0


#include <iostream>
#include <vector>
#include <functional>

using namespace std;
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

class A;
class B
{
    public:
        //class A;
        typedef  bool (A::*fp)(void);  
        fp *ptr;


};

class A : public B
{


    private:
        fp fparr[3] = {&A::f1, &A::f2, &A::f3};
    
        //std::vector<std::function<bool(void)>> fvec ={f1, f2, f3};
    

        //std::vector<fp> fvec ={&A::f1, &A::f2, &A::f3};
    protected:

        fp* execute;
        fp* execute2;
    public:
        B b;

        A()
        {
            //std::vector<fp>::iterator it = fvec.begin();
            //std::vector<std::function>::iterator it = fvec.begin();
            execute = fparr;
            //execute2 = fparr+1;
            //execute = *fparr;
            //execute2 = *(fparr+1); //(this->*(fparr+1));
        }
        bool f1()
        {
            std::cout<<"f1"<<std::endl;
            return true;
        };


        bool f2()
        {

            std::cout<<"f2"<<std::endl;
            return true;
        };

        bool f3()
        {
            std::cout<<"f3"<<std::endl;
            return true;
        };

        void func(){
            static int i=0;
            //b.ptr = reinterpret_cast<fp> fparr;
            //b.ptr = reinterpret_cast<fp*>(fparr);

            //b.ptr = static_cast<fp*>(fparr);

            b.ptr = fparr;
            //(*(b.ptr))();
            (this->*(b.ptr[i]))();
            i++;
            
            //(this->*fparr[i])();
            //i++;
            //(this->**execute)();
            //execute = execute+1;

            
        }
    private:
        //bool f11();
};


bool A::f11()
{
    return false;
}

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

    bool (A::*e)(void);
    bool (*f)(void);
    

    //a.f1();
    //a.f1();
    //a.f2(2);
    //a.f1();
    //a.f2(2);
    //a.f2(2);
    //a.f2(1);


    a.func();
    a.func();

    std::vector<int> vec;
    std::vector<int> *ptr;


    return 0;
}