#include<iostream>
#include<string>
using namespace std;
/*
struct sinhvien
{
    char ten[10];
    char maso[10];
    float dtb;
    sinhvien *pNext;
};
struct List
{
    sinhvien *pHead;
    sinhvien *pTail;
};
void taoDanhSach(List &l)
{
    l.pHead=l.pTail=NULL;
}
sinhvien *TaoSinhvien(char *Ten, char* MaSo, float Dtb)
{
    sinhvien *p= new sinhvien;
    //Nếu ta sử dụng string thì gán thẳng luôn nhưng khi sử dụng
    // char * hoặc char[], ta phải sử dụng hàm strcpy
    strcpy(p->ten,Ten);
    strcpy(p->maso,MaSo);
    p->dtb=Dtb;
    p->pNext=NULL;
}
void themsinhvienCuoiVaoDanhSach(List &l, sinhvien *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=NULL;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void nhapSinhvienVaoLink(List &l)
{
    char Ten[10];
    char Maso[10];
    float Dtb;
    do{
        cout<<"Nhap Ten :";
        cin.getline(Ten,10);
        if(strlen(Ten)==0)
        {
            break;
        }
        cout<<"Nhap Ma so :";
        cin.getline(Maso,10);
        cout<<"Nhap diem cua sinh vien ";
        cin>>Dtb;
        sinhvien *p= TaoSinhvien(Ten,Maso, Dtb);
        themsinhvienCuoiVaoDanhSach(l,p);
    }while(1);
}
void xuatSinhvien(sinhvien *p)
{
    cout<<"\nTen :"<<p->ten;
    cout<<"\n Ma so :"<<p->maso;
    cout<<"\n Diem trung binh :"<<p->dtb;
}
void xuatDanhSach(List &l)
{
    sinhvien *ptr=l.pHead;
    while(ptr!=NULL)
    {
        xuatSinhvien(ptr);
        ptr=ptr->pNext;
    }
}

int main()
{
    List l;
}
*/
struct student
{
   string name,id;
    float diem;
};
struct SV
{
    student s;
    struct SV *next;
};
typedef struct SV* sv;
sv MakeNode()
{
    student s;
    cout<<"Nhap thong tin cua sinh vien :\n";
    cout<<" nhap ID"; 
    cin>>s.id;
    cin.ignore();
    cout<<"Nhap ten"; 
    getline(cin,s.name);
    cout<<"nhap GPA"; cin>>s.diem;
    sv tmp=new SV();
    tmp->s=s;
    tmp->next=NULL;
    return tmp;
}
void themVAoDAu(sv &a)
{
    sv tmp = MakeNode();
    if(a==NULL)
    {
        a= tmp;
    }
    else
    {
        tmp->next=a;
        a = tmp;
    }
}
void ThemVaoCuoi(sv &a)
{
    sv tmp = MakeNode();
    if(a==NULL)
    {
        a=tmp;
    }
    else
    {
        sv ptr = a;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=tmp;

    }
}
void xoaDAu(sv &a)
{
    if(a==NULL) return;
    sv p=a;
    a= a->next;
    free(p);
}
void xoaCuoi(sv &a)
{
    if(a==NULL) return;
    sv truoc = NULL;
    sv sau =a;
    while(sau->next!=NULL)
    {
        truoc = sau;
        sau = sau->next;
    }
    truoc->next=NULL;
    free(sau);
}
void in(student s)
{
    cout<<"\n Ten :"<<s.name;
    cout<<"\n iD :"<<s.id;
    cout<<"\n Diem :"<<s.diem;
}
void xuatDanhSach(sv &a)
{
    sv p= a;
    while(p!=NULL)
    {
        in(p->s);
        p=p->next;
    }
}
void nhapDanhSachTamThoi( sv &a)
{
    int n;
    cin>>n;
    while(n--)
    {
        ThemVaoCuoi(a);
    }
}
void giaiPhongBoNHo(sv &a)
{
    sv p= NULL;
    while(a!=NULL)
    {
        p= a;
        a=a->next;
    }
}
int main()
{
    sv head = NULL;
    while(1)
    {
        cout<<"-------------MeNU----------";
        cout<<"\n1.Them mot sinh vien vao dau danh sach ";
        cout<<"\n2.Chen mot sinh vien vao cuoi danh sach ";
        cout<<"\n3.Xoa sinh vien o dau ";
        cout<<"\n4.Xoa sinh vien o cuoi danh sach ";
        cout<<"\n5.Duyet danh sach lien ket";
        cout<<"\n6.Thoat !";
        cout<<"----------------------------\n";
        cout<<"Nhap lua chon";
        int lc; cin>>lc;
        if(lc==1)
        {
            themVAoDAu(head);
        }
        else if(lc==2)
        {
            ThemVaoCuoi(head);
        }
        else if(lc==3)
        {
            xoaDAu(head);
        }
        else if(lc==4)
        {
            xoaCuoi(head);
        }
        else if(lc==5)
        {
            xuatDanhSach(head);
        }
        else{
            break;
        }
    }
    return 0;
}