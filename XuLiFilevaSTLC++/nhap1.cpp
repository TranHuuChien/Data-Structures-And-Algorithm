/*#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct ngaydangki
{
    int ngay, thang, nam;
};
struct thuebao
{
    string mathuebao;
    string hovaten;
    ngaydangki ngayDangki{};
    string sodt;
    int tggoinoimang;
    int tggoingoaimang;
    string loaithuebao;
};
void nhap1thuebbao( vector<thuebao>&danhsach)
{
    cout<<"-------------Nhap Thong Tin-----------";
    thuebao THUEBAO;
    cin.ignore();
    cout<<"Nhap ma thue bao : ";
    getline(cin,THUEBAO.mathuebao);
    cout<<"Nhap ho ten cua chu thue bao : ";
    getline(cin,THUEBAO.hovaten);
    cout<<" Ngay ngay thang nam dang ki ";
    cin>>THUEBAO.ngayDangki.ngay>>THUEBAO.ngayDangki.thang>>THUEBAO.ngayDangki.nam;
    cin.ignore();
    cout<<" Nhap so dien thoai thue bao ";
    getline(cin,THUEBAO.sodt);
    cout<<"Nhap thoi gian goi noi mang : ";
    cin>>THUEBAO.tggoinoimang;
    cout<<"Nhap thoi gian goi ngoai mang :";
    cin>>THUEBAO.tggoingoaimang;
    cout<<"\n Nhap loai thue bao: TT(tra truoc) - TS(tra sau) ";
    cin>>THUEBAO.loaithuebao;
    danhsach.push_back(THUEBAO);
}
void nhapDanhsach(vector<thuebao>&danhsach, int soluong)
{
    for(int i = 0 ; i < soluong; i++)
    {
        nhap1thuebbao(danhsach);
    }
}
void xuat1thuebao(thuebao ds)
{
    cout<<"---------THONG TIN-------------";
    cout<<"\nMa thue bao : "<<ds.mathuebao;
    cout<<"\n Ho ten cua chu thue bao la : "<<ds.hovaten;
    cout<<"\n Ngay thang nam dang ki :"<<ds.ngayDangki.ngay<<"/"<<ds.ngayDangki.thang<<"/"<<ds.ngayDangki.nam;
    cout<<"\n So dien thoai cua thue bao "<<ds.sodt;
    cout<<"\n Thoi gian goi noi mang :"<<ds.tggoinoimang;
    cout<<"\n Thoi gian goi ngoai mang : "<<ds.tggoingoaimang;
    cout<<"\n Loai hinh dich vu loai thue bao ma ";
    if(ds.loaithuebao=="TT")
    {
        cout<<" Thue bao tra truoc  !";
    }
    else{
        cout<<" Thue bao tra sau !";
    }
}
void xuatDanhsach(vector<thuebao>danhsach)
{
    //list<thuebao>::iterator it;
    for( int i = 0 ; i < danhsach.size(); i++)
    {
        xuat1thuebao(danhsach[i]);  
    }
}
void them1ThueBao(vector<thuebao>&danhsach)
{
    thuebao THUEBAO;
    cin.ignore();
    cout<<"Nhap ma thue bao : ";
    getline(cin,THUEBAO.mathuebao);
    cout<<"Nhap ho ten cua chu thue bao : ";
    getline(cin,THUEBAO.hovaten);
    cout<<" Ngay ngay thang nam dang ki ";
    cin>>THUEBAO.ngayDangki.ngay>>THUEBAO.ngayDangki.thang>>THUEBAO.ngayDangki.nam;
    cin.ignore();
    cout<<" Nhap so dien thoai thue bao ";
    getline(cin,THUEBAO.sodt);
    cout<<"Nhap thoi gian goi noi mang : ";
    cin>>THUEBAO.tggoinoimang;
    cout<<"Nhap thoi gian goi ngoai mang :";
    cin>>THUEBAO.tggoingoaimang;
    cout<<"\n Nhap loai thue bao: TT(tra truoc) - TS(tra sau) ";
    cin>>THUEBAO.loaithuebao;
    danhsach.push_back(THUEBAO);
}
void swap(thuebao a,thuebao b)
{
    thuebao tempt = a;
    a = b;
    b = tempt;
}
void sapxep(vector<buukien>danhsach)
{
    for(int i = 0 ; i < danhsach.size()-1; i++)
    {
        for(int j = i + 1; j < danhsach.size(); i++)
        {
            if(danhsach[i].mabuukien.compare(danhsach[j].mabuukien)>0)
            {
                swap(danhsach[i], danhsach[j]);
            }
        }
    }
}
void xoakhangtrang(string s)
{
    while(s[0]==' ')
    {
        s.erase(s.begin());
    }
    while(s[s.length()]==' ')
    {
        s.erase(s.begin()+ s.length());
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]==' '&& s[i+1]==' ')
        {
            s.erase(s.begin()+ i);
        }
        i--;
    }
}
void timtheoten(vector<thuebao>danhsach, string name)
{
    for(auto i = danhsach.begin(); i!= danhsach.end(); i++)
    {
        if((*i).hovaten==name)
        {
            xuat1thuebao(*i);
        }
    }
}
void xuatThuebaotheoloai(vector<thuebao>danhsach)
{
    string s;
    cout<<" Hay nhap lua chon cua ban ";
    cin>>s;
    if(s=="TT"){
    for(int i = 0; i < danhsach.size(); i++)
    {
        if(danhsach[i].loaithuebao=="TT")
        {
            xuat1thuebao(danhsach[i]);
        }
    }
    }
    else{
    for(int i = 0; i < danhsach.size(); i++)
    {
        if(danhsach[i].loaithuebao=="TS")
        {
            xuat1thuebao(danhsach[i]);
        }
    }
    }

}
void xuatThueBaonam(vector<thuebao>danhsach)
{
    int nam;
    cout<<"\nNhap nam ban can xuat ";
    cin>>nam;
    for(auto i = danhsach.begin(); i!=danhsach.end(); i++)
    {
        if(((*i).ngayDangki.nam-2010)>=0)
        {
            xuat1thuebao(*i);
        }
    }
}
void cuocPhi(vector<thuebao>danhsach)
{
    cout<<"\n Phi thue bao cua ban thang nay hay tra nhanh chong khong se bi cat mang ";
    for(auto i = danhsach.begin(); i!=danhsach.end(); i++)
    {
        cout<<"\nphi cua thue bao thu "<<(*i).tggoinoimang*1500+(*i).tggoingoaimang*3000;
    }
}
int main()
{
    vector<thuebao>danhsach;
    int soluong, luachon;
    string name;
    cout<<"Hay nhap so luong thue bao ";
    cin>>soluong;
    nhapDanhsach(danhsach, soluong);
    xuatDanhsach(danhsach);
   while(true){
       do{
           cout<<"\n-------------Menu--------------";
        cout<<"\n   1. Nhap thong tin cua cac thue bao ";
        cout<<"\n   2. Xuat thong tin cac thue bao ";
        cout<<"\n   3. Them mot thue bao ";
        cout<<"\n   4. Sap xep cac thue bao theo ma buu kien ";
        cout<<"\n   5. Tim thue bao theo ho ten cua chu thue bao ";
        cout<<"\n   6. Xuat thue bao theo loai loai nao do nguoi dung chon TT(tra truoc) TS(tra sau) ";
        cout<<"\n   7. Xuat cac thue bao dang ki tu 2010 tro len ";
        cout<<"\n   8. Tinh cuc phi cua cac thue bao ";
        cout<<" \n  9. Hay chon yeu cau ma ban muon ";
        cin>>luachon;
        switch (luachon)
        {
        case 1:
        cout<<endl;
             nhapDanhsach(danhsach, soluong);
            break;
        case 2:
        cout<<endl;
        xuatDanhsach(danhsach);
        break;
        case 3:
        cout<<endl;
        them1ThueBao(danhsach);
        break;
        case 4:
        cout<<endl;
        //sapxep(danhsach);
        break;
        case 5:
        cout<<endl;
        cin.ignore();
        getline(cin,name);
        timtheoten(danhsach,name);
        break;
        case 6:
        cout<<endl;
        xuatThuebaotheoloai(danhsach);
        break;
        case 7:
        cout<<endl;
        xuatThueBaonam(danhsach);
         break;
         case 8:
         cout<<endl;
         cuocPhi(danhsach);
         break;
        default:
            break;
        }
    }while(luachon<0||luachon>8);}
    danhsach.clear();
    return 0;
}
*/
/*
#include<iostream>
#include<string>
#include<regex>
#include<list>
using namespace std;
struct ngaydangki
{
    int ngay, thang, nam;
};
struct thuebao
{
    string mathuebao;
    string hovaten;
    ngaydangki ngayDangki;
    string sodt;
    int tggoinoimang;
    int tggoingoaimang;
    string loaithuebao;
};
void nhap1thuebbao( list<thuebao>&danhsach)
{
    thuebao THUEBAO;
    cin.ignore();
    cout<<"Nhap ma thue bao : ";
    getline(cin,THUEBAO.mathuebao);
    cout<<"Nhap ho ten cua chu thue bao : ";
    getline(cin,THUEBAO.hovaten);
    cout<<" Ngay ngay thang nam dang ki ";
    cin>>THUEBAO.ngayDangki.ngay>>THUEBAO.ngayDangki.thang>>THUEBAO.ngayDangki.nam;
    cin.ignore();
    cout<<" Nhap so dien thoai thue bao ";
    getline(cin,THUEBAO.sodt);
    cout<<"Nhap thoi gian goi noi mang : ";
    cin>>THUEBAO.tggoinoimang;
    cout<<"Nhap thoi gian goi ngoai mang :";
    cin>>THUEBAO.tggoingoaimang;
    //cout<<"\n Nhap loai thue bao: nhan phim 0 neu ban chon tra truoc ";
    //cin>>THUEBAO.loaithuebao;
    
    danhsach.push_back(THUEBAO);
}
void nhapDanhsach(list<thuebao>&danhsach, int soluong)
{
    for(int i = 0 ; i < soluong; i++)
    {
        nhap1thuebbao(danhsach);
    }
}
void xuat1thuebao(thuebao ds)
{
    cout<<"\nMa thue bao : "<<ds.mathuebao;
    cout<<"\n Ho ten cua chu thue bao la : "<<ds.hovaten;
    cout<<"\n Ngay thang nam dang ki :"<<ds.ngayDangki.ngay<<"/"<<ds.ngayDangki.thang<<"/"<<ds.ngayDangki.nam;
    cout<<"\n So dien thoai cua thue bao "<<ds.sodt;
    cout<<"\n Thoi gian goi noi mang :"<<ds.tggoinoimang;
    cout<<"\n Thoi gian goi ngoai mang : "<<ds.tggoingoaimang;
}
void xuatDanhsach(list<thuebao>danhsach)
{
    list<thuebao>::iterator it;
    for( it = danhsach.begin(); it!= danhsach.end(); it++)
    {
        xuat1thuebao(*it);  
    }
}
int main()
{
    list<thuebao>danhsach;
    int soluong;
    cout<<"Hay nhap so luong thue bao ";
    cin>>soluong;
    nhapDanhsach(danhsach, soluong);
    xuatDanhsach(danhsach);
}

*/
//--------------------------------------------------

