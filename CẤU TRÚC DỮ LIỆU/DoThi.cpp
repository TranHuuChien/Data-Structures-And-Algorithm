#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
/*void Binarry()
{
    stack<int>st;
    int n;
    cin>>n;
    while(n!=0)
    {
        int x;
        x= n%2;
        st.push(x);
        n=n/2;
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();       
    }
}*/
/*void kiemTraMoNgoac()
{
    string s;
    stack<char>st;
    getline(cin,s);
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else{
            st.pop();
        }
    }
    if(st.empty())
    {
        cout<<"Hop le";
    }
    else{
        cout<<" khong hop le";
    }
}*/
/*void tongMotChuoiSo()
{
    // input 1234 = 1
    // 3559  4
    string s;
    getline(cin,s);
     int tong = 0;
    int n = atoi(s.c_str());
    while(n>0|| tong > 9)// yeu cau n chia het hoac tong phai co 2 chu so
    // neu co 1 chu so thi thoa man yeu cau
    {
        if(n==0)// chia het roi
        {
            n = tong;// gan n = tong de chia chi con 1 so
            tong = 0;// khoi tao lai tong = 0
        }
        tong += n%10;
        n/=10;
    }
}
void BieuDienDSCanhMaTranKe()
{
// 5 9
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 2 5
// 3 4
// 3 5
// 4 5
// 0  1  1  1  0
// 1  0  1  1  1
// 1  1  0  1  1
// 1  1  1  0  1
// 0  1  1  1  0
    int a[10][10]={0};
    int n, m;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++)
    {
        int x,y; cin>>x>>y;// các đỉnh ta cần tìm
        a[x][y]=a[y][x]=1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n; j ++)
        cout<<a[i][j]<<"  ";
        cout<<endl;
    }
}
void chuyenTuDsCanhsangDSke()
{
// 5 9
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4
// 2 5
// 3 4
// 3 5
// 4 5
// 1  2  3  4
// 2  1  3  4  5
// 3  1  2  4  5
// 4  1  2  3  5
// 5  2  3  4
    vector<int>a[10];// a[i] sẻ lưu danh sách kề cùa đỉnh i
    int n, m;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++)
    {
        int x, y; cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1; i <= n ; i++)
    {
        cout<<"thu tu dinh "<<i<<" : ";
        for(int x : a[i]) cout<<x<<"  ";
        cout<<endl;

    }
}
void ChuyenTuMaTranKeSangDScanh()
{
// 5
// 0 1 1 1 0
// 1 0 1 1 1
// 1 1 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0
// 1  2
// 1  3
// 1  4
// 2  3
// 2  4
// 2  5
// 3  4
// 3  5
// 4  5
    vector<pair<int, int>>vt;
    int a[10][10];
    int n; cin>>n;
    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1 ; j <=n ; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1 ; j <=n ; j++)
        {
            if(a[i][j]==1 && i < j)
            vt.push_back({i,j});
        }
    }
    for(int i = 0 ; i < vt.size(); i++)
    {
        cout<<vt[i].first<<"  "<<vt[i].second;
        cout<<endl;
    }
}
void MaTranKeSangDSKe()
{
//  5
// 0 1 1 1 0
// 1 0 1 1 1
// 1 1 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0
// output
// 2  3  4  
// 1  3  4  5
// 1  2  4  5
// 1  2  3  5
// 2  3  4
    int a[10][10];
    vector<int>b[10];
    int n; cin>>n;
    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1 ; j <=n ; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1 ; j <=n ; j++)
        {
            if(a[i][j]==1)
            {
                b[i].push_back(j);
            }
        }
    }
    for(int i = 1 ; i <= n; i++)
    {
        for(int x : b[i])
        {
            cout<<x<<"  ";
        }
        cout<<endl;
    }
}
void chuyenTuDSKeSangMaTranKe()
{
    vector<int>a[10];
    int b[10][10];
    int n; cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int x : a[i])
        {
            cin>>x;
        }
    }
    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1 ; j <=n ; j++)
        {
            if(b[i][j]==1)
            {
                a[i].push_back(j);
            }
        }
    }
    
}
vector<int>a[10];
bool visited[10];
void InPut()
{
    int n, m;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++)
    {
        int x,y; cin>>x>>y;
        a[x].push_back(y);// đồ thị vô hướng thi ta sẻ push back 2 lần 
        //a[y].push_back(x);// đồ thị có hướng thì ta chỉ 1 lần thôi
    }
    for(int i = 0 ; i < n; i++)
    {
        for(int x : a[i])
        cout<<"diem "<<i<<" noi voi "<<x<<" ";
        cout<<endl;
    }
    //memset(visited,false,sizeof(visited));
}*/
int n, m;
vector<int>adj[10];
bool visted[10];
void TimKiemDFS()
{
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9
// 1  2  4  3  6  7  9  8  5 thứ tự duyêt của thuật toán DFS
    cin>>n>>m;
    for(int i = 0 ; i < m ;i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int x : adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    //memset(visted,false,sizeof(visted));
}
// 10 11
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9
void DFSbyDequy(int u )
{
    cout<<u<<" ";
    visted[u]=true;
    for(int v : adj[u])
    {
        if(!visted[v])
        {
            DFSbyDequy(v);
        }
    }
}
void DFSbyStack(int u)
{
    stack<int>st;
    st.push(u);
    while(!st.empty())
    {
        int s = st.top(); st.pop();
        if(!visted[s])
        {
            cout<<s<<"  "; visted[s] = true;
        }
        for(int x : adj[s])
        {}
    }
}
void BFS(int u)
{
    queue<int>q;
    q.push(u);
    visted[u] = true;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        cout<<v<<" ";
        for(int x : adj[v])
        {
            if(!visted[x])
            {
                q.push(x);
                visted[x] = true; //  đánh dấu điểm x đã được thăm 
            }
        }
    }
}
void addgraph(vector<int>a[],int u , int v)
{
    a[u].push_back(v);
}
void printGraph(vector<int>a[], int V)
{
    for(int v = 0 ; v < V; v++)
    {
        cout<<v;
    }
}

int main()
{
    TimKiemDFS();
    return 0;
}
