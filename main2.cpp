#include <iostream>
#include "PhanSo.h"

using namespace std;

int main(){
    PhanSo a;
    cout<<"Nhap phan so a:\n";
    cin>>a;
    cout<<"Phan so vua nhap: "<<a;
    cout<<"\n\n";

    PhanSo b;
    cout<<"Nhap phan so b:\n";
    cin>>b;
    cout<<"\n\n";

    PhanSo tong=a+b;
    cout<<"Tong 2 phan so: "<<tong;
    cout<<"\n";

    PhanSo hieu=a-b;
    cout<<"Hieu 2 phan so: "<<hieu;
    cout<<"\n";

    PhanSo tich=a*b;
    cout<<"Tich 2 phan so: "<<tich;
    cout<<"\n";

    PhanSo thuong=a/b;
    if (b==0) cout<<"Khong the chia cho 0";
    else cout<<"Thuong 2 phan so: "<<thuong;
    cout<<"\n\n";

    if (a==b) cout<<"2 phan so bang nhau\n";
    else cout<<"2 phan so khong bang nhau\n";
    if (a>b) cout<<"Phan so a lon hon\n";
    else if (a<b) cout<<"Phan so a nho hon\n";
}
