#include<iostream>
#include<string>
using namespace std;

/*class student
{
    private:
    int ngay, thang, nam;
    public:
    student();
    void nhap();
    bool KiemTraHopLe();
    ~student();
};
void student::nhap()
{
    cin>>ngay>>thang>>nam;
}
bool student::KiemTraHopLe()
{
    if(ngay > 0 && thang > 0 && nam > 0)
    {
        if(thang <= 12)
        {
            switch(thang)
            {
                case 1: case 3: case 5: case 7: case 8: case 10 : case 12:
                return (this->ngay<=31);
                case 4: case 6: case 9: case 11:
                return (this->ngay<= 30);
                case 2:
                if(nam %400==0 || this->nam %4 ==0|| this->nam%100!=0)
                    return this->ngay<=29;
                else return this->ngay<=28;
            }
        }
        return false;
    }
    return false;
}*/
class canbo
{
    protected:
    string hoten;
    unsigned short hesoluong;
    unsigned int phucap;
    public:
    virtual void nhap();// phuong thuc ao 
    virtual void xuat();
    virtual unsigned int tinhluong() = 0;// phuong thuc thuan ao trong cac lop dan xuat phair dinh nghia no con lop co ban khong the dinh nghia
    canbo();
};