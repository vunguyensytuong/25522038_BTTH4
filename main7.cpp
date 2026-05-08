#include "CVector.h"
#include <limits>

CVector::CVector(int SoChieu) {
    n = SoChieu;
    p = new double[n];
    for(int i = 0; i < n; i++) p[i] = 0;
}

CVector::CVector(const CVector& other) {
    this->n = other.n;
    this->p = new double[n]; //cap phat vung nho
    for (int i = 0; i < n; i++) {
        this->p[i] = other.p[i]; //copy du lieu
    }
}

CVector::~CVector(){
    delete []p;
}

//toan tu gan =
CVector& CVector::operator=(const CVector& other) {
    if (this == &other) return *this; //truong hop tu gan

    delete[] p; //xoa mang cu
    this->n = other.n;
    this->p = new double[n];
    for(int i = 0; i < n; i++) {
        this->p[i] = other.p[i];
    }
    return *this;
}

//cong 2 vector
CVector CVector::operator+(const CVector& other) {
    if (this->n != other.n) {
        cout << "Loi: Khong cung so chieu!" << endl;
        return CVector(0);
    }
    CVector KetQua(n);
    for(int i = 0; i < n; i++) {
        KetQua.p[i] = this->p[i] + other.p[i];
    }
    return KetQua;
}

//tru 2 vector
CVector CVector::operator-(const CVector& other) {
    if (this->n != other.n) {
        cout << "Loi: Khong cung so chieu!" << endl;
        return CVector(0);
    }
    CVector KetQua(n);
    for(int i = 0; i < n; i++) {
        KetQua.p[i] = this->p[i] - other.p[i];
    }
    return KetQua;
}

//tich vo huong 2 vector
double CVector::operator*(const CVector& other) {
    double KetQua = 0;
    if (this->n == other.n) {
        for(int i = 0; i < n; i++) {
            KetQua += this->p[i] * other.p[i];
        }
    }
    return KetQua;
}

double CVector::at(int i) const { return p[i]; }
void CVector::setAt(int i, double giaTri) { p[i] = giaTri; }
int CVector::getN() const { return n; }


//nhap vector
istream& operator>>(istream& is, CVector& v) {
    int moi;
    bool hopLe = false;

    while (!hopLe) {
        cout << "Nhap so chieu cho vector (phai la so nguyen duong): ";

        //Kiem tra xem co phai la so nguyen khong
        if (!(is >> moi)) {
            cout << "Loi: Vui long chi nhap so nguyen!\n";
            is.clear(); //Xoa trang thai loi cua cin
            is.ignore(numeric_limits<streamsize>::max(), '\n'); //Xoa bo dem
            continue;
        }

        //Kiem tra gia tri so chieu
        if (moi <= 0) {
            cout << "Loi: So chieu phai lon hon 0!\n";
            continue;
        }

        hopLe = true; //Neu vuot qua cac buoc tren thi hop le
    }

    //Neu so chieu thay doi, phai cap phat lai bo nho
    if (moi != v.n) {
        delete[] v.p;
        v.n = moi;
        v.p = new double[v.n];
    }

    //Nhap cac thanh phan
    for (int i = 0; i < v.n; i++) {
        while (true) {
            cout << "Nhap thanh phan thu " << i + 1 << ": ";
            if (is >> v.p[i]) {
                break; //Nhap dung so thuc thi thoat vong lap
            } else {
                cout << "Loi: Thanh phan phai la mot so!\n";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    return is;
}
//xuat vector theo dinh dang (a, b, c,...)
ostream& operator<<(ostream& os, const CVector& v) {
    os << "(";
    for (int i = 0; i < v.n; i++) {
        os << v.p[i] << (i == v.n - 1 ? "" : ", ");
    }
    os << ")";
    return os;
}
