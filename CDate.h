#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;

class CDate
{
private:
    int CNgay, CThang, CNam;
public:
    CDate(int d=1, int m=1, int y=1);

    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    CDate operator + (int n);
    CDate operator - (int n);
    long int TinhNgayTuyetDoi()const;
    long operator - (const CDate& other);

    friend istream& operator >> (istream& in, CDate& d);
    friend ostream& operator << (ostream& out, const CDate& d);
    static bool NgayHopLe(int d, int m, int y);
    static int NgayTrongThang(int m, int y);
    static bool NamNhuan(int y);
};

#endif // CDATE_H
