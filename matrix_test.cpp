#include "matrix.h"

int main()
{

//    phy::matrix <int> mat(2,2);
//    mat.mprint();
    
    phy::matrix<int> m(2,2);
    m.mprint();
    

    /*identity*/
    phy::matrix<int> t(2,2);
    t = m.identity(2,2);    
    t.mprint();

    return 0;

}