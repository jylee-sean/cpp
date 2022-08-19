#include "simpleList.h"
#include <iostream>


typedef float TYPE;


/* 수정사항
 * true , false 로 return 하도록  
 */

int main()
{
    SimpleList<TYPE> slist; 
    char ch;
    TYPE data;

    for(int i=0;i<slist.getMaxSize()+2; i++){
        slist.push(i*1.0);
        slist.printList();
    }

    for(int i=0;i<slist.getMaxSize()+2; i++){
        slist.pop();
        slist.printList();
    }

    return 0;
}