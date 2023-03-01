#include<iostream>
#include<vector>
using namespace std;

// lớp con kế thừa lớp cha và lớp ông
// một cha có nhiều con
// một con có nhiều cha
// protected giông 90% rpivatr nhưng có điều khác nhau ở chỗ protected có thể cho các thuộc tính của nó và con của nó sủ dụng 
/*class NhanVien
{
    protected:
    string hoten;
    int namvaolam;
    unsigned tienphucap;
    public:
    NhanVien()
    {
        hoten="";
        namvaolam = 0;
        tienphucap = 100;
    }
    void NhapNhanVien();
    void XuatNhanVien();
};
void NhanVien::NhapNhanVien()
{
    cin.ignore();
    cout<<"Nhap ho ten :";
    getline(cin,hoten);
    do
    {
       cout<<"Nhap nam vao lam";
        cin>>namvaolam;
        if(namvaolam<0 || namvaolam > 2021)
        {
            cout<<"hay nhap lai ";
        }
    } while (namvaolam<0 || namvaolam > 2021);
    
}
void NhanVien::XuatNhanVien()
{
    cout<<" ho ten cua nhan vien : "<<hoten<<endl<<"Nam vao lam cua nhan vien ::"<<namvaolam;
}

class NhanVienSanXuat: public NhanVien
{
    private:
    int  sosanpham;
    public:
    NhanVienSanXuat():NhanVien()// goi contructor cua class cha
    {
        sosanpham = 0;
    }
    void NhapSanXuat();
    void XuatSanXuat();
};
void NhanVienSanXuat::NhapSanXuat()
{
    NhanVien::NhapNhanVien();
    do
    {
      cout<<"Nhap so san pham cua nhan vien san xuat";
      cin>>sosanpham;
      if(sosanpham<0 )
      {
          cout<<"xin vui long nhap lai";
      }  
    } while ( sosanpham<0 );
}
void NhanVienSanXuat::XuatSanXuat()
{
    NhanVien::XuatNhanVien();
    tienphucap += (20*(2021- namvaolam));
    unsigned int luong = sosanpham *1000 + tienphucap;
    cout<<"so san pham "<<sosanpham<<" Luong"<<luong;
}
class NhanVienVanPhong :public NhanVien
{
    private:
    int luongcb;
    int ngaynghi;
    public:
    NhanVienVanPhong();
    void NhapVanPhong();
    void XuatVanPhong();
};
NhanVienVanPhong::NhanVienVanPhong()
{
    luongcb = 0;
    ngaynghi = 0;
}
void NhanVienVanPhong::NhapVanPhong()
{
    NhanVien::NhapNhanVien();
    do
    {
        cout<<"Nhap muc luong co ban cua nhan vien van phong "; cin>>luongcb;
        if(luongcb < 0)
        {
            cout<<"Hay nhap lai";
        }
    } while (luongcb < 0);
    do
    {
        cout<<"Nhap so ngay nghi cua nhan vien "; cin>>ngaynghi;
        if(ngaynghi < 0)
        {
             cout<<"hay nhap lai";
        }
    } while (ngaynghi < 0);
    
}
void NhanVienVanPhong::XuatVanPhong()
{
    NhanVien::XuatNhanVien();
    unsigned luong;
    cout<<"muc luong co ban cua nhan vien van phong"<<luongcb;
    cout<<"so ngay nghi "<<ngaynghi;
}
// tính tổng số tiền lương của tất cả các nhân viên trong công ty sử dụng biến tĩnh
class QuanLyNhanVien
{
    private:
    vector<NhanVienSanXuat>dssx;
    vector<NhanVienVanPhong>dsvp;
    static unsigned tongLuong;
    public:
    void NhapThongTin();
    void XuatThongTin();
};
unsigned QuanLyNhanVien::tongLuong = 0;

void QuanLyNhanVien::NhapThongTin()
{ 
    int lc;
    do
    {
        cout<<"1 .Them Nhan Vien San Xuat";
        cout<<" 2. Them Nhan Vien Van Phong";
        cout<<"3. Exit!";
         cin>>lc;
        if(lc==1) 
        {
            NhanVienSanXuat a;
            a.NhapNhanVien();
            dssx.push_back(a);
        }
        if(lc==2)
        {
            NhanVienVanPhong a;
            a.NhapVanPhong();
            dsvp.push_back(a);
        }
        if(lc==3)
        {
            break;
        }
    } while (lc!3);
}
void QuanLyNhanVien::XuatThongTin()
{
    cout<<"Danh Sach Nhan Vien Van Phong";
    for(int i  = 0; i < dsvp.size() ; i++)
    {
        dsvp[i].XuatVanPhong();
    }
    cout<<"Danh sach Nhan Vien San Xuat";
    for(int i = 0 ; i <dssx.size(); i++)
    {
        dssx[i].XuatSanXuat();
    }
}*/
class dathuc
{
    int bac;
    int *heso;// dùng con trỏ trỏ tới vùng nhớ chưa các hệ số
    public:
    dathuc()
    {
        heso = NULL;
        bac = 0;
    }
    //dathuc( int);
    void Nhap();
    void Xuat();
    dathuc cong( dathuc & u);

