#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class SinhVien
{
    string mssv, lop, ngaySinh, hoten;
    float diemgpa;
    public:
    SinhVien()
    {
        mssv="";
        hoten="";
        lop ="";
        ngaySinh = "";
        diemgpa = 0;
    }
    static int dem;
    friend istream &operator>>(istream &in, SinhVien &a);
    friend ostream &operator<<(ostream &out, SinhVien a);
};
int SinhVien::dem=0;
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
// 1
// Nguyen Van An
// D20CQCN01-B
// 2/12/2002
// 3.19

istream &operator>>(istream &in, SinhVien &a)
{
    string s = tostring(a.dem);
    dem++;
    while(s.length()<3)
    {
        s="0"+s;
    }
    s = "B20DCCN"+ s;
    a.mssv = s;
    in.ignore();
    getline(cin,a.hoten);
    in>>a.lop;
    in>>a.ngaySinh;
    in>>a.diemgpa;
    if(a.ngaySinh[1]=='/') a.ngaySinh = "0" + a.ngaySinh;
    if(a.ngaySinh[4]=='/') a.ngaySinh.insert(3,0);
    return in;
}
ostream &operator<<(ostream &out, SinhVien a)
{
    cout<<a.mssv<<" "<<a.hoten<<" "<<a.lop<<" "<<a.ngaySinh<<" "<<fixed<<setprecision(2)<<a.diemgpa<<endl;
    return out;
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