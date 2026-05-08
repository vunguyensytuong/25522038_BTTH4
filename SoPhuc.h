#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>
#include <string>
using namespace std;

class SoPhuc
{
private:
    double iThuc,iAo;
public:
    SoPhuc();
    SoPhuc(double r);
    SoPhuc(double r, double i);

    SoPhuc operator + (SoPhuc b);
    SoPhuc operator - (SoPhuc b);
    SoPhuc operator * (SoPhuc b);
    SoPhuc operator / (SoPhuc b);
    bool operator == (SoPhuc b);
    bool operator != (SoPhuc b);
    static double NhapSoThuc(istream& in, string thongBao);
    friend istream& operator >> (istream& in, SoPhuc& a);
    friend ostream& operator << (ostream& out, const SoPhuc& a);
};

#endif // SOPHUC_H
