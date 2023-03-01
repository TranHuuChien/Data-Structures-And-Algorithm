#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
void MaxSlidingUsingStack(int a[], int n, int k)
{
    vector<int>vt;
    stack<int>st;
    st.push(0);
    for(int i = 1; i < n ; i++)
    {
        while(!st.empty() && a[st.top()] < a[i])
        {
            vt[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        vt[st.top()] = n- 1;
        st.pop();
    }
    int j = 0;
    for(int i = 0 ; i < n - k ; i++)
    {
        while( j < i || vt[j] < i + k - 1)
            j++;
            cout<<vt[j]<<"  ";
    }
}
// class Employee
// {
//     private:
//     string name;
//     int tuoi;
//     int luong;
//     public:
//     void SetName(string name)
//     {
//         this->name = name;
//     }
//     void setTuoi(int age)
//     {
//         this->tuoi = age;
//     }
//     void setLuong(int luong)
//     {
//         this->luong = luong;
//     }
//     void show()
//     {
//         cout<<"Ho va ten Nhan vien : "<<name<<endl;
//         cout<<"Tuoi cua nhan vien : "<< tuoi<< endl;
//         cout<<"Luong cua Nhan vien : "<<luong<<endl;
//     }
// };
// class Sinhvien
// {
//     string hoTen;
//     float diem;
//     string xepLoai;
//     public:
//     void setHoTen(string);
//     void setDiem(float);
//     void XepLoai();
//     void show();
// };
// void Sinhvien:: setHoTen(string ten)
// {
//     hoTen = ten;
// }
// void Sinhvien::setDiem(float Diem)
// {
//     diem = Diem;
// }
// void Sinhvien:: XepLoai()
// {
//     if(diem >= 9 && diem <= 10)
//     {
//         xepLoai = "Gioi";
//     }
//     else if(diem >= 7 && diem <= 8)
//     {
//         xepLoai = "Kha";
//     }
//     else if(diem >= 5 && diem <= 6)
//     {
//         xepLoai = "Trung binh";
//     }
//     else
//     {
//         xepLoai = "Khong dat";
//     }
// }
// void Sinhvien::show()
// {
//     cout<<"\n\tXEP LOAI NHAN VIEN\n";
//     cout<<"HO VA TEN"<< setw(14)<<"DIEM"<<setw(14)<<"XEP LOAI"<<endl;
//     cout<<hoTen<<setw(10)<<diem<<setw(10)<<xepLoai<<endl;
// }
// // Sinhvien sv;
// //     cout<<"Nhap ten sinh vien";
// //     string ten; getline(cin,ten);
// //     sv.setHoTen(ten);
// //     cout<<"Nhap diem cua sinh vien :"; int diem; cin>>diem;
// //     sv.setDiem(diem);
// //     sv.XepLoai();
// //     sv.show();
// bool DayTangChap(string s)
// {
//     for(int i = 0 ; i < s.length() - 1; i++)
//     {
//         if(s[i] >= s[i+1])
//         return false;
//     }
//     return true;
// }
class GiaoVien;
class SinhVien
{
    private :
    string id, ten ,ns;
    double  gpa;
    static int dem;// các đối tượng cùng class sẻ có giá trị đếm giống nhau
    public:
    //SinhVien(string , string,string , double);
    void nhap();
    void in();
    double getGpa();
    string getiD();
    string getTen();
    string getNs();
    friend void inThongTin(SinhVien);// friend function
    friend void ChuanHoa(SinhVien&);
    friend void ChuanHoaNgaySinh(SinhVien&);
    friend istream& operator >>(istream& in,SinhVien& a);
    friend ostream& operator <<(ostream& out, SinhVien a);
    bool operator < (SinhVien a);// operator này là member của class
    friend bool operator < (SinhVien a, SinhVien b);//operator là phương thức friend của class
    //friend class GiaoVien;
    //~SinhVien();
};

bool operator < (SinhVien a, SinhVien b)
{
    return a.gpa < b.gpa;
}
bool SinhVien::operator < (SinhVien a)
{
    return this->gpa < a.gpa;
}
istream& operator >>(istream& in,SinhVien& a)
{
    cout<<"Nhap id : ";
    in>>a.id;
    cout<<"Nhap ten : "; in.ignore();
    getline(in,a.ten);
    in>>a.ns>>a.gpa;
    return in;
}
ostream& operator <<(ostream& out, SinhVien a)
{
    cout<<a.id<<"  "<<a.ten<<"  "<<a.ns<<"  "<<a.gpa<<endl;
    return out;
}

// void GiaoVien::update(SinhVien& x);
// {
//     x.gpa = 4.5;
// }
int SinhVien::dem = 0;
// fiend fuction k phải là một cái menber trong cái class nhưng có thể truy cập các thuộc tính trong class 
void ChuanHoa(SinhVien &a)
{
    string res="";
    stringstream ss(a.ten);
    string token;
    while(ss>>token)
    {
        res+=toupper(token[0]);
        for(int i = 1 ; i <token.length(); i++)
        {
           res+=tolower(token[i]);
        }
        res+=" ";
    }
    res.erase(res.length()-1);
    a.ten = res;
}
void ChuanHoaNgaySinh(SinhVien &a)
{
    string s ="";
    s = a.ns;
    if(s[1]=='/')
    s.insert(s.begin(),'0');

    if(s[4]=='/')
    {
        s.insert(s.begin()+3,'0');
    }
    a.ns = s;
}
string SinhVien::getiD()
{
    return this->id;
}
string SinhVien::getNs()
{
    return this->ns;
}
string SinhVien::getTen()
{
    return this->ten;
}
double SinhVien::getGpa()
{
    return this->gpa;
}
bool campare(SinhVien a, SinhVien b)
{
    return a.getGpa()>b.getGpa();
}
/*SinhVien:: SinhVien(string id , string ten, string ns, double gpa)
{
    this->id = id;
    this->ten = ten;
    this->ns = ns;
    this->gpa = gpa;
}*/
/*SinhVien::~SinhVien()
{
    cout<<"doi tuong bi huy\n";
}*/
void SinhVien::nhap()
{// neu tao theo contructor khi ay tang bien dem trong constructor
    ++dem;
    this->id = "SV"+ string (3-to_string(dem).length(),'0')+ to_string(dem);
    cin.ignore(); cout<<"Nhap ten : ";
    getline(cin,ten);
    cout<<"Nhap ngay sinh : "; cin>>ns;
    cout<<" Nhap diem : "; cin>>gpa;
    cin.ignore();
}
void SinhVien:: in()
{
    cout<<id<<"  "<<ten<<" "<<ns<<"  "<<gpa<<endl;
}
// friend function
void inThongTin(SinhVien a)
{
    cout<<a.id<<" "<<a.ten<<"  "<<a.ns<<"  "<<a.gpa<<endl;
}
// operator overloading

class hocsinh:public SinhVien
{
    string hoten;
    int age;
    public:
    void setName(string hoten)
    {
        this->hoten = hoten;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    string getName()
    {
        return this->hoten;
    }
    int getAge(){
        return this->age;
    }
    friend istream& operator>>(istream & in, hocsinh &a)
    {
        in>>a.age;
        return in;
    }
};
/*class car
{
    private:
    int speed;
    string mark;
    float price;
    public:
    void setSpeed(int);
    int getSpeed();
    void SetMark();
    string getMark();
    void setPrice(float);
    float getPrice();
    car(int  ,string, float);
};
void car::setSpeed(int speed)
{
    this->speed = speed;
}
int car::getSpeed()
{
    return speed;
}
void car::SetMark(string mark)
{
    strcpy(this->mark, mark);
}
string car::getMark()
{
    return this->mark;
}
void car::setPrice(float price)
{
    this->price =price;
}
float car::getPrice()
{
    return this->price;
}
car::car(int speed, string mark, float price)
{
    this->mark = mark;
    this->speed = speed;
    this->price = price;
}*/
class Hinhthoi
{
    int chieucao;
    string dacdiem;
    public: 
    Hinhthoi()
    {
        chieucao = 0;
        dacdiem = "";
    }
    Hinhthoi(int chieucao, string dacdiem)
    {
        this->chieucao = chieucao;
        this->dacdiem = dacdiem;
    }

    void nhap();
    void show()
    {
        cout<<this->chieucao<<"\t";
        cout<<this->dacdiem<<"\t";
    }
    void setChieucao(int);
    int getChieuCao();
};
void Hinhthoi::nhap()
{
    cin>>this->chieucao;
    cin.ignore();
    getline(cin,this->dacdiem);
}
void Hinhthoi::setChieucao(int chieucao)
{
    this->chieucao = chieucao;
}
int Hinhthoi::getChieuCao()
{
    return chieucao;
}
class Hinhthoi1 :private Hinhthoi
{
    int chieudai;
    public:
    Hinhthoi1()
    {
        this->chieudai =0;
    }
    Hinhthoi1(int chieucao, string dacdiem, int chieudai):Hinhthoi(chieucao, dacdiem)
    {// khi này khi khai bao ocntructỏ của lóp con thì nó sẻ gọi constuctor của lớp cha
        this->chieudai=chieudai;
    }
    void nhap();
    void show();
    void setChieudai(int);
    int TinhTheTich();
    int getChieudai();
};
void Hinhthoi1::nhap()
{// khi ta sử dụng cái hàm nhập nó sẻ truy cập đến hàm nhập của lớp con, khi k khia báo hàm nhập ở lớp con ta sư truy cập đến hàm nhập của lớp cha
    Hinhthoi::nhap();
    cin>>this->chieudai;
}
void Hinhthoi1::show()
{
    Hinhthoi::show();//function overridding
    cout<<this->chieudai;
}
void Hinhthoi1::setChieudai(int chieudai)
{
    this->chieudai = chieudai;
}
int Hinhthoi1::TinhTheTich()
{
    return this->chieudai;//*getChieuCao;
}
int Hinhthoi1::getChieudai()
{
    return this->chieudai;
}
int main()
{  
    Hinhthoi1 a;
    a.nhap();
    //a.nhap();
    //a.Hinhthoi::nhap() gọi đến hàm nhập của lớp cha
    //a.show();
    /*SinhVien a[3];
    for(int i = 0 ; i < 3 ;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3);
    for(SinhVien x : a)
    {
        cout<<x;
    }*/
   /*SinhVien x[3];
   int sl; cin>>sl;

   for(int i = 0 ; i < sl; i++)
   {
       x[i].nhap();
   }
   sort(x,x+sl,campare);
   for(int i = 0 ; i < sl ; i++)
   {
       x[i].in();
   }*/
    
    
    return 0;
}
