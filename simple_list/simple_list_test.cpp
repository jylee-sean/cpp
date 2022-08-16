#include "simpleList.h"
#include <iostream>


typedef float TYPE;


int main()
{
    SimpleList<TYPE> slist; 
    char ch;
    TYPE data;

    char b;
    while(1){
        cout<<"Add: A, Delete: D, Quit: Q \n";

        if(cin >> ch && toupper(ch) == 'Q'){
            break;
        }
        cout<<ch<<'\n';
        cout<<cin.get()<<'\n';
        
        //cout<<ch<<'\n';
        //while(cin.get() !='\n')
        //     cout<<"cin get\n";
        //     continue;
        // if(!isalpha(ch)){
        //     cout<<'\a';
        //     continue;
        // }
        switch(ch){
            case 'A':
            case 'a':  cout<<"input data: ";
                       cin>>data;
                       if(slist.isFull()){
                            cout<<"list is full\n";
                       }
                       else{
                            slist.push(data);
                            slist.printList();
                       }
                       break;
            case 'D': 
            case 'd':
                      if(slist.isEmpty()){
                        cout<<"list is empty\n";
                      }else{
                        slist.pop();
                      }
                      slist.printList();
                      break;
            
        }

    }

    return 0;
}