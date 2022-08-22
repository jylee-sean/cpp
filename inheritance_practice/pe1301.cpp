
#include "Cd.h"

using namespace std;

//void Bravo(const Cd & disk);



int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat", "Alfred","Philips", 2, 57.17);

    Cd *pcd = &c1;

    cout<<"객체를 직접 사용한다"<<endl;
    
    c1.Report();  // Cd method 사용
    c2.Report();  // Classic method 사용

    cout<<"객체를 지시하는 Cd * 포인터를 사용한다"<<endl;
    pcd->Report(); // Cd 객체에 Cd method를 사용
    pcd = &c2;
    pcd->Report(); // Classic 객체에 Classic method 사용

    return 0;
}