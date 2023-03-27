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
        bool isEmpty() const{
            return top == 0;
        }
        bool isFull() const{
            return top == SIZE;
        }

        bool push(const T& item){
            if(isFull()){
                std::cout<<item<<" is not pushed"<<std::endl;
                std::cout<<"idx:"<<top<<std::endl;
                return false;
            }else{
                items[top++]=item;
                std::cout<<item<<" is pushed"<<std::endl;
                std::cout<<"idx:"<<top<<std::endl;
                return true;
            }
        }
        bool pop(){
            if(isEmpty()){
                std::cout<<"can't pop"<<std::endl;
                std::cout<<"idx:"<<top<<std::endl;
                return false;
            }else{
                items[--top];
                std::cout<<items[top]<<" is popped"<<std::endl;
                std::cout<<"idx:"<<top<<std::endl;
                return true;
            }
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

    





