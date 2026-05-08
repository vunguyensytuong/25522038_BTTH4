#include "CMatrix.h"
#include <limits>

CMatrix::CMatrix(int dong, int cot) : r(dong), c(cot) {
    if (r > 0 && c > 0) {
        data = new double*[r];
        for (int i = 0; i < r; i++) {
            data[i] = new double[c];
            for (int j = 0; j < c; j++) data[i][j] = 0;
        }
    } else {
        data = nullptr;
    }
}

CMatrix::~CMatrix() {
    for (int i = 0; i < r; i++) delete[] data[i];
    delete[] data;
}

// Copy Constructor
CMatrix::CMatrix(const CMatrix& other) {
    r = other.r;
    c = other.c;
    data = new double*[r];
    for (int i = 0; i < r; i++) {
        data[i] = new double[c];
        for (int j = 0; j < c; j++) data[i][j] = other.data[i][j];
    }
}

//toan tu gan =
CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this == &other) return *this;

    //xoa bo nho
    if (data != nullptr) {
        for (int i = 0; i < r; i++) delete[] data[i];
        delete[] data;
    }

    r = other.r;
    c = other.c;
    data = new double*[r];
    for (int i = 0; i < r; i++) {
        data[i] = new double[c];
        for (int j = 0; j < c; j++) data[i][j] = other.data[i][j];
    }
    return *this;
}

CMatrix CMatrix::operator+(const CMatrix& other) {
    //liem tra dieu kien: phai cung kich thuoc
    if (this->r != other.r || this->c != other.c) {
        cout << "Loi: Hai ma tran khong cung kich thuoc, khong the cong!" << endl;
        return CMatrix(0, 0); //Tra ve ma tran rong
    }

    //Tao ma tran ket qua co cung kich thuoc
    CMatrix ketQua(this->r, this->c);

    //Cong tung phan tu tuong ung
    for (int i = 0; i < this->r; i++) {
        for (int j = 0; j < this->c; j++) {
            ketQua.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }

    return ketQua;
}

CVector CMatrix::operator*(const CVector& v) {
    CVector res(this->r);
    for (int i = 0; i < r; i++) {
        double sum = 0;
        for (int j = 0; j < c; j++) {
            sum += this->data[i][j] * v.at(j);//lay toa do thu j
        }
        res.setAt(i, sum);
    }
    return res;
}



CMatrix CMatrix::operator*(const CMatrix& other) {
    if (this->c != other.r) return CMatrix(0, 0);

    CMatrix res(this->r, other.c);
    for (int i = 0; i < res.r; i++) {
        for (int j = 0; j < res.c; j++) {
            res.data[i][j] = 0;
            for (int k = 0; k < this->c; k++) {
                res.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return res;
}
istream& operator>>(istream& is, CMatrix& m) {
    int rowInput, colInput;

    //nhap so hang
    while (true) {
        cout << "Nhap so dong r (r > 0): ";
        if (is >> rowInput && rowInput > 0) break;
        cout << "Loi! Vui long nhap lai so nguyen duong." << endl;
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //nhap so cot
    while (true) {
        cout << "Nhap so cot c (c > 0): ";
        if (is >> colInput && colInput > 0) break;
        cout << "Loi! Vui long nhap lai so nguyen duong." << endl;
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //cap phat lai bo nho
    if (m.data != nullptr) {
        for (int i = 0; i < m.r; i++) delete[] m.data[i];
        delete[] m.data;
    }

    m.r = rowInput;
    m.c = colInput;
    m.data = new double*[m.r];
    for (int i = 0; i < m.r; i++) m.data[i] = new double[m.c];

    //nhap phan tu
    cout << "Nhap ma tran " << m.r << "x" << m.c << ":" << endl;
    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            while (true) {
                cout << "Phan tu [" << i << "][" << j << "]: ";
                if (is >> m.data[i][j]) break;
                cout << "Loi! Phai nhap so thuc." << endl;
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    return is;
}

//toan tu xuat<<
ostream& operator<<(ostream& os, const CMatrix& m) {
    if (m.r == 0 || m.c == 0) {
        os << "Ma tran rong!" << "\n";
        return os;
    }

    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            os << m.data[i][j] << "\t"; //dung nut tab de cac cot thang hang
        }
        os << "\n"; //xuong dong
    }
    return os;
}