    //friend dathuc operator+(dathuc , dathuc);
};
/*dathuc::dathuc(int n)
{
    bac = n;
    heso = new int[bac + 1];
}*/
dathuc operator+(dathuc &u)
{
    int  k = (bac > u.bac ? bac : u.bac);
    dathuc res;
    res.heso = new int[k + 1];
    for(int i  = 0 ; i <= k ; i++)
    {
        if(i <= bac && i <= u.bac)
        {
            res.heso[i]= heso[i] + u.heso[i];
        }
        else if(i <= bac )
        {
            res.heso[i]= heso[i];
        }
        else
        {
            res.heso[i] = u.heso[i];
        }
    }
    return res;
}
/*dathuc operator+(dathuc a , dathuc b)
{
    dathuc c;
    if(a.bac <= b.bac)
    {
        c.bac = b.bac;
        c.heso = new int(b.bac + 1);
        int i;
        for(i = 0 ; i <= a.bac ; i++)
        {
            c.heso[i] = a.heso[i] + b.heso[i];
        }
        for(int j = i + 1 ; j <= b.bac; j++)
        {
            c.heso[j] = b.heso[j];
        }
    }
    else// a.bac > b.bac
    {
        c.bac = a.bac;
        c.heso = new int(a.bac+ 1);
        for(int i = 0 ; i <= b.bac ; i++)
        {
            c.heso[i] = a.heso[i] + b.heso[i];
        }
        for(int k = b.bac + 1; k <= a.bac; k++)
        {
            c.heso[k] = a.heso[k];
        }
    }
    return c;
}*/
void dathuc::Nhap()
{
    do
    {
        cout<<"Nhap bac cua cac da thuc ";
        cin>>bac;
        if(bac< 0)
        {
            cout<<"Nhap lai";
        }
    } while (bac < 0);
    heso = new int(bac + 1);
    for(int i = 0 ; i <= bac; i++)
    {
        cout<<"Nhap bac thu "<<i<<"= ";
        cin>>heso[i];
    }
}
void dathuc::Xuat()
{
    if(heso[0]!=0)
    {
        cout<<heso[0]<<"+";
    }
    for( int i = 1 ; i < bac ;i++)
    {
        if(heso[i]!=0)
        cout<<heso[i]<<"*X^"<<i<<"+";
    }
    if(heso[bac]!=0)
    {
        cout<<heso[bac]<<"*X^"<<bac;
    }
}
int main()
{
    dathuc a;
    a.Nhap();
    a.Xuat();
    cout<<endl;
    dathuc b; b.Nhap(); b.Xuat();
    dathuc c;
    c = a;
    cout<<endl;
    c.Xuat();
}