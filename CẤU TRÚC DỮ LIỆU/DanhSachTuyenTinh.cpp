#include<iostream>
using namespace std;
#define max 10
//=====================================
//DANH SACH TUYEN TINH THUAN NHAT
// struct List
// {
//     int data[max]={0};// du lieu có thể là một truct khác cũng dc
//     int n =0;// so phan tu trong danh sach tuyen tinh
// };
// void themCuoi(List &l,int x)
// {
//     if(l.n<max)// neu l.n vuot qua max thi se bi loi
//     l.data[l.n++]=x;
// }
// void ThemVaoVitriPhanTu(List &l , int vitri, int x)
// {
//     if(l.n<max)
//     {
//         for(int i = l.n; i> vitri; i--)
//       {
//         l.data[i]=l.data[i-1];
//        }
//     l.n++;
//     l.data[vitri]=x;
//     }
// }
// void themVaoSauPhanTucoGiaTri(List &l , int p, int x)
// {
//     if(l.n < max)
//      {
//         for(int i = 0 ; i < l.n; i++)
//       {
//         if(l.data[i]==p)
//         {
//             ThemVaoVitriPhanTu(l,i+1,x);
//         }
//        }
//     }
// }
// // sap xep theo theo thu tu tu be den lon
// void themTheoThuTu(List &l, int x)
// {
//     if(l.n<1)
//     {
//         themCuoi(l,x);
//     }
//     else
//     {
//         if(l.n<max)
//         {
//             for(int i = 0 ;i< l.n; i++)
//             {
//                 if(x < l.data[i])
//                 {
//                     ThemVaoVitriPhanTu(l,i,x);
//                     break;
//                 }
//             }   
//         }
//     }
// }
// void xoaCuoi(List &l)
// {
//     l.n--;
// }
// void xoaTaiViTriBatKi(List &l, int vitri)
// {
//     for(int i = vitri; i< l.n; i++)
//     {
//         l.data[vitri]=l.data[vitri + 1];
//     }
//     l.n--;
// }
// void xoaTheoGiaTRi(List &l, int giatri)
// {
//     for(int i = 0;i < l.n; i++)
//     {
//         if(l.data[i]==giatri)
//         {
//             xoaTaiViTriBatKi(l,i);
//         }
//     }
// }
// // void xoaTheoGiaTri2(List &l , int giatri)
// // {
// //     if(l.n ==0)
// //     {
// //         return;
// //     }
// //     int vitri;
// //     for(vitri = 0; vitri<l.n && *l.data[vitri]!=data; vitri ++)
// //     {

// //     }
// // }
// int timKiem(List &l, int giatri)
// {
//     for(int i = 0;i< l.n; i++)
//     {
//         if(l.data[i]==giatri)
//         {
//             return i;
//         }
//     }
// }
// void xuatDanhSachLinear(List &l)
// {
//     cout<<"Danh sach tuyen tinh : ";
//     for(int i = 0; i< l.n; i++)
//     {
//         cout<<l.data[i]<<"  ";
//     }
// }
// int main()
// {
//     List l;
//     themCuoi(l,1);
//     themCuoi(l,4);
//     themCuoi(l,6);
//     themCuoi(l,9);
//     themCuoi(l,12);
//     ThemVaoVitriPhanTu(l,2,30);
//     xuatDanhSachLinear(l);
//     return 0;
// }
//========================================
// DANH SACH TUYEN TINH THEO MANG CON TRO
#define max 10
struct PointerList
{
    int *data[max]={NULL};
    int sl = 0;
};

void themcuoi(PointerList &l, int dt)
{
    l.data[l.sl++]=new int(dt);// cấp phát vùng nhớ cho nó
}
void themTheothutu(PointerList &l,int data)
{
    if(l.sl < max)
    {
        int vitri;
        for(vitri = 0; vitri < l.sl && *l.data[l.sl] < data ; vitri++)
        {
            for(int i = l.sl ; i > vitri ;i--)
            {
                l.data[i] = l.data[i-1];
                l.data[vitri]= new int(data);
            }
        }
    }
}
void themVaoVitri(PointerList &l, int vitri, int x)
{
    if(l.sl<max)
    {
        for(int i = l.sl; i>vitri ;i--)
            {
                l.data[i]=l.data[i-1];// doi cac phan tu 
            }
        l.data[vitri]=new int(x);
    }
}
void xoaCuoi(PointerList &l)
{
    if(l.sl==0)
    return;
    void *temp = l.data[l.sl--];
    l.data[l.sl]=NULL;
    delete temp;
}
void xoaTheoGiaTRi(PointerList &l, int giatri)
{
    if(l.sl==0)
    {
        return;
    }
    int vitri;
    for(vitri = 0; vitri<l.sl && *l.data[vitri]!=giatri; vitri++)
    {
        if(vitri==l.sl)
        {
            return;
        }
        for(int i = vitri; i < l.sl; i++)
        {
            l.data[i]=l.data[i+1];
        }
        int *temp = l.data[l.sl--];
        l.data[l.sl]=NULL;
        delete temp;
    }
}
// int timKiem(PointerList &l, int giatri)
// {
//     for(int i = 0; i< l.sl; i++)
//     {
//         if(giatri==(*l.data[i]))
//         {
//             return 1;
//         }
//     }
//     return 0;
// }
void GiaiPhong(PointerList l)
{

}
void Duyetdahsach(PointerList &l)
{
    for(int i = 0 ; i< l.sl; i++)
    {
        // con trỏ nó chứa cái địa chỉ nên phải * trước mới ra giá trị của biến mà con trỏ nó trỏ tới
        cout<<(*l.data[i])<<"  ";
    }
}
int main()
{
    PointerList l;
    themcuoi(l,1);
    themcuoi(l,4);
    themcuoi(l,9);
    xoaCuoi(l);
    Duyetdahsach(l);
}