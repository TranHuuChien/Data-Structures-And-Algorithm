#include<iostream>
#include<map>
#include<string>
using namespace std;
int max(int a, int b)
{
    return (a>b)?a:b;
}
/*int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        if(s.length() < 2)
            {return s.length();}
        
        set<char> st;
        
        int i = 0, j = 1;
        st.insert(s[0]);
        
        while(j < s.length()){
           
            while(st.find(s[j]) != st.end())    {
                st.erase(s[i++]);
            }
            st.insert(s[j]);
            ans = max(ans, st.size());
            
            j++;
        }
        return ans;
    }*/
int  timmax(vector<int>a)
{
    int maxsum = a[0];
    for(int i= 0 ; i < a.size(); i++)
    {
        if(maxsum < a[i])
        {
            maxsum = a[i];
        }
    }
    return maxsum;
}
void manglon(vector<int>a, int k)
{
    vector<int>b;
    for(int i = 0 ; i <a.size(); i++)
    {
        b.push_back(a[i]);
        if(i>=k-1)
        {
             b.erase(b.begin()+i-(k-1));
            cout<<timmax(b);
        }
    }
}
/*
tim mang con co gia tri lon nhat
int maxsub(vector<int>nums)
{
    vector<int>demo(nums.size(),0);
    nums[0]=demo[0];
    for(auto i = 1; i< nums.size(); i++)
    {
        demo[i]= max(demo[i-1]+nums[i], nums[i])
    }
    return *max_elemnt(demo.begin,demo.end());
}
*/
/*int main()
{
    vector<int>a(5);
    int x;
    for(int i = 0 ; i < 5; i++)
    {
        cin>>a[i];
    }
    manglon(a,2);
    vector<vector<int> > vt;
    int s;
    for(int i = 0 ; i < 3;i++)
    {
        vector<int>a;
        for(int j= 0 ; j < 3; j++)
        {
            a.push_back(i);
        }
        vt.push_back(a);
    }
    for(int i = 0 ; i < vt.size(); i++)
    {
    for(int j = 0 ; j < vt[i].size();j++)
    {
        cout<<vt[i][j];
    }
    cout<<endl;
    }*/
    
bool kiemtrachuoidoixung(string s, int low , int high)
{
    if(low >= high)
    {
        return true;
    }
    else 
    {
        return s[low]==s[high]&& kiemtrachuoidoixung(s,low+1, high-1);
    }
}
bool chuoiconlaplai(string s)
{
    if(s.length()==0)
    {
        return false;
    }
    unordered_map<char, int> freq;
    for(int i = 0 ; i < s.length();i++)
    {
        if()
    }
}
int main()
{
    string s("aabaa");
    if(kiemtrachuoidoixung(s,0,s.length()-1)==true)
    {
        cout<<"doi xung";
    }
    return 0;
}