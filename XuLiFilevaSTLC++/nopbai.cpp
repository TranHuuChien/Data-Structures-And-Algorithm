#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
class Nhanvien
{
    protected:
    string manhanvien="00001";
    char hoten[40];
    string gioitinh;
    string ngaySinh;
    char diachi[100];
    char mathue[10];
    string ngayki;
    public:
    
    friend istream &operator>> (istream &in, Nhanvien &a);
    friend ostream &operator<< (ostream &out, Nhanvien a);
    
    void nhap();
    void xuat();

};
istream &operator>> (istream &in, Nhanvien &a)
    {
        char s[100];
        in.getline(s,100); strcpy(a.hoten,s);
        return in;
    }
ostream &operator<< (ostream &out, Nhanvien a)
    {
        out<<a.manhanvien<<" "<<a.hoten;
        return out;
    }
void Nhanvien::nhap()
{
    Nhanvien a;
    cin>>a;
}
void Nhanvien::xuat()
{
    Nhanvien a;
    cout<<a;
}
class CanBo
{
    protected:
    string hoten;
    int namSinh;
    string gioitinh;
    string diachi;
    float hesoluong;
    public:
    void nhapCanBo();
    void xuatCanBo();
};
void CanBo::nhapCanBo()
{
    cin.ignore();
    getline(cin,hoten);
    cin>>namSinh;
    cin.ignore();
    getline(cin,gioitinh);
    getline(cin,diachi);
    cin>>hesoluong;
}
void CanBo::xuatCanBo()
{
    cout<<hoten<<" "<<namSinh<<" "<<gioitinh<<" "<<diachi;
}
class congNhan:public CanBo
{
    float bac;
    int luongCN;
    public:
    void tinhLuong()
    {
        luongCN = hesoluong*(3500+ 3500*0.07);
    }
};
class KySu:public CanBo
{
    string nganhDaoTao;
    int luongKS;

    public:
    void tinhLuongKysu()
    {
        luongKS = hesoluong*(3500+ 3500*0.02);
    }
};
class NhanVienPhucVu:public CanBo
{
    string congviec;
    int luongPV;
    public:
    void TinhluongPhucVu()
    {
        luongPV =hesoluong*(3500 + 3500*0.1);
    }
};
class QLCB
{
    public:
    vector<congNhan>cn;
    vector<KySu>ks;
    vector<NhanVienPhucVu>pv;
};
int main()
{
    QLCB a;
}
int dem = 0;
class SinhVien
{
    string mssv, lop, ngaySinh;
    char hoten[30];
    float diemgpa;
    public:
    SinhVien()
    {
        mssv="";
        strcpy(hoten,"");
        lop ="";
        ngaySinh = "";
        diemgpa = 0;
    }
    void setNgaySinh(string s)
    {
        ngaySinh = s;
    }
    string getNgaySinh()
    {
        return ngaySinh;
    }
    friend istream &operator>>(istream &in, SinhVien &a);
    friend void chuanNgay(SinhVien &);
    friend bool sosanh(SinhVien , SinhVien);
    friend ostream &operator<<(ostream &out, SinhVien a);
};
bool sosanh(SinhVien a, Sinhvien b)
{
    
}
istream &operator>>(istream &in, SinhVien &a)
{
    dem++;
    string s = to_string(dem);
    s = string(3-s.length(),'0')+ s;
    s = "B20DCCN"+ s;
    a.mssv = s;
    in.ignore();
    in.getline(a.hoten,30);
    in>>a.lop;
    in>>a.ngaySinh;
    in>>a.diemgpa;
    if(a.ngaySinh[1]=='/') a.ngaySinh = "0" + a.ngaySinh;
    if(a.ngaySinh[4]=='/') a.ngaySinh.insert(3,0);
    return in;
}
ostream &operator<<(ostream &out, SinhVien a)
{
    cout<<a.mssv<<" "<<a.hoten<<" "<<a.lop<<" "<<a.ngaySinh<<" "<<a.diemgpa<<endl;
    return out;
}
void chuanNgay(SinhVien &a)
{
    string s = a.getNgaySinh();
        if(s[1]=='/')
        {
            s.insert(s.begin()+0, '0');
        }
        if(s[4]=='/')
        {
            s.insert(s.begin()+ 3,'0');
        }
    a.setNgaySinh(s);
}

int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}