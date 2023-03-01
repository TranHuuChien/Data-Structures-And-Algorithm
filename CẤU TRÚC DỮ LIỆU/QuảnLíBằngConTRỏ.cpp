#include<iostream>
using namespace std;

struct node
{
    int data;
    node * next;
};
void themVaoDau(node **head)
{
    node *new_node=new node;
    cin>>new_node->data;
    new_node->next=(*head);
    (*head)=new_node;
}
// tao node luon
node *createdNode(int d)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = d;
    return temp;
}
void ThemVaoCuoi(node **head)
{
    node *new_node= new node;
    cin>>new_node->data;
    if(*head==NULL)
    {
        *head =new_node;
    }
    else
    {
        node *p = *head;// khi khai bao nhu nay thi p da tro tu dong den NULL roi
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=new_node;
        
    }
}
int TongCacNode(node *head)
{
    node *ptr=head;
    int tong = 0;
    while(ptr!=NULL)
    {
        tong+=(ptr->data);
        ptr=ptr->next;
    }
    return tong;
}
void printNode(node * head)
{
    if(head ==NULL)
    {
        cout<<"empty link list";
        return;
    }
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<(ptr->data)<<"  ";
        ptr=ptr->next;
    }
}
// 1-->2---> 3--->4 -->NULL
// 
node *reverse(node *head)
{
    node *next = NULL;
    node *curr = head;
    node *prev = NULl;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
    }
    return prev;
}
node* DaoNguocThepDeQuy(node *head)
{
    if(head ==NULL || head->next==NULL)
    return head;
    node *tempt = DaoNguoc(head->next);
    head->next->next=head;

    head->next=NULL;
    return rest;
}
void Reverseprint(node * head)
{
    if(head==NULL)
    return;
    Reverseprint(head->next);
    cout<<head->data<<" ";
}
node* DaoNGuoctheosoLUong(node *head , int k)
{
    if(head==NULL)
    return;

    node *cur = head;
    node *next = NULL;
    node *prev = NULL;
    int dem = 0;
    while(head!=NULL && dem < k)
    {
        next = cur->next;
        cur->next = prev;
        cur = next;
        prev = cur;
        dem ++;
    }
    return prev;
}
// chia danh sach lien kết ra 2 danh sách liên kết khác nhau do yêu cầu của người dùng
/*void chiaDanhSachLam2Phan(node *start1, node **start2, node **start3)
{
    while(start1!=NULL)
    {
        node *tempt1=new node;
        tempt1->data=start1->data;
        tempt1->next=(*start2);
        (*start2)=tempt1;
        start1=start1->next;
        if(start1!=NULL)
        {
            node *tempt2=new node;
            tempt2->data=start1->data;
            tempt2->next=(*start3);
            (*start3)=tempt2;
            start1=start1->next;
        }
    }
}
void danXenChanLe(node *start1, node **start2,node **start3)
{
    node * ptr=start1;
    while(ptr!=NULL)
    {
        if((ptr->data)%2==0)
        {
            node *tempt1=new node;
            tempt1->data=ptr->data;
            tempt1->next=(*start2);
            (*start2)=tempt1;
        }
        else
        {
            node *tempt2=new node;
            tempt2->data=ptr->data;
            tempt2->next=(*start3);
            (*start3)=tempt2;
        }
        ptr=ptr->next;
    }
}*/
void giaiPhongBoNHo(node *head)
{
    node *ptr=NULL;
    while(head!=NULL)
    {
        head=ptr;
        head=head->next;
        delete ptr;
    }
}
/*void xuatCacNodeThuN(node *head)
{
    cout<<"\n Nhap thu tu can xuat";
    int t;
    cin>>t;
    int dem = 0;
    int len = 0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
         len++;
    }
    while(ptr!=NULL)
    {
        if((len-dem)>=t)
        {
            cout<<ptr->data<<"  ";
        }
        dem++;
        ptr=ptr->next;
    }
}*/
/*bool 2DanhSachGiongNhau(node *head, node *head1)
{
    node *ptr=head;
    node *pts=head1;
    while(ptr!=NULL && pts !=NULL)
    {
        if(ptr->data==pts->data)
        {
            return false;
        }
        ptr=ptr->next;
        pts=pts->next;
    }
}*/
// tong 3 danh sach lien ket theo một tong cố định
/*void TongDanh(node *a, node *b, node *c, int target)
{
    // a= 20-->4-->15-->10-->NULL
    // b= 10-->9-->4-->2-->NULL
    // c= 1-->2--->4--->8-->NULL
    node *ptr1=a;
    node *ptr2= b;
    node *ptr3=c;
    int tong = 0;
    while(ptr1!=NULL)
    {
        while(ptr2!=NULL && ptr3!=NULL)
        {
            tong = ptr1->data+ptr2->data+ptr3->data;
            if(tong = target)
            {
                cout<<ptr1->data<<"  "<<ptr2->data<<"  "<<ptr3->data<<endl;
            }
            else if(tong < target)
            {
                ptr3=ptr3->next;
            }
            else{
                ptr2=ptr2->next;
            }
        }
        ptr1= ptr1->next;
    }
// ở một diễn biến khác chúng ta có thể sử dụng pp trâu bò chơi luôn 3 vòng lặp while()
}*/
/*void quayDanhSach(node *head, int k)
{
    // 1 --> 2--->3--->
    node *ptr=head;
    int dem = 1;
    if(ptr=NULL)
    {
        return;
    }
    while(dem < k && ptr!=NULL)
    {
        dem++;
        ptr=ptr->next;
    }
    node *pts = ptr;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        ptr->next=head;
        head=ptr;
        pts->next=NULL;

    }
}
node *rotate(node *head, int h)
{
    // 1-->2-->3-->4-->5-->6-->7-->NULL
    // vitri la 3 di nha
    // (head)1-->2-->3 (ngưng)-->NULL    4(newhead)-->5-->6-->7-#>NULL
    //(head mới)4-->5-->6-->7-->(head cũ)1-->2-->3-->NUll
    node *ptr= head, *q,*new_head;
    int dem =0;
    while(ptr!=NULL)
    {
        if(h==dem)
        {
            break;
        }
        dem++;
        ptr=ptr->next;
    }
    new_head=ptr->next;
    q= new_head;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=head;
    ptr->next=NULL;
    return new_head;
}*/
// sắp xếp theo thứ tự 1s, 2s, 3s
/*void sortList(node * head)
{
    int count[3]={0,0,0};
    // phương pháp đếm số lượng phần tử trùng giá trị trong mội container
    node *ptr=head;
    while (ptr!=NULL)
    {
        count[ptr->data]+=1;
        ptr=ptr->next;
    }
    ptr=head;//  đánh dấu lại ptr ở đầu file chứ không thì ptr sẽ ở cuối danh sách nên không thể sort
    int i = 0;
    while (ptr!=NULL)
    {
        if(count[i]==0)
        {
            i++;
        }
        else
        {
            ptr->data=i;
            --count[i];
            ptr=ptr->next;
        }
    }
}*/
//phương pháp này dùng đến 2 vòng lặp nên O(n^2)
// không khả thi hạn chế sử dụng
/*void xoa1NodeBatKitheoVitri(node *head, int vitri)
{
    node *ptr = head;
    node * pts = NULL;
    int dem = 1;
    if(head ==NULL)
    {
        return;
    }
    while(ptr !=NULL)
    {
        if(dem = vitri)
        {
           break; 
        }
        dem++;
        ptr=ptr->next;
    }
    pts = ptr->next;
    ptr->next=ptr->next->next;
    free(pts);
}
void xoaNodetuVTdenN(node *head,int n)
{
    cout<<"nhap vi tri xoa";
    int vitri, soluong;
    cin>>vitri>>soluong;
    int dem = 0;
    for(node * ptr = head ; ptr != NULL; ptr=ptr->next)
    {
        if(dem >= vitri && dem < vitri + soluong)
        {
            xoa1NodeBatKitheoVitri(head, dem);
        }
        dem++;
    }
}*/
// phương pháp trên geekforgeek phương pháp bị sai lỗi
//1 2 3 4 5 6 7
//7  6  3  2
/*void xoaChumNodeTuvitri(node *head, int M, int N)
{
    node *ptr = head , *t;
    int dem;
    while(ptr)
    {
        for(dem = 1; dem < M && ptr !=NULL; dem++)
        {
            ptr=ptr->next;
        }
         t = ptr->next;
        if(ptr==NULL)
            {
                return;
            }
        for(dem = 1; dem <=N && t !=NULL;dem ++)
        {
            node *tempt = t;
            t= t->next;
            free(tempt);
        }
        ptr->next=t;
        ptr=t;
    }
}*/
void SortLinkList(node* head)
{
    node * i , *j;
    i = head;
    j = head->next;
    while(i->next!=NULL)
    {
        while(j!=NULL)
        {
            if(i->data>j->data)
            {
                swap(i->data,j->data);
            }
            j=j->next;
        }
        i =i->next;
    }
}
struct node * partition(node *first, node * last)
{
    node *pivot = first;
    node *front = first;
    int tempt = 0;
    while(front!=NULL && front !=last)
    {
        if(front->data< last->data)
        {
            pivot = first;
            // Swap node value
            tempt = first->data;
            first->data= front->data;
            front->data=tempt;
            // visit to next node
            first = first->next;
        }
        front=front->next;
    }
    tempt=first->data;
    first->data=last->data;
    last->data=tempt;
    return pivot
}
node* LastNode(node * head)
{
    node * ptr = head;
    while( ptr!=NULL&&ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr;
}
void QuickSort(node *first, node * last)
{
    if(first==last) return;

    node *pivot = partition(first, last);
    if(pivot!=NULL && pivot->next!=NULL)
    {
        QuickSort(pivot->next,last);
    }
    if(pivot!=NULL && first!=pivot)
    {
        QuickSort(first, pivot);
    }
}
// merge two sort link list tuong tu voi 2 con tro
node* MergeTwoSortlinkLIst(node* p, node* q, node* sorting)
{
    node* newHead = NULL;
      if(q==NULL) return p;
      if(p==NULL) return q;
      if( p && q)
      {
          if(p->data <= q->data)
          {
              sorting = p;
              p = sorting->next;
          }
          else// p->data > q->data
          {
              sorting = q;
              q= sorting->next;
          }
      } 
      newHead= sorting; 
    while(cur!=NULL &&prev!=NULL)
    {
        if(p->data <= q->data)
        {
            sorting->next = p;
            sorting = p;
            p = sorting->next;
        }
        else{
            sorting->next=q;
            sorting = q;
            q = sorting->next;
        }
    }
    if(p==NULL) sorting->next = q;
    if(q==NULL) sorting->next = p;
    return newHead;
}
node* Merge2LLinkList(node* a, node *b)
{
    node* newHead = NULL;

}
int main()
{
    /*node *start1=NULL;
    node *start2=NULL;
    node *start3=NULL;*/
    node *head=NULL;
    cout<<"so luong node can lap";
    int n;
    cin>>n;
    while(n--)
    {
       themVaoDau(&head);
    }
   SortLinkList(head);
    printNode(head);
    cout<<endl;
    giaiPhongBoNHo(head);
}
// Reverse a stack without ussing  extra space in 0(n)
/*class StackNode
{
    public :
    int data;
    StackNode *pNext;
    StackNode(int d)
    {
        this->data = data;
        this->pNext = NULL;
    }
};
class Stack{
    StackNode *top;
    public:
    void push(int d)
    {
        if(top==NULL)
        {
            top = new StackNode(d);
            return;
        }
    }
    StackNode *s = new StackNode(d);

};*/
// class StackNode
// {
//     int data;
//     StackNode next;
//     public StackNode(int d)
//     {
//         this.data= d;
//         this.next = null;
//     }
// }
// class Stack{
//     StackNode top;
//     public void push(int data)
//     {
//         if(this.top==null)
//         {
//             top = new StackNode(data);
//             return;
//         }
//         StackNode s = new StackNode(data);
//         s.next = this.top;
//         this.top = s;
//     }
//     public StackNode pop()
//     {
//         StackNode s = this.top;
//         this.top = this.top.next;
//         return s;
//     }
//     public void display()
//     {
//         StackNode s = this.top;
//         while(s!=null)
//         {
//             System.out.print(s.data + " ");
//             s = s.next;
//         }
//         System.out.println();
//     }
//     public void reverse()
//     {
//         StackNode prev = null;
//         StackNode cur = this .top;
//         StackNode next = null;
//         while(cur!=null)
//         {
//             next = cur.next;
//             cur.next = prev;
//             prev = cur;
//             cur = next;
//         }
//         this.top = prev;
//     }
// }



