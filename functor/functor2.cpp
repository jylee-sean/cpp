

#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void sort(int* x , int sz, bool (*cmp)(int, int))
{
    for(int i=0; i< sz-1 ; i++){
        for(int j=i+1; j<sz; j++){
            if(cmp(x[i],x[j])){
                swap(x[i],x[j]);
            }
        }
    }
}
inline bool cmp1(int a, int b){return a>b;}
inline bool cmp2(int a, int b){return a<b;}


template<typename T>
void sort(int*x , int sz, T cmp)
{
    for(int i=0; i< sz-1 ; i++){
        for(int j=i+1; j<sz; j++){
            if(cmp(x[i],x[j])){
                swap(x[i],x[j]);
            }
        }
    }
}


struct Less
{
    inline bool operator()(int a, int b) const {return a>b;}
};

struct Greater
{
    inline bool operator()(int a, int b) const {return a<b;}
};

int main()
{

    int x[10] = {1,3,4,5,76,213,15,79,2,100};
    
    // case1. functio pointer
    //sort(x, 10, &cmp1);


    // case2. function object
    Less f1;
    Greater f2;

    sort(x, 10, f1);

    for( auto e: x)
        cout<<e<<",";
    cout<<endl;
    return 0;
}