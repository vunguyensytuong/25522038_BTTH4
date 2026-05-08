#ifndef CMATRIX_H
#define CMATRIX_H

#include "CVector.h"
#include <iostream>
using namespace std;

class CMatrix {
private:
    int r, c;
    double **data;

public:
    CMatrix(int dong = 0, int cot = 0);
    CMatrix(const CMatrix& other);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& other);
    CMatrix operator+(const CMatrix& other);
    CMatrix operator*(const CMatrix& other);
    CVector operator*(const CVector& v);

    friend istream& operator>>(istream& is, CMatrix& m);
    friend ostream& operator<<(ostream& os, const CMatrix& m);
};

#endif
