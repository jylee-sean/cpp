#include "matrix.h"

using namespace std;
int main()
{



    phy::matrix<float> mat3x2(3,2);
    cout<<"3x2 matrix\n";
    mat3x2.mprint();

    phy::matrix<float> mat2x2(2,2);
    cout<<"2x2 matrix\n";
    mat2x2.mprint();


    phy::matrix<float> mat1x4(1,4);
    cout<<"1x4 matrix\n";
    mat1x4.mprint();

    phy::matrix<float> mat4x4(4,4);
    cout<<"4x4 matrix\n";
    mat4x4.mprint();


    // phy::matrix<float> mat11x12(11,12);
    // cout<<"11x12 matrix\n";
    // mat11x12.mprint();

    /*identity*/
    phy::matrix<float> mat2x2identity(2,2);

    cout<<"identity\n";
    mat2x2identity = phy::matrix<float>::identity(2,2);    
    mat2x2identity.mprint();

    /*transpose*/
    phy::matrix<float> mat2x2trans(2,2);

    cout<<"transpose\n";
    mat2x2trans = mat2x2.transpose(2,2);    
    mat2x2trans.mprint();

    /*attribute*/
    cout<<"min:"<<mat2x2.min()<<"\n";
    cout<<"max:"<<mat2x2.max()<<"\n";
    cout<<"sum:"<<mat2x2.sum()<<"\n";
    cout<<"prod:"<<mat2x2.prod()<<"\n";
    cout<<"mean:"<<mat2x2.mean()<<"\n";

    /*compare*/
    bool result;
    result = (mat2x2==mat2x2trans);
    cout<<boolalpha<<"result:"<<result<<"\n";
    result = (mat2x2==mat2x2);
    cout<<boolalpha<<"result:"<<result<<"\n";
    result = (mat2x2!=mat2x2trans);
    cout<<boolalpha<<"result:"<<result<<"\n";
    result = (mat2x2!=mat2x2);
    cout<<boolalpha<<"result:"<<result<<"\n";

    phy::matrix<float> mat3x3(3,3);
    result = (mat2x2==mat3x3);
    cout<<boolalpha<<"result:"<<result<<"\n";


    /* basic operation: [+ ,- ,* ,/] */
    phy::matrix<float> mat2x2op(2,2);
       
    mat2x2op = mat2x2.operator+(mat2x2trans);
    cout<<"[ + op]\n";
    mat2x2op.mprint();

    mat2x2op = mat2x2.operator-(mat2x2identity);
    cout<<"[ - op]\n";
    mat2x2op.mprint();

    float scalar = 5.0;
    mat2x2op = mat2x2.operator*(scalar);
    cout<<"[ * op(scalar)]\n";
    mat2x2op.mprint();

    mat2x2op = mat2x2op.operator/(scalar);
    cout<<"[ / op(scalar)]\n";
    mat2x2op.mprint();
    
    /*dived by zero*/
    mat2x2op = mat2x2op.operator/(0.0);
    cout<<"[ / op(scalar)]\n";
    
    /*matrix multiplication*/
    phy::matrix<float> mat2x2mul(2,2);
    cout<<"matrix multiplication\n";
    
    mat2x2mul = mat2x2.operator*(mat3x3);


    mat2x2mul = mat2x2.operator*(mat2x2);
    mat2x2mul.mprint();



    phy::matrix<int> mat2x2ref(2,2);

    auto x2d = mat2x2ref.operator()(1,0);
    cout<<x2d<<endl;

    auto x1d = mat2x2ref.operator()(3);
    cout<<x1d<<endl;

    const phy::matrix<int> constmat2x2ref(2,2);

    auto y2d = constmat2x2ref.operator()(1,1);
    cout<<y2d<<endl;

    auto y1d = constmat2x2ref.operator()(1);
    cout<<y1d<<endl;

    

    return 0;
}