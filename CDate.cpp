#include "CDate.h"
#include <limits>

CDate::CDate(int d, int m, int y):CNgay(d),CThang(m),CNam(y){
}

bool CDate::NgayHopLe(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12) return false; //nam phai >0, thang phai >0 va <=12
    if (d < 1 || d > NgayTrongThang(m, y)) return false; //kiem tra ngay hop le
    return true;
}

bool CDate::NamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int CDate::NgayTrongThang(int m, int y){
    switch (m){
        case 2:
        if (NamNhuan(y)) return 29;
        return 28;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 0;
    }
}


istream& operator >> (istream& in, CDate& d) {
    int TempNgay, TempThang, TempNam;

    while (true) {
        cout << "Nhap ngay thang nam (cach nhau khoang trang): ";

        //kiem tra co phai la so nguyen khong
        if (in >> TempNgay >> TempThang >> TempNam) {

            //kiem tra ngay co hop le khong
            if (CDate::NgayHopLe(TempNgay, TempThang, TempNam)) {
                d.CNgay = TempNgay;
                d.CThang = TempThang;
                d.CNam = TempNam;
                break; //thoat khoi vong lap
            } else {
                cout << "Loi: Ngay thang nam khong ton tai trong thuc te!\n";
            }
        } else {
            //khi nhap ki tu khong phai so nguyen
            cout << "Loi: Vui long chi nhap so nguyen!\n";
            in.clear(); //xoa loi
            in.ignore(numeric_limits<streamsize>::max(), '\n'); //xoa loi nhap lai
        }
    }
    return in;
}

//toan tu xuat
ostream& operator << (ostream& out, const CDate& d) {
    //in theo dinh dang dd/mm/yyyy
    if (d.CNgay < 10) out << "0"; out << d.CNgay << "/";
    if (d.CThang < 10) out << "0"; out << d.CThang << "/";
    out << d.CNam;
    return out;
}

//++d
CDate& CDate::operator++() {
    CNgay++;
    if (CNgay > NgayTrongThang(CThang, CNam)) {
        CNgay = 1;
        CThang++;
        if (CThang > 12) {
            CThang = 1;
            CNam++;
        }
    }
    return *this; // tra ve chinh doi tuong
}

//d++
CDate CDate::operator++(int) {
    CDate temp = *this; //luu gia tri
    ++(*this);          //tang gia tri
    return temp;        //tra ve gia tri cu
}

//--d
CDate& CDate::operator--() {
    CNgay--;
    if (CNgay < 1) {
        CThang--;
        if (CThang < 1) {
            CThang = 12;
            CNam--;
        }
        CNgay = NgayTrongThang(CThang, CNam);
    }
    return *this;//sau khi giam, tra ve chinh doi tuong
}

//d--
CDate CDate::operator--(int) {
    CDate temp = *this;//luu gia tri
    --(*this);          //giam gia tri
    return temp;        //tra ve gia tri cu
}

//cong them n ngay
CDate CDate::operator + (int n) {
    CDate res = *this;
    for (int i = 0; i < n; i++) {
        ++res; //goi toan tu cong 1
    }
    return res;
}

//tru n ngay
CDate CDate::operator - (int n) {
    CDate res = *this;
    for (int i = 0; i < n; i++) {
        --res; //goi toan tu tru 1
    }
    return res;
}

//khoang cach giua 2 ngay
long CDate::TinhNgayTuyetDoi() const {
    int d = CNgay;
    int m = CThang;
    int y = CNam;

    if (m < 3) {
        y--;
        m += 12;
    }
    return 365L * y + y / 4 - y / 100 + y / 400 + (153 * m + 8) / 5 + d;
}
//toan tu tru -
long CDate::operator - (const CDate& other) {
    return this->TinhNgayTuyetDoi() - other.TinhNgayTuyetDoi();
}
