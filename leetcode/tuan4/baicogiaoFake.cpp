#include<iostream>
#include<vector>
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
    ngaysinh ngaySinh;
};
void nhap1Sinhvien( vector<sinhvien>&danhsach)
{
    sinhvien sv;
    regex mssvRegex("^[b|n][0-9]{2}dccn[0-9]{3}$");
    regex lopRegex("^d\\d{2}cqcn\\d{2}-[n|b]$");
   // regex hotenRegex("^\\D{20}$");
    regex gioitinhRegex("[x|y]");
    cin.ignore();
    do{
        cout<<"Nhap Ma so sinh vien  ";
        getline(cin,sv.mssv);
        if(!regex_match(sv.mssv,mssvRegex))
        {
            cout<<"nhap lai\n";
        }

}while(!regex_match(sv.mssv,mssvRegex));
    
        cout<<"Nhap ho ten sinh vien   ";
        getline(cin,sv.hoten);
        /*if(!regex_match(sv.hoten,hotenRegex))
        {
            cout<<"nhap lai";
        }
    }while(!regex_match(sv.hoten,hotenRegex));*/
    do{
    cout<<"Nhap lop hoc cua sinh vien   ";
    getline(cin,sv.lop);
    if(!regex_match(sv.lop,lopRegex))
    {
        cout<<"nhap lai\n";
    }
    }while(!regex_match(sv.lop,lopRegex));
    /*do{
        cout<<" Nhap gioi tinh cua sinh vien (nam : y nu :x) ";
        cin>>sv.gioitinh);
        if(!regex_match(sv.gioitinh,lopRegex))
        {
            cout<<" ban da nhap sai hay nhap lai ";
        }
    }while(!regex_match(sv.gioitinh,lopRegex));*/
    cout<<"\nNhap gioi tinh cua sinh vien ";
    getline(cin,sv.gioitinh);
    cout<<" nhap diem trung binh cua sinh vien   ";
    cin>>sv.diemtb;
    cout<<"Nhap ngay thang nam sinh (vd 23 2 2002) ";
    cin>>sv.ngaySinh.ngay>>sv.ngaySinh.thang>>sv.ngaySinh.nam;
    danhsach.push_back(sv);
}
void nhapDanhsach(vector<sinhvien>&danhsach, int n)
{
    cout<<"-----------THONG TIN------------\n";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Thong tin sinh vien thu "<<i+1;
        nhap1Sinhvien(danhsach);
    }
}
void xuat1Sinhvien(sinhvien sv)
{
    cout<<"\nMa so sinh vien cua sinh vien"<<sv.mssv;
    cout<<"\nHo va ten cua sinh vien "<<sv.hoten;
    cout<<"\nTen lop hien tai cua sinh vien "<<sv.lop;
    cout<<"\nGioi tinh cua sinh vien "<<sv.gioitinh;
    cout<<"\n Diem trung binh hoc ki cua sinh vien "<<sv.diemtb;
    cout<<"\n Ngay thang nam sinh cua sinh vien "<<sv.ngaySinh.ngay<<"/"<<sv.ngaySinh.thang<<"/"<<sv.ngaySinh.nam;
}
void xuatDanhsach(vector<sinhvien>danhsach)
{
    cout<<"-----------THONG TIN DA NHAP------------\n";
    for(int i = 0 ; i < danhsach.size();i++)
    {
        xuat1Sinhvien(danhsach[i]);
    }
}
/*
void xuatDanhSach(vector<sinhvien>danhsach)
{
    for(auto i =danhsach.begin(); i!= danhsach.end();i++)
    {
        xuatdanhsach(*i);
    }
*/
/*
void danhsachlonhon5(vector<sinhvien>danhsach)
{
    for(auto i = danhsach.begin(); i!=danhsach.end();i++)
    {
        if((*i).diemtb>5)
        {
            xuat1Sinhvien(*i);
        }
    }
}*/
void danhSachsvdiem(vector<sinhvien>danhsach)
{
    for(int i = 0 ; i < danhsach.size();i++)  
    {                                              
        if(danhsach[i].diemtb>5)
        {
            xuat1Sinhvien(danhsach[i]);
        }
    }
}
void danhsachsvcntt(vector<sinhvien>danhsach)
{
    for(int i = 0 ; i < danhsach.size(); i++)
    {
        if(danhsach[i].mssv.find("cn")!=0)
        {
            cout<<danhsach[i].hoten;// xuat danh sach ten cua sinh vien khoa cong nghe thong tin
            // xuat1Sinhvien(danhsach[i]) xuat toan bo thong tin cua sinh vien
        }
    }
}
void demsoluongsvnu(vector<sinhvien>danhsach)
{
    int dem= 0;
    for(auto i = danhsach.begin(); i!= danhsach.end(); i++)
    {
        if((*i).gioitinh=="nu")
        {
            dem++;
        }
    }
    cout<<"toan bo danh sach cong nghe thong tin co "<<dem<<" ban nu :)";
}
void timsinhviencodiemcaonhat(vector<sinhvien>danhsach)
{
    float max =danhsach[0].diemtb;
    for(int i = 1;i< danhsach.size(); i++)
    {
        if(danhsach[i].diemtb>max)
        {
            max = danhsach[i].diemtb;
        }
    }
    for(auto i = danhsach.begin(); i!= danhsach.end(); i++)
    {
        if((*i).diemtb==max)
        {
            cout<<"\nsinh vien co diem cao nhat ten la  "<<(*i).hoten;
        }
    }
}
void themsinhviencuoids(vector<sinhvien>danhsach)
{
    nhap1Sinhvien(danhsach);
}
void  timsvtheomssv(vector<sinhvien>danhsach)
{
    string mssv;
    regex mssvRegex("^[b|n][0-9]{2}dccn[0-9]{3}$");
     do{
        cout<<"Nhap Ma so sinh vien  ";
        getline(cin,mssv);
        if(!regex_match(mssv,mssvRegex))
        {
            cout<<"nhap lai\n";
        }

}while(!regex_match(mssv,mssvRegex));
    for(int i = 0; i < danhsach.size(); i++)
    {
        if(danhsach[i].mssv ==mssv)
        {
            xuat1Sinhvien(danhsach[i]);
            danhsach.erase(danhsach.begin()+i);
        }
    }
}
void swap(int &a, int &b)
{
    int tempt = a;
    a=b;
    b= tempt;
}
/*void sapxep(vector<sinhvien>danhsach)
{
    for(int i = 0 ; i < danhsach.size(); i++)
    {
        sort(danhsach,danhsach + danhsach.size());
    }
}*/
int main()
{
    vector<sinhvien>danhsach;
    int n,luachon;
    cout<<" Hay nhap so luong danh sach sinh vien ";
    cin>>n;
    nhapDanhsach(danhsach,n);
    xuatDanhsach(danhsach);
    do
    {
        cout<<"\n1.Xuat danh sach sinh vien co diem trung bình > 5 \n ";
        cout<<"2.Xuat danh sach cac sinh vien thuoc nganh cong nghe thong tin \n ";
        cout<<"3.So luong sinh vien nu la \n ";
        cout<<"4. Xuat ra sinh vien co diem trung binh cao nhat\n ";
        cout<<"5. Them mot sinh vien moi vao cuoi danh sach\n";
        cout<<"6 Tim sinh vien theo ma so , xoa sinh vien co ra khoi danh sach \n";
        cout<<"7.Sap xep sinh vien theo diem tang dan \n";
        cout<<"8. Thoat !";
        cout<<"xuat ra su lua chon cua ban\n ";
        cin>>luachon;
        switch (luachon)
        {
        case 1:
            cout<<"danh sach sinh vien co diem lon hon 5 \n";
            danhSachsvdiem(danhsach);
            break;
        case 2: 
        cout<<"Danh sach thuoc nganh cong nghe thong tin\n ";
        danhsachsvcntt(danhsach);
        break;
        case 3:
        cout<<"So luong sinh vien nu : ";
        demsoluongsvnu(danhsach);
        break;
        case 4:
        cout<<"Sinh vien co diem lon nhat\n ";
        timsinhviencodiemcaonhat(danhsach);
        break;
        case 5:
        cout<<"them mot sinh vien vao cuoi danh sach\n ";
        themsinhviencuoids(danhsach);
        break;
        case 6:
        cout<<"Hay nhap thong tin sinh vien can tim va xoa khoi danh sach \n";
        timsvtheomssv(danhsach);
        cout<<"danh sach sinh vien sau khi da xoa ";
        xuatDanhsach(danhsach);
        break;
        case 7:
        cout<<"Sap xep danh sach theo die\n ";
        break;
        case 8:
        cout<<"cam on ban da su dung dich vu cua chung toi \n";
        default:
            break;
        }
    } while (luachon<0||luachon>8);
    
    system("pause");
    return 0;
}
