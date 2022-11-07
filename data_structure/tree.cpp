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
            std::cout<< ptr->data << std::endl;

            while(1){
                std::cout<<ptr->data<<std::endl;
                if(ptr->right != nullptr){
                    s.push(ptr->right);
                }else{
                    if(!s.empty()){
                        *ptr = s.top();
                        s.pop();
                    }else{
                        break;
                    }
                }                

                if(ptr->left != nullptr){
                    ptr= ptr->left;
                }else{
                    if(!s.empty()){
                        *ptr = s.top();
                        s.pop();
                    }else{
                        break;
                    }
                }

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
                        ptr->right = newnode;
                        break;
                    }else{
                        ptr  = ptr->right; 
                    }
                }else{
                    if(ptr->left == nullptr){
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
    t.add(30);

    t.print();
    return 0;
}