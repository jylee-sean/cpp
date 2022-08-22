
#include <iostream>
#include <string>


class Cd
{
    private: 
        std::string performers;
        std::string label;
        int selections;
        double playtime;
    protected:
        const std::string getperformers() const {return performers;}
        const std::string getlbel() const {return label;}
        const int getselection() const {return selections;}
        const double getplaytime() const {return playtime;}

    public:
        Cd(const std::string s1, std::string s2, int n, double x){
            //strcpy(performers,s1);
            //strcpy(label, s2);
            performers = s1;
            label = s2;
            selections = n;
            playtime = x;

            std::cout<<"called"<<std::endl;
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
        std::string title;

    public:
        Classic(std::string t, std::string s1, std::string s2, int n, double x): Cd(s1,s2,n,x){
                    //strcpy(title, t);
                title = t;
                };

        void Report() const{
            std::cout<<title<<std::endl;
            std::cout<<getperformers()<<std::endl;
            std::cout<<getlbel()<<std::endl;
            std::cout<<getselection()<<std::endl;
            std::cout<<getplaytime()<<std::endl;
        }
};