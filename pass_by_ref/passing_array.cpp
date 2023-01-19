#include <iostream>



class A
{
    public:
        int arr[3] = {1,2,3};

};

class B
{
    public:

        void print(int *array)
        {
            std::cout<<"print"<<std::endl;
            std::cout<<array[0]<<std::endl;
            std::cout<<sizeof(array[0])<<std::endl;
            std::cout<<sizeof(array)<<std::endl;
        }

};
int main()
{
    A a;

    B().print(a.arr);

    return 0;
}