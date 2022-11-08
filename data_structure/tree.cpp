#include <iostream>
#include <stack>



typedef struct node{

    int data;
    node* left;
    node* right;

}node;

std::stack<node> s;



class tree
{
    public:
        tree(int data){

            head->data = data;
            head->left = nullptr;
            head->right = nullptr;
        }

         
        void print()
        {
            node *ptr = head;
            //std::cout<< ptr->data << std::endl;

            while(1){


                if(ptr->left != nullptr){

                    if(ptr->right != nullptr){
                        s.push(*(ptr->right));
                    }    
                    ptr= ptr->left;
                }
                else if( (ptr->left == nullptr) && (ptr->right != nullptr) ){
                    ptr= ptr->right;
                }
                else if(!s.empty()){
                    *ptr = s.top();
                    s.pop();
                }
                else{
                    break;
                }
            

                std::cout<<ptr->data<<std::endl;

            }
        }
        bool compare(int a, int b)
        {
            return a>=b? true:false ;
        }
        void add(int data)
        {
            node* newnode = new node();
            newnode->data = data;
            newnode->left = nullptr;
            newnode->right = nullptr;

            node *ptr = head;
            while(1){
                if(compare(data, ptr->data )){

                    if(ptr->right == nullptr){
                        //std::cout<<"larger: "<< data <<std::endl;
                        ptr->right = newnode;
                        break;
                    }else{
                        ptr  = ptr->right; 
                    }
                }else{
                    if(ptr->left == nullptr){
                        //std::cout<<"smaller: "<< data <<std::endl;
                        ptr->left = newnode;
                        break;
                    }else{
                        ptr  = ptr->left; 
                    }
                }
            }

        }
    private:
        int data;
        node *head = new node();

};
int main()
{
    tree t(50);

    t.add(49);
    t.add(51);
    t.add(44);
    t.add(89);
    t.add(99);
    t.add(98);
    t.add(88);
    t.add(33);
    t.add(32);
    t.add(31);
    t.add(103);
    t.add(45);
    t.add(48);
    t.add(43);

    t.print();
    return 0;
}