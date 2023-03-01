#include<iostream>
#include<unordered_set>
#include<stack>
#include<cmath>
using namespace std;
/*
struct Node
{
    int data;
    struct Node *pNext;
};
struct List
{
    Node *pHead;
    Node *pTail;
};
// Khoi tao danh sach lien ket don
void khoiTaodanhsach(List &l)
{
    l.pHead=l.pTail=NULL;
}
// Tao node trong danh sach 
Node* KhoitaoNode(int x)// de truyen vao data 
{
    Node *p = new Node(); // Cap phat vung nho ccho1 node
    if(p == NULL)
    {
        return NULL;
    }
    p->data=x;  // truyen x vao data
    p->pNext=NULL;//
    return p; //tra ve node p vua khoi tao
}
// Them node
void ThemVaoDau(List &l, Node *p)
{
    if(l.pHead==NULL)// danh dach dang rỗng
    {
        l.pHead=l.pTail=p; //node cũng là node cuối và bằng p
    }
    else{
        p->pNext=l.pHead;// cho con trỏ của node cần thêm là node p liên kết với node đầu -phead
        l.pHead=p;//cập nhật lại chính pHead chính là p;
    }
}
void ThemVaoCuoi(List &l, Node *p)
{
    if(l.pHead==NULL) // danh sách đang rỗng
    {
        l.pHead=l.pTail=p; //node cũng là node cuối và bằng p
    }
    else{
        l.pTail->pNext=p;// cho con trỏ của pTail liên kết với node của p
        l.pTail=p;// cập nhật lại p là node pTail
    }
}
void xuatDanhSach(List l)
{
     Node *k = l.pHead;
    while(k!=NULL)
    {
        cout<<k->data;
        k=k->pNext;
    }
    
    //for(Node *k = l.pHead; k !=NULL; k = k->pNext)
    //{
        //cout<<k->data<<"  ";
    //}
}
int timMax(List l)
{
    int max = l.pHead->data;
    for(Node * k = l.pHead; k !=NULL; k=k->pNext)
    {
        if(max < k->data)
        {
            max = k->data;// cập nhật lại giá trị max 
        }
    }
    return max;
}
// Them node p vào sau node q
void Themnodevaosau(List &l, Node *p)
{
    int x;
    cout<<"NHap gia tri cua node q: ";
    cin>>x;
    Node *q= KhoitaoNode(x);
    // nếu danh sach chỉ có 1 phần tử và phần tử đó chính là node p 
    if(q->data==l.pHead->data&& l.pHead->pNext==NULL)
    {
        ThemVaoCuoi(l,p);
    }
    else{
        for(Node *k = l.pHead; k != NULL; k = k->pNext)
        {
            if(k->data==q->data)
                {
                    Node *h = KhoitaoNode(p->data);
                    Node *g= k->pNext; // cho node g trỏ đến node nằm sau node q;
                    h->pNext=g;//
                    k->pNext=h;
                }
        }
    }
}
void themNodeVaoViTriBatKi(List &l, Node *p, int vt, int n)
{
    if(l.pHead==NULL ||  vt==1)
    {
        ThemVaoDau(l,p); // theem  node p vao dau danh sach 
    }
    else if(vt = n +1)
    {
        ThemVaoCuoi(l,p);
    }
    else{
        int dem = 0;
        Node *g = new Node;// la node giu lien ket voi node truoc vi tri can them
        for(Node *k = l.pHead; k!=NULL; k=k->pNext)// tim ra vi tri vt can them node p vao
        {
            dem++;
            if(dem ==vt)
            {
                Node *h =KhoitaoNode(p->data);
                h->pNext=k;
                g->pNext=h;
            }
        }
    }
}
int main()
{
    List l;
    int luachon;
    khoiTaodanhsach(l);// khởi tạo danh sách liên kết đơn
    while(2)
    {
    cout<<"\n\t==========Menu==========";
    cout<<"\n\t1.Them node vao danh sach ";
    cout<<"\n\t2.Xuat danh sach lien ket don ";
    cout<<"\n\t3.Them node p vao sau node q ";
    cout<<"\n\t 4.THem node p vap vi tri bat ki ";
    cout<<"\n \t =========End===========";
    cout<<"\n\t Nhap lua chon cua ban  :";
    cin>>luachon;
    if(luachon==1)
    {
       int n;
        cout<<" Nhap so luong node can them :";
        cin>>n;
    for(int i = 0; i < n; i++)
       {
        int x;
        cout<<"Nhap gia tri data trong node ";
        cin>>x;
        //Node *p = KhoitaoNode(x);// khởi tạo một node số nguyên 
        ThemVaoCuoi(l,KhoitaoNode(x)); // thêm node p vao đầu danh sách liên kết đơn
       }
    }
    else if(luachon==2)
       {
    cout<<"Xuat Danh Sach Lien Ket Don : ";
    xuatDanhSach(l);
       }
    else if(luachon == 3)
    {
        int x;
        cout<<"Nhap du lieu node p can them vao trong node q";
        cin>>x;
        Themnodevaosau(l,KhoitaoNode(x));
    }
    else if(luachon ==4)
    {
    int n = 1;
    for( Node *k = l.pHead; k !=NULL; k = k->pNext)
    {
        n++;
    }
        int x;
        cout<<"Nhap gia tri cua node p can them ";
        cin>>x;
        Node *p=KhoitaoNode(x);
        int vt;
        do{
            cout<<"\n Nhap vi tri can them";
            cin>>vt;
            if(vt<1||vt>n+1)
            {
                cout<<"\n Hay nhap lai vi tri can them";
                system("pause");
            }
        }while(vt<1||vt>n+1);
        themNodeVaoViTriBatKi(l,p,vt,n);
    }
    else{
        break;
    }
    }
    
    return 0;
    
}
=================================================
*/
struct node
{
    
