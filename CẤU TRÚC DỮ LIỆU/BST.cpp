#include<iostream>
#include<stack>
#include<set>
#include<queue>
using namespace std;


// node* CHuyenLInkListSangVector(node* head)
// {
//     vector<node*>vt;
//     PustDLLtoTree(head, vt);
//     return BuildBalanceBSTree(vt,0 ,vt.size() - 1);/// tru vij tri null cuoi
// }


// TreeNode* BuildBinaryTree(ListNode *node)
// {
//     if(node==NULL)
//     return NULL;

//     ListNode *tempt = node;
//     int dem = 0;
//     while(tempt!=NULL)
//     {
//         dem++;
//         tempt=tempt->next;
//     }
//     if(dem==1)
//     {
//         return new TreeNode(node->data);
//     }
//     ListNode * TreeLeft = new ListNode(node->data);
//     ListNode* TreeFake = TreeLeft;
//     for(int i = 0 ; i < dem /2 -1 ; i++)
//     {
//         node =node->next;
//         TreeLeft->next = new ListNode(node->data);
//     }
// }
//





struct TreeNode
{
    int data;
    TreeNode *Left, *Right;
    TreeNode(int d)
    {
        this->data = d;
        this->Left = NULL;
        this->Right = NULL;
    }
};
TreeNode* newNode(int data)
{
    TreeNode* newNODE = new TreeNode(data);
    newNODE->Left = NULL;
    newNODE->Right = NULL;
    return newNODE;
}
// struct ListNode
// {
//     int data;
//     ListNode *Next;
//     ListNode(int d)
//     {
//         this->data = d;
//         this->Next = NULL;
//     }
// };
// ListNode* push(ListNode * head, int data)
// {
//     ListNode*node = new ListNode(data);
//     node->Next = head;
//     head = node;
//     return head;
// } 
void PrintTree(TreeNode * root)
{
    if(root==NULL) return;

    else
    {
        PrintTree(root->Left);
        cout<<root->data<<"  ";
        PrintTree(root->Right);
    }
}
// TreeNode* BiuldThanhBSt(ListNode * head)
// {
//     queue<TreeNode*>q;
//     TreeNode* root = new TreeNode(head->data);
//     head = head->Next;
//     while(head)
//     {
//         if( root->data < head->data);
//         {
//             root->Right = BiuldThanhBSt(head);
//         }
        
//     }
//     return root;
// }

// int TimElementThoaManDieuKien(TreeNode* root, int n1, int n2)
// {
    
//     else if( n1 < root->data && n2 < root->data)
//     {
//        return TimElementThoaManDieuKien(root->Left,n1,n2);
//     }
//     else if(n2 < root->data)
//     {
//         return TimElementThoaManDieuKien(root, n1, n2);
//     }
//     return 0;
// }
TreeNode* insert(TreeNode* root, int k)
{
    if(root==NULL)
    {
        return new TreeNode(k);
    }
    
    if(root->data < k)
    {
        root->Right = insert(root->Right,k);
    }
    else if(root->data > k)
    {
        root->Left = insert(root->Left, k);
    }
    return root;
}
int KthSmallestUsingSpace(TreeNode* root, int k)
{
    int dem =0;
    int kSmall = INT_MIN;
    TreeNode*cur = root;
    while(cur)
    {
        if(cur->Left==NULL)
        {
            dem++;
            if(dem == k)
            {
                kSmall = cur->data;
            }
            cur= cur->Right;
        }
        else
        {
            TreeNode* prev = cur->Left;
            while(prev->Right!=NULL && prev->Right!= cur)
            {
                prev = prev->Right;
            }
            if(prev->Right==NULL)
            {
                prev->Right  = cur;
                cur = cur->Left;
            }
            else{
                prev->Right =NULL;
                dem++;
                if(dem==k)
                {
                    kSmall = cur->data;
                }
                cur = cur->Right;
            }
        }
    }
    return kSmall;
}
void VectorTree(TreeNode* root, vector<int>&vt)
{
    if(root==NULL) return;

    VectorTree(root->Left,vt);
    vt.push_back(root->data);
    VectorTree(root->Right,vt);
}
void FindPairSum(TreeNode* root,int sum)
{
    vector<int>vt;
    VectorTree(root,vt);
    int start = 0;
    int end = vt.size() - 1;
    while(start < end)
    {
        if(vt[start] + vt[end] == sum)
        {
            cout<<vt[start]<<"  "<< vt[end];
        }
        else if(vt[start] + vt[end] < sum)
        start++;

        else
        end--;
    }
}
bool SameTree(TreeNode* root, TreeNode* floot)
{
    if(root==NULL && floot ==NULL)
    {
        return true;
    }
    if(root == NULL || floot ==NULL)
    {
        return false;
    }
    return SameTree(root->Left,floot->Left);
}
TreeNode* minValue(TreeNode* node)
{
   TreeNode *tmp = node;
   while(tmp && tmp->Left !=NULL)
   {
       tmp = tmp->Left;
   }
   return tmp;
}
TreeNode* deleteNode(TreeNode* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data < key)
    {
        root->Right= deleteNode(root->Right,key);
    }
    else if(root->data > key)
    {
        root->Left= deleteNode(root->Left, key);
    }
    else
    {
        //case no child
        if(root->Left==NULL && root->Right==NULL)
        {
            return NULL;
        }// case node have one child
        else if(root->Left==NULL)
        {
            TreeNode* tmp = root->Right;
            free(root);
            return tmp;
        }
        else if(root->Right==NULL)
        {
            TreeNode* tmp = root->Left;
            free(root);
            return tmp;
        }
        TreeNode *tmp = minValue(root->Right);
         root->data = tmp->data;
        root->Right = deleteNode(root->Right, tmp->data);
    }
    return root;
}
// TreeNode* deleteNode(TreeNode* root, int key)
// {
//     if(root==NULL)
//     return NULL;

//     if(root->data < key)
//     root->Right = deleteNode(root->Right, key);

//     else if(root->data > key)
//     {
//         root->Left = deleteNode(root->Left, key);
//     }
//     else
//     {
//         if(root->Left==NULL && root->Right==NULL)
//         return NULL;

//         else if(root->Right == NULL)
//         {
//             TreeNode* tmp = root->Left;
//             free(tmp);
//             return tmp;
//         }
//         else if(root->Left == NULL)
//         {
//             TreeNode* tmp = root->Right;
//             free(tmp);
//             return tmp;
//         }
//         TreeNode * tmp = minValue(root->Right);
//         root->data = tmp->data;
//         deleteNode(root->Right,tmp->data);
//     }
//     return root;
// }
int main()
{
    /* Let us create following BST
            50
          /   \
        30     70
        / \ / \
    20 40 60 80 */
    TreeNode* root  = NULL;
    root= insert(root,9);
    insert(root,10);
    insert(root, 2);
    insert(root,13);
    insert(root,5);
    insert(root,7);
    insert(root,19);
    insert(root,25);
    // deleteNode(root,13);
    PrintTree(root);
    // cout<<endl;
    // root->Left =newNode(3);
    // root->Right =newNode(8);
    // root->Left->Right = newNode(5);
    // root->Left->Left = newNode(2);
    // root->Right->Left = newNode(7);
    // root->Right->Right = newNode(9);
    // root->Left->Right->Left = newNode(10);

    // ListNode* head = NULL;
    // head = push(head,1);
    // head = push(head,2);
    // head = push(head,3);
    // head = push(head,4);
    // head = push(head,5);
    // PrintList(head);
    // cout<<endl;
    // TreeNode* root = BiuldThanhBSt(head);
    return 0;
}
 