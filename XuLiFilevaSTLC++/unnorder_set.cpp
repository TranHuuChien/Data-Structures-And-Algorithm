#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<unordered_set>
#include<string>
using namespace std;
void hamTrongSet()
{
    set<int>s;
    // này chỉ có một giá trị phân biệt vào thôi những giá trị bị trùng thì lấy giá trị đầu tiên bị trùng
    s.insert(12);// nghia la vao
    s.insert(10);
    s.insert(11);
    s.insert(11);
    s.insert(20);
    //set<int>::iterator i;
    if(s.empty())// return true neu set rong 
    // else return false neu khong rong
    /*for(  auto i = s.begin(); i!=s.end(); i++)
    {
        if((*i)%2 !=0)
        {
            s.erase(*i);
        }
    }*/
     for(  auto i = s.begin(); i!=s.end(); i++)
     {
         cout<<*i<<"  ";
     }
    s.clear();
}
void hamTrongUnorder_Set()
{
    // cac phuong thức trên tập hợp không có thứ tự trong đó được sử dụng 
    // nhiều nhất là kích thước và trống cho dung lượng, tìm từ khóa , chèn và xóa để sửa đổi
    // đươc sử dụng như kiểu bảng băm
    unordered_set<string>s;
    s.insert("in");// hàm insert này khi thêm vào sau cùng thì khi in ra nó sẽ ra đầu tiên giống như stack
    s.insert("code");
    s.insert("c++");
    s.insert("is");
    s.insert("fast");
    string str="is";
    // hàm find dùng để tìm kiếm phần tử có trong tập hợp hay không 
    // if(s.find(str)==s.end())// tra ve end() neu khong tim thay
    // {
    //     cout<<"khong tim thay";
    // }
    // if(s.find(str)!=s.end())
    // {
    //     cout<<"tim thay";
    // }
    // hàm count tra về số lần xuất hiện trong tập hợp đó trả về !=0 có sự xuất hiện của phần tử  đó
    //
    // hàm erase(): chúc năng xóa phần tử khỏi tập hợp;
    // cú pháp ten.erase(iterator start [s.begin()] , iterator end); khoir nguyen mot vung
    // cusphap ten.erase(element);
    // s.erase(str);
    for( auto i = s.begin(); i!=s.end(); i++)
    {
        cout<<(*i)<<" ";
    }
}
void baiToanunordered_set()
{
    unordered_set<int>s;
    set<int>st;
    int a[]={1,5,2,1,4,3,1,7,2,8,9,5};
    for(int x : a)
    {
        if(s.count(x)!=0)// tim thay
        {
            cout<<x;
            //st.insert(x);// nếu chỉ có 2 phần tử trung nhau ta có thể cout<<x ra luôn nhưng do có 3 số
            //có 2 số 1 nên khi in ra 2 số 1
        }
        else{
            s.insert(x);
        }
    }
    for(auto i = st.begin(); i!=st.end(); i++)
    {
        cout<<*i;
    }

}
void baiTap()
{
    vector<int>vt;
    vt.push_back(34);
    vt.push_back(13);
    vt.push_back(100);
    vt.erase(vt.begin()+1);
    for(auto i = vt.begin(); i!=vt.end(); i++)
    {
        cout<<*i<<"  ";
    }
}
void chuyen()
{
    unordered_set<int>s;
    s.insert(1);
    s.insert(0);
    s.insert(0);
    s.insert(1);
    for(auto i = s.begin(); i!=s.end(); i++)
    {
        cout<<*i;
    }
}
int main()
{
    //hamTrongSet();
    chuyen();
    //baiToanunordered_set();
    //chuyenVeNHiPhan();
    return 0;
}