#include<iostream>
#include<string>
using namespace std;
/*class A
{
    public:
    int x;
};
class B :public A
{
    private: 
    int y;
    public:
    int getY()
    {
        y = x;
        return y;
    }
};

class classa
{
    public:
    int a;
};
class classb: virtual public classa
{
    public:
    int b;
};
class classc:public classa
{
    public:
    int c;
};
class classd : public classb, public classc
{
    public:
    int d;
};
int main()
{
   // airport vn("hang khong mau hang");
    classd obj1;
    classb obj;
    //obj.a=4;
    //obj1.classb::a = 8;//sử dụng toán tử phân  giải phạm vị
    cout<<endl<<obj.a<<obj1.classb::a;
    int **ptr;
    ptr = new int*[n];
    for(int i = 0 ; i < n;i++)
    {
        ptr[i] = new int[m];
    }
}*/
class student
{
    private:
    string a;
    string mssv;
    int age;
    float mark;
    public:
    student()
    {
        cout<<"ham tao khong co tham so";
        this->a=" ";
        this-> mssv=" ";
        this->age= 0;
        this->mark = 0;
    }
    student(string &a)
    {
        cout<<"ham tao co tham so";
        this->a="chien ";
        this-> mssv=" ";
        this->age= 0;
        this->mark = 0;
    }
    ~studen
    {
        cout<<"huy ham contructor";
    }
};
int main()
{
    string a;
    cout<<"ten cua sinh vien";
    getline(cin,a);
    student s(a);
    return 0;
}