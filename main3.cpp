#include <iostream>
#include "CTime.h"
using namespace std;

int main(){
    int YeuCau;
    while (true){
        cout<<"Chon chuong trinh:\n";
        cout<<"[1] de nhap thoi gian va tinh toan\n";
        cout<<"[2] de tao dong ho\n";
    if (!(cin >> YeuCau)){
        cout << "Loi: Vui long nhap so nguyen!\n";
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
    cin.ignore(1000, '\n');
    if (YeuCau == 1 || YeuCau == 2) {
        break;
    }
    cout << "Nhap sai! Chi duoc chon 1 hoac 2.\n";
    }

    CTime a;
    cout<<"Nhap thoi gian:\n";
    cin>>a;

    if (YeuCau==1){
        cout<<"Dong ho luc nay: "<<a;
        cout<<"\n\n";

        int GiayTang;
        cout<<"Nhap so giay tang them: ";
        cin>>GiayTang;
        a=a+GiayTang;
        cout<<"Sau khi tang "<<GiayTang<<" giay, dong ho hien tai la: "<<a;
        cout<<"\n\n";

        int GiayGiam;
        cout<<"Nhap so giay giam: ";
        cin>>GiayGiam;
        a=a-GiayGiam;
        cout<<"Sau khi giam "<<GiayGiam<<" giay, dong ho hien tai la: "<<a;
        cout<<"\n\n";

        CTime aTang1=a, aGiam1=a;
        ++aTang1;
        --aGiam1;
        cout<<"Dong ho neu tang 1 giay: "<<aTang1<<"\n\n";
        cout<<"Dong ho neu giam 1 giay: "<<aGiam1;
    }
    else if (YeuCau==2){
        a.InDongHo();
    }
    return 0;
}