    int data;
    struct node *pNext;
};
struct List
{
    node *pHead;
    node *pTail;
};
void Khoitaolist(List &l)
{
    l.pHead=l.pTail=NULL;
}
node *KhoitaoNode(int x)
{
    node*p=new node;
    p->data=x;
    p->pNext=NULL;
    return p;
}
/*void ThemVaoDau(List &l, node *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else{
        p->pNext=l.pHead;
        l.pHead=p;
    }
}*/
void ThemVaoCuoi(List &l, node* p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void xuatDanhSach(List l)
{
    for(node *k = l.pHead; k != NULL;k = k->pNext)
    {
        cout<<k->data<<"   ";
    }
}
/*void chenNodePsauNodeQ(List &l,node *p)
{
    cout<<"Nhap Node q can chen phia sau ";
    int x;
    cin>>x;
    node * q =KhoitaoNode(x);
    if(l.pHead->data==q->data && l.pHead->pNext==NULL)
    {
        ThemVaoCuoi(l,p);
    }
    else{
        for(node *k = l.pHead; k!= NULL; k=k->pNext)
        {
            if(k->data==q->data)
            {
                node *h = KhoitaoNode(p->data);
                node *g= k->pNext;
                h->pNext=g;
                k->pNext=h;
            }
        }
    }
}
void themNodePvaotruocNodeQ(List &l, node *p)
{
    cout<<"Nhap Node q can chen phia truoc ";
    int x;
    cin>>x;
    node * q =KhoitaoNode(x);
    if(l.pHead->data==q->data && l.pHead->pNext==NULL)
    {
        ThemVaoDau(l,p);
    }
    else{
        node *g= new node;
        for(node *k = l.pHead; k!= NULL; k=k->pNext)
        {
            if(k->data==q->data)
            {
            // node h chinh la node phuoc truoc node Q
                node *h=KhoitaoNode(p->data);
                 h->pNext=k;
                 g->pNext=h;
            }
        g=k;
        }
    }
}
*/
void hamTaoNodecogiatri(List &l)
{
    int n;
    cout<<"Nhap so phan tu trong danh sach";
    cin>>n;
    for(int i = 0 ; i< n; i++)
    {
        int x;
        cin>>x;
        node *p=KhoitaoNode(x);
        ThemVaoCuoi(l,p);
    }
}
/*void xoaDau(List &l)
{
    if(l.pHead==NULL)
    {
        return;
    }
    else{
        node *p=l.pHead;
        l.pHead=l.pHead->pNext;
        delete p;
    }
}
void xoaCuoi(List &l)
{
    if(l.pHead==NULL)
    {
        return;
    }
    else{
        for(node *k =l.pHead; k!= NULL; k=k->pNext)
        {
            if(k->pNext=l.pTail)
            {
                k->pNext=NULL;
                k=l.pTail;
                delete l.pTail;
            }
        }
    }
}*/
// xóa tại một vi trí bất kì
/*void deleteinValue(List &l,int key)
{
    node *tempt=l.pHead;
    node *ptr=NULL;
    if(tempt!=NULL && tempt->data==key)
    {
        l.pHead=l.pHead->pNext;
        delete tempt;
    }
    else{
        while(tempt!=NULL && tempt->data!=key)
        {
            ptr=tempt;
            tempt=tempt->pNext;
        }
        if(tempt==NULL)
        {
            return;
        }
        ptr->pNext=tempt->pNext;
        delete tempt;
    }
}
void deletePositive(List &l,int pos)
{
    if(l.pHead==NULL)
    {
        return;
    }
    node *ptr=l.pHead;
    if(pos==0)
    {
        l.pHead=ptr->pNext;
        free(ptr);
        return;
    }
    for(int i = 0; ptr!=NULL&& i <pos-1;i++)
    {
        ptr=ptr->pNext;
    }
    node *pNext=ptr->pNext->pNext;
    free(ptr->pNext);
    ptr->pNext=pNext;
}
void xoaList(List &l)
{
    node *a =l.pHead;
    node *b = NULL;
    while (a!=NULL)
    {
        b=a->pNext;
        free(b);
        a = b;
    }
    l.pHead=NULL;
}*/
/*void findLength(List &l)
{
    node *k=l.pHead;
    int dem=0;
    while (k!=NULL)
    {
        dem++;
        k=k->pNext;
    }
    
}*/

/*int GetNth(List &l, int index)
{
 
    node* current = l.pHead;
 
    // the index of the
    // node we're currently
    // looking at
    int count = 0;
    while (current != NULL) {
        if (count == index-1)
            return (current->data);
        count++;
        current = current->pNext;
    }
    return 0;
}*/
// in ra phần tử ở giữa của danh sach liên kết
// Phương pháp 1
/*int TraVeNodeOGiua(List &l)
{
    node *ptr = l.pHead;
    int dem=0,t;
    while (ptr!=NULL)
    {
        dem++;
        ptr=ptr->pNext;
    }
    ptr = l.pHead;
    while(ptr!=NULL)
    {
        if(t==dem/2)
        {
            return ptr->data;
        }
    }
    return 0;
}*/
//PHương pháp 2
/*void inRaPhanTuOGiua(List &l)
{
    node *slowPtr=l.pHead;
    node *fastPtr=l.pHead;
    while(fastPtr!=NULL && slowPtr!=NULL)
    {
        fastPtr=fastPtr->pNext->pNext;
        slowPtr=slowPtr->pNext;
    }
    cout<<slowPtr->data;
}*/
// Dem so lan xuat hien cua cac phan tu
/*int demSoLanXuatHien(node **pHead, int x)
{
    int dem = 0;
    for(node *ptr= *pHead ; ptr!=NULL; ptr=ptr->pNext)
    {
        if(ptr->data==x)
        {
            dem++;
        }
    }
    return dem;
}
int demSoLan(node *head,int key)
{
    if(head==NULL)
    {
        return 0;
    }
    if(head->data==key)
    {
        return 1+demSoLan(head->pNext,key);
    }
    return demSoLan(head->pNext,key);
}*/
/*bool kiemTraVongLap(List &l)
{
    node *slowPtr=l.pHead;
    node *fastPtr=l.pHead;
    while (slowPtr && fastPtr && fastPtr->pNext) {
        slowPtr = slowPtr->pNext;
        fastPtr = fastPtr->pNext->pNext;
        if (slowPtr == fastPtr) {
            return 1;
        }
    }
    return 0;
}
void TaoVonglaptrongDSLk(List &l)
{
    l.pHead->pNext->pNext->pNext->pNext=l.pHead;
    if(kiemTraVongLap(l))
    {
        cout<<"co vong lap";
    }
}*/
/*void chiaChanLe(List &l)
{
    node *end=l.pHead;
    node *tempt = NULL;
    node *start=l.pHead;
    while(end->pNext!=NULL)
    {
        end = end->pNext;
    }
    node * new_end=end;
    while(start->data%2!=0 && start != end)
    {
        new_end->pNext=start;
        start=start->pNext;
        new_end->pNext->pNext=NULL;
        new_end=new_end->pNext;        
    }
    if(start->data%2==0)
    {
        node *ptr=start;
        while(start!=end)
        {
            if(start->data%2==0)
            {
                tempt=start;
                start=start->pNext;
            }
            else{
                tempt->pNext=start->pNext;
                start->pNext=NULL;
                new_end->pNext=start;
                new_end=start;
                start=tempt->pNext;
            }
        }
    }
    else tempt=start;
    if(new_end!=end && (end->data)%2!=0)
    {
        tempt->pNext=end->pNext;
        end->pNext=NULL;
        new_end->pNext=end;
    }
    return;
}*/
/*void xuatChan(List l)
{
    node *ptr=l.pHead;
    while(ptr!=NULL)
    {
        if((ptr->data)%2==0)
        {
            cout<<ptr->data<<"  ";
        }
        ptr=ptr->pNext;
    }
}*/
// đảo ngược cặp trogn linklist
/*node *swapPairNode(List &l)// phương pháp này mình có ghi trong giấy vỡ nháp
{
    node *start=l.pHead;
    node *p=start;
    node *new_start=p->pNext;
    while(1)
    {
        node *q = q->pNext;
        node *temp=q->pNext;
        q->pNext=p;
        if(temp==NULL || temp->pNext==NULL)
        {
            p->pNext=NULL;
            break;
        }
        p->pNext=temp->pNext;
        p=temp;

    }
    return start;
}
void swapNode(List &l)
{
    node *temp = l.pHead;
    while(temp!=NULL && temp->pNext!=NULL)
    {
        swap(temp, temp->pNext);
        temp= temp->pNext->pNext;
    }

}
node * swwap(node *head)
{
    if(head==NULL) return NULL;
    struct node *curr = head;
    while(curr && curr->pNext)
    {
        int temp = curr->data;
        curr->data = curr->pNext->data;
        curr->pNext->data = temp;
        curr=curr->pNext->pNext;
    }
    return head;
}
void swapPair(List &l)
{
    while(l.pHead&& l.pHead->pNext)
    {
        node *one=l.pHead;
        node *two =one->pNext->pNext;
        l.pHead= one ->pNext;
        one->pNext->pNext=one;
        one->pNext=two;
        l.pHead =one->pNext;
    }
}*/
// chia link list thanh 2 cai khac nhau
/*void devideLinkList(List &l)
{
    // phan nay su dung ki thuat 2c on tro nhanh va cham
    node *p=l.pHead;
    node *q=l.pHead;
    while(1)
    {
        node *start=NULL;
        p=p->pNext->pNext;
        if(p==NULL)
        {
            start=q->pNext;
        }
        if(p->pNext==NULL)
        {
            start=start->pNext->pNext;
        }
        q=q->pNext;
    }
}
void daoNguocDanhSach(List &l)
{
    node *ptr=l.pHead;
    node *pts=NULL, *pNext=NULL;
    while(ptr!=NULL)
    {
        pNext=ptr->pNext;
        ptr->pNext=pts;
        pts=ptr;
        ptr=pNext;
    }
    l.pHead=pts;
}*/
// xoa cac phan tu bi trung lien tieo nhau thoi
/*void xoaCacPhanTuBiTrung(node *head)
{
    node *ptr=head;
    node *pts;
    if(ptr==NULL)
    {
        return;
    }
    while(ptr->pNext!=NULL)
    {
        if(ptr->data==ptr->pNext->data)
        {
            //=ptr->pNext->pNext;
            //free(ptr->pNext);
            //ptr->pNext=pts;
            pts=ptr->pNext;
            ptr->pNext=ptr->pNext->pNext;
            free(pts);
        }
        else{
            ptr=ptr->pNext;
        }
    }
}
// phuong phap de quy
void xoaPhanTuTrung(node *head)
{
    node *ptr;
    if(head==NULL)
    {
        return;
    }
    if(head->pNext!=NULL)
    {
        if(head->data==head->pNext->data)
        {
            //ptr=head->pNext->pNext;
            //free(head->pNext);
            //head->pNext=ptr;
            ptr=head->pNext;
            head->pNext=head->pNext->pNext;
            free(ptr);
            xoaPhanTuTrung(head);
        }
        else{
            xoaPhanTuTrung(head->pNext);
        }
    }
}*/
// xóa các ptử bị trùng trongdslk nhưng không liên kề
//Phương pháp sử dụng 2 vòng lặp
/*void xoaTrungPHanTu(List &l)
{
    node *ptr=l.pHead;
    node *pts;
    node *ips;
    if(l.pHead==NULL)
    {
        return;
    }
    while(ptr!=NULL && ptr->pNext!=NULL)
    {
         pts=ptr;
         while(pts->pNext!=NULL)
         {
             if(ptr->data==pts->pNext->data)
             {
                 ips=pts->pNext;
                 pts->pNext=pts->pNext->pNext;
                 delete(ips);
             }
             else{
                 pts=pts->pNext;
             }
         }
         ptr=ptr->pNext;
    } 
}
//Phương pháp 2 sử dụng pp sort xong rồi thưc hiện xóa trùng liền kề
//phương pháp 3 sử dụng bảng băm
void xoaTrungBangBam(List &l)
{
     unordered_set<int> st;
     node *ptr=l.pHead;
     node *pts=NULL;
     while(ptr!=NULL)
     {
         if(st.count(ptr->data)>0)
         {
             ptr->pNext=ptr->pNext->pNext;
             delete(ptr->pNext);
         }
         else
         {
             st.insert(ptr->data);
             ptr=ptr->pNext;
         }
     }
}*/
/*void quayLinkList(List &l)
{
    node *ptr;
    node*pts;
    pts=NULL;
    ptr=l.pHead;
    if(ptr->pNext==NULL|| ptr==NULL){
        return;
    }
    while(ptr->pNext!=NULL)// diều kiện có ít nhất 2 node trong liên kết
    // và cũng là để xét đk pts phải là node kế cuối
    // 1--->2-->3--->4(pts)---->5(ptr)--->NULL
    // 5(ptr)--->1--->2--->3--->4(pts)--->NULL
    {
        pts=ptr;
        ptr=ptr->pNext;
    }
    pts->pNext=NULL;
    ptr->pNext=l.pHead;
    l.pHead=ptr;
}
void quayPhanTucoVitrilenDau(List &l,int giatri)
{
    node *ptr,*pts;
    pts=NULL;
    ptr=l.pHead;
    while(ptr!=NULL && ptr->pNext->data!=giatri)
    {
        ptr=ptr->pNext;
    }
    pts=ptr->pNext;
    ptr->pNext=ptr->pNext->pNext;
    pts->pNext=l.pHead;
    l.pHead=pts;  
}
*/
// dem xem co bao nhieu cap từ q danh sách có tổng bằng k
/*int demCapKTong(List &l, int k)
{
    node *ptr=l.pHead;
    node *pts=NULL;
    int dem=0;
    while(ptr->pNext!=NULL&&ptr!=NULL)
    {
        pts=ptr;
        while(pts->pNext!=NULL)
        {
            if((pts->data)+(ptr->data)==k)
            {
                dem++;
            }
            pts=pts->pNext;
        }
        ptr=ptr->pNext;
    }
    return dem;
}*/
// tìm phần tử có cả ở danh sách a và danh sách b
/*void push(node **head,int d)
{// không chạy đc
    node *p=new node;
    p->data=d;
    p->pNext=(*head);
    (*head)=p;
}
node *timPhantucoCa2DanhSach(node *a, node *b)
{
    node *result=NULL;
    node **lastPtr=&result;
    while (a!=NULL && b!=NULL)
    {
        if(a->data==b->data)
        {
            push(lastPtr,a->data);
            lastPtr=&((*lastPtr)->pNext);
            a=a->pNext;
            b=b->pNext;
        }
        else if(a->data < b->data)
        {
            a=a->pNext;
        }
        else
        {
            b=b->pNext;
        }
    }
    return result;
}
void xuat(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"  ";
        ptr=ptr->pNext;
    }
}
int main()
{
    node *a,*b;
    for(int i = 0; i< 4; i++)
    {
        int x;
        cin>>x;
        push(&a,x);
    }
    xuat(a);
    for(int j = 0; j< 4; j++)
    {
        int y;
        cin>>y;
        push(&b,y);
    }
    //node *result=NULL;
    //result=timPhantucoCa2DanhSach(a,b);
    xuat(b);
}*/

//1---> 2--->3 ---->4---> 6--->null
// 2-->4---->5
//tach chan le
/*void tachChanLe(List &l)
{
    node *ptr=l.pHead;
    node *pts=NULL;
    node *tempt=l.pHead;
    node *new_ptr=NULL;
    while(ptr->pNext!=NULL)
    {
        ptr=ptr->pNext;
        new_ptr=ptr;
    }
    while(tempt->data %2 !=0 && tempt !=ptr)
        {
            new_ptr->pNext=tempt;
            tempt=tempt->pNext;
            new_ptr->pNext->pNext=NULL;
            new_ptr=new_ptr->pNext;
        }
        
    if(tempt->data % 2 ==0)
        {
            l.pHead=tempt;
            while(tempt !=ptr)
            {
                if((tempt->data)%2==0)
                {
                    pts=tempt;
                    tempt=tempt->pNext;
                }
                else
                {
                    pts->pNext=tempt->pNext;
                    tempt->pNext=NULL;
                    new_ptr->pNext=tempt;
                    new_ptr=tempt;
                    tempt=pts->pNext;
                }
        }
    }
    else pts=tempt;

    if(new_ptr != ptr && (ptr->data)%2 !=0)
    {
        pts->pNext=ptr->pNext;
        ptr->pNext=NULL;
        new_ptr->pNext=ptr;
    }
    return;
}
// Tach chan le 
void TachChanLe(List &l)
{
    node *a=NULL;
    node *a1 = NULL;
    node *b=NULL;
    node *b1=NULL;
    node *ptr=l.pHead;
    while(ptr!=NULL)
    {
        int value=ptr->data;
        if(value %2 ==0)
        {
            if(a==NULL)
            {
                a = a1 = ptr;
            }
            else{
                a1->pNext=ptr;
                a1=a1->pNext;
            }
        }
        else
        {
            if(b==NULL)
            {
                b = b1 = ptr;
            }
            else{
                b1->pNext=ptr;
                b1=b1->pNext;
            }
        }
        ptr=ptr->pNext;
    }
    if(a==NULL||b==NULL)
    {
        return;
    }
    a1->pNext=b;
    b1->pNext=NULL;
    l.pHead=a;
}
//  input: 3-->4-->2-->1-->9-->8-->7-->6-->NULL
// chẵn : 4-->2-->8-->6;
// lẻ : 3-->1-->9-->7;
// sau đó ta liên kết hai đầu lại 
// output: 4-->2-->8-->6-->3-->1-->9-->7--->NULL
 void tachLevaChan(List &l)
 {
     node * a=NULL;
     node *b=NULL;
     node *c=NULL;
     node *d=NULL;
     node *ptr=l.pHead;
     while(ptr!=NULL)
     {
         int value=ptr->data;
         if(value %2==0)
         {
             if(a=NULL)
             {
                 a=b=ptr;
             }
             else{
                 b->pNext=ptr;
                 b=b->pNext;
             }
         }
         else
         {
             if(c=NULL)
             {
                 c=d=ptr;
             }
             else{
                 d->pNext=ptr;
                 d=d->pNext;
             }
         }
     }

 }*/
// dao nguoc danh sach lien ket  
/*void DaoNGuocDanhSach(List &l)
{
    node *ptr=l.pHead;
    node *pts=NULL;
    while(ptr->pNext!=NULL)
    {
        pts=ptr->pNext;
        ptr->pNext=pts->pNext;
        pts->pNext=l.pHead;
        l.pHead=pts;
    }
}*/
void GiaiPhongVungNho(List &l)
{
    /*for(node *k=l.pHead; k !=NULL ; k= k->pNext)
    {
        delete k; //giải phóng từng node trong danh sách liên kết
    }*/
    node *ptr=NULL;
    while(l.pHead!=NULL)
    {
        ptr=l.pHead;
        l.pHead=l.pHead->pNext;
        delete(ptr);
    }
}
/*void DanXenChanLe(List &l)
{
    stack<node*>a;
    stack<node*>b;
    node *ptr=l.pHead;
    int i = 1;
    while(ptr!=NULL)
    {
        if((ptr->data)%2!=0 && i%2==0)
        {
            a.push(ptr);
        }
        else if((ptr->data)%2==0 && i%2!=0)
        {
            b.push(ptr);
        }
        ptr=ptr->pNext;
        i++;
    }
    while(a.empty()==false && b.empty()==false)
    {
        a.top();
        b.top();
    }
}*/
// xÓA NODE CHẴN LẺ RA KHỎI DANH SÁCH LIÊN KẾT
/*bool SoNguyenTo(int n)
{
    if(n < 2)
    {
        return false;
    }
    else{
        for(int i = 2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
    }
    return true;
}
void XoaNodeChan(List &l)
{
    node *ptr=l.pHead;
    node *pts=NULL;
    while(ptr->pNext!=NULL)
    {
        if((ptr->pNext->data)%2==0)
        {
            pts=ptr->pNext;
            ptr->pNext=ptr->pNext->pNext;
            delete(pts);
        }
        else{
            ptr=ptr->pNext;
        }
    }
}
void XoaNodeNto(List &l)
{
    node *ptr=l.pHead;
    node *pts=NULL;
    while(ptr->pNext!=NULL)
    {
        if(SoNguyenTo((ptr->pNext)->data)==false)
        {
            pts=ptr->pNext;
            ptr->pNext=ptr->pNext->pNext;
            delete(pts);
        }
        else{
            ptr=ptr->pNext;
        }
    }
}*/
void QuickSort(int a[], int left, int right)
{
    int i = left;
    int j = right - 1;
    int M = a[(left+right)/2];
    do
    {
        while(a[i] < M) 
        {
            i++;
        }
        while(a[j]>M)
        {
            j--;
        }
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    
    
}
int main()
{
    List l;
    node *pHead=NULL;
    // cách tạo danh sách chỉ với con trỏ pHead dấud tiên
    //struct node *start=newNODE(10);
    //start->pNext=newNODE(11);
    //start->pNext->pNext=newNODE(12);
    //start->pNext->pNext->pNext=newNODE(13);
    Khoitaolist(l);
    hamTaoNodecogiatri(l);
    
    xuatDanhSach(l);
    GiaiPhongVungNho(l);
    return 0;
}
//=============================================

