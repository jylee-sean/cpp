
// ref: https://coder-in-war.tistory.com/entry/C-13-%ED%95%A8%EC%88%98-%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%B0%B0%EC%97%B4-%ED%99%9C%EC%9A%A9%ED%95%98%EA%B8%B0


#include <iostream>




using namespace std;

bool f1()
{
    std::cout<<"f1"<<std::endl;
    return true;
}


bool f2()
{
    std::cout<<"f2"<<std::endl;
    return true;
}

bool f3()
{
    std::cout<<"f3"<<std::endl;
    return true;
}


bool (*fparr[3])(void) = {f1, f2, f3};


int main(void)
{
    //std::cout<<"bool:"<<sizeof(bool)<<std::endl;
    //std::cout<<"int:"<<sizeof(int)<<std::endl;
    //std::cout<<"double:"<<sizeof(double)<<std::endl;
    //std::cout<<"size_t:"<<sizeof(size_t)<<std::endl;

    //std::cout<<sizeof(fparr)<<std::endl;

    //for(int i=0; i<3; ++i){

    int *a;

    int *c, *d;
    int *b[2] = {c,d};

    a = (*b);

    a = ++(*b);
    int cnt = 0;

    bool (**fp)(void);

    //fp = (*fparr);

    fp = fparr;


    std::cout<<fparr<<std::endl;
    std::cout<<reinterpret_cast<void *>(*fparr)<<std::endl;
    std::cout<<reinterpret_cast<bool *>(&f1)<<std::endl;
    std::cout<<reinterpret_cast<bool *>(*fp)<<std::endl;

    std::cout<<reinterpret_cast<void *>(*(fparr+1))<<std::endl;
    std::cout<<reinterpret_cast<bool *>(&f2)<<std::endl;

    //*fp = *(fp+1);
    std::cout<<reinterpret_cast<bool *>(*fp)<<std::endl;

    //std::cout<<fp<<std::endl;
    
    while(1)
    {

        //cout<<cnt<<endl;
        (*fp)();

        *fp = *(fp+1);
        
        
        
        
        //std::cout<<"size:"<<sizeof(fparr)/sizeof(*fparr)<<std::endl;
    

        cnt+=1;
        if(cnt==sizeof(fparr)/sizeof(*fparr)){
            break;
        }
        
        
    };



    return 0;
}