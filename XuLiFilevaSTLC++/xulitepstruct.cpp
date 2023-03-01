#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
struct monhoc
{
    string tenMon;
    int diem;
};
struct sinhvien
{
    string hoten;
    string mssv;
    vector<monhoc>dsMonHoc;
};
void docThongTinsinhvien(sinhvien &sv,fstream &filein)
{
    getline(filein,sv.hoten,',');
    getline(filein,sv.mssv);
}
void docThongTinMonHoc(monhoc &MH, fstream &filein)
{
    string tempt;
        getline(filein,MH.tenMon,',');
        filein>>MH.diem;
    
}
void docTHONGTIN(vector<sinhvien>&danhsach,fstream &filein)
{
    while(filein.eof()==false)
    {
        sinhvien sv;
        string tempt;
        docThongTinsinhvien(sv,filein);
        int n;
        filein>>n;
        for(int i = 0 ; i < n; i++)
        {
            monhoc MH;
            docThongTinMonHoc(MH,filein);
            sv.dsMonHoc.push_back(MH);
        }
        danhsach.push_back(sv);
    }
}
void xuat1sinhvien(sinhvien sv)
{
    cout<<"\nHo va ten cua sinh vien "<<sv.hoten;
    cout<<"\nMa so sinh vien :"<<sv.mssv;
}
void xuatThongtinMOnHoc(monhoc MH)
{
    cout<<"\nten mon hoc :"<<MH.tenMon;
    cout<<"\n diem cua sinh vien :"<<MH.diem;
}
void xuatTHONGTIN(vector<sinhvien>danhsach)
{
    for(int i = 0 ; i < danhsach.size(); i++)
    {
        xuat1sinhvien(danhsach[i]);
        for(int j = 0; j < danhsach[i].dsMonHoc.size(); j++)
        {
            xuatThongtinMOnHoc(danhsach[i].dsMonHoc[j]);
        }
    }
}
void timsinhvien(vector<sinhvien>danhsach)
{
    string ten;
    cout<<"\n Nhap ten sinh vien can tim";
    getline(cin,ten);
    for(int i =  0; i < danhsach.size();i++)
    {
        if(danhsach[i].hoten==ten)
        {
            xuat1sinhvien(danhsach[i]);
            for(int j = 0; j<danhsach[i].dsMonHoc.size();j++)
            xuatThongtinMOnHoc(danhsach[i].dsMonHoc[j]);
        }
    }
}
int main()
{
    vector<sinhvien>danhsach;
    fstream filein("input.txt",ios::in);
    //docTHONGTIN(danhsach,filein);
    //timsinhvien(danhsach);
    xuatTHONGTIN(danhsach);
    filein.close();
    return 0;
}
/*void giaiquyet()
{
  int count;
  long long n;
  cin>>n;
  for(long long i = 2; i<sqrt(n); i++)
  {
    if(n%i==0)
    {
      count = 0;
      while(n %i==0)
      {
        n=n/i;
        count++;
      }
      cout<<i<<" "<<count<<" ";
    }
  }
  if(n>1)*/