#include <stdexcept>
#include <string>
#include <iostream>

class Sales
{
    public:
        enum {MONTHS = 12};
        class bad_index : public std::logic_error{
            private:
                int bi;
            public:
                explicit bad_index(int ix, const std::string &s = "Sales객체 인덱스 에러\n");
                int bi_val() const {return bi;}
                virtual ~bad_index() {}
        };

        explicit Sales(int yy=0);
        Sales(int yy, const double *gr, int n);
        virtual ~Sales(){}
        int Year() const {return year;}
        virtual double operator[](int i) const;
        virtual double &operator[](int i);

    private:
        double gross[MONTHS];
        int year;
};

class LabeledSales : public Sales
{
    public:
        class nbad_index: public Sales::bad_index
        {
            private:
                std::string lbl;
            public:
                nbad_index(const std::string &lb, int ix, const std::string &s = "LabeledSales 객체 인덱스 에러\n");
                const std::string &label_val() const {return lbl;}
                virtual ~nbad_index() {}

        };
        explicit LabeledSales(const std::string &lb = "없음", int yy = 0);
        LabeledSales(const std::string& lb, int yy, const double * gr, int n);
        virtual ~LabeledSales(){}
        const std::string &Label() const{return label;}
        virtual double operator[](int i) const;
        virtual double &operator[](int i);

    private:
        std::string label;
        
};

Sales::bad_index::bad_index(int ix, const std::string &s): std::logic_error(s), bi(ix)
{

}

Sales::Sales(int yy)
{
    std::cout<<"sales constructor1 called"<<std::endl;
    year =yy;
    for (int i=0;i<MONTHS; ++i){
        gross[i]=0;
    }
}

Sales::Sales(int yy, const double *gr, int n)
{
    std::cout<<"sales constructor2 called"<<std::endl;
    year =yy;
    int lim = (n<MONTHS)? n: MONTHS;
    int i;
    std::cout<<"lim:"<<lim<<std::endl;
    for (int i=0;i<lim; ++i){
        gross[i]=gr[i];
        //std::cout<<gross[i] <<" "<<gr[i]<<std::endl;
    }

    //for i>n and i<MONTHS
    for(;i<MONTHS;++i){
        gross[i]=0;
    }
}

double Sales::operator[] (int i) const
{
    std::cout<<"value return operator called"<<std::endl;
    if(i<0 || i>=MONTHS)
        throw bad_index(i);
    return gross[i];
}

double & Sales::operator[](int i)
{
    std::cout<<"reference return operator called"<<std::endl;
    if(i<0 || i>= MONTHS)
        throw bad_index(i);
    return gross[i];
}

LabeledSales::nbad_index::nbad_index(const std::string &lb, int ix, const std::string &s)
:Sales::bad_index(ix,s)
{
    lbl = lb;
}

LabeledSales::LabeledSales(const std::string &lb, int yy): Sales(yy)
{
    std::cout<<"Labeled Sales constructor1 called"<<std::endl;
    label = lb;
}

LabeledSales::LabeledSales(const std::string &lb, int yy, const double *gr, int n)
:Sales(yy, gr, n)
{
    std::cout<<"Labeled Sales constructor2 called"<<std::endl;
    label = lb;
}


double LabeledSales::operator[](int i) const
{
    if (i<0 || i>= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

double & LabeledSales::operator[](int i)
{
    if(i<0 || i>=MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

