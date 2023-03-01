#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct node
{
    int data;
    node* next;
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
void ThemVaoSau(node ** head)
{
    node* newNode = new node;
    cin>>newNode->data;
    newNode->next = (*head)->next;
    (*head)->next = newNode;
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

// node *reverse(node *head)
// {
//     node *next = NULL;
//     node *curr = head;
//     node *prev = NULL;
//     while(curr!=NULL)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr =next;
//     }
//     return prev;
// }
// void Reverseprint(node * head)
// {
//     if(head==NULL)
//     return;
//     Reverseprint(head->next);
//     cout<<head->data<<" ";
// }
/*node* MergeTwoSortlinkLIstNoiDanhSach(node* p, node* q)
{
    node* newHead = NULL;
    node* sorting;
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
    while(p!=NULL && q!= NULL)
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
*/
void moveListNode(node** result, node** tempt)
{
    node* newNode = *tempt;
    *tempt = (*tempt)->next;// chinh cho nay do phai thay doi thu tu trong danh sach cu nen 
    // phai dung den con tro de gan gia tri moi co the thay doi duoc
    newNode->next =(*result);
    (*result) = newNode;
}
node* CachMotMergeTwolinkLIstPP()
{
    
}
// Using Recursion
/*node* CachHaiMergeTwoLInkList(node* a, node* b)
{
    if(a==NULL)
    return b;

    else if(b ==NULL)
    {
        return a;
    }
    node* result = NULL;
    if(a->data <= b->data)
    {
        result = a;
        result->next = CachHaiMergeTwoLInkList(a->next,b);
    }
    else// a->data > b->data
    {
        result = b;
        result->next = CachHaiMergeTwoLInkList(a,b->next);
    }
    return result;
    // time O(n + m) voi n, m la chieu dai cua 2 link list
}
*/
void giaiPhongBoNHo(node* head)
{
    node* tempt = NULL;
    while(head!=NULL)
    {
        tempt = head;
        head = head->next;
        free(tempt);
    }
}
// struct Node
// {
//     int data;
//     int maxium;
// };
// int getMax(stack<Node>st1, stack<Node>st2)
// {
//     int  MAX = INT_MIN;
//     // maxium element int stack st1
//     if(st1.size() > 0)
//     {
//         MAX = max(MAX, st1.top().maxium);// diem nhan la day
//     }
//     // Maxium element in stack st2
//     if(st2.size()>0)
//     {
//         MAX = max(MAX, st2.top().maxium);
//     }
//     return MAX;
// }
// void inSertElement(stack<Node>st2, int value)
// {
//     Node newNode ;
//     newNode.data = value;
//     if(st2.empty())
//     newNode.maxium = value;
//
//     else
//     {
//         Node front = st2.top();
//
//         newNode.maxium = max(value, front.maxium);
//     }
//     st2.push(newNode);
// }
// void deleteElement(stack<Node>st1, stack<Node>st2)
// {
//     if(st1.size() > 0)
//     {
//         st1.pop();
//     }
//     else
//     {
//         while(!st2.empty())
//         {
//             Node value = st2.top();
//             inSertElement(st1, value.data);
//             st2.pop();
//         }
//         st1.pop();
//     }
// }
// void MaxSlidingWinDowbyStack(vector<int>vt, int k)
// {
//     stack<Node>st1;
//     stack<Node>st2;
//     for(int i = 0 ; i < k - 1; i++)
//     {
//         inSertElement(st2,vt[i]);
//     }
//     for(int i = 0  ; i <= vt.size() - k; i++)
//     {
//         if(i - 1 >= 0)
//         {
//             deleteElement(st1,st2);
//         }
//         inSertElement(st2,vt[i+k - 1]);
//         cout<<getMax(st1,st2);
//     }
// }
node* reverseSubLK(node* head , int start, int end)
{
    node* iter = head;
    int dem = 0;
    while( iter!=NULL && dem < start)
    {
        dem++;
        iter = iter->next;
    }
    node* ptr = iter->next;
    while(start < end)
    {
        node* tempt = ptr->next;
        ptr->next = tempt->next;
        tempt->next = ptr->next;
        iter->next = tempt;
        iter = iter->next;
    }
    return head;
}
// void ChenVaoDau(node** head, int DATA)
// {
//     node* newNode = new node;
//     newNode->data = DATA;
//    newNode->next =(*head);
//     (*head) = newNode;
// }
// node* mergerTwoLinkListChenTrucTiep(node* list1, node* list2)
// {
//     if(list1 == NULL && list2== NULL)
//     {
//         return NULL;
//     }
//     node* res= NULL;
//     while(list1 !=NULL && list2 !=NULL)
//     {
//         if(list1->data <= list2->data)
//         {
//             ChenVaoDau(&res,list1->data);
//         }
//         else
//         {
//             ChenVaoDau(&res,list2->data);
//         }
//     }
//     while(list2!=NULL)
//     {
//         ChenVaoDau(&res,list2->data);
//         list2 = list2->next;
//     }
//     while(list1!=NULL)
//     {
//         ChenVaoDau(&res, list1->data);
//         list1 =list1->next;
//     }
//     return res;
// }
int main()
{
 node *head=NULL;
    cout<<"so luong node can lap";
    int n,m;
    cin>>n;
    while(n--)
    {
       themVaoDau(&head);
    }
    sortLinkList(head);
    printNode(head);
    giaiPhongBoNHo(head);
    return 0;
}
