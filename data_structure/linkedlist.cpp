/*
 * https://www.youtube.com/watch?v=AUY_wbHAq14&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR
 */

#include <iostream>


typedef struct node{

    int data;
    node* next;

};


class LinkedList{


    private:
    

    public:
        LinkedList(){
            node* head = NULL;
            node* tail = NULL;
        }
        void addNode(int val){
            node* newNode = new node;

            newNode->data = val;
            newNode->next = NULL;


        }

        void display(){

        }

        void getHead(){

        }

        void addFrontNode(int val){

        }

        void insertNode(node *pNode, int val){

        }

        void delteNode(node *pNode){

        }
};


int main(void)
{
    
    LinkedList llist;

    llist.addNode(1);
    llist.addNode(2);
    llist.addNode(3);




    return 0;
}