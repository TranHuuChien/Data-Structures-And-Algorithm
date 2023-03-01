#include<iostream>
#include<conio.h>
#define MAX 3
using namespace std;
int MenuDong(){
    char* menu[]={"Start","About","Exit"};
    int pointer = 0;
    while (1)
    {
        system("cls");// xoa man hinh
        // in ra menu man hinh may tinh
        for(int i = 0 ; i < MAX; i++)
        {
            {
                cout<<menu[i]<<endl;
            }
        }
    while(1)
    {
        if(kbhit())
        {
            char key = getch();
            if(key==72)// mã ascii của phím mũi tên là 
           {
               if(pointer>0)
               {
                   --pointer;
               }
               else{
                   pointer=MAX;
               }
               break;
           }
           if(key==80)
           {
               if(pointer < MAX - 1)
               ++pointer;
               else{
                   pointer = 0;
               }
               break;
           } 
           if(key==13)
           {
               switch(pointer)// su ly giua cac ham voi nhau
               {
                   case 0:
                   cout<<"Start";
                   break;
                   case 1:
                   cout<<"About";
                   break;
                   case 2:
                   cout<<"Goodbye";
                   break;
                   default:
                   break;
               }
           }
        }
    }
    }
    _getch();
    return 0;
}