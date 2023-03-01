#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
class HinhHoc
{
    public:
    virtual void nhap()= 0;
    virtual void xuat() = 0;
};
class HinhChuNhat: public HinhHoc
{
    private:
    float chieudai, chieurong;
    public:
    void nhap();
    void xuat();
};
void HinhChuNhat::nhap()
{
    do{
        cout<<"Nhap chieu dai , chieu rong : "; cin>>chieudai>>chieurong;
        if(chieudai < 0 || chieurong < 0)
        {
            cout<<"Hay Nhap lai";
        }
    }while(chieudai < 0 || chieurong < 0);
}
void HinhChuNhat::xuat()
{
    cout<<"Chieu dai"<<chieudai<<" "<<"Chieu rong : "<<chieurong<<endl;
}
class HinhTron:public HinhHoc
{
    private:
    float r;
    public:
    void nhap();
    void xuat();
};
void HinhTron::nhap()
{
    do{
        cout<<"Nhap ban kinh hinh tron "; cin>>r;
    }while(r < 0);
}
void HinhTron::xuat()
{
    cout<<"Ban kinh cua hinh tron :"<<r<<endl;
    cout<<"Dien tich cua hinh tron : "<<3.14*r*r<<endl;
}
int main()
{
    HinhHoc *hh = new HinhChuNhat();
    hh->nhap();
    hh->xuat();
}