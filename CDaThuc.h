#ifndef CDATHUC_H
#define CDATHUC_H
#include <iostream>
using namespace std;

class CDaThuc
{
private:
    int n;
    double *p;
public:
    CDaThuc(int k=0);
    CDaThuc(const CDaThuc& d);
    ~CDaThuc();


    CDaThuc& operator=(const CDaThuc& d);

    CDaThuc operator+(const CDaThuc& d);
    CDaThuc operator-(const CDaThuc& d);
    double TinhGiaTri(double x);

    friend istream& operator>>(istream& is, CDaThuc& d);
    friend ostream& operator<<(ostream& os, const CDaThuc& d);

};

#endif // CDATHUC_H