/*
#include<iostream>
#include<string>
using namespace std;
struct sach
{
    string masach, tensach, tentacgia,loaisach;
    int namxuatban;
    int soluong;
    float giatien;
};
void nhap1Cuonsach(sach &p)
{
    cin.ignore();
        cout<<"\n Nhap ma sach ";
        getline(cin,p.masach);
        cout<<"\n Nhap ten sach ";
        getline(cin, p.tensach);
        cout<<"\n Nhap ten tac gia ";
        getline(cin,p.tentacgia);
        cout<<"\n Loai sach ";
        getline(cin, p.loaisach);
        cout<<"\n Nhap nam xuat ban ";
        cin>>p.namxuatban;
        cout<<"\nNhap so luong ";
        cin>>p.soluong;
        cout<<"\n Gia tien cua tung loai ";
        cin>>p.giatien;
}
void nhapThongtin(sach ptr[], int len)
{
    for(int i = 0 ; i < len; i++)
    {
       //cin.ignore();
        //cout<<"\n Nhap ma sach ";
        //getline(cin,ptr[i].masach);
        //cout<<"\n Nhap ten sach ";
        //getline(cin, ptr[i].tensach);
        //cout<<"\n Nhap ten tac gia ";
        //getline(cin,ptr[i].tentacgia);
        //cout<<"\n Loai sach ";
        //getline(cin, ptr[i].loaisach);
        //cout<<"\n Nhap nam xuat ban ";
        //cin>>ptr[i].namxuatban;
        //cout<<"\nNhap so luong ";
        //cin>>ptr[i].soluong;
        //cout<<"\n Gia tien cua tung loai ";
        //cin>>ptr[i].giatien;
        nhap1Cuonsach(ptr[i]);
    }
} 
void xuat1Cuonsach(sach p)
{
    cout<<"\n Ma sach : "<<p.masach;
    cout<<"\n ten sach "<<p.tensach;
    cout<<"\n Ten tac gia :"<<p.tentacgia;
    cout<<"\n Loai sach : "<<p.loaisach;
      cout<<"\n Nam xuat ban : "<<p.namxuatban;
        cout<<"\n So luong : "<<p.soluong;
        cout<<"\n So tien cua sach : "<<p.giatien;
}
/*void xuatThongtin(sach ptr[], int len)
{
    for(int i = 0 ; i < len; i++)
    {
        cout<<"\n Ma sach : "<<ptr[i].masach;
        cout<<"\n ten sach "<<ptr[i].tensach;
        cout<<"\n Ten tac gia :"<<ptr[i].tentacgia;
        cout<<"\n Loai sach : "<<ptr[i].loaisach;
        cout<<"\n Nam xuat ban : "<<ptr[i].namxuatban;
        cout<<"\n So luong : "<<ptr[i].soluong;
        cout<<"\n So tien cua sach : "<<ptr[i].giatien;
    }
}
void xuatThongtin(sach ptr[], int len)
{
    for(int i = 0 ;i < len ; i++)
    {
        xuat1Cuonsach(ptr[i]);
    }
}
void sosanh(sach ptr[], int len)
{
    for(int i = 0 ; i < len -1; i ++)
    {
        for(int j = 0 ; j < len ; j++)
        {
            if(ptr[i].masach.compare(ptr[j].masach)>0)
            {
                sach tempt = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tempt;
            }
        }
    }
}
void them1Cuonsach(sach ptr[], int &len)
{
    len++;
    cin.ignore();
    nhap1Cuonsach(ptr[len-1]);
}
/*int tongTiencuasach(sach ptr[], int len)
{
    int sum = 0;
    for(int i = 0 ; i < len; i++)
    {
         sum = sum +ptr[i].giatien* ptr[i].soluong;
    }
    return sum;
}
void timSachtheoTen(sach ptr[], int len )
{
    cout<<" Hay nhap ten cuon sach ban muon tim ";
    cin.ignore();
    string name;
    getline(cin,name);
    for(int i = 0 ; i <len ; i++)
    {
        if(ptr[i].tensach==name)
        {
            xuat1Cuonsach(ptr[i]);
        }
    }
}
void timtheomasach(sach ptr[],int start, int end, string id)
{
    int r=start;
    int l = end;
    int mid = (r+l)/2;
    if(ptr[mid].masach==id)
    {
        xuat1Cuonsach(ptr[mid]);
    }
    else if(ptr[mid].masach.compare(id)>0)
    {
        return timtheomasach(ptr,mid +1, end, id);
    }
    else{
        return timtheomasach(ptr,start, mid-1,id);
    }
}
void xuatsachtheonam(sach ptr[], int len)
{
    cout<<"\nNhay nam ban muon xuat ";
    int nam;
    cin>>nam;
    for(int i = 0 ; i < len ; i++)
    {
        if(ptr[i].namxuatban>nam)
        {
            cout<<ptr[i].tensach<<endl;
        }
    }
}
int demsachgialon50000d(sach ptr[], int len)
{
    int dem=0;
    for(int i = 0 ; i <len ; i++)
    {
        if(ptr[i].giatien>5000)
        {
            dem++;
        }
    }
    return dem;
}
void xuatTheoLoaiSach(sach ptr[], int len)
{
    string name;
    cout<<"\n Nhap sach ban muon xuat theo loai ";
    getline(cin,name);
    for(int i = 0 ; i < len ; i++)
    {
        if(ptr[i].loaisach==name)
        {
            cout<<ptr[i].tensach<<endl;
        }
    }
}
int main()
{
    int n;
    cout<<" \n Nhap so luong sach ";
    cin>>n;
    sach ptr[n];
    nhapThongtin(ptr,n);
    sosanh(ptr,n);
    cin.ignore();
    string id;
    getline(cin,id);
    timtheomasach(ptr,0,n-1,id);
    return 0;
}
*/
//=========================================
/*#include<iostream>
#include<string>
using namespace std;
class STUDENT
{
    private:
    string name;
    float mark;
    int rollno;
    char grade;
    public:
    void Enter()
    {
        cout<<"Enter rollno ";
        cin>>rollno;
        cin.ignore();
        cout<<" Name's student  :";
        getline(cin,name);
        cout<<" Enter mark :";
        cin>>mark;
    }
    void display()
    {
        cout<<"\nRoll No :"<<rollno;
        cout<<"\n Name "<<name;
        cout<<" \n Your Mark :"<<mark;
    }
    int getroll() {return rollno;}
    float getMark() {return mark;}
    string getName()
    {
        return name;
    }
    char calculategrade()
    {
        if(mark >= 80) grade = 'A';
        else if(mark >= 60 && mark < 80) grade = 'B';
        else if(mark >= 40 && mark < 60) grade = 'C';
        else grade ='F';
        return grade;
    }
};
int main()
{
    system("cls");
    STUDENT a[2];
    for(int i = 0; i < 2 ; i++)
    {
        cout<<"\nEnter information detail for student "<<i+1<<"   ";
        a[i].Enter();
    }
    for(int i = 0; i < 2 ; i++)
    {
        if(a[i].getName()=="chien")
        {
            a[i].display();
        }
    }
    int choice, rno, highmark = 0;
    do
    {
        cout<<"\n Main Menu ";
        cout<<" \n1 . Specific Studen ";
        cout<<"\n 2. Topper ";
        cout<<" \n 3.Rank of result your student ";
        cout<<" 4. Exit ";
        cout<<" Please your Choice :))";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<" Enter roll no of student whose detail you want to know ";
            cin>>rno;
            for(int i = 0 ; i < 2 ; i++)
            {
                if(a[i].getroll()==rno)
                {
                    a[i].display();
                    break;
                }
            }
            break;
        case 2:
{ 
    int pos;
    for(int i = 0 ; i < 2; i++)
    {
        if(a[i].getMark()>highmark)
        {
            pos = i;
            highmark = a[i].getMark();
        }
    }
    a[pos].display();
}
         break;
        case 3:
        for(int i = 0 ; i < 2; i++)
        {
            cout<<" Xep loai cua sinh vien "<<a[i].getName();
            cout<<" := "<<a[i].calculategrade();
        }
        case 4:
        cout<<" Thank you .See you again :)";
        break;
        default:
            break;
        }
    } while (choice>5||choice <1);
    system("pause");
    return 0;
}*/
/*class ITEM
{
    int item;
    int price;
    public:
    void setdata(int i , int j)
    {
        item = i;
        price = j;
    }
    void getdata()
    {
        cout<<" \nItem "<<item;
        cout<<" \nPrice  "<<price;
    }
};
int main()
{
    ITEM a[2];
    int x,y;
   for(int i = 0 ; i < 2; i++)
    {
        cout<<"Enter  value for item "<<i+1<<endl;
        cin>>x>>y;
        a[i].setdata(x,y);
    }
    cout<<endl;
     for(int i = 0 ; i < 2; i++) {
         a[i].getdata();
         cout<<endl;
     }
     system("pause");
     return 0;
}*/
/*class SUBJECT
{
    int days;
    int subj;
    public:
    SUBJECT(int d=1, int s=0)
    {
        cout<<"Contructing Subject \n";
        days=d;
        subj=s;
    }
    void printsubj()
    {
        cout<<" \nDays :"<<days;
        cout<<" \nSubject :"<<subj;
    }
};
class STUDENT
{
    int rollno;
    int mark;
    public:
    void getvalue()
    {
        cout<<"Enter value of variable ";
        cin>>rollno>>mark;
    }
    void printstud()
    {
        cout<<" \nRoll no"<<rollno;
        cout<<" \nMark : "<<mark;
    }
};
class ADMIN
{
    float tall;
    public:
    SUBJECT sub;
    STUDENT stud;
    void print()
    {
        cout<<tall;
    }
};
int main()
{
    ADMIN a;
    a.stud.getvalue();
    a.stud.printstud();
    return 0;
}*/
