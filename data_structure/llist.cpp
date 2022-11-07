

#include <iostream>


typedef struct node{
    int data;
    node* next;
}node;

class linkedlist{


    public:
        linkedlist(){
            head.data = 0;
            head.next = nullptr;
        }
        void add(int data){
            node* n = new node();
            n->data = data;
            n->next = head.next;

            head.next = n;


        }
        void print(){
            node* nodeptr = head.next;
            for(;;){
                std::cout<<nodeptr->data<<std::endl;
                nodeptr = nodeptr->next;
                if(nodeptr==nullptr)
                    break;
            }
        }
    private:
        node head;
};

int main(void)
{
    linkedlist mylist;

    mylist.add(100);
    mylist.add(200);
    mylist.add(300);

    mylist.print();

    return 0;
}
