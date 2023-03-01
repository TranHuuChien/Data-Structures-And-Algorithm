#include<iostream>
#include<algorithm>
using namespace std;
#define max 10;
/*void sapxep(int *a, int n)
{
    
    sort(a,a+n);
    int i = 0;
    int j = n -1;
    while(i < j)
    {
        cout<<a[i] <<"  "<<a[j];
        i++;
        j--;
    }
}*/
void nhap(int *a, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
}
void xuat(int *a, int n)
{
    for(int i = 0 ; i <n ; i++)
    {
        cout<<a[i]<<"  ";
    }
}
// demo bài toán nếu phần tử hiện tại có phần tử kế tiếp giống nhau thì nhân đôi ht gán cho kế tiếp = 0
// 0 2 2 2 0 6 6 0 0 8
// kq 2 4 16 8 0 0 0 0
/*void khong(int *a , int n)
{
    int count = 0;
    for(int i = 0 ; i < n ;i++)
    {
        if(a[i] != 0)
        {
            a[count] = a[i];
            count++;
        }
    }
    while(count < n)
    {
        a[count++] = 0;
    }
}
void zeroshifting(int *a, int n)
{
    int positive = 0;
    for(int i =  0; i <n ;i++)
    {
        if(a[i] != 0)
        {
            int tempt = a[i];
            a[i] = a[positive];
            a[positive] = tempt;
            positive++;
        }
    }
}*/
/*void gan(int *a, int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(a[i] == a[i + 1] &&a[i] != 0)
        {
            a[i] = a[i]* 2;
            a[i + 1] = 0;
            i++; // bo qua den 2 phan tu
        }
    }
    khong(a,n);
}
*/
void swap(int a,int b)
{
    int tempt = a;
    a =b;
    b = tempt;
}
/*void chiaamduong(int *a, int n)
{
    int ik = 0;
    int t[n];
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] < 0)
        {
            swap(a[ik],a[i]);
            ik++;
        }
     
    }
    for(int i = 0 ; i < n ; i++)
    {
        int nep = 0;
        int pos = ik;
        while(a[nep] < 0 && a[pos] > 0)
        {
            swap(a[nep],a[pos]);
            nep=nep + 2;
            pos=pos -2;
        } 
    }
}*/
/*void cachkhac(int *a,int n)
{
    int left = 0;
    int right = n -1;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[left] < 0 &&a[right] < 0)
        {
            left++;
        }
        else if (a[left] > 0] && a[right] < 0)
        {
            a[left] = a[right];
        }
        else if (a[left] > 0 && a[right] > 0)
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
        
    }
}*/
/*int chick(int *a,int n)// mang con co tong lon nhat
{
    int meo= a[0];
    int cho = a[0];
    for(int i = 0 ; i < n ;i++)
    {
        meo =max(a[i],meo+a[i]);
        cho = max(cho,meo);
    }
    return cho;
    
    int max_sofar = INT_MAX;
    int max_fake = 0;
    int start =0, end = 0,int s = 0;
    for(int i = 0 ; i < n ; i++)
    {
        max_fake +=a[i];
        if(max_sofar< max_fake)
        {
            max_sofar = max_fake;
            start = s;
            end = i;
        }
        if
    }
}*/
// tong cac phan tu trong khoang
struct query
{
    int l;
    int r;
};
void chack(int *a,int n, struct query q[],int m)
{
    for(int i = 0 ; i <= m; i++)
    {
        int l= q[i].l;
        int r = q[i].r;
        int sum = 0;
        for(int j = l ; j <= r;j++)
        {
            sum = sum + a[j];
        }
        cout<<"tong [" << l<<" , " <<r<<" ] = "<<sum;
    }
}
// cach khác khá khó hiểu
/*void preproces(int *a , int n, query q[])
{
    int lookup[3][3];//mục địch cái này kiểm tra xem tao ra ma trận chỉ có 
    for(int i = 0 ; i <n ; i++)
    {
        lookup[i][i] = i;
    }
    for(int i = 0 ; i <n ; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[lookup[i][j - 1]]< a[j])
            {
                lookup[i][j - 1] = lookup[i][j];
            }
            else
            {
                lookup[i][j-1] = j;
            }
        }
    }

    int m = sizeof(q)/sizeof(int);
    for(int i = 0 ; i< m;i++)
    {
        int r=q[i].r;
        int l = q[i].l;
        cout<<"minimize of"<<l<<"and"<<r<<a[lookup[r][l]];
    }
    
}*/
int main()
{
    int n;
    query q[] ={1,3};
    cout<<"nhap so luong ";
    cin>>n;
    int *a = new int[n];
    // n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(q)/sizeof(q[0]);
    nhap(a,n);
    chack(a,n,q,m);
    //xuat(a,n);
    delete [] a;
    return 0;
}