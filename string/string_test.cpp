#include <iostream>


/*
 * https://flaviocopes.com/c-return-string/
 *
 * Note the use of const, 
 * because from the function I’m returning a string literal, 
 * a string defined in double quotes, which is a constant
 * 
 * The reason is that variables are allocated on the stack, by default. 
 * But declaring a pointer, the value the pointers points to is allocated on the heap, 
 * and the heap is not cleared when the function ends
 */
   
const char* char_ref_return()
{
    //const char* c_string = "ggggg";
    //return c_string;
    return "error eroor";
}


int int_val_return()
{
    return 3;
}

int main(void)
{

    //char* c;

    //c = 
    const char* str = char_ref_return();

    std::cout<<str<<std::endl;

    //int_val_return();

    return 0;
}

