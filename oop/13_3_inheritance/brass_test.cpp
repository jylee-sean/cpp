#include <iostream>

#include "brass.h"

const int CLIENTS = 4;

/**
 * Q. 파생클래스(BrassPlus)에서 virtual 을 하는게 의미가 있나?
 * A) (C++기초플러스)p935. 기초클래스에 있는 메서드를 파생 클래스에서 
 * 다시 정의할 예정이라면, 그것을 가상 함수로 선언해야함.
 * 다시 정의할 예정이 아니라면, 그것을 가상이 아닌 함수로 선언해야 함
 */

int main()
{
    /*객체에 의한 호출 예제 13.9 */
    // Brass dom("dominic",123, 44.4);
    // BrassPlus dot("chali",14145,35.545);

    // dom.ViewAcct();
    // cout<< endl;
    // dot.ViewAcct();
    // cout<< endl;

    // dom.Deposit(1000.00);

    // cout<<dom.Balance()<<endl;

    // dot.Withdraw(11.0);
    // cout<<dot.Balance()<<endl;

    // dom.Withdraw(4200.00);
    // dom.ViewAcct();

    /*다형성 설명하는 예제 13.10*/

    Brass *p_clients[CLIENTS];
    string temp;

    long tempnum;
    double tempbal;
    char kind;

    for(int i=0;i<CLIENTS; i++)
    {
        
    }

    return 0;
}


