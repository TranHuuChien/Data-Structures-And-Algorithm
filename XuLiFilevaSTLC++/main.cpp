#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class canbo
{
    protected:
    string hoten;
    unsigned short hesoluong;
    unsigned int phucap;
    public:
    virtual void nhap() = 0;// phuong thuc ao 
    virtual void xuat(ostream &os) = 0;
    virtual unsigned int tinhluong() = 0;// phuong thuc thuan ao trong cac lop dan xuat phair dinh nghia no con lop co ban khong the dinh nghia
    canbo();
};
void canbo::nhap()
{
    cin.ignore();    
    cout<<"nhap ho ten : ";
    getline(cin,hoten);
    cout<<"Nhap he so luong : "; cin>>hesoluong;
    cout<<"Nhap phu cap : "; cin>>phucap;
}
void canbo::xuat(ostream &os)
{
    os<<" Ho ten :"<<hoten<<" He so luong :"<<hesoluong<<" Phu cap :"<<phucap;
}
canbo::canbo()
{
    hoten ="";
    hesoluong = 0;
    phucap = 0;
}
class giangvien:public canbo
{
    private:
    string khoa, trinhdo;
    int sotiet;
    public:
    giangvien();
    void nhap();
    void xuat(ostream &os);
    unsigned int tinhluong();
};
giangvien::giangvien()
{
    khoa ="cntt";
    trinhdo = "cunhan";
    sotiet = 0;
}
void giangvien::nhap()
{
    canbo::nhap();
    cin.ignore();
    cout<<"Nhap ten khoa"; getline(cin, khoa);
    cout<<"Chon trinh do";
    int chon;
    do
    {
        cout<<"1 . Cu Nhan ";
        cout<<" 2. Thac si ";
        cout<<" 3 . Tien si";
        cin>>chon;
        switch(chon)
        {
            case 1:
            trinhdo = "Cu nhan";
            phucap = 300;
            break;
            case 2:
            trinhdo = "Thac si";
            phucap = 500;
            break;
            case 3:
            trinhdo = "Tien si";
            phucap = 1000;
            break;
            default: cout<<"Ban chon lai . Hay chon pham vi ";
            system("pause");
            break;
        }
    } while (chon < 1 || chon > 3);
    cout<<"Nhap so tiet :"; cin>>sotiet;
}
void giangvien::xuat(ostream &os)
{
    canbo::xuat(os);
    os<<endl<<"ten khoa : "<<khoa<<" Trinh do : "<<trinhdo<<"  So tiet : "<<sotiet<<"  Luong : "<<tinhluong()<<endl;
}
unsigned int giangvien::tinhluong()
{
    return hesoluong*730+ phucap + sotiet*45;
}
class NhanVien:public canbo
{
    string phongban;
    int songaycong;
    string chucvu;
    public:
    NhanVien();
    void nhap();
    void xuat(ostream &os);
    unsigned int tinhluong();
};
NhanVien::NhanVien()
{
    songaycong =0;
    phongban ="";
    chucvu = "";
}
void NhanVien::nhap()
{
    canbo::nhap();
    cin.ignore();
    cout<<"\nNhap ten phong ban : ";
    getline(cin,phongban);
    cout<<"\nChon chuc vu : ";
    int chon;
    do
    {
        cout<<"1 .Truong phong ";
        cout<<" 2. Pho phong ";
        cout<<" 3 . Nhan vien";
        cin>>chon;
        switch(chon)
        {
            case 1:
            chucvu = "Truong Phong";
            phucap = 2000;
            break;
            case 2:
            chucvu = "Pho phong";
            phucap = 1000;
            break;
            case 3:
            chucvu = "Nhan vien";
            phucap = 500;
            break;
            default: cout<<"Ban chon lai . Hay chon pham vi ";
            system("pause");
            break;
        }
    } while (chon < 1 || chon > 3);
    cout<<"Nhap so ngay cong : "; cin>>songaycong;
}
unsigned int NhanVien::tinhluong()
{
    return hesoluong*730+ phucap + songaycong*200;
}
void NhanVien::xuat(ostream &os)
{
    canbo::xuat(os);
    os<<"\nPhong ban "<<phongban<<" Chuc vu"<<chucvu<<"  so ngay cong"<<songaycong<<"  luong :"<<tinhluong()<<endl;
}
class quanlycanbo
{
    vector<canbo*>dscanbo;
    public:
    void NhapDanhsach();
    void InDanHSachRaManHinh(ostream &os);
    unsigned int TinhTongLuong();
    //void TimCanBOcoLuongcaoNhat();
};
void quanlycanbo::NhapDanhsach()
{
    canbo *canBo;
    int chon;
    do
    {
        system("cls");
        cout<<"\n1. Nhap giang vien";
        cout<<"\n2. Nhap nhan vien";
        cout<<"\n3. Tro ve ve giao dien chinh\n";
        cin>>chon;
        switch(chon)
        {
            case 1: canBo = new giangvien(); 
            canBo->nhap();
            dscanbo.push_back(canBo);
            break;
            case 2: canBo = new NhanVien();
            canBo->nhap();
            dscanbo.push_back(canBo);
            break;
            case 3:break;
            default: break;
        }
    } while (chon!= 3);
    
}
void quanlycanbo::InDanHSachRaManHinh(ostream& os)
{
    
    for(int i = 0 ; i < dscanbo.size();i++)
    {
        dscanbo[i]->xuat(os);
    }
}
unsigned int quanlycanbo::TinhTongLuong()
{
    unsigned int tong = 0;
    for(int i = 0 ; i < dscanbo.size(); i++)
    {
        tong+=dscanbo[i]->tinhluong();
    }
    return tong;
}
int main()
{
    quanlycanbo a;
    int chon;
    do
    {
        cout<<"\n1. Nhap danh sach ";
        cout<<"\n2. In danh sach ra man hinh";
        cout<<"\n 3.Tong so tien :";
        cout<<"\n4.Thoat !";
        cin>>chon;
        switch(chon)
        {
            case 1: a.NhapDanhsach(); break;
            case 2: a.InDanHSachRaManHinh(cout); break;
            case 3: cout<<a.TinhTongLuong(); break;
            case 4: break;
            default:
            break;
        }
    } while (chon != 4);
    
} 
