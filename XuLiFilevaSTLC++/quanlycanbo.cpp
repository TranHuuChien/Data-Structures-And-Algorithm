#include<iostream>
#include<vector>
using namespace std;
class CanBo
{
    protected:
    string maSo;
    string hoten;
    unsigned int phucap;
    public:
    virtual void nhap();// phuong thuc dinh nghia duoc ta goi no la phuong thuc ao
    virtual void xuat();
    virtual unsigned int TinhLuong()= 0; // phuong thuc thuan ao vi hien tai ta chua the dinh tinh ra duoc;
};
void CanBo::nhap()
{
    cout<<" Nhap MA so"; cin>>maSo;
    cout<<"Nhap ho ten cua nguoi do la : "<< getline(cin, hoten);
}
void CanBo::xuat()
{
    cout<<"\nMa So : "<<maSo;
    cout<<"\nHO ten : "<<hoten;
}
class GiangVien:public CanBo
{
    private:
    string khoa,trinhdo;
    unsigned int sotiet;
    public:
    void nhap();
    void xuat();
    unsigned int TinhLuong();
};
void GiangVien::nhap()
{
    CanBo::nhap();
    cout<<"Nhap ten khoa lam viec : "; cin>>khoa;
    int chon;
    do
    {
        cout<<"Nhap trinh do hien tai : ";
        cout<<"\n1. Cu Nhan ";
        cout<<"\n2 . Thac Si ";
        cout<<"\n3 Tien si";
        cin>>chon;
        switch(chon)
        {
            case 1:
            trinhdo ="Cu Nhan";
            phucap = 300;
            break;
            case 2:
            trinhdo = "Thac Si";
            phucap = 500;
            break;
            case 3:
            trinhdo ="Tien Si";
            phucap = 1000;
            break;
        }
    } while (chon<1|| chon>3);
    
    cout<<"NHap so tiet day : "; cin>>sotiet;
}
void GiangVien::xuat()
{
    CanBo::xuat();
    cout<<"\nKhoa : "<<khoa<<"\n Trinh do hien tai : "<<trinhdo<<:"\n Phu cap : "<<phucap<<endl;
}
class NhanVien:public CanBo
{
    private:
    string phongban;
    unsigned int songaycong;
    string  chucvu;
    public:
    void nhap();
    void xuat();
};
void NhanVien::nhap()
{
    cout<<"Nhap Phong Ban : "; cin.ignore(); getline(cin,phongban);
    cout<<"Nhap so ngay cong : "; cin>>songaycong;
    int chon;
    do{
        cout<<"\n1. TRUONG PHONG ";
        cout<<"\n2 PHO PHONG ";
        cout<<"\n3. NHAN VIEN";
        cin>>chon;
        switch(chon)
        {
            case 1: 
            chucvu = "TRUONG PHONG";
            phucap = 2000;
            break;
            case 2: 
            chucvu = "PHO PHONG";
            phucap = 1000;
            break;
            case 3:
            chucvu ="NHAN VIEN ";
            phucap = 500;
            break;
            default:
            break;
        }
    }
    while(chon < 1|| chon > 3);
}
class QUANLY
{
    public:
    vector<CanBo*>dsquanly;
    void NhapThongtin();
    void 
}
int main()
{

}