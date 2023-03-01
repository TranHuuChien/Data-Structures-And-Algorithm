#include<iostream>
#include<vector>
#include<sstream>
#include<iomanip>
#include<map>
#include<algorithm>
using namespace std;
#define ll long long
/*ll UCLN(ll a, ll b)
{
    if(b==0) return a;
    return UCLN(b,a%b);
}
ll BCNN(ll a, ll b)
{
    return (a*b)/UCLN(a,b);
}
class Phanso
{
    private :
    ll tu, mau;
    public:
    Phanso(ll,ll);
    void rutgon();
    friend istream& operator>> (istream & in, Phanso &);
    friend ostream& operator<<(ostream &out, Phanso);
    friend Phanso operator+(Phanso , Phanso );
    friend Phanso operator-(Phanso , Phanso );
};
Phanso::Phanso(ll tu,ll mau)
{
    this->tu = tu;
    this->mau = mau;
}
istream& operator>> (istream& in, Phanso& a)
{
    in>>a.tu;
    in>>a.mau;
    return in;
}
ostream& operator<<(ostream &out, Phanso a)
{
    out<<a.tu<<"/"<<a.mau;
    return out;
}
Phanso operator + (Phanso a, Phanso b)
{
    Phanso res(1,1);
    ll mc = BCNN(a.mau, b.mau);
    res.tu = mc/a.mau*a.tu + mc/b.mau*b.tu;
    res.mau = mc;
    return res;
}
Phanso operator-(Phanso a, Phanso b)
{
    Phanso res(1,1);
    ll mc = BCNN(a.mau,b.mau);
    res.tu = mc/a.mau*a.tu + mc/b.mau*b.tu;
    res.mau = mc;
    return res;
}
void Phanso:: rutgon()
{
    ll s = UCLN(tu, mau);
    tu/=s;
    mau/=s;
}
class SinhVien
{
    string hoten,lop,ngaySinh;
    float diem;
    public:
    SinhVien();
    friend void nhap(SinhVien &);
    friend void xuat(SinhVien);
    string getLop();
    friend istream& operator>>(istream& in, SinhVien &a);
    friend ostream &operator<<(ostream& out,SinhVien a);
};
string SinhVien::getLop()
{
    return lop;
}
void nhap(SinhVien &a)
{
  
    getline(cin,a.hoten);
    cin>>a.lop>>a.ngaySinh>>a.diem;
}
void xuat(SinhVien a)
{
    cout<<a.hoten<<a.lop<<a.ngaySinh<<fixed<<setprecision(2)<<a.diem;

}
ostream &operator<<(ostream& out,SinhVien a)
{
    out<<a.hoten<<"  "<<a.lop<<" "<<a.ngaySinh<<a.diem<<endl;
    return out;
}
istream& operator>>(istream& in, SinhVien &a)
{
    getline(in,a.hoten);
    string s, word;
    stringstream str(a.hoten);
    while(str>>word)
    {
        s+=word+" ";
    }
    s.erase(s.length()-1);
    s[0]=toupper(s[0]);
    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i]==' '&& s[i + 1]!=' ')
        {
            s[i+1]=toupper(s[i+1]);
        }
    }
    a.hoten = s;
    in>>a.lop>>a.ngaySinh>>a.diem;
    if(a.ngaySinh[1]=='/') a.ngaySinh ="0"+a.ngaySinh;
    if(a.ngaySinh[4]=='/') a.ngaySinh.insert(a.ngaySinh.begin()+ 3,'0');
    return in;
}
SinhVien::SinhVien()
{
    hoten=lop=ngaySinh="";
    diem = 0;
}*/
class ngaySinh
{
    private:
    unsigned int ngay;
    unsigned int thang;
    unsigned int nam;
    public:
    ngaySinh();
    void chuanHoa();
    void nhap();
    void xuat();
};
ngaySinh::ngaySinh()
{
    ngay = 0;
    thang = 0;
    nam = 0;
}
void ngaySinh::chuanHoa()
{
    string s1 = to_string(ngay);
    if(s1.length()==1)    {
        s1 = "0"+s1;
    }
    // hàm stoi này dùng trong c nếu bạn muốn dùng nó phải sử dụng hàm c_tr()
    ngay = stoi(s1.c_str());
    string s2 = to_string(thang);
    if(s2.length()<2)
    {
        s2 = "0"+s2;
    }
    thang = stoi(s2.c_str());
    //string s3 = to_string(nam);
    // if(s3.length()<2)
    // {
    //     s3 = "0"+s3;
    // }
    // nam = stoi(s3.c_str());
}
void ngaySinh::nhap()
{
    cin>>ngay>>thang>>nam;
}
void ngaySinh::xuat()
{
    cout<<ngay<<"/"<<thang<<"/"<<nam;
}
class sinhvien
{
    private: 
    string ma, ten,lop, email;
    public:
    sinhvien()
    {
        ma = ten = lop = email = "";
    }
    string getLop()
    {
        return lop;
    }
    string getTen()
    {
        return ten;
    }
    friend istream& operator>>(istream& in, sinhvien &a);
    friend ostream &operator<<(ostream& out,sinhvien a);
    friend bool sosanhlop(sinhvien, sinhvien);
    friend string tachTen(sinhvien);
    friend string tachten(sinhvien);
    bool operator < (sinhvien a)
    {
        return lop < a.lop;
    }
    // void operator = (const sinhvien a)
    // {
    //     ma = a.ma;
    //     ten = a.ten;
    //     lop = a.lop;
    //     email = a.email;
    // }
};
// có hai cách nạp chồng toán tử một là sử dụng kiểu phương thức trong class luôn
// cách khác là sử dụng hàm bạn để nạp chồng toán tử
string tachTen(sinhvien a)
{
    string s;
    for(int i = a.ten.length()-1; i>=0; i--)
    {
        if(a.ten[i]==' ') break;
        s = a.ten[i]+s;
    }
    return s;
}
bool sosanhlop(sinhvien a, sinhvien b)
{
    return a.lop < a.lop;
}
string tachten(sinhvien a)
{
    stringstream s(a.ten);
    string word;
    string str;
    while(s>>word)
    {
        str = word;
    }
    return str;
}
// nếu cùng lớp thì so sánh theo ten
bool SoSanhNoi(sinhvien a, sinhvien b)
{
    if(a.getLop()==b.getLop())
    return tachten(a) < tachten(b);
    return a.getLop() < b.getLop();
}
bool sosanhtheoTen( sinhvien a, sinhvien b)
{
    return tachTen(a) < tachTen(b);
}
istream& operator>>(istream& in, sinhvien &a)
{
    in>>a.ma;
    in.ignore();
    getline(in,a.ten);
    in>>a.lop;//>>a.email;
    return in;
}
ostream &operator<<(ostream& out,sinhvien a)
{
    out<<a.ma<<" "<<a.ten<<" "<<a.lop<<endl;//<<" "<<a.email<<endl;
    return out;
}
// so sánh hai sinh viên dựa theo tên lớp tăng dần
// bool cmp(sinhvien a, sinhvien b)
// {
//     return a.getLop() < b.getLop();
// }

