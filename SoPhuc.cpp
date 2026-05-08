#include "SoPhuc.h"

SoPhuc::SoPhuc(){iThuc=0; iAo=0;}
SoPhuc::SoPhuc(double r){iThuc=r; iAo=0;}
SoPhuc::SoPhuc(double r, double i) {iThuc=r; iAo=i;}

SoPhuc SoPhuc::operator+(SoPhuc b){
    SoPhuc KetQua;
    KetQua.iThuc=this->iThuc+b.iThuc;
    KetQua.iAo=this->iAo+b.iAo;
    return KetQua;
}

SoPhuc SoPhuc::operator-(SoPhuc b){
    SoPhuc KetQua;
    KetQua.iThuc=this->iThuc-b.iThuc;
    KetQua.iAo=this->iAo-b.iAo;
    return KetQua;
}

SoPhuc SoPhuc::operator*(SoPhuc b){
    SoPhuc KetQua;
    KetQua.iThuc=iThuc*b.iThuc-iAo*b.iAo;
    KetQua.iAo=iThuc*b.iAo+iAo*b.iThuc;
    return KetQua;
}

SoPhuc SoPhuc::operator/(SoPhuc b) {
    SoPhuc KetQua;
    double Mau = b.iThuc * b.iThuc + b.iAo * b.iAo;

    if (Mau == 0) {
        return SoPhuc(0, 0);
    }

    KetQua.iThuc = (iThuc * b.iThuc + iAo * b.iAo) / Mau;
    KetQua.iAo = (iAo * b.iThuc - iThuc * b.iAo) / Mau;
    return KetQua;
}

bool SoPhuc::operator==(SoPhuc b){
    if (iThuc!=b.iThuc) return false;
    if (iAo!=b.iAo) return false;
    return true;
}

bool SoPhuc::operator!=(SoPhuc b){
    if (iThuc==b.iThuc&&iAo==b.iAo) return false;
    return true;
}

double SoPhuc::NhapSoThuc(istream& in, string thongBao) {
    double n;
    while (true) {
        cout << thongBao;
        if (in >> n) return n;
        else {
            cout << "Loi! Nhap lai.\n";
            in.clear();
            in.ignore(1000, '\n');
        }
    }
}

istream& operator >> (istream& in, SoPhuc& a) {
    a.iThuc=SoPhuc::NhapSoThuc(in, "Nhap phan thuc: ");
    a.iAo=SoPhuc::NhapSoThuc(in, "Nhap phan ao: ");
    return in;
}

ostream& operator << (ostream& out, const SoPhuc& a) {
    out<<a.iThuc<<(a.iAo>=0?" + ":" - ")<<abs(a.iAo)<<"i";
    return out;
}
