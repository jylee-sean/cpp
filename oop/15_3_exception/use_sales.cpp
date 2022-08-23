#include "sales.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double vals1[12]=
    {
        1220,1100,1122,2212,1232,2334,
        2884,2393,3302,2922,3002,3544
    };
    double vals2[12]=
    {
        12,11,22,21,32,34,
        28,29,33,29,32,35
    };

    Sales sales1(2001,vals1, 12);
    LabeledSales sales2("blogstar",2012, vals2, 12);

    cout<<"first try block"<<endl;
    try{
        int i;
        cout<< "year = " << sales1.Year() <<endl;
        for(i=0; i<12; ++i){
            cout<<sales1[i]<<' ';
            if(i%6 ==5)
                cout<<endl;
        }
        cout<<"year = "<<sales2.Year()<<endl;
        cout<<"label = "<< sales2.Label()<<endl;

        for(i=0;i<=12; ++i){
            cout <<sales2[i]<<' ';
            if(i%6 ==5)
                cout<<endl;
        }
        cout <<"end of try block1"<<endl;
    }
    catch(LabeledSales::nbad_index &bad){
        cout<<bad.what();
        cout<<"company:"<<bad.label_val() <<endl;
        cout<<"잘못된 인덱스:"<<bad.bi_val() <<endl;
    }
    catch(Sales::bad_index &bad){
        cout <<bad.what();
        cout<<"잘못된 인덱스:"<<bad.bi_val()<<endl;
    }
    
    cout<<"\nNext try block:\n";
    
    try{
        sales2[2] = 37.5;
        sales1[20]=23345;
        cout<<"end of try block2"<<endl;
    }
    catch(LabeledSales::nbad_index &bad){
        cout<<bad.what();
        cout<<"company:"<<bad.label_val()<<endl;
        cout<<"잘못된 인덱스:"<<bad.bi_val() <<endl;
    }
    catch(Sales::bad_index &bad){
        cout<<bad.what();
        cout<<"잘못된 인덱스:"<<bad.bi_val() <<endl;
    }
    cout<<"program shut down"<<endl;

    return 0;
}