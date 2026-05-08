#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;

class PhanSo
{
private:
    long long iTu, iMau;
public:
    PhanSo();
    PhanSo (int iTu);
    PhanSo (int iTu, int iMau);

    void RutGon();
    PhanSo operator+(PhanSo b);
    PhanSo operator-(PhanSo b);
    PhanSo operator*(PhanSo b);
    PhanSo operator/(PhanSo b);

    bool operator==(PhanSo b);
    bool operator>(PhanSo b);
    bool operator<(PhanSo b);

    static void NhapSoNguyen(istream& in, string thongBao);
    friend istream& operator >> (istream& in, PhanSo& a);
    friend ostream& operator << (ostream& out, const PhanSo& a);
};

#endif // PHANSO_H