// bool sosanhTEN(sinhvien a, sinhvien b)
// {
//     return a.getTen() < b.getTen();
// }
string tostring(int n)
{
    string s="";
    int mod;
    while(n>0)
    {
        mod=n%10;
        switch(mod)
        {
            case 0:
            s ="0"+s;
            break;
            case 1:
            s ="1"+ s;
            break;
            case 2:
            s ="2"+ s;
            break;
            case 3:
            s ="3"+ s;
            break;
            case 4:
            s ="4"+ s;
            break;
            case 5:
            s ="5"+ s;
            break;
            case 6:
            s ="6"+ s;
            break;
            case 7:
            s ="7"+ s;
            break;
            case 8:
            s ="8"+ s;
            break;
            case 9:
            s ="9"+ s;
            break;
        }
        n/=10;
    }
    return s;
}
void timKiemDanhSachTheoLop(sinhvien a[], int n)
{
    string s; cin.ignore(); getline(cin,s);
   for(int i = 0; i < n; i++)
   {
       if(a[i].getLop()==s) cout<<a[i];
   }
}
void timkiemTheoKhoa(sinhvien a[], int n)
{
    int nam; cin>>nam;
    for(int i = 0; i < n ;i++)
    {
        if(stoi(a[i].getLop().substr(1,2))==nam)
        cout<<a[i];
    }
}
void timkiemTheoMap(sinhvien a[], int n)
{ map<string,vector<sinhvien>>mp;
    for(int i = 0 ;i < n; i++)
    {
        sinhvien tmp; cin>>tmp;
        mp[tmp.getLop()].push_back(tmp);
    }
    cin.ignore();
    string s; getline(cin,s); 
    for(sinhvien x : mp[s])
        cout<<x;
}
void timKiemTheoTenNganh(sinhvien a[], int n, string s)
{
    for(int i = 0 ; i < n;i++)
    {
        if(a[i].getLop().substr(3,2)==s)
        cout<<a[i];
    }
}
void sortBullesort(sinhvien a[], int n)
{
    for(int i = 0 ; i < n - 1; i++)
    {
        for(int j = 0 ; j < n - i -1;j++)
        {
            if(!SoSanhNoi(a[j], a[j+1]))
                swap(a[j], a[j+1]);
        }
    }
}
void chuanHOaTen(string s)
{
    stringstream str(s);
    string token;
    string sctr;
    while(str>>token)
    {
        sctr+=toupper(token[0]);
        for(int i = 1; i < token.length(); i++)
        {
            sctr+=tolower(token[i]);
        }
        sctr+=" ";
    }
    sctr.erase(sctr.length()-1);
    cout<<sctr;
}
int main()
{
    int n; cin>>n; sinhvien a[n];
    for(int i = 0 ; i <n ; i++)
    {
        cin>>a[i];
    }
    cout<<"Nhap Nganh Sinh Vien :"; cin.ignore();string s;getline(cin,s);
    stringstream str(s);
    string word,t;
    while(str>>word)
    {
        t+=toupper(word[0]);
    }
    timKiemTheoTenNganh(a,n,t);
    // báo mảng các sinh viên yêu cầu có só lượng nhât định 
    //int l; cin>>l;
    // for(int i = 0 ; i < l; i++)
    // {
    //     int n = i;
    //     string ma;
    //     ma = "GV"+ string(3-to_string(n).length(),'0')+to_string(n);
    //     cout<<ma<<endl;
    // }
   //    return 0;
   // đọc cho đến khi hết dữ kiệu đầu vào không biết số lượng nhất định
   /*vector<sinhvien>vt;
   sinhvien tmp;
   while(cin>>tmp)
   {
       vt.push_back(tmp);
   }*/
//    sinhvien a, b;
//    cin>>a;
//    b = a;
//     cout<<b;
//     return 0;

}