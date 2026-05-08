#include "PhanSo.h"
#include <iostream>
#include <algorithm>
using namespace std;

PhanSo::PhanSo()
{
    iTu=0;
    iMau=1;
}

PhanSo::PhanSo(int Tu){
    iTu=Tu;
    iMau=1;
}

PhanSo::PhanSo(int Tu, int Mau){
    iTu=Tu;
    iMau=Mau;
    RutGon();
}

int UCLN (int a, int b){
    return b==0?abs(a):UCLN(b, a%b);
}

void PhanSo::RutGon(){
    int ucln=UCLN(iTu, iMau);
    iTu=iTu/ucln;
    iMau=iMau/ucln;
    if (iMau<0){
        iTu=-iTu;
        iMau=-iMau;
    }
}

PhanSo PhanSo::operator+(PhanSo b){
    return PhanSo(iTu*b.iMau+b.iTu*iMau,iMau*b.iMau);
}

PhanSo PhanSo::operator-(PhanSo b){
    return PhanSo(iTu*b.iMau-b.iTu*iMau,iMau*b.iMau);
}

PhanSo PhanSo::operator*(PhanSo b){
    return PhanSo(iTu*b.iTu,iMau*b.iMau);
}

PhanSo PhanSo::operator/(PhanSo b){
    return PhanSo(iTu*b.iMau,iMau*b.iTu);
}

bool PhanSo::operator==(PhanSo b){
    RutGon();
    b.RutGon();
    if (iTu!=b.iTu||iMau!=b.iMau) return false;
    return true;
}

bool PhanSo::operator<(PhanSo b){
    RutGon();
    b.RutGon();
    if (iTu*b.iMau<b.iTu*iMau) return true;
    return false;
}

bool PhanSo::operator>(PhanSo b){
    RutGon();
    b.RutGon();
    if (iTu*b.iMau>b.iTu*iMau) return true;
    return false;
}


//toan tu xuat<<
ostream& operator<<(ostream& os, const PhanSo& ps) {
    //chi in tu so neu mau so =1
    if (ps.iMau == 1) {
        os << ps.iTu;
    }
    //neu tu so =0, chi in so 0
    else if (ps.iTu == 0) {
        os << "0";
    }
    else {
        os << ps.iTu << "/" << ps.iMau;
    }
    return os;
}

//toan tu nhap>>
istream& operator>>(istream& is, PhanSo& ps) {
    //nhap tu so
    while (true) {
        cout << "Nhap tu so: ";
        if (is >> ps.iTu) {
            break; //nhap dung thi thoat vong lap
        } else {
            cout << "Loi: Vui long nhap mot so nguyen!\n";
            is.clear(); //xoa loi
            is.ignore(1000, '\n'); //bo qua ki tu loi
        }
    }

    //nhap mau
    while (true) {
        cout << "Nhap mau so (khac 0): ";
        if (is >> ps.iMau) {
            if (ps.iMau != 0) {
                break; //thoat vong lap
            } else {
                cout << "Loi: Mau so khong duoc bang 0!\n";
            }
        } else {
            cout << "Loi: Vui long nhap mot so nguyen!\n";
            is.clear();
            is.ignore(1000, '\n');
        }
    }

    ps.RutGon();
    return is;
}
