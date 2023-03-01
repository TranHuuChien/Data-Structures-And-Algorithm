#include<iostream>
#include<sstream>
#include<set>
#define ll long long
using namespace std;
// nếu gặp kí tự mở ngoặc nó sẻ đưa vào trong stack nếu gặp dấu đóng ngoặc pop 3 phần tử ra khỏi st
int main()
{
    set<ll>s;
    ll n;
    cin>>n;
    for(ll i = 0 ; i < n; i++ )
    {
        ll  x; cin>>x;
        s.insert(x);
    }
    for(ll x : s)
    {
        cout<<x<<" ";
    }
}