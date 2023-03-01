#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
/*struct ngaysinh 
{
    int ngay , thang , nam;
};
struct employee
{
    char name[20];
    ngaysinh ngaySinh;
    char chucvu[20];
    float luong;
};
void nhapFile(fstream &fileOut,employee &myEmployee )
{
int recordNumber;
    cin>>recordNumber;
    for(int i =0 ; i < recordNumber; i++)
    {
        cout<<"Ban ghi thu "<<i +1<<endl;
        cin.ignore();
        cout<<"Name ";
        gets(myEmployee.name);
        cout<<"Ngay thang nam sinh ";
        cin>>myEmployee.ngaySinh.ngay>>myEmployee.ngaySinh.thang>>myEmployee.ngaySinh.nam;
        cin.ignore();
        cout<<"Chuc vu c";
        gets(myEmployee.chucvu);
        cout<<"Luong ";
        cin>>myEmployee.luong;
        // Ghi du lieu vao file
        fileOut.write(reinterpret_cast<char *>(&myEmployee), sizeof(employee));

    }
    fileOut.close();
}
void xuatFile(fstream &fileOut,employee &myEmployee)
{
     fileOut.read(reinterpret_cast<char *>(&myEmployee),sizeof(employee));
        cout<<"\nTen cua nhan vien "<<myEmployee.name;
        cout<<"\n Ngay thang nam sinh"<<myEmployee.ngaySinh.ngay<<" "<<myEmployee.ngaySinh.thang<<"  "<<myEmployee.ngaySinh.nam;
        cout<<"\n Chuc vu nhan vien "<<myEmployee.chucvu;
        cout<<"\n Luong cua nhan vien "<<myEmployee.luong;
}

int main()
{
    employee myEmployee;
    fstream fileOut("output.txt",ios::binary|ios::app);
    //nhapFile(fileOut,myEmployee);
        xuatFile(fileOut,employee);
    fileOut.close();

}*/

/*struct monhoc
{
    
    string tenmonhoc;
    float diem;
};

struct sinhvien
{
    string hovaten;
    string maso, ngaythang;
    vector<monhoc>dsmonhoc;
};
void docThongtinsinhvien(fstream &filein, sinhvien &sv )
{
    getline(filein,sv.hovaten);
    getline(filein,sv.maso);
    getline(filein,sv.ngaythang);
}
void docMonHoc(fstream &filein, monhoc &monHoc)
{
    getline(filein,monHoc.tenmonhoc,'-');
    filein>>monHoc.diem;
}
void docThongtinsinhvien(fstream &filein, vector<sinhvien>danhsach)
{
    while(filein.eof()==false)
    {
        sinhvien sv;
        docThongtinsinhvien(filein,sv);
        int n; // so luong mon hoc
        filein>>n;
        for(int i = 0 ; i < n; i++)
        {
            monhoc monHoc;
            docMonHoc(filein,monHoc);
            sv.dsmonhoc.push_back(monHoc);
        }
        danhsach.push_back(sv);
    }
}
void xuatThongTin1sinhvien(sinhvien sv)
{
    cout<<" \n Ten cua sinh vien "<<sv.hovaten;
    cout<<"\n Ma so sinh vien cua tung nguoi"<<sv.maso;
    cout<<"\n Ngay thang nam sinh cua tung sinh vien "<< sv.ngaythang;
}
void xuatMonhoc( monhoc Monhoc)
{
    cout<<"\n Mon hoc :"<<Monhoc.tenmonhoc<<"   diem :"<<Monhoc.diem;
}
void xuatthongtin( vector<sinhvien>danhsach)
{
    for(int i = 0 ; i < danhsach.size();i++)
    {
        xuatThongTin1sinhvien(danhsach[i]);
        for(int j = 0 ; j < danhsach[i].dsmonhoc.size(); i++)
        {
            xuatMonhoc(danhsach[i].dsmonhoc[j]);
        }
    }
}
int main()
{
    fstream filein;
    vector<sinhvien>danhsach;
    sinhvien sv;
    filein("sinhvien.txt",ios::out);
    filein.read(reinterpret_cast<char *>(&sv),sizeof(sinhvien));
    //docThongtinsinhvien(filein,danhsach);
    cout<<sv.hovaten;
    filein.close();
    xuatthongtin(danhsach);
    return 0;
}*/

