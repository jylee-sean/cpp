#ifndef TV_H_
#define TV_H_
class Tv;


class Remote
{
    private:
        int mode;
    public:
        Remote(int m = Tv::TV):mode(m){}
        bool volup(Tv & t){return t.volup();}
        bool voldown(Tv & t){return t.voldown();}
        void onoff(Tv & t){t.onoff();}
        void chanup(Tv & t){t.chanup();}
        void chandown(Tv &t){t.chandown();}
        void set_chan(Tv &t, int c){t.channel = c;}
        void set_mode(Tv &t){t.set_mode();}
        void set_input(Tv &t){t.set_input();}
};



class Tv
{
    public:
        friend void Remote::set_chan(Tv &t, int c);
        enum {Off, On};
        enum {MinVal, MaxVal=20};
        enum {Antenna, Cable};
        enum {TV, DVD};

        Tv(int s= Off, int mc = 125)
        : state(s), volume(5), maxchannel(mc), channel(2),mode(Cable), input(TV){}

        void onoff() {state = (state == On) ? Off : On;}
        bool ison() const {return state == On;}
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode() { mode = (mode == Antenna) ? Cable: Antenna;}
        void set_input() { input = (input == TV)? DVD : TV;}
        void settings() const;


    private:
        int state;
        int volume;
        int maxchannel;
        int channel;
        int mode;
        int input;

};


bool Tv::volup()
{
    if(volume < MaxVal){
        volume++;
        return true;
    }else{
        return false;
    }
}
bool Tv::voldown()
{
    if(volume > MinVal){
        volume--;
    }else{
        return false;
    }
}

void Tv::chanup()
{
    if(channel < maxchannel){
        channel++;
    }
    else{
        channel=1;
    }
}
void Tv::chandown()
{
    if(channel > 1){
        channel--;
    }else{
        channel = maxchannel;
    }
}
void Tv::settings() const
{
    using std::cout;
    using std::endl;

    cout<<"TV: "<<(state == Off ? "OFF" : "ON") << endl;
    if(state == On){
        cout<<"volume="<<volume <<endl;
        cout<<"channel="<<channel <<endl;
        cout<<"mode="<<(mode==Antenna ? "regular" : "cable")<<endl;
        cout<<"input="<<(input == TV? "TV": "DVD") << endl;
    }

}

#endif