#include<iostream>
#include<algorithm>
using namespace std;
void nhapmang(int *a ,int n)
{
    for(int i = 0 ; i <n ; i++)
    {
        cin >>a[i];
    }
}
void xuat(int *a, int n)
{
    for(int i = 0 ; i < n;i++)
    {
        cout<<a[i]<<"    ";
    }
}
/*void set(int *a,int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != i && a[i] != -1)
        {
            int tempt = a[a[i]];
        a[a[i]] = a[i];
        a[i] = tempt;
        }
       else
       {
           i++;
       }
    }
}*/
/*void check(int *a , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != i && a[i] != -1)
        {
            int x = a[i];
            while(a[x] != 1 && a[x] != x)
            {
                int y = a[x];
                a[x] = x;
                x = y;
            }
        }
        if(a[i] != i)
        {
            a[i] = -1;
        }
    }
}*/
/*void tachso(int n)
{
    int x;
    while( n > 0)
    {
        x = n % 10;
        n = n / 10;
        cout <<x<<endl;
    }
}*/
/* câu ni làm sai không biết
int sumkmax(int *a, int n, int k)
{
    int sum1= INT_MAX;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int sum2 = a[i];
        for(int j = i + 1; j < k ; j++)
        {
            sum2 = sum2 + a[j];
        }
        k++;
        if(sum2 > sum1)
        {
            sum1 = sum2;
        }
        else
        {
            return sum;
        }
    }
    return -1;
}*/
void swap(int c, int b)
{
    int tempt =c;
    c = b;
    b = tempt;
}
/*void haha(int *a, int n)//gia tri vi tri le nho hon  giá trị vi tri chan
//ngược lại là that
{
    sort(a,a+n);
    int b = 0;
    int c = n - 1;
    int q[n];
    for(int i = 0 ; i < n ;i++)
    {
        if((i)%2==0)
        {
            q[i] = a[c];
            c--;
        }
        else
        {
            q[i] = a[b];
            b++;
        }
    }
    // cach khac
    for(int i = 1; i < n ; i++)
    {
        if(i % 2 ==0)
        {
            if(a[i] > a[i -1])
            {
                swap(a[i], a[i -1]);
            }
        }
        else
        {
            if(a[i] < a[i -1])
            {
                swap(a[i],a[i-1]);
            }
        }
    }
}*/
void sapxep(int *a, int n) //chẵn tăng dần lẻ giữ nguyên
{
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] %2 ==0)
        {
            for(int j = i + 1; j < n;j++)
            {
                if(a[i]  <a[j] && a[j] % 2==0)
                {
                    int tempt =a[i];
                    a[i] = a[j];
                    a[j] = tempt;
                }
            }
        }
        else
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(a[j] %2 != 0 && a[i] < a[j])
                {
                    int tempt =a[i];
                    a[i] = a[j];
                    a[j] = tempt;
                }
            }
        }
    }
}
bool kiemtra(int x)
{
    if(x % 2 ==0)
    {
        return true;
    }
    return false;
}
//tinh tong các so lẻ theo
void check(){
for(size_t i = 0 ; i < 5 ; i++ )
    {
        cin>>a[i];
    }
    for(size_t i = 0 ; i < 5 ; i++ )
    {
        if(kiemtra(a[i]) == true)
        {
            cout<<a[i]<<" la so chan"<<endl;;
        }
    }
}
int main()
{
    int n,k;
    cin >>n;
    //cout<<"nhap so luong can tin";
    //cin>>k;
    int *a= new int[n];
    nhapmang(a,n);
    sapxep(a,n);
    xuat(a,n);
    delete [] a;
    return 0;
}