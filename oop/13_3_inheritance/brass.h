#ifndef BRASS_H_
#define BRASS_H_

#include <string>

using std::cout;
using std::endl;

class Brass
{
    private:
        std::string fullName;
        long accNum;
        double balance;

    public:
        Brass(const std::string &s="Nullbody",long an = -1, double bal =0.0);
        void Deposit(double amt){}
        virtual void Withdraw(double amt);
        double Balance() const {}
        virtual void ViewAcct() const;
        virtual ~Brass(){} /* 파생 클래스 객체가 소멸할 때, 소멸자들이 올바른 순서로 호출되도록 해 줌*/
};
Brass::Brass(const std::string &s, long an, double bal)
{
    fullName = s;
    accNum = an;
    balance = bal;
}


void Brass::Withdraw(double amt)
{
    cout<<"brass with draw"<<endl;
}

void Brass::ViewAcct() const
{
    cout<<"brass view acct"<<endl;
}

class BrassPlus : public Brass
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0, 
                  double ml = 500, double r =0.11125);
        BrassPlus(const Brass &ba, 
                  double ml = 500, double r =0.11125);

        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m){maxLoan = m;}
        void ResetRate(double r){rate =r;}
        void ResetOwes(){owesBank=0;}
};


BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r): Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
void BrassPlus::ViewAcct() const
{
    cout<<"brass plus view acct"<<endl;
}


void BrassPlus::Withdraw(double amt)
{
    cout<<"brass plus with draw"<<endl;
}


#endif