#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    char * menu[]={"bat dau"," tiep tuc", "ket thuc"};
    for(int i = 0 ; i < 3 ; i++)
    {
        cout<<menu[i]<<endl;
    }
    while(1)
    {
        if(kbhit())
        {
            char kitu = getch();
            if(kitu=='1')
            {
                cout<<"chao mung ban den voi chung toi";
                break;
            }
            if(kitu = '2' )
            {
                cout<<"tiep tuc thuc hien chuong trinh";
                break;
            }
            else{
                cout<<" rat vui khi phuc vu quy khach";
                break;
            }
        }
    }
    return 0;
}