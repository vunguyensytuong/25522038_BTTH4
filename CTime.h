#ifndef CTIME_H
#define CTIME_H
#include <iostream>
using namespace std;

class CTime
{
private:
    int CGio,CPhut,CGiay;
public:
    CTime(int h=0, int m=0, int s=0);
    ~CTime();

    void ChuanHoa();
    CTime operator+(int s);
    CTime operator-(int s);
    CTime& operator++();
    CTime& operator--();
    CTime operator++(int);
    CTime operator--(int);
    friend istream&operator>>(istream& is,CTime&t);
    friend ostream&operator<<(ostream& os, const CTime &t);
    void InDongHo();
};

#endif // CTIME_H
