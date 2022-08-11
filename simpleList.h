#include <iostream> 
#include <array>

using namespace std;

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

        bool push(const T& item){
            if(top < SIZE){
                items[top++]=item;
                return true;
            }
            else
                return false;

        }
        bool pop(){
            if(top>0){
                items[--top];
                return true;
            }
            else 
                return false;
        }

        bool isEmpty() const{
            return top == 0;
        }
        bool isFull() const{
            return top == SIZE;
        }

        void printList(){
            cout<<"current: ";
            for(int i=0;i<top;i++){
                cout<<items[i]<<' ';
            }
            cout<<"\n";
        }

        ~SimpleList(){};

};

    





