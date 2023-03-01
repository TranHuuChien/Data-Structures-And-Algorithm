#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
/*void xoa(int a[], int &n, int vitri)
{
    for(int k = vitri ; k < n; k++)
        {
            a[k]= a[k +1];
         }
         n--;
}
void timtrung(int a[], int &n, int b[], int &t)
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < t ; j++)
        {
            if(a[i]==b[j])
            {
                xoa(a,n,i);
                xoa(b,t,j);
            }
        }
    }
                
}
void mang(int a[],int &n, int b[], int t)
{
    int c[10];
    int dem= 0;
    for(int i= 0 ; i < n;i++)
    {
        for(int j = 0 ; j < t; j++)
        {
            if(a[i]==b[j])
            {
                c[dem]=a[i];
                dem++;
            }
        }
    }
    cout<<"so phan tu chung cua hai mang :  ";
    sort(c,c+dem);
    for(int i = 0 ; i < dem; i++)
    {
        if(c[i]==c[i + 1])
        {
            xoa(c,dem,i);
        }
    }
    for(int i =0 ; i < n; i++)
    {
        for(int j = 0 ; j < dem ; j++)
        {
            if(a[i]==c[j])
            {
                xoa(a,n,i);
            }
        }
    }
}
*/

/*void DaoPhanTudoiXung()
{
    int n;
    cin>>n;
    int a[4];
    for(int i =0 ; i< n; i++)
    {
        cin>>a[i];
    }
    int i = 0;
    int j = n -1;
    while(i < j)
    {
        swap(a[i], a[j]);
    }
    for(int i = 0 ; i< n; i++)
    {
        cout<<a[i];
    }
}*/
/*int pHantuLonNhat()
{
    int n;
    cin>>n;
    int a[4];
    for(int i =0 ; i< n; i++)
    {
        cin>>a[i];
    }
    int max = a[0];
    int min= a[0];
    for(int i = 1; i< n; i++)
    {
        if(max <a[i])
        {
            max = a[i];
        }
        if(min > a[i]) min = a[i];
    }
    return min + max;
}*/
/*void xuat1s2s3s()
{
    // 0 0 1 0 2 0 2 2
    // output 0 0 0 0 1 2 2 2
    int n;
    cin>>n;
    int a[4];
    for(int i =0 ; i< n; i++)
    {
        cin>>a[i];
    }
    int c0 = 0;
    int c1 = 0, c2 =0;
    for(int i =0 ;i< n;i++)
    {
        if(a[i]==0)
        {
            c0++;
        }
        else if(a[i]==1)
        {
            c1++;
        }
        else{
            c2++;
        }
    }
    for(int i = 0 ;i< c0; i++)
    a[i]= 0;

    for(int i = c0 ; i< c1+c0; i++)
    a[i]=1;
    int i = 0;
    while(c2--)
    {
        a[i++]= 2;
    }
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" ";
    }
}*/
// cách khác bai trên
/*void xuat0den1den2()
{
    // 0 1 0 1 2 2 0 1
    int a[8];
    for(int i =0 ; i< 8; i++)
    {
        cin>>a[i];
    }
    int count[3]={0, 0, 0};
    int dem =0;
    for(int i = 0; i< 8; i++)
    {
        count[a[i]]++;
    }
    int i = 0;
    int j =0;
    while(j < 8)
    {
        if(count[i]==0)
        {
            i++;
        }
        else{
            a[j]=i;
            --count[a[j]];
            j++;
        }
    }
    for(int i = 0;i< 8; i++)
    {
        cout<<a[i];
    }
}*/
// cach khac ta co ther sort di
// tron phan tu cua 2 mang xoa phan tu trung
/*void xoaTrung2mang()
{
    int a[4];
    int b[4];
    set<int> st;
    for(int i = 0; i< 4; i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    for(int i = 0; i< 4; i++)
    {
        cin>>b[i];
        st.insert(b[i]);
    }
    set<int>::iterator it;
    for(it= st.begin(); it!=st.end(); it++)
    {
        cout<<*it;
    }

}*/
// tong con lon nhat thuat toan Kadanes's algorithm
/*int subSum()
{
    int a[4];
    for(int i = 0; i< 4; i++)
    {
        cin>>a[i];
    }
    int max_ = a[0];
    int maxC=a[0];
    for(int i = 1; i< 4; i++)
    {
        maxC= max(maxC + a[i], a[i]);
        if(max_ < maxC)
        {
            max_ = maxC;
        }
    }
    return max_;
}*/

int main()
{
    cout<<subSum();
    return 0;
}