#include <iostream>
#include "CVector.h"

using namespace std;

int main()
{
    CVector a;
    cout<<"Nhap vector a:\n";
    cin>>a;
    cout<<"Vector vua nhap la: "<<a;
    cout<<"\n\n";

    CVector b;
    cout<<"Nhap vector b:\n";
    cin>>b;
    cout<<"\n";

    cout<<"Cong 2 vector:\n";
    CVector tong=a+b;
    if (!!tong) cout<<"Tong 2 vector: "<<tong;
    cout<<"\n";

    cout<<"Tru 2 vector:\n";
    CVector hieu=a-b;
    if (!!tong) cout<<"Hieu 2 vector: "<<hieu;
    cout<<"\n";

    cout<<"Tich vo huong cua 2 vector: "<<a*b;

}
