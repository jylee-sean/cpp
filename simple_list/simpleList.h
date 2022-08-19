#include <iostream> 
#include <array>

//using namespace std;

template <typename T>


class SimpleList
{
    private:
        //T items[10];
        std::array<T, 10> items;
        int top;
        enum {SIZE = 10};

    public: 
        SimpleList() { 
            top=0; 
        }
        int getMaxSize(){
            return SIZE;
        }
        bool push(const T& item){
            if(top < SIZE){
                items[top++]=item;
                std::cout<<item<<" is pushed"<<std::endl;
                std::cout<<"cnt:"<<top<<std::endl;

                return true;
            }
            else{
                std::cout<<item<<" is not pushed"<<std::endl;
                std::cout<<"cnt:"<<top<<std::endl;
                this->isFull();
                return false;
            }
        }
        bool pop(){
            if(top>0){
                items[--top];
                std::cout<<items[top]<<" is popped"<<std::endl;
                std::cout<<"cnt:"<<top<<std::endl;
                return true;
            }
            else{ 
                std::cout<<"can't pop"<<std::endl;
                std::cout<<"cnt:"<<top<<std::endl;
                this->isEmpty();
                return false;
            }
        }

        bool isEmpty() const{
            return top == 0;
        }
        bool isFull() const{
            return top == SIZE;
        }

        void printList(){
            std::cout<<"current: ";
            for(int i=0;i<top;i++){
                std::cout<<items[i]<<' ';
            }
            std::cout<<"\n-------------------------"<<std::endl;
        }

        ~SimpleList(){};

};

    





