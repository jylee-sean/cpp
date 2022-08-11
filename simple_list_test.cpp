#include "simpleList.h"
#include <iostream>


typedef float TYPE;

/* 
TODO
기능1 A, D, Q 외 입력 안받도록 수정
기능2 data 설정한 type으로 입력 유도
기능3 일괄 삭제
기능4 일괄 입력      
*/

int main()
{
    SimpleList<TYPE> slist; 
    char ch;
    TYPE data;


    while(1){
        cout<<"Add: A, Delete: D, Quit: Q \n";

        if(cin >> ch && toupper(ch) == 'Q'){
            break;
        }
        while(cin.get() !='\n')
            continue;
        if(!isalpha(ch)){
            cout<<'\a';
            continue;
        }
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