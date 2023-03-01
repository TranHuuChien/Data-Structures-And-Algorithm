#include<iostream>
#include<string>
#include<regex>
using namespace std;
struct ngaysinh
{
    int ngay,thang, nam;
};
struct sinhvien
{
    string mssv, lop,hoten, gioitinh;
    int diemtb;
    ngaysinh b;
};
struct danhsach
{
    int soluong;
    sinhvien a[5];
};
void nhap1TT(sinhvien &sv)
{
    regex mssvRegex("^[b|n]\\d{2}(dc)(cn|AT|DPT|KT|QT|VT|DT)[0-9]{3}$");
    regex lopRegex("^d\\d{2}(cq)(cn|AT|DPT|KT|QT|VT|DT)\\d{2}-[n|b]$");
    regex hotenRegex("[a-z|A-Z");
    regex gioitinhRegex("^(NAM)||(NU)||(nam)||(nu)||(khac)$");
    //regex diemtbRegex("^[0-9]\\.?[0-9]{2}|10$");
     do
     {
         cin.ignore();
        cout<<" Nhap ma so sinh vien ";
        getline(cin,sv.mssv);
        if(!regex_match(sv.mssv,mssvRegex))
        {
            cout<<"ban da nhap sai cau truc hay nhap lai";
        }
     } while (!regex_match(sv.mssv,mssvRegex));
     
    cout<<"Nhap ho va ten sinh vien  ";
    getline(cin,sv.hoten);
    cout<<" Nhap lop hoc  ";
    getline(cin,sv.lop);
    cout<<"Nhap gioi tinh ";
    getline(cin,sv.gioitinh);
    cout<<" Nhap ngay thang nam sinh ";
    cin>>sv.b.ngay>>sv.b.thang>>sv.b.nam;
    cout<<" Nhap diem trung binh cua sinh vien";
    cin>>sv.diemtb;
    cin.ignore();
}
void xuat1tt(sinhvien sv)
{
    cout<<"thong tin cua sinh vien ";
    cout<<"\nma so sinh vien "<<sv.mssv;
    cout<<"\n ho ten cua sinh vien la :  "<<sv.hoten;
    cout<<"\n ten lop cua sinh vien la :  "<<sv.lop;
    cout<<"\n Gioi tinh cua sinh vien la:  "<<sv.gioitinh;
    cout<<"\n ngay thang nam sinh :  "<<sv.b.ngay<<"/"<<sv.b.thang<<"/"<<sv.b.nam;
    cout<<"\n diem cua sinh vien  "<<sv.diemtb;
    cout<<endl;
}
void nhapdanhsach(danhsach &ds)
{
    for(int i = 0 ; i < ds.soluong; i++)
    {
        nhap1TT(ds.a[i]);
    }
}
void xuatdanhsach(danhsach ds)
{
    for(int i = 0 ; i < ds.soluong; i++)
    {
        xuat1tt(ds.a[i]);
    }
}
void xuatdiemtb(danhsach ds)
{
    for(int i =0 ; i < ds.soluong ; i++)
    {
        if(ds.a[i].diemtb > 5)
        {
            xuat1tt(ds.a[i]);
        }
    }
}
void dssvcntt(danhsach ds)
{
    string s="cn";
    int q;
    for(int i =0; i < ds.soluong; i++)
    {
        q=ds.a[i].mssv.find(s);
        if(q!=std::string::npos)
        {
            xuat1tt(ds.a[i]);
        }
    }
}
void xoakhoangtrang(string &s)
{
    int len=s.length();
    while(s[0]==' ')
    {
        s.erase(0,1);
        len--;
    }
    for(int i = 0 ; i < len; i++)
    {
        if(s[i]==' '&& s[i+1]==' ')
        {
            s.erase(i,1);
            i--;
        }
    }
    while(s[s.length()-1]==' ')
    {
        s.erase(len-1,1);
        len--;
    }
}
int demnu(danhsach ds)
{
    int dem =0;
    for(int i = 0 ; i < ds.soluong; i++)
    {
        xoakhoangtrang(ds.a[i].gioitinh);
        if(ds.a[i].gioitinh=="nu")
        {
            dem++;
        }
    }
    return dem;
}
void svcaonhat(danhsach ds)
{
    int max = ds.a[0].diemtb;
    int dem = 0;
    for(int i = 1 ; i < ds.soluong;i++)
    {
        if(ds.a[i].diemtb>max)
        {
            max=ds.a[i].diemtb;
            dem++;
        }
        if(ds.a[i].diemtb=max)
        {
            xuat1tt(ds.a[i]);
        }
    }
    xuat1tt(ds.a[dem]);
}
void themsinhvien(danhsach ds)
{
    cout<<"them mot sinh vien vao cuoi danh sach\n";
    ds.soluong++;
    nhap1TT(ds.a[ds.soluong]);
}
void swap(int &a, int &b)
{
    int tempt = a;
    a = b;
    b=tempt;
}
void sapxeptheodiem(danhsach ds)
{
    for(int i = 0 ; i < ds.soluong; i++)
    {
        for(int j = i+ 1; j < ds.soluong;j++)
        {
            if(ds.a[i].diemtb>ds.a[i].diemtb)
            {
                swap(ds.a[i], ds.a[j]);
            }
        }
    }
}
int main()
{
    system("cls");
    sinhvien sv;
    danhsach ds;
    nhap1TT(sv);
    /*do
    {
        cout<<"1.Xuat danh sach sinh vien co diem trung bình > 5  ";
        cout<<"2.Xuat danh sach cac sinh vien thuoc nganh cong nghe thong tin  ";
        cout<<"3.So luong sinh vien nu la  ";
        cout<<"4. Xuat ra sinh vien co diem trung binh cao nhat ";
        cout<<"5. Them mot sinh vien moi vao cuoi danh sach";
        cout<<"xuat ra su lua chon cua ban ";
        cin>>luachon;
        switch (luachon)
        {
        case 1:
            break;
        
        default:
            break;
        }
    } while ();*/
    
    return 0;
}