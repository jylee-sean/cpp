#include <iostream>
#include <string>
#include <memory>
#include <functional>
// https://m.blog.naver.com/hikari1224/221433853707

class ClosureType
{
    public:
        ClosureType(){std::cout<<"Constructor called"<<std::endl;};

        bool func(int a, int b) const{
            std::cout<<" func called"<<std::endl; 
            return a + b;
        }
        bool operator()(int a , int b) const { 
            std::cout<<"() operator called"<<std::endl; 
            return a < b ;
            }
        bool operator()(double a , double b) const { 
            std::cout<<"() double operator called"<<std::endl; 
            return a < b ;
            }
        bool operator()(int a , int b, int c) const { 
            std::cout<<"() operator2 called"<<std::endl; 
            return a < b ;
            }
            
};


void print(int (&arr)[7])
{
    for(auto &element : arr)
        std::cout<<element <<" ";
    std::cout<<"\n";
}


#include <typeinfo>


class Song
{
    private:
        std::string  title;
    public:
        Song(std::string t):title(t) {};

        void print(){std::cout<<title<<std::endl; };
};


typedef int (*fp)(int, int);

void foo(fp f)
{
    int res = f(12,24);

    std::cout<<res<<std::endl;

};


using ff =  std::function<int(int, int)>;


void foo2(ff f)
{
    int res = f(12,24);

    std::cout<<res<<std::endl;

};



class Test
{
    private:
        int data = 0;
    public:
        void foo()
        {
            int val = 10;
            auto f1 = [this] () {data = 10;};
            auto f2 = [*this] () {data = 10;};
            f2();
        }
        void print(){
             std::cout<<this->data<<std::endl;
        }
};

void f_print(int n)
{
    std::cout<<n<<" ";
}
int main(void)
{



    //int v[5]= {1,2,3,4,5};

    //std::for_each(&v[0], &v[4], [](auto n){std::cout<< n << " ";});


    //std::cout<<std::endl;;
    //std::for_each(&v[0], &v[5], f_print);
    //std::cout<<std::endl;;

    Test t;
    t.foo();
    t.print();

    //int (*f)(int a, int b) = [=](){return a+b;};
    //auto l = [](int a, int b){ return a>b; };

    //foo([](int a, int b){return a*b;});
    //foo([](int a, int b){return a+b;});

    // auto closure = [ ](int a, int b) { return a * b; } ;                             //  inline replacement - O 

    // foo(closure);

    // int (*f)(int, int) = [ ](int a, int b) { return a * b; };                          //  inline replacement - X
    
    // foo(f);

    // f =  [ ](int a, int b) { return a + b; };   

    // foo(f);

    // std::function<int(int, int) > func = [ ](int a , int b) { return a* b; };   //  inline replacement - X

    // //foo(func);

    // foo2(func);

    // func =  [ ](int a , int b) { return a + b; };

    // foo2(func);

    // foo2(closure);    

    //std::cout<< typeid(l).name() <<std::endl;
    //std::cout<< typeid(l2).name() <<std::endl;

    //case1
    //double nums[7] = {5,6,7,132,53,55,99};
    //print(nums);

    //ClosureType c;

    
    //std::sort(nums, nums+7, ClosureType());


    //c(1,2,3);

    //std::sort(nums, nums+7, [](int a, int b){ return a < b ; } );
    //print(nums);


    //std::cout<<ClosureType()(3, 4)<<std::endl;




    //auto res1= [](int a, int b){ return a < b ;};

    //auto res2 = [](int a, int b){ return a < b ;}(44, 57); 

    //std::cout<<res1<<" "<<res2<<std::endl;

    // int val1 = 20; 
    // int val2 = 30; 
    // auto f = [val1, val2]( ) { return val1 + val2; };

    // auto f2 = [ ] () { return true; };

    // std::cout<<sizeof(f)<< ","<<sizeof(f2) <<std::endl;

    // std::string s = "hello world";

    // auto f2 = [d = move(s)] () { std::cout<<d<<std::endl; };



    // std::cout<<s<<std::endl;
    // f2();


    //std::unique_ptr<Song> song("dancing queen");

    // auto ptr = std::make_unique<Song>("dancing queen");
    // ptr->print();
    // auto f12 = [p= move(ptr) ]() {p->print();};
    // f12();
    // if(ptr == nullptr){
    //     std::cout<< "null ptr"<<std::endl;
    // }
     

    //  const int val = 100;

    //  auto fff = [](){return val;};

    //  fff();

    //ptr->print();
    //std::cout<<sizeof(a)<<std::endl;

    return 0;
}