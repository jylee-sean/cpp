
#include <iostream>

class Cd
{
    private: 
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    protected:
        const char* getperformers() const {return performers;}
        const char* getlbel() const {return label;}
        const int getselection() const {return selections;}
        const double getplaytime() const {return playtime;}

    public:
        Cd(const char* s1, const char* s2, int n, double x){
            strcpy(performers,s1);
            strcpy(label,s2);
            selections = n;
            playtime = x;
        };
        Cd(const Cd &d){};
        Cd(){};
        ~Cd(){};

        Cd & operator=(const Cd &d);

        virtual void Report() const{
            std::cout<<performers<<std::endl;
            std::cout<<label<<std::endl;
            std::cout<<selections<<std::endl;
            std::cout<<playtime<<std::endl;
        }

};



class Classic : public Cd
{
    private:
        char title[50];

    public:
        Classic(const char* t, const char* s1, const char* s2, int n, double x): Cd(s1,s2,n,x){
                strcpy(title ,t);
                };

        void Report() const{
            std::cout<<title<<std::endl;
            std::cout<<getperformers()<<std::endl;
            std::cout<<getlbel()<<std::endl;
            std::cout<<getselection()<<std::endl;
            std::cout<<getplaytime()<<std::endl;
        }
};