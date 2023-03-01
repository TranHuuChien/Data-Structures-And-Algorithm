#include<iostream>
using namespace std;
struct node
{
    int data;// dữ liệu của cái node
    struct node* pLeft;// node lên ket ben trai cua cay
    struct node *pRight;// node lien ket ben phai cua cay
};
// typedef struct node Node;
typedef node* tree;// đổi tên thôi chứ không quan trọng

void KhoiTaoCay(tree &t)
{
    t =NULL;// cay rong
}
// ham them phan tu vao vao cay nhi phan
void ThemNodeVaoCay(tree &t, int v)
{
    if(t==NULL)// cay rong
    {
        node *p = new node;// khoi tao 1 cai node de them vao cay
        p->data = v; //them du lieu v vao data
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;// do cay ban dau la rong nen phan tu them vao chinh la goc cua cay luon nha hihi heheh
    }
    else//cây có tồn tại phần tử nhỏ qua trái lớn qua phải
    {
        // nếu phần tử thêm vào mà nhỏ hơn node gốc ta them nó vào bên trái
        if(t->data > v)
        {
            ThemNodeVaoCay(t->pLeft,v);// duyệt qua bên trái để thêm phần tử x 
        }
        else if(t->data < v)// chỉ có thể lớn hơn hoặc nhỏ hơn chứkhông có chuyện bằng
        {
            ThemNodeVaoCay(t->pRight,v);// duyệt qua bên phải để thêm phần tử x
        }
    }
}
// void DuyetNLR(tree t)
// {
//     if(t!=NULL)
//     {
//         cout<<t->data<<"  ";
//         DuyetNLR(t->pLeft);// duyệt qua trái
//         DuyetNLR(t->pRight);// duyệt  qua phải
//     }
// }
void DuyetNLR(tree t)
{
     if(t!=NULL)
     {
         cout<<t->data<<"  ";
         DuyetNLR(t->pRight);// duyệt qua phải
         DuyetNLR(t->pLeft);// duyệt qua trái
     }
}
void DuyetLNR(tree l)// tự động sắp xếp tăng dần
{
    if(l!=NULL)
    {
        DuyetLNR(l->pLeft);
        cout<<l->data<<"  ";
        DuyetLNR(l->pRight);
    }
}
// void DuyetRNL(tree l)// sắp xếp giảm dần
// {
//     if(l!=NULL)
//     {
//         DuyetRNL(l->pRight);
//         cout<<l->data<<" ";
//         DuyetRNL(l->pLeft);
//     }
// }
// void DuyetLRN(tree l)
// {
//     if(l!=NULL)
//     {
//         DuyetLRN(l->pLeft);
//         DuyetLRN(l->pRight);
//         cout<<l->data<<" ";
//     }
// }
// void DuyetRLN(tree l)
// {
//     if(l!=NULL)
//     {
//         DuyetRLN(l->pRight);
//         DuyetRLN(l->pLeft);
//         cout<<l->data<<" ";
//     }
// }
// node* TimKiem(tree l, int x)
// {
//     if(l==NULL)
//     {
//         return NULL;
//     }
//     else
//     {
//         if(x < l->data)
//         {
//             TimKiem(l->pLeft,x); 
//         }
//         else if(x > l->data)
//         {
//             TimKiem(l->pRight,x);
//         }
//         else //x == l->data
//         {
//             return l;
//         }
//     }
//     return NULL;
// }
node* XoaNode(tree &l, int k)
{
    if(l==NULL) return NULL;

    if(k < l->data)
    {
        l->pLeft = XoaNode(l->pLeft,k);
    }
    else if(k > l->data)
    {
        l->pRight = XoaNode(l->pRight, k);
    }
    else 
    {
        if(l->pLeft ==NULL && l->pRight==NULL)
        {
            return NULL;
        }
        else if(l->pLeft==NULL)
        {
            node* temp = l->pRight;
            free(l);
            return temp;
        }
    }
    return l;
}
// int MaxValue(tree l)
// {
//     node* curr = l;
//     while(curr->pRight!=NULL)
//     {
//         curr=curr->pRight;
//     }
//     return curr->data;
// }
// node* SearchNodeinBST(tree l, int k)
// {
//     // space complexity n + n/2 + n/4+ n/8+...~  0(n);
//     // time O(log(n))
//     if(l==NULL) return NULL;
//     if(l->data== k) return l;
//     if(l->data > k)
//     {
//         return SearchNodeinBST(l->pLeft,k);
//     }
//     return SearchNodeinBST(l->pRight,k);
// }

