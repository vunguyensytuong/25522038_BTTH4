#include "CDaThuc.h"
#include <iostream>
#include <cmath>
using namespace std;

//Constructor
CDaThuc::CDaThuc(int k) {
    n = k;
    p = new double[n + 1];
    for(int i = 0; i <= n; i++) p[i] = 0;
}

CDaThuc::CDaThuc(const CDaThuc& d) {
    n = d.n;
    p = new double[n + 1]; //cap phat vung nhoi moi
    for (int i = 0; i <= n; i++) {
        p[i] = d.p[i];
    }
}

// Destructor
CDaThuc::~CDaThuc() {
    delete[] p;
}

//toan tu gan =
CDaThuc& CDaThuc::operator=(const CDaThuc& d) {
    if (this == &d) return *this;//khong tu gan cho chinh no

    delete[] p; //xoa vung nho
    n = d.n;
    p = new double[n + 1]; //cap phat vung nho moi
    for(int i = 0; i <= n; i++) {
        this->p[i] = d.p[i];
    }
    return *this; //tra ve doi tuong hien tai
}

double CDaThuc::TinhGiaTri(double x) {
    double ketQua = 0;
    for (int i = n; i >= 0; i--) {
        ketQua = ketQua * x + p[i];
    }
    return ketQua;
}

//cong 2 da thuc
CDaThuc CDaThuc::operator+(const CDaThuc& d) {
    int BacMax = max(this->n, d.n);
    CDaThuc KetQua(BacMax);
    for(int i = 0; i <= BacMax; i++) {
        double v1 = (i <= this->n) ? this->p[i] : 0;
        double v2 = (i <= d.n) ? d.p[i] : 0;
        KetQua.p[i] = v1 + v2;
    }
    return KetQua;
}

//tru 2 da thuc
CDaThuc CDaThuc::operator-(const CDaThuc& d) {
    int BacMax = max(this->n, d.n);
    CDaThuc KetQua(BacMax);
    for(int i = 0; i <= BacMax; i++) {
        double v1 = (i <= this->n) ? this->p[i] : 0;
        double v2 = (i <= d.n) ? d.p[i] : 0;
        KetQua.p[i] = v1 - v2;
    }
    return KetQua;
}

istream& operator>>(istream& is, CDaThuc& d) {
    cout << "Nhap bac cua da thuc: ";
    int tempN;
    is >> tempN;

    //xoa cu va tao moi
    if (d.p != nullptr) delete[] d.p;
    d.n = tempN;
    d.p = new double[d.n + 1];

    for (int i = d.n; i >= 0; i--) {
        cout << "Nhap he so cua x^" << i << ": ";
        is >> d.p[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const CDaThuc& d) {
    bool BatDau = true; //bien kiem tra de in dau

    for (int i = d.n; i >= 0; i--) {
        if (d.p[i] == 0) continue; //he so bang 0

        //dau cua he so
        if (!BatDau && d.p[i] > 0) os << " + ";
        else if (d.p[i] < 0) os << " - ";

        //xu li tri tuyet doi cua he so
        double GiaTri = abs(d.p[i]);
        if (GiaTri != 1 || i == 0) os << GiaTri;

        //in x va dau mu ^
        if (i > 0) {
            os << "x";
            if (i > 1) os << "^" << i;
        }

        BatDau = false;
    }

    if (BatDau) os << "0"; //truong hop da thuc khong co gi, in so 0
    return os;
}