struct sanpham
{
    int maSP;
    char TenSP[10];
    char NhaSX[20];
    int soluong;
};
void ghi1SanPham(sanpham sp)
{
    cout<<"Nhap ma san pham :";
    cin>>sp.maSP;
    cin.ignore();
    cout<<"Nhap ten san pham :";
    gets(sp.TenSP);
    cout<<" Nhap  nha ssan xuat :";
    gets(sp.NhaSX);
    cout<<"So luong san pham ";
    cin>>sp.soluong;
    //danhsach.push_back(sp);
}
void nhapDanhSach(vector<sanpham>&danhsach)
{
    cout<<"nhap so luong san pham ";
    int n;
    cin>>n;
    sanpham sp;
    for(int i = 0; i< n;i++)
    {
        ghi1SanPham(sp);
        danhsach.push_back(sp);
    }
}
void ghiFile( vector<sanpham>&danhsach, int n)
{
    fstream fileout("output.txt",ios::out|ios::app);
    for(int i = 0 ; i < n; i++)
    {
    sanpham sp;
    cout<<"Nhap ma san pham :";
    cin>>sp.maSP;
    cin.ignore();
    cout<<"Nhap ten san pham :";
    gets(sp.TenSP);
    cout<<" Nhap  nha ssan xuat :";
    gets(sp.NhaSX);
    cout<<"So luong san pham ";
    cin>>sp.soluong;
    fileout.write(reinterpret_cast<char*>(&sp),sizeof(sanpham));
    }
    fileout.close();
}
void doc1SanPham(sanpham sp)
{
    cout<<"\n Ma san pham "<<sp.maSP;
    cout<<"\n Ten san pham "<<sp.TenSP;
    cout<<"\n Nha san pham "<<sp.NhaSX;
    cout<<"\n So luong "<<sp.soluong;
}
void xuatDanhSach(vector<sanpham>danhsach)
{
    for(int i = 0; i< danhsach.size();i++)
    {
        doc1SanPham(danhsach[i]);
    }
}
void docFile(vector<sanpham>&danhsach)
{
    fstream filein("output.txt",ios::in);
    sanpham sp;
    while(filein.read(reinterpret_cast<char*>(&sp),sizeof(sanpham)))
    {
        //doc1SanPham(sp);
        danhsach.push_back(sp);
    }
    filein.close();
}
//tim sinh vien sau đó khi vao file input
void timsinhvien(vector<sanpham>danhsach)
{
    fstream fide("input.txt", ios::out);
    int name;
    cin>>name;
    for(auto i = danhsach.begin() ; i != danhsach.end() ; i++)
    {
        if((*i).maSP==name)
        {
            doc1SanPham((*i));
            fide.write(reinterpret_cast<char*>(&(*i)),sizeof(sanpham));
        }
    }
    fide.close();
}
/*int main()
{
    vector<sanpham>danhsach;
    int luachon;
    //while(IN.read(reinterpret_cast<char *>(&x),sizeof(sanpham)))
    //{
    //    danhsach.push_back(x);
    //}
    //IN.close();
    do
    {
    cout<<"\n1 Them san pham ";
    cout<<"\n2xuat danh sach san pham ";
    cout<<"\n 3. Read file";
    cout<<"\nChon lua ";
    cin>>luachon;
    switch(luachon)
    {
        case 1:
        {
            fstream OUT("output.binary", ios::out|ios::app|ios::binary);
            sanpham x;
            Nhap(x);
            OUT.write(reinterpret_cast<char*>(&x),sizeof(sanpham));
              OUT.close();
            break;
        }
        case 2:
        {
            for(int i = 0 ; i < danhsach.size(); i++)
            {
                xuat(danhsach[i]);
            }
            break;
        }
        case 3:
        {
             fstream IN("output.binary", ios::in|ios::binary);
            sanpham sp;
            while(IN)
            {
            IN.read(reinterpret_cast<char*>(&sp),sizeof(sanpham));
            xuat(sp);
            }
            IN.close();
            break;
        }
    }
    }while (luachon!=0);
    
    danhsach.clear();
}*/
int main()
{
    vector<sanpham>danhsach;
    //ghiFile(danhsach,1);
    docFile(danhsach);
    //xuatDanhSach(danhsach);
    timsinhvien(danhsach);
    return 0;
}