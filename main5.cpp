#include <iostream>
#include "CDaThuc.h"

using namespace std;

int main()
{
    CDaThuc f;
    cout<<"Nhap da thuc f(x):\n";
    cin>>f;

    cout<<"Da thuc vua nhap:"<<f;
    cout<<"\n\n";

    double x0;
    cout<<"Nhap gia tri x0: ";
    cin>>x0;
    cout<<"Gia tri cua f(x0): "<<f.TinhGiaTri(x0)<<"\n\n";

    CDaThuc g;
    cout<<"Nhap da thuc g(x):\n";
    cin>>g;
    cout<<"\n";

    CDaThuc tong=f+g;
    cout<<"Tong 2 da thuc: "<<tong;
    cout<<"\n\n";

    CDaThuc hieu=f-g;
    cout<<"Hieu 2 da thuc: "<<hieu;
}
