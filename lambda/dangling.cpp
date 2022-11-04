
/*
* https://bbagwang.com/programming/cpp/c-%EC%97%90%EC%84%9C%EC%9D%98-lambda
*/

#include <iostream>
#include <vector>
#include <functional>


using Container = std::vector<std::function<void(void)>>;

Container con;
class Test
{
    public:
        Test(){
            m_vec.push_back(10);
            m_vec.push_back(20);
        };
        void push_back_lambda_function(){
            con.emplace_back([=] {
                std::cout<<"default by value: "<<m_vec[0]<<std::endl;  
                } );

            con.emplace_back([&]{
                std::cout<<"default by reference: "<<m_vec[1]<<std::endl;
            });
        };
    private:
        std::vector<int> m_vec;
};



enum st{
    st_1 = 1,
    st_2 = 2,
    st_3 = 3
};

int main()
{
    auto instance = new Test;

    instance->push_back_lambda_function();

    con[0]();
    con[1]();   
    delete instance;
    instance = nullptr;

 
    std::cout<< 400 + st::st_1*10 + 1 <<std::endl;
    return 0;
}