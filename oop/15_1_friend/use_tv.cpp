#include <iostream>
#include "tv.h"

int main()
{
    using std::cout;
    using std::endl;

    Tv s42;
    cout<<"setting"<<endl;

    s42.settings();
    s42.onoff();
    s42.chanup();
    
    cout<<"changed"<<endl;
    
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    s42.settings();
    return 0;

}