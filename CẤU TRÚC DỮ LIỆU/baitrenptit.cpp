#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

/*int main()
{
    vector<pair<int,int>>vt;
    for(int i = 0 ; i< 4; i++)
    {
        int a, b;
        cin>>a>>b;
        vt.push_back(make_pair(a,b));
    }
    sort(vt.begin(),vt.end());
    for(int i = 0 ; i < 4; i++)
    {
        cout<<vt[i].first<<"  "<<vt[i].second<<endl;
    }
}8*/
/*void solve(int n, int cnt, vector<int>ans, set<int>&s, int a[])
{
    if(cnt==n)
    {
        for(int i = 0 ; i<n;i++)
        {
            cout<<ans[i];
        }
        return;
    }
    for(int i = 0; i< k;i++)
    {
        if(s.count(a[i])==0)
        {
            ans.push_back(a[i]);
            s.insert(a[i]);
            solve(n,cnt+1,ans,s,a);
            s.erase(s.find(a[i]));
            ans.pop_back();
        }
    }
    return;
}
int main()
{
    int n,k;
    int cnt;
    vector<int>ans;
    set<int>s;
    cin>>n>>k;
    int a[n];
    for(int i = 0 ; i< n;i++)
    {
        cin>>a[i];

    }
    solve(n,0,ans,s,a);   
}*/
class KhachHang;
class HangHoa
{
    private:
    string tenHang,ngaySanXuat;
    int donGia;
    int soLuong;
    public:
    void SetTenHang(string);
    string GetTenHang();
    void SetNgaySanXuat(string);
    string GetNgaySanXuat();
    void SetDonGia(int);
    int GetDonGia();
    void SetSoLuong(int);
    int GetSoLuong();
    int TinhTien();
    friend class KhachHang;
    friend void hehe(HangHoa);
};

