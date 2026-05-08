#include <iostream>
#include "CDate.h"

using namespace std;

int main()
{
    CDate a;
    cin>>a;

    cout<<"\nNgay thang nam vua nhap: "<<a;
    cout<<"\n";

    CDate acong1=a;
    cout<<"Ngay thang nam a++ se in ra: "<<acong1++<<"\n";
    cout<<"Sau khi thuc hien, a se la: "<<acong1<<"\n";
    CDate cong1a=a;
    cout<<"Ngay thang nam ++a se in ra: "<<cong1a<<"\n";
    cout<<"\n";

    CDate atru1=a;
    cout<<"Ngay thang nam a-- se in ra: "<<atru1--<<"\n";
    cout<<"Sau khi thuc hien, a se la: "<<atru1<<"\n";
    CDate tru1a=a;
    cout<<"Ngay thang nam --a se in ra: "<<tru1a<<"\n\n";

    int Cong, Tru;
    cout<<"Nhap so ngay cong them: ";
    cin>>Cong;
    cout<<a<<" sau khi cong "<<Cong<<" ngay: "<<a+Cong<<"\n\n";
    cout<<"Nhap so ngay tru di: ";
    cin>>Tru;
    cout<<a<<" sau khi tru di "<<Tru<<" ngay: "<<a-Tru<<"\n\n";

    cout<<"\nTinh lai suat:\n";
    CDate NgayGui, NgayRut;
    long SoNgayGui;
    while (true){
        cout<<"Nhap ngay gui:\n";
        cin>>NgayGui;
        cout<<"Nhap ngay rut:\n";
        cin>>NgayRut;
        SoNgayGui=NgayRut-NgayGui;
        if (SoNgayGui>0) break;
        cout<<"Loi! Ngay rut phai sau ngay gui. Vui long nhap lai.\n";
    }
    long long SoTienGoc, LaiSuat;

    cout<<"Nhap so tien goc(VND): ";
    cin>>SoTienGoc;
    cout<<"Nhap lai suat nam (%): ";
    cin>>LaiSuat;
    double TienLai = (SoTienGoc * (LaiSuat / 100.0) * SoNgayGui) / 365.0;
    cout << "\nSo ngay gui: " << SoNgayGui << " ngay";
    cout << "\nTong tien lai: " << (long long)TienLai << " VND";
    cout << "\nTong so tien nhan duoc: " << (long long)(SoTienGoc + TienLai) << " VND";
}