node* MInValue(tree l)
{
    node* curr = l;
    while(curr->pLeft!=NULL)
    {
        curr=curr->pLeft;
    }
    return curr;
}
tree deleteNode(tree &l, int key)
{
    if(l==NULL) return l;
    // tiến hành tìm kiếm
    if(key < l->data)
    {
        deleteNode(l->pLeft, key);// tìm bên trái
    }
    else if( key > l->data)
    deleteNode(l->pRight,key);// tìm bên phải

    else// key ==l->data lúc này đã tìm được
    {
        if(l->pLeft==NULL && l->pRight==NULL)
        {
            return NULL;
        } 
        else if(l->pLeft ==NULL)
        {
            node* tmp = l->pRight;
            free(l);
            return tmp;
        }
        else if(l->pRight ==NULL)
        {
            node* tmp = l->pLeft;
            free(l);
            return tmp;
        }
        tree tempt = MInValue(l->pRight);
        l->data = tempt->data;
        l->pRight = deleteNode(l,tempt->data);
    }
    return l;
}
void diTimNodeTheThan(tree &x, tree &y)
{// x la node can xoa  , y la node the than
    if(y->pLeft!=NULL)// tim node trai nhat cua cay con phai
    {
        diTimNodeTheThan(x,y->pLeft);
    }
    else{// tim thay
        x->data = y->data;// cap nhat thay the node can xoa bang node con trai nhat

        x = y; // cho node x tro den node y
        y = y->pRight;// cap nhat lai cai node the than thanh null y->pRight = null
    // luc nay vi node y tro tro den NULL 
    //    y
    //   / \
    //NULL   NULL
    }
}
void xoaNodetrongCay(tree &l, int key)
{
    if(l==NULL) return;
    else
    {
        if(key<l->data)
        {
            xoaNodetrongCay(l->pLeft,key);
        }
        else if(key > l->data)
        {
            xoaNodetrongCay(l->pRight,key);
        }
        else
        {
            node *tmp = l;// thế thân của l;
            if(l->pLeft==NULL)
            {
                l=l->pRight;// ta chỉ xóa thế thân giá trị của nó thôi còn cái liên kết thì vẫn như cữ
            }// cập nhật lại cái bị xóa là cái con cháu phía dưới nó
            else if(l->pRight==NULL)
            {
                l=l->pLeft;
            }
            else// node can xoa la node co 2 nhanh
            {
                node *p = l->pRight;// cay con ben phai gan nhat cua node can xoa
                diTimNodeTheThan(l,p);// tim node trai nhat cua cay con phai ben tren
        
            }
            delete tmp;
        }
    }
}
// void deleteAllTree(tree &l)
// {
//     if(l==NULL)
//     {
//         return;
//     }
//     deleteAllTree(l->pLeft);
//     free(l);
//     deleteAllTree(l->pRight);
// }
// node* BuildBST(int a[], int left , int right)
// {
//     if(left > right) return NULL;
//     int mid = (left+ right)/2;

//     node* root = new node(a[mid]);
//     root->pLeft = BuildBST(a,left, mid-1);
//     root->pRight = BuildBST(a,mid+1, right);
//     return root;
// }

void GiaiPhongBoNHo(tree &l)
{
    if(l==NULL)
    return;

    GiaiPhongBoNHo(l->pLeft);
    GiaiPhongBoNHo(l->pRight);
    free(l);
}
int main()
{
    tree l;
    KhoiTaoCay(l);
    int n;
    cin>>n;
    while(n--)
    {
        int v; cin>>v;
        ThemNodeVaoCay(l,v);
    }
    // cout<<"cay luc dau :  ";
    // DuyetLNR(l);
    // cout<<endl;
    // xoaNodetrongCay(l,1);
    // cout<<"cay luc sau  ";
    struct node* root = deleteNode(l,12);
    DuyetLNR(l);
    GiaiPhongBoNHo(l);
    return 0;

}