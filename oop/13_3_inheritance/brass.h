#ifndef BRASS_H_
#define BRASS_H_

#include <string>

using std::cout;
using std::endl;
using std::string;

/* regarding formatting */
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

class Brass
{
    private:
        std::string fullName;
        long accNum;
        double balance;

    public:
        Brass(const std::string &s="Nullbody",long an = -1, double bal =0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt);
        double Balance() const ;
        virtual void ViewAcct() const;
        virtual ~Brass(){} /* 파생 클래스 객체가 소멸할 때, 소멸자들이 올바른 순서로 호출되도록 해 줌*/
};
Brass::Brass(const std::string &s, long an, double bal)
{
    fullName = s;
    accNum = an;
    balance = bal;
}
void Brass::Deposit(double amt)
{
    if(amt <0){
        cout<<"마이너스 입금 허용 안됨"<<endl;
    }else{
        balance +=amt;
    }
}

void Brass::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if(amt <0){
        cout<<"마이너스 입금 허용 안됨"<<endl;
    }else if (amt <= balance){
        balance-=amt;
    }else{
        cout<<"잔액 초과"<<endl;
    }

    restore(initialState, prec);
}
double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    cout<<"name:"<<fullName <<endl;
    cout<<"Account Number:"<<accNum <<endl;
    cout<<"Current Balance:"<<balance <<endl;

    restore(initialState,prec);
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

        /*virtual*/ void ViewAcct() const;
        /*virtual*/ void Withdraw(double amt);
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
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();
    cout<<"maxLoan:"<<maxLoan <<endl;
    cout<<"owesBank:"<<owesBank<<endl;
    cout.precision(3);
    cout<<"Rate:"<<100*rate <<"%"<<endl;

    restore(initialState,prec);
}

void BrassPlus::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if(amt<=bal){
        Brass::Withdraw(amt);
    }else if(amt<=bal+maxLoan-owesBank){
        double advance = amt-bal;
        owesBank +=advance *(1.0+rate);
        cout<<"advance: "<<advance<<endl;
        cout<<"interset:"<<advance*rate <<endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }else{
        cout<<"canceled"<<endl;
    }

    restore(initialState,prec);
}

format setFormat()
{
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}




#endif