void HangHoa::SetTenHang(string tenHang)
{
    this->tenHang = tenHang;
}
string HangHoa:: GetTenHang()
{
    return this->tenHang;
}
void HangHoa::SetNgaySanXuat(string ngaySanXuat)
{
    this->ngaySanXuat = ngaySanXuat;
}
string HangHoa:: GetNgaySanXuat()
{
    return this->ngaySanXuat;
}
void HangHoa::SetDonGia(int donGia)
{
    this->donGia = donGia;
}
int HangHoa::GetDonGia(){
    return this->donGia;
}
void HangHoa::SetSoLuong(int soLuong)
{
    this->soLuong = soLuong;
}
int HangHoa::GetSoLuong()
{
    return this->soLuong;
}
int HangHoa::TinhTien()
{
    return donGia*soLuong;
}
class KhachHang
{
    private:
   string Username;
    string password;
    public:
    void SetUsername();
    string GetUsername();
    void SetPassword();
    string GetPassword();
    void MuaHang(HangHoa&);
};
void KhachHang::SetUsername()
{
    this->Username = "chiendeptrainhatquadat";
}
string KhachHang::GetUsername()
{
    return Username;
}
void KhachHang::SetPassword()
{
    this->password = "123456789";
}
string KhachHang:: GetPassword()
{
    return password;
}
void KhachHang:: MuaHang(HangHoa &a)
{
    string tenhang,ngaysanxuat;
    int dongia;
    int soluong;
    cout<<" Nhap ten Hang : ";
    getline(cin,tenhang);
    a.SetTenHang(tenhang);
    cout<<" Nhap ngay san xuat ";
    getline(cin,ngaysanxuat);
    a.SetNgaySanXuat(ngaysanxuat);
    cout<<" Nhap don Gia ";
    cin>>dongia;
    a.SetDonGia(dongia);
    cout<<" Nhap so luong ";
    cin>>soluong; 
    a.SetSoLuong(soluong);
    cout<<" so tien ban can phai thanh toan : ";
    cout<<a.TinhTien()<<"$";
    cout<<"Cam on ban da su dung dich vu cua chung toi ";
}
/*class car
{
    private:
    int speed;
    char mark[20];
    float price;
    public:
    car(int);
    int getSpeed()
    {
        return speed;
    }
};
car:: car(int speed)
{
    this->speed = speed;
    // strcpy(this->mark, mark);
    // this->price= price;
}
class bus: public car
{
    int label;
    public :
    bus();
    bus(int , int);
};
bus::bus():car()
{
    label = 0;
}*/
class Sach
{
    string tenTacgia;
    int soTrang;
    public:
    void nhap()
    {
    cout<<"\n Nhap ten tac gia :";
    getline(cin, tenTacgia);
    cout<<" \nNHap so trang cua moi cuon sach : ";
    cin>>soTrang;
    }
    void xuat()
    {
        cout<<"\nTen tac gia : "<<this->tenTacgia<<"\t"<<"so Trang cua cuon sach " << this->soTrang<<endl;
    }
};
class TapChi
{
    int SoPhatHanh;
    int thangPhatHanh;
    public:
    void nhap()
    {
        cout<<" \nNhap so phat hanh :";cin>>this->SoPhatHanh; cout<<"Thang phat hanh : "; cin>>this->thangPhatHanh;
    }
    void xuat()
    {
        cout<<endl<<"So Phat Hanh "<< this->SoPhatHanh<<"\t"<< this->thangPhatHanh<<endl;
    }
}; 
class Bao
{
    int ngayPhathanh;
    public:
    void nhap()
    {
        cout<<" \nNhap Ngay Phat Hanh ";
        cin>>ngayPhathanh;
    }
    void xuat()
    {
        cout<<"\n nhap ngay phat hanh ";
        cout<<ngayPhathanh<<endl;
    }
};
class TaiLieu: public Sach,public TapChi ,public Bao
{
    string maTailieu, tenNhasanxuat;
    int soPhatHanh;
    public:
    void nhap();
    void xuat();
};
void TaiLieu::nhap()
{
    Sach::nhap();
    TapChi::nhap();
    Bao::nhap();
    cin.ignore();
    cout<<"\n Nhap Ma tai lieu "; getline(cin,maTailieu);
    cout<<"\nNhap ten nha san xuat "; getline(cin,tenNhasanxuat);
    cout<<"\n Nhap so phat hanh "; cin>>soPhatHanh;
    cin.ignore();
}
void TaiLieu::xuat()
{
    Sach::xuat();
    TapChi::xuat();
    Bao::xuat();
    cout<<"\n Ma tai Lieu "<<maTailieu;
    cout<<"\n ten Nha san xuat "<<tenNhasanxuat;
    cout<<"\n so phat hanh "<<soPhatHanh;
}
class QuanLyTaiLieu
{
    vector<TaiLieu>vt;
};
/*class Engine
{
    int power;
    public:
    Engine()
    {
        power = 0;
    }
    Engine(int power)
    {
        this->power = power;
    }
    void show();
    float getPower()
    {
        return power;
    }
};
void Engine::show()
{
    cout<<" this is an engine having a power of "<< power<<" KWH "<<endl;
}
class car: public virtual Engine
{
    int speed;
    string mark;
    float price;
    public:
    car();
    car(int ,int , string, float);
    string getMark() { return mark;}
    int getSpeed() { return speed;}
    float getPrice() { return price;}
    void show();
};
car:: car():Engine()
{
    speed=0;
    mark ="";
    price = 0;
}
car:: car(int power, int speed, string mark , float price):Engine(power)
{
    this->speed = speed;
    this->mark = mark;
    this->price = price;
}
void car::show()
{
    cout<<" this is a "<<mark<<" having a speed of"<<speed<<"km/h, its power is"<<getPower()<<" km and price is $"<<price<<endl;
    return;
}
class PublicTransport: public virtual Engine
{
    float ticket;
    public:
    PublicTransport();
    PublicTransport(int,float);
    void show();
    float getticket()
    {
        return ticket;
    }
};
PublicTransport::PublicTransport()
{
    ticket=0;
}
PublicTransport::PublicTransport(int power, float ticket):Engine(power)
{
    this->ticket = ticket;
}
void PublicTransport::show()
{
    cout<<"this is a public transport having a ticket of $";
    cout<<ticket<<"and its power is "<< getPower()<<"KWh"<<endl;
}
class Bus: public car, public PublicTransport
{
    int label;
    public:
    Bus();
    Bus(int , int , string , float, float, int);
    void show();
};
Bus::Bus():Engine(), car(), PublicTransport()
{
    label  = 0;
}
Bus::Bus(int power, int speed, string mark, float price, float ticket, int label):Engine(power), car(power,speed, mark,price), PublicTransport(power,ticket)
{
    this->label = label;
}
void Bus::show()
{
    cout<<"This is a bus on the line "<<label<<", its speed is "<<getSpeed()<<"km/h, power is"<<getPower()<<"Kwh , mark is "<<getMark()<<", price is $ "<<getPrice()<<" and ticket is "<<getticket()<<endl;
    return;
}*/
void Nhap(vector<TaiLieu>&vt)
{
    TaiLieu tl;
    cout<<"Nhap so luong cuon sach ban muon "; int n; cin>>n;
    cin.ignore();
    for(int i = 0 ; i < n ; i++)
    {
        tl.nhap();
        vt.push_back(tl);
    }
}
void Xuat(vector<TaiLieu>vt)
{
    for(int i = 0 ; i < vt.size(); i++)
    {
        vt[i].xuat();
    }
}
class PhanSo
{
    private: 
    int tuso;
    int mauso;
    public:
    PhanSo();
    PhanSo(int , int);
    void NhapPhanSo();
    void XuatPhanSo();
    int getMauso();
    int getTuso();
    int UCLN(int , int);
    // có hai cách  để dùng toán tử cộng 
    // một kiểu sự dụng hàm trong class chỉ cần có một đối tượng thôi
    // 2 là sử dụng hàm friend cộng hai đối tượng lại với nhau
    PhanSo operator+(PhanSo &b)
    {
        PhanSo res;
        res.tuso = tuso + b.tuso;
        res.mauso = mauso + b.mauso;
        return res;
    }
    friend PhanSo operator+(PhanSo &, PhanSo&);
    void RutGonPS();
    friend PhanSo operator-(PhanSo&, PhanSo &);
    friend PhanSo operator*(PhanSo & , PhanSo&);
    friend istream & operator >>(istream &in , PhanSo &a);
    friend ostream & operator <<(ostream & out, PhanSo a);
};
PhanSo operator*(PhanSo &a, PhanSo& b)
{
    PhanSo res;
    res.tuso = a.tuso + b.tuso;
    res.mauso = a.mauso + b.mauso;
    return res;
}
PhanSo operator-(PhanSo& a, PhanSo & b)
{
    PhanSo res;
    res.tuso = a.tuso + b.tuso;
    res.mauso = a.mauso + b.mauso;
}
PhanSo operator +(PhanSo &a, PhanSo &b)
{
    PhanSo res;
    res.tuso = a.tuso + b.tuso;
    res.mauso = a.mauso + b.mauso;
    return res;
}
PhanSo::PhanSo()
{
    tuso = 0;
    mauso = 1;
}
PhanSo::PhanSo(int tuSo, int mauSo)
{
    tuso = tuSo;
    mauso = mauSo;
}
int PhanSo::UCLN(int tu, int mau)
{
    int a = tu;
    int b = mau;
    if(a>b) a = a - b;
    if(b > a) b = b - a;
    if(a==0) return b;
    else
    {
        return a;
    }
    
}
void PhanSo::NhapPhanSo()
{
    cin>>tuso;
    cin>>mauso;
}
void PhanSo::XuatPhanSo()
{
    cout<<tuso<<"/"<<mauso;
}
void PhanSo::RutGonPS()
{
    int tu = tuso;
    int mau = mauso;
    int uc = UCLN(tu, mau);
    cout<<tuso/uc<<"/"<<mauso/uc;
}
int PhanSo::getTuso()
{
    return tuso;
}
int PhanSo::getMauso()
{ return mauso; }

istream & operator >>(istream &in , PhanSo &a)
{
    in>>a.tuso;
     in>>a.mauso;
    return in;
}
ostream & operator <<(ostream& out, PhanSo a)
{
    out<<a.tuso<<endl<<a.mauso;
    return out;
}
class complex
{
    int real;
    int imag;
    public: 
    complex();
    complex(int , int);
    void Xuat();
    complex operator+(complex &a)
    {
        complex res;
        res.real = real + a.real;
        res.imag = imag + a.imag;
        return res;
    }
    operator float() const 
    {
        return float(real)/ float(imag);
    }
};
void complex::Xuat()
{
    cout<<real<<"  "<<imag<<endl;
}
complex::complex()
{
    real = 0;
    imag = 0;
}
complex::complex(int a, int b)
{
    real = a;
    imag = b;
}
int main()
{
   complex a(1,2);
   float n = a;
   cout<<n;
}