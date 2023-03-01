#include<iostream>
#include<vector>
using namespace std;
struct ngayGui
{
    int ngay, thang, nam;
};

struct buukien
{
    /* data */
    string mabuukien, tennggui, tenngnhan;
    float trongluong,dongia;
    ngayGui ngaygui;
    string noidung;
};
void nhap1buukien(vector<buukien>&danhsach)
{
    buukien bk;
    cin.ignore();
        cout<<"Nhap ma buu kien  ";
        getline(cin,bk.mabuukien);
        cout<<"Nhap ten nguoi gui ";
        getline(cin,bk.tennggui);
        cout<<" Nhap ten nguoi nhan ";
        getline(cin,bk.tenngnhan);
        cout<<"Nhap trong luong ";
        cin>>bk.trongluong;
        cin.ignore();
        cout<<"Nhap ngay thang nam ";
        cin>>bk.ngaygui.ngay>>bk.ngaygui.thang>>bk.ngaygui.nam;
        cin.ignore();
        cout<<"Nhap noi dung gui ";
        getline(cin,bk.noidung);
        cout<<" nhap don gia gui ";
        cin>>bk.dongia;
    danhsach.push_back(bk);
}
void nhapdanhsach(vector<buukien>&danhsach, int soluong)
{
    for(int i = 0; i < soluong; i++)
    {
       nhap1buukien(danhsach);
     } 
}
void xuat1buukien(buukien bk)
{
    cout<<"Ma buu kien : "<<bk.mabuukien;
    cout<<"\nTen nguoi gui :"<<bk.tennggui;
    cout<<"\n Ten nguoi nhan : "<<bk.tenngnhan;
    cout<<"\n Trong luong cua buu kien :"<<bk.trongluong;
    cout<<"\nNgay thang nam gui buu kien :  " <<bk.ngaygui.ngay<<"/"<<bk.ngaygui.thang<<"/"<<bk.ngaygui.nam;
    cout<<"\n Noi dung "<<bk.noidung;
    cout<<"\n Don gia cua buu kien "<<bk.dongia;
}
void xuatdanhsach(vector<buukien>danhsach)
{
    int a = 1;
    for(auto i =danhsach.begin();i!=danhsach.end();i++)
    {
        cout<<" Buu kien thu "<<a<<endl;
        xuat1buukien(*i);
        a++;
    }
}
/*void xuatdanhsach(vector<buukien>danhsach)
{
    for(int i = 0 ; i < danhsach.size(); i++)
    {
        cout<<"Ma buu kien "<<danhsach[i].mabuukien;
        cout<<"\nTen nguoi gui "<<danhsach[i].tennggui;
        cout<<"\n Ten nguoi nhan "<<danhsach[i].tenngnhan;
        cout<<"\n Trong luong cua buu kien "<<danhsach[i].trongluong;
        cout<<danhsach[i].ngaygui.ngay<<"/"<<danhsach[i].ngaygui.thang<<"/"<<danhsach[i].ngaygui.nam;
        cout<<"\n Noi dung "<<danhsach[i].noidung;
    }
}*/
void them1buukien(vector<buukien>&danhsach, int vt)
{
    buukien bk;
        cout<<"Nhap ma buu kien  ";
        getline(cin,bk.mabuukien);
        cout<<"Nhap ten nguoi gui ";
        getline(cin,bk.tennggui);
        cout<<" Nhap ten nguoi nhan ";
        getline(cin,bk.tenngnhan);
        cout<<"Nhap trong luong ";
        cin>>bk.trongluong;
        cout<<"Nhap ngay thang nam ";
        cin>>bk.ngaygui.ngay>>bk.ngaygui.thang>>bk.ngaygui.nam;
        cin.ignore();
        cout<<"Nhap noi dung gui ";
        getline(cin,bk.noidung);
        cout<<" nhap don gia gui ";
        cin>>bk.dongia;
    danhsach.insert(danhsach.begin()+vt-1,bk);
}
/*void sapxeptheobuukien(vector<buukien>danhsach)
{
    for( int i = 0 ; i <  danhsach.size(); i++)
    {
        for(int j = i + 1; j <danhsach.size() ; j++)
        {
            if(danhsach[i].mabuukien.compare(danhsach[j].mabuukien)<0)
            {
                vector<buukien>tempt;
                tempt.swap(danhsach[i]);
                danhsach.swap
            }
        }
    }
}*/
void sapxeptheobuukien(vector<buukien>danhsach)
{
    
}
void giatribuumoibuukien(vector<buukien>danhsach)
{
    for(int i = 0 ; i < danhsach.size(); i++)
    {
        cout<<"\ngia cua buu kien "<<danhsach[i].mabuukien<<" == "<<danhsach[i].trongluong*danhsach[i].dongia;
    }
}
int main()
{
    system("cls");
    int soluong;
    cout<<" Nhap so luong danh sach ";
    cin>>soluong;
    vector<buukien>danhsach;
    nhapdanhsach(danhsach,soluong);
    them1buukien(danhsach,1);
    xuatdanhsach(danhsach);
    /*do
    {
        cout<<"1.Nhap danh dach buu kien \n";
        cout<<"2.Xuat danh sach cac buu kien \n";
        cout<<"3. Them 1 buu kien vao danh sach \n";
        cout<<"4.Sap xep thu tu buu kien kien theo ma buu kien \n";
        cout<<"5. Xuat gia tri cua moi buu kien \n";
        cout<<"6."
    } while ();*/
    
    return 0;
}