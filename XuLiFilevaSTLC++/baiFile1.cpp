#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
/*struct kichthuoc
{
    float ngang , cao ,day;
};
struct sanphamtivi
{
    char maTivi[6];
    char tenTivi[50];
    char HDH[30];
    char Congnghehinhanh[30];
    char DKgiongnoi[5];
    kichthuoc kichThuoc;
    int namSX;
    char Hang[30];
    double giaBan;
};
void nhapThongtin1Tivi(sanphamtivi &a)
{
    cin.ignore();
    cout<<"Nhap ma tivi : ";
    cin.getline(a.maTivi,6);
    cout<<"Nhap ten Tivi : ";
    cin.getline(a.tenTivi,50);
    cout<<"He dieu hanh ma tivi su dung ";
    cin.getline(a.HDH,30);
    cout<<"Cong nghe hinh anh cua ti vi";
    cin.getline(a.Congnghehinhanh,30);
    cout<<"Kha nang dieu khien bang giong noi : ";
    cin>>a.DKgiongnoi;
    cout<<"THong tin ve chieu dai ngang va be day ";
    cin>>a.kichThuoc.cao>>a.kichThuoc.ngang>>a.kichThuoc.day;
    cin.ignore();
    cout<<"Hang san xuat TIVI";
    cin.getline(a.Hang,30);
    cout<<"Nhap nam ra mat";
    cin>>a.namSX;
    cout<<"Gia ban ";
    cin>>a.giaBan;
}
void GhidanhsachTiVi(vector<sanphamtivi>&danhsach, int n)
{
    int luachon;
    cout<<"1.Ban muon viet tiep  ";
    cout<<"0.xoa di viet lai";
    cin>>luachon;
    if(luachon==1)
    {
        fstream filein("input.txt",ios::app|ios::in|ios::binary);
        sanphamtivi tv;
        for(int i = 0 ; i< n; i++)
        {
            nhapThongtin1Tivi(tv);
            danhsach.push_back(tv);
            filein.write(reinterpret_cast<char *>(&tv),sizeof(sanphamtivi));
        }
        filein.close();
    }
    else{
        fstream filein("input.txt",ios::trunc|ios::out|ios::binary);
        sanphamtivi tv;
        for(int i = 0 ; i< n; i++)
        {
            nhapThongtin1Tivi(tv);
            danhsach.push_back(tv);
            filein.write(reinterpret_cast<char *>(&tv),sizeof(sanphamtivi));
        }
        filein.close();
    }
}

void xuat1Sanpham(sanphamtivi tv)
{
    cout<<"\nMa ti vi : "<<tv.maTivi;
    cout<<"\nTen ti vi : "<<tv.tenTivi;
    cout<<"\nHe dieu hanh ma tivi su dung :"<<tv.HDH;
    cout<<"\nCong nghe hinh anh "<<tv.Congnghehinhanh;
    cout<<"\n Kha nang nhan dien giong noi "<<tv.DKgiongnoi;
    cout<<"\nThong tin ve chieu dai chieu rong chieu cao:\t"<<" Ngang"<<tv.kichThuoc.ngang<<"cm\t";
    cout<<"Cao "<<tv.kichThuoc.cao<<"cm\t"<<"Rong "<<tv.kichThuoc.day<<" cm";
}
void xuatDanhsachtheovector(vector<sanphamtivi>danhsach)
{
    for(int i = 0 ; i < danhsach.size();i++)
    {
        xuat1Sanpham(danhsach[i]);
    }
}
void docFile(vector<sanphamtivi>&danhsach)
{
    fstream filein("input.txt",ios::in|ios::binary);
    sanphamtivi tv;
    cout<<"1.ban muon doc tu file de xem xuat ra man hinh  ";
    cout<<"2.ban muon doc tu file de xu li mot so thao tac";
    int luachon;
    cin>>luachon;
    if(luachon==1)
    {
    while(filein.read(reinterpret_cast<char*>(&tv),sizeof(sanphamtivi)))
      {
        xuat1Sanpham(tv);
      }
    }
    else{
        while (filein.read(reinterpret_cast<char*>(&tv),sizeof(sanphamtivi)))
        {
            danhsach.push_back(tv);
            xuat1Sanpham(tv);
        }
        
    }
    filein.close();
}
void timTiVitheoma(vector<sanphamtivi>danhsach)
{
    char mativi[5];
    cin.getline(mativi,5);
    for(int i = 0 ; i< danhsach.size();i++)
    {
        if(strcmp(danhsach[i].maTivi,mativi)==0)
        {
            xuat1Sanpham(danhsach[i]);
        }
    }
}
void timChucNangTimKiem(vector<sanphamtivi>danhsach)
{
    for(int i = 0 ; i< danhsach.size();i++)
    {
        if(strcmp(danhsach[i].DKgiongnoi,"co")==0)
        {
            xuat1Sanpham(danhsach[i]);
        }
    }
}
void timKiemTheoNam(vector<sanphamtivi>danhsach)
{
    cout<<"nhap nam ra mat san pham ban muon";
    int nam;
    cin>>nam;
    for(int i = 0 ; i< danhsach.size();i++)
    {
        if(danhsach[i].namSX==nam)
        {
            xuat1Sanpham(danhsach[i]);
        }
    }
}
void demTVxuatdanhsachtheogiaBan(vector<sanphamtivi>danhsach)
{
    cout<<"nhap gia trong khoang ban muon";
    int first,second, dem=0;
    cin>>first>>second;
    for(int i = 0 ; i< danhsach.size(); i++)
    {
        if(first < danhsach[i].giaBan < second)
        {
            xuat1Sanpham(danhsach[i]);
            dem++;
        }
    }
}
void demVainradanhsachtheohang(vector<sanphamtivi>danhsach)
{
    for(int i = 0; i< danhsach.size();i++)
    {
        if(danhsach[i].Hang)
    }
}
void sapXepTheoNam(vector<sanphamtivi>danhsach)
{
    for(int i = 0; i < danhsach.size();i++)
    {
        for(int j = i+1; i< j;j++)
        {
            if(danhsach[i].namSX >danhsach[j].namSX){
                sanphamtivi tem=danhsach[i];
                danhsach[i]=danhsach[j];
                danhsach[j]=tem;
            }
        }
    }
}
void sapXepTheoHang(vector<sanphamtivi>danhsach)
{
    for(int i = 0; i < danhsach.size();i++)
    {
        for(int j = i+1; i< j;j++)
        {
            if(strcmp(danhsach[i].Hang ,danhsach[j].Hang)<0){
                sanphamtivi tem=danhsach[i];
                danhsach[i]=danhsach[j];
                danhsach[j]=tem;
            }
            if(danhsach[i].Hang==danhsach[j].Hang)
            {
                if(danhsach[i].giaBan>danhsach[i].giaBan)
                {
                    sanphamtivi tem=danhsach[i];
                danhsach[i]=danhsach[j];
                danhsach[j]=tem;
                }
            }
        }
    }
}
int main()
{
    vector<sanphamtivi>danhsach;
    int luachon;
    int n;
    //cin>>n;
    //GhidanhsachTiVi(danhsach,n);
    docFile(danhsach);
    timChucNangTimKiem(danhsach);
    do{
        cout<<"\n1.nhap thong tin cua cac tivi va luu  vao file";
        cout<<"\n2.Docfile va xuat thong tin cac tivi ra man hinh";
        cout<<"\n3.Tim tivi theo ma ";
        cout<<"\n4.Xuat ra tivi co chuc nang dieu kien bang giong noi";
        cout<<"\n5,Xuat ra danh sach tivi theo nam ra mat ";
        cout<<"\n6.Dem so luong tivi va in ra danh sach co gia ban nam trong khoang nguoi dung nhap";
        cout<<"\n7.Dem so luong theo hang va in ra tat ca cac tivi theo tung hang luu thong tin vao file";
        cout<<"\n8.Sap xep theo tivi ra mat truoc";
        cout<<"\n9.Sap xep theo tivi tang dan theo hang . trong cung mot hang , sap xeo thep gia ban tang dan";
        cout<<"nhap luachon cua ban";
        cin>>luachon;
        switch (luachon)
        {
        case 1:
        cout<<"Nhap so luong tivi";
        cin>>n;
        GhidanhsachTiVi(danhsach,n);
        break;
        case 2:
        docFile(danhsach);
        break;
        case 3:
        
        
        default:
            break;
        }
    }while();
    return 0;
}*/
struct kichthuoc
{
    float ngang , cao ,day;
};
struct sanphamtivi
{
    string maTivi;
    string tenTivi;
    string HDH;
    string Congnghehinhanh;
    string DKgiongnoi;
    kichthuoc kichThuoc;
    int namSX;
    string Hang;
    double giaBan;
};
void nhapThongtin1Tivi(sanphamtivi &a)
{
    cin.ignore();
    cout<<"Nhap ma tivi : ";
    getline(cin,a.maTivi);
    cout<<"Nhap ten Tivi : ";
    getline(cin,a.tenTivi);
    cout<<"He dieu hanh ma tivi su dung ";
    getline(cin,a.HDH);
    cout<<"Cong nghe hinh anh cua ti vi";
    getline(cin,a.Congnghehinhanh);
    cout<<"Kha nang dieu khien bang giong noi : ";
    cin>>a.DKgiongnoi;
    cout<<"THong tin ve chieu dai ngang va be day ";
    cin>>a.kichThuoc.cao>>a.kichThuoc.ngang>>a.kichThuoc.day;
    cin.ignore();
    cout<<"Hang san xuat TIVI";
    getline(cin,a.Hang);
    cout<<"Nhap nam ra mat";
    cin>>a.namSX;
    cout<<"Gia ban ";
    cin>>a.giaBan;
}
//GHI FILE KIEU FILE TXT
void ghiFile(vector<sanphamtivi>danhsach, int n)
{
    fstream f("input.txt",ios::out);
    sanphamtivi tv;
    for(int i = 0 ; i < n; i++)
    {
        nhapThongtin1Tivi(tv);
        f<<tv.maTivi<<"\n";
        f<<tv.tenTivi<<"\n";
        f<<tv.HDH<<"\n";
        f<<tv.Congnghehinhanh<<"\n";
        f<<tv.DKgiongnoi<<"\n";
        f<<tv.kichThuoc.cao<<"\t"<<tv.kichThuoc.day<<"\t"<<tv.kichThuoc.ngang<<"\n";
        f<<tv.namSX<<"\n";
        f<<tv.giaBan<<"\n";
        //f<<"-----------------------\n";
    }
    f.close();
}
void xuat1Sanpham(sanphamtivi tv)
{
    cout<<"\nMa ti vi : "<<tv.maTivi;
    cout<<"\nTen ti vi : "<<tv.tenTivi;
    cout<<"\nHe dieu hanh ma tivi su dung :"<<tv.HDH;
    cout<<"\nCong nghe hinh anh "<<tv.Congnghehinhanh;
    cout<<"\n Kha nang nhan dien giong noi "<<tv.DKgiongnoi;
    cout<<"\nThong tin ve chieu dai chieu rong chieu cao:\t"<<" Ngang"<<tv.kichThuoc.ngang<<"cm\t";
    cout<<"Cao "<<tv.kichThuoc.cao<<"cm\t"<<"Rong "<<tv.kichThuoc.day<<" cm";
}
void xuatDanhsachtheovector(vector<sanphamtivi>danhsach)
{
    for(int i = 0 ; i < danhsach.size();i++)
    {
        xuat1Sanpham(danhsach[i]);
    }
}
// DOC FILE KIEU TXT
void docFile(vector<sanphamtivi>danhsach)
{
    ifstream filein;
    filein.open("input.txt",ios::in);
    sanphamtivi tv;
    //while(filein.good())
    while(!filein.eof())
    {
        sanphamtivi tv;
        getline(filein,tv.maTivi);
        getline(filein,tv.tenTivi);
        getline(filein,tv.HDH);
        getline(filein,tv.Congnghehinhanh);
        getline(filein,tv.DKgiongnoi);
        //filein.ignore();
        filein>>tv.kichThuoc.cao;
        filein>>tv.kichThuoc.day;
        filein>>tv.kichThuoc.ngang;
        filein>>tv.namSX;
        getline(filein,tv.Hang);
        filein>>tv.namSX;
        filein>>tv.giaBan;
        //xuat1Sanpham(tv);
        //co the push_bach vao dung luon nha
        danhsach.push_back(tv);
    }
    filein.close();
}
// DOC FILE KIEU NHI PHAN BINARY 
/*void docFile(vector<sanphamtivi>&danhsach)
{
    fstream filein("input.txt",ios::in|ios::binary);
    sanphamtivi tv;
    cout<<"1.ban muon doc tu file de xem xuat ra man hinh  ";
    cout<<"2.ban muon doc tu file de xu li mot so thao tac";
    int luachon;
    cin>>luachon;
    if(luachon==1)
    {
    while(filein.read(reinterpret_cast<char*>(&tv),sizeof(sanphamtivi)))
      {
        xuat1Sanpham(tv);
      }
    }
    else{
        while (filein.read(reinterpret_cast<char*>(&tv),sizeof(sanphamtivi)))
        {
            danhsach.push_back(tv);
            xuat1Sanpham(tv);
        }
        
    }
    filein.close();
}*/
int main()
{
    vector<sanphamtivi>danhsach;
    // hồi trước khi mình chuyền số vào hàm thì sẽ 
    int n;
    cin>>n;
    sanphamtivi a;
    //ghiFile(danhsach,n);
    //docFile(danhsacch);
    //xuatDanhsachtheovector(danhsach);
}