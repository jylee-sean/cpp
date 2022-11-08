
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

            /*con.emplace_back([&]{
                std::cout<<"default by reference: "<<m_vec[1]<<std::endl;
            });*/
        };
    private:
        std::vector<int> m_vec;
};



int main()
{
    auto instance = new Test;

    instance->push_back_lambda_function();

    con[0]();
    //con[1]();   
    delete instance;
    instance = nullptr;

    //Test arr[1000];
    con[0]();
    //con[1]();   
 
 
    return 0;
}