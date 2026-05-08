#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main(){
    SoPhuc a;
    cout<<"Nhap so phuc a:\n";
    cin>>a;
    cout<<"So phuc vua nhap: "<<a;
    cout<<"\n\n";

    SoPhuc b;
    cout<<"Nhap so phuc b:\n";
    cin>>b;
    cout<<"\n";

    cout<<"Tong 2 so phuc: "<<a+b<<"\n";

    cout<<"Hieu 2 so phuc: "<<a-b<<"\n";

    cout<<"Tich 2 so phuc: "<<a*b<<"\n";

    if (b==0) cout<<"Khong the chia cho so phuc 0\n";
    else cout<<"Thuong 2 so phuc: "<<a/b<<"\n";

    cout<<"\n\n";
    cout<<"So sanh 2 so phuc:\n";
    if (a==b) cout<<"2 so phuc bang nhau";
    if (a!=b) cout<<"2 so phuc khong bang nhau";
    cout<<"\n\n";
}
