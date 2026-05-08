#include <windows.h>
#include "CTime.h"
#include <iostream>
#include <iomanip>

CTime::CTime(int h, int m, int s) : CGio(h), CPhut(m), CGiay(s) {
    ChuanHoa();
}

CTime::~CTime(){

}

void CTime::ChuanHoa() {
    //doi giay du sang phut
    CPhut += CGiay / 60;
    CGiay %= 60;
    if (CGiay < 0) { CGiay += 60; CPhut--; }

    //phut bi du chuyen sang gio
    CGio += CPhut / 60;
    CPhut %= 60;
    if (CPhut < 0) { CPhut += 60; CGio--; }

    //doi gio bi du
    CGio %= 24;
    if (CGio < 0) CGio += 24;
}

//cong 1 so nguyen giay, goi ham chuan hoa de dua lai dung gio
CTime CTime::operator+(int s) {
    return CTime(CGio, CPhut, CGiay + s);
}

//tru mot so nguyen giay va goi ham chuan hoa
CTime CTime::operator-(int s) {
    return CTime(CGio, CPhut, CGiay - s);
}

//cong them 1 giay, goi ham de dua ve dung gio
CTime& CTime::operator++() {
    CGiay++;
    ChuanHoa();
    return *this;
}

//tru di 1 giay, goi ham de dua ve dung gio
CTime& CTime::operator--() {
    CGiay--;
    ChuanHoa();
    return *this;
}

//toan tu t++
CTime CTime::operator++(int) {
    //luu gia tri vao bien tam
    CTime temp = *this;

    //tang giay len 1
    this->CGiay++;
    //goi ham de xu ly neu tran phut hoac gio
    ChuanHoa();
    //tra ve gia tri chua tang
    return temp;
}

//toan tu t--
CTime CTime::operator--(int) {
    //luu gia tri
    CTime temp = *this;
    //giam giay
    this->CGiay--;
    //goi ham chuan hoa de xu li neu giay xuong <0
    ChuanHoa();
    //tra gia tri
    return temp;
}

//ham nhap dong ho
istream& operator>>(istream& is, CTime& t) {
    int h, m, s;
    bool HopLe = false;

    while (!HopLe) {
        std::cout << "Nhap gio (0-23), phut (0-59), giay (0-59): ";

        //kiem tra du lieu nhap co phai so nguyen khong
        if (!(is >> h >> m >> s)) {
            std::cout << "Loi: Ban phai nhap so nguyên!\n";
            is.clear(); //xoa loi
            is.ignore(1000, '\n'); //xoa ki tu thua
            continue;
        }

        char NextChar = is.peek();
        //kiem tra ki tu con lai co sai hay khong
        if (!isspace(NextChar) && NextChar != EOF) {
            std::cout << "Loi: Du lieu nhap co ky tu la!\n";
            is.clear();
            is.ignore(1000, '\n');
            continue;
        }

        //kiem tra so duoc nhap co bi vuot qua gioi han khong
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            std::cout << "Loi: Gia tri thoi gian khong hop le. Vui long thu lai!\n";
        } else {
            HopLe = true; //thoat vong lap
        }
    }
    //luu gia tri
    t.CGio = h;
    t.CPhut = m;
    t.CGiay = s;
    return is;
}

//Ham xuat dong ho
ostream& operator<<(ostream& os, const CTime& t) {
    //xuat voi 2 ki tu so, dung setfill
    os << setfill('0') << setw(2) << t.CGio << ":"
       << setw(2) << t.CPhut << ":"
       << setw(2) << t.CGiay;
    return os;
}

void gotoxy(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
}

void CTime::InDongHo(){
    system("cls");
    while (true) {
        gotoxy(70, 0);//dua len goc phai
        std::cout << "[" << *this << "]"; //in ra man hinh

        Sleep(1000); //sau 1 giay
        ++(*this); //tang thoi gian len 1
    }
}
