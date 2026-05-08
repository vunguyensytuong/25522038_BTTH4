#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>
using namespace std;

class CVector
{
private:
    int n;
    double *p;
public:
    CVector(int SoChieu = 2);
    CVector(const CVector& other);
    ~CVector();

    CVector& operator=(const CVector& other);
    CVector operator+(const CVector& other);
    CVector operator-(const CVector& other);
    double operator*(const CVector& other);

    friend istream& operator>>(istream& is, CVector& v);
    friend ostream& operator<<(ostream& os, const CVector& v);

    double at(int i) const;
    void setAt(int i, double giaTri);
    int getN() const;
};

#endif // CVECTOR_H
