//
//  main.cpp
//  
//
//  Created by sean.lee on 2023/02/07.
//

#include "main.hpp"


int main()
{
    
    ::pthread_setname_np(pthread_self(), "main()");
    
    
    return 0;
}
