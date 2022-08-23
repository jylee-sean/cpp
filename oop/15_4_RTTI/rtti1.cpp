#include <iostream>
#include <cstdlib>
#include <ctime>



class Grand
{
    private:
        int hold;
    public:
        Grand(int h=0): hold(h){ }
        virtual void Speak() const { std::cout<<"grand 클래스"<<std::endl;}
        virtual int Value() const {return hold;}
};

class Superb: public Grand
{
    public:
        Superb(int h=0):Grand(h){}
        void Speak() const {std::cout<<"superb 클래스"<<std::endl;}
        virtual void Say() const {std::cout<<" Superb value:"<<Value()<<std::endl;}
};

class Magnificient : public Superb
{
    private: 
        char ch;
    public:
        //Magnificient(){}
        Magnificient(int h =0, char c = 'A'): Superb(h), ch(c) {}
        void Speak() const {std::cout<< "Magnificient 클래스" <<std::endl;}
        void Say() const {std::cout<<" Magnificient value:"<<Value()<<" "<<ch<<std::endl;}
};

Grand *GetOne();

int main()
{
    std::srand(std::time(0));

    Grand *pg;
    Superb *ps;
    for(int i=0;i<5;i++){
        pg = GetOne();
        pg->Speak();
        if(ps = dynamic_cast<Superb*>(pg))
            ps->Say();
    }
    return 0;
}

Grand *GetOne()
{
    Grand *p;
    switch(std::rand()%3)
    {
        case 0: p = new Grand(std::rand() % 100);
                    break;
        case 1: p = new Superb(std::rand() % 100);
                    break;
        case 2: p = new Magnificient(std::rand() %100, 'A' + std::rand() % 26);
                    break;

    }
    return p;
}