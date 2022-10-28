#include <iostream>

// https://m.blog.naver.com/hikari1224/221433853707

class ClosureType
{
    public:
        bool operator()(int a , int b) const { return a < b ;}
};


void print(int (&arr)[7])
{
    for(auto &element : arr)
        std::cout<<element <<" ";
    std::cout<<"\n";
}


int x= 10;

int f1(){return x;}

int& f2(){return x;}

typedef struct _struct_test{
    int data1;
    int data2;
} testData;


void func(testData *data){



    std::cout<<data->data1<<std::endl;
    std::cout<<data->data2<<std::endl;

    data->data1 = 1000;
}


int main(void)
{
    //case1
    //int nums[7] = {5,6,7,132,53,55,99};
    //print(nums);
    //std::sort(nums, nums+7, ClosureType());
    //print(nums);

    //case2
    /*int value = 10;
    auto a = [&] () {
         value = 20; 
         std::cout<<value<<std::endl;
         return;
    };
    a();
    std::cout<<value<<std::endl;
    */

    //case3
    /*
    int nums[7] = {5,6,7,132,53,55,99};


    for(auto const &&num : nums){
        //num*=10;
        std::cout<<num<<" "<<std::endl;
    }
    std::cout<<std::endl;

    for(auto num : nums){
        
        std::cout<<num<<" "<<std::endl;
    }*/



//    std::cout<<f1()<<std::endl;


    //f2() = 20;
    //std::cout<<x<<std::endl;


    //int n = 0;
    //n= 10;

    //n++ = 20;
    //++n = 20;

    //std::cout<<n<<std::endl;

    //int a = 10, int b= 0;

    //a+b=20;

    int n = 10;

    //int &r = n;

    int &&r2 = 10;



    //std::cout<<r2<<std::endl;
    //std::cout<<&r2<<std::endl;
    //std::cout<<&&r2<<std::endl;
    //std::cout<<&n<<std::endl;

    
    std::ratio<1000,1> r;

    //std::kilo
    //std::cout<<r.num<<std::endl;
    //std::cout<<r.den<<std::endl;




    testData dd;
    dd.data1 = 10;
    dd.data2 = 20;

    _struct_test testData2;



    func(&dd);


    std::cout<<dd.data1<<std::endl;
    std::cout<<dd.data2<<std::endl;



    return 0;
}