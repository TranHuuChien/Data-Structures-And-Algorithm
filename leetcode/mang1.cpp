#include<iostream>
#include<algorithm>
using namespace std;
/*void reanger(int *a, int n)
{
    sort(a,a+n);
    for(int i = 0 , j = n - 1; i <= n /2, j < n/2;i++, j--)
    {
        w
    }
}*/
/*int mixarray(int *a1, int *a2, int size1, int size2)
{
    int *mix = new int[size1 + size2];
    int index1 = 0;
    int index2 = 0;
    int min = (size1 > size2) ? size1 : size2;
    for(int i = 0 ; i < size1 + size2 ; i++)
    {
        if(i % 2 == 0)
        {
            mix[i] = a1[index1];
            index1++;
        }
        else{
            mix[i]=a2[index2];
            index2++;
        }
    }
}*/
/*int vnthang(int a[], int n)// tich mảng con lớn nhất
{
    int result = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int mod = a[i];
        for(int j = i + 1 ; j < n ; j++)
        {
            mod = mod * a[j];
        }
        result=max(mod,result);
    }
    return result;
}
void mang(int a[], int n)
{
    for(int i = 0 ; i < n; i++)
    {
        if(a[i]== a[i + 1])
        {
            a[i] = a[i]*2;
            a[i+1]=0;
            i++;
        }
    }
}*/
int largest(int a[], int n)
{
    return *max_element(a,a+n);
    //return *min_alement(a,a+n);
}
void searcj(int a[], int n,int k)
{
    for(int i = 0 ; i < n; i++)
    {
         int dem = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i]==a[j])
            {
                dem++;
            }
        }
        if(dem==k)
        {
            cout<<a[i]<<"  ";
        }
    }
}
/*void tim(int a[],int n)
{
    int b[4];
    int largest = 0;
    int dem = 0;
    int secondlargest =-1;
    for(int i = 0 ; i < n ;i++)
    {
        if(a[i] > a[largest])
        {
            largest = i;
           b[dem]= i;
           dem++;
        }
    }
    for(int j = 3 ; j >=0 ; j--)
    {
        cout<<b[j];
    }
   
}*/
/*int binarylack(int a[],int n, int start, int end)
{
    if (start != a[start])
    {
        return start;
    }
    int mid=(start + end)/2;
    if(mid == a[mid]){ return binarylack(a,n,mid+1,end);}
    return binarylack(a,n,start,mid);
}*/
void xoa(int a[], int &n, int k,int vitri)
{
        for(int j = k ; j <= k + vitri-1; j++)
        {
            a[j]= a[j + 1];
            n--;
        }
}
void dele(int a[], int &n, int b[], int t)
{
    for(int i= 0 ; i < t; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(b[i]==a[j])
            {
                a[j]= a[j + 1];
                n--;
                j--;
            }
        }
    }
}
class complex
{
    private :
    int r;
    int l;
    public:
    complex(int x, int y)
    {
        r = x;
        l = y;
    }
    ~complex();
};
int main()
{
    /*int a[4]= { 1,2,4 ,6};
    int *ptr= a;
    cout<<*(++ptr);
    return 0;*/
    /*char *ptr = new char[5];
    for(int i = 0 ; i < 5 ; i++)
    {
        cin>>*(ptr + i);
    }
     for(int i = 0 ; i < 5 ; i++)
    {
        cout<<*(ptr + i);
    }
    delete [] ptr;*/
    int a[]= {0,1,4,9,5,9,7,9};
    int n = sizeof(a)/sizeof(a[0]);
    /*int k;
    cin>>k;
    int vitri;
    cin>>vitri;
    xoa(a,n,k,vitri);*/
    int b[]={1,9};
    int k = sizeof(b)/sizeof(b[0]);
    dele(a,n,b,k);
     for(int i= 0 ; i < n ; i++)
     {
         cout<<a[i];
     }
     return 0;
}