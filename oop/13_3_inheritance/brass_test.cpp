#include <iostream>
#include "brass.h"




int main()
{
    Brass dom("dominic",123, 44.4);
    BrassPlus dot("chali",14145,35.545);

    dom.ViewAcct();
    dot.ViewAcct();

    return 0;
}


