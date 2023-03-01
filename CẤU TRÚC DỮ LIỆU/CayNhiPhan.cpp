#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
struct NodeTree
{
    int data;
    NodeTree *pLeft;
    NodeTree *pRight;
    NodeTree(int data)
    {
        this->data = data;
        this->pLeft = NULL;
        this->pRight = NULL;
    }
};
NodeTree* CreateNode(int data)
{
    NodeTree* tmp =  new NodeTree(data);
    if(!tmp)
    {
        cout<<"mermory error ";
        return NULL;
    }
    tmp->pLeft = NULL;
    tmp->pRight = NULL;
    return tmp;
}
NodeTree* insert(NodeTree* root, int data)
{
    if(!root)
    {
        root = CreateNode(data);
        return root;
    }
    queue<NodeTree*>q;
    q.push(root);
    while(!q.empty())
    {
        NodeTree* tmp = q.front();
        q.pop();
        if(tmp->pLeft!=NULL)
        q.push(tmp->pLeft);
        else{
            tmp->pLeft = CreateNode(data);
            return root;
        }

        if(tmp->pRight!=NULL)
        q.push(tmp->pRight);

        else
        {
            tmp->pRight = CreateNode(data);
            return root;
        }
    }
    return root;
}
/*NodeTree* deleteTion(NodeTree* root, int key)
{
    if(root==NULL)
    return NULL;

    if(root->pLeft==NULL && root->pRight==NULL)
    {
        if(root->data == key)
        {
            return NULL;
        }
        else
        {
            return root;
        }
    }
    NodeTree* keyNode = NULL;
    NodeTree* tmp, last;
    queue<NodeTree*>q;
    q.push(root);
    while(!q.empty())
    {
        tmp = q.front(); q.pop();
        if(tmp->data==key)
        {
            keyNode = tmp;
        }
        if(tmp->pLeft)
        {
            q.push(tmp->pLeft);
        }
        if(tmp->pRight)
            q.push(tmp->pRight);
    }
    if(keyNode!=NULL)
    {
        int x = tmp->data;
        
    }
}*/
NodeTree* deletion(NodeTree* root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->pLeft==NULL && root->pRight ==NULL)
    {
        if(root->data ==key)
            return NULL;
        else
        {
            return root;
        }
        
    }
    NodeTree*keyNode = NULL;
    NodeTree* last;
    NodeTree* tmp;
    queue<NodeTree*>q;
    q.push(root);
    while(!q.empty())
    {
         tmp = q.front();
        q.pop();
        if(tmp->data==key)
        {
            keyNode = tmp;
        }
        if(tmp->pLeft!=NULL)
        {
            last = tmp;
            q.push(tmp->pLeft);
        }
        if(tmp->pRight!=NULL)
        {
            last = tmp;
            q.push(tmp->pRight);
        }
    }
    if(keyNode!=NULL)
    {
       keyNode->data = tmp->data;
       if(last->pRight==tmp)
       {
           last->pRight = NULL;
       }
       else
       {
           last->pLeft =NULL;
       }
       delete(tmp);
    }
    return root;
}
/*void printPostorder(NodeTree* root)
{
    if(root==NULL)
    return;
    printPreorder(root->pLeft);
    printPreorder(root->pRight);
    cout<<root->data<<"  ";
}
void printInorder(NodeTree* root)
{
    if(root==NULL) return;
    disPlay(root->pLeft);
    cout<<root->data<<"  ";
    disPlay(root->pRight);
}
void printPreorder(NodeTree * root)
{
    if(root==NULL) return;
    cout<<root->data;
    printPreorder(root->pLeft);
    printPreorder(root->pRight);
}
void PrintWithOutRecusion(NodeTree* root)
{
    stack<NodeTree*>s;
    NodeTree* cur = root;
    while(!s.empty()|| cur!=NULL)
    {
        while(cur!=NULL)
        {
            s.push(cur);
            cur=cur->pLeft;
        }
        cur = s.top();
        s.pop();
        cout<<cur->data<<"  ";
        cur = cur->pRight;
    }
}
void printRightNodeleft(NodeTree* root)
{
    stack<NodeTree*>s;
    NodeTree* cur = root;
    while(1)
    {
        while(cur)//!=null
        {
            s.push(cur);
            cur = cur->pRight;
        }
        if(s.empty())
            break;
        cur = s.top(); s.pop();
        cout<<cur->data<<" ";
        cur = cur->pLeft;
    }
}
void printNodeLeftRight(NodeTree* root)
{
    queue<NodeTree*>s;
    s.push(root);
    while(!s.empty())
    {
        NodeTree* tmp = s.front();
        s.pop();
        cout<<tmp->data<<"  ";
        if(tmp->pLeft)
        {
            s.push(tmp->pLeft);
        }
        if(tmp->pRight)
            s.push(tmp->pRight);
    }
}*/
void findNthNodePostordered(NodeTree* root, int n, int dem)
{
    if(root==NULL) return;
    findNthNodePostordered(root->pLeft,n,dem++);
    if(dem==n)
    {
        cout<<root->data<<"  ";

    }
    findNthNodePostordered(root->pRight,n,dem++);

    // if(root==NULL) return;
    // static int dem = 0;
    // findNthNode(root->pLeft, n);
    // dem++;
    // if(dem==n)
    // {
    //     cout<<root->data;
    // }
    // findNthNode(root->pRight,n);
}
/*int sumTree(NodeTree* root)
{
    if(!root)
    return 0;
    else
    {
        int left = sumTree(root->pLeft);
        int right = sumTree(root->pRight);
    }
    return root->data + left + right;
}
int heightTree(NodeTree* root)
{
    if(root==NULL) return 0;
    int left = heightTree(root->pLeft);
    int right = heightTree(root->pRight);
    return 1 + max(left,right);
}
void invertTreeUsingRecursion(NodeTree *root)
{
    if(root==NULL) return;

    reverseTree(root->pLeft);
    reverseTree(root->pRight);
    root->pLeft = root->pRight;
    root->pRight = root->pLeft;
}
NodeTree* invertTree(TreeNode root)
{
    if(root == null) return root;
    TreeNode left = invertTree(root.left);
    TreeNode right = invertTree(root.right);
    root.right = left;
    root.left = right;
}
int heighttreeusingstack(NodeTree* root)
{
    if(root == NULL) return 0;
    queue<NodeTree*> q; int height = 0;
    int nodeCount = 0;
    q.push(root);
    while(!q.empty())
    {
        height++;
        nodeCount = q.size();
        while(nodeCount--)
        {
            NodeTree* tmp = q.front();
            if(tmp->pLeft)
                q.push(tmp->pLeft);

            if(tmp->pRight)
                q.push(tmp->pRight);
            q.pop();
        }
    }
    return height;
}
// phương pháp nay sai nha
int heightTREE(NodeTree* root)
{
    if(root==NULL)
        return 0;

    int chieucao = INT_MIN;
    int dem = 0;
    NodeTree* cur = root;
    stack<NodeTree*>st;
    while(1)
    {
        while(cur!=NULL)
        {
            st.push(cur);
            cur = cur->pLeft;
        }
        if(st.empty()==false)
            break;
        cur = st.top(); st.pop();
        dem++;
        if(st.size()==1)
        {
            chieucao = max (chieucao,dem);
            dem = 0;
        }
        cur=cur->pRight;
    }
    return chieucao;
}*/
/*void reverseTree(NodeTree* root)
{
    // 4 2 5 1 6 3 7
    // 7 6 5 4   3 2   1 duyệt từ lá về gốc
    if(root==NULL) return;
   queue<NodeTree*>q;
   stack<NodeTree*>st;
   q.push(root);
   while (!q.empty())
   {
      NodeTree* tmp = q.front(); q.pop();
      if(tmp->pLeft)
        q.push(tmp->pLeft);
        if(tmp->pRight)
        q.push(tmp->pRight);
        st.push(tmp);
   }
   while (!st.empty())
   {
       cout<<st.top()->data<<" ";
       st.pop();
   }
}
void ThayDoi(NodeTree* root, vector<NodeTree*>vt,int p, int key)
{
    if(root==NULL) return;

    vt[p++] = root;
    if(root->data == key)
    {
        int i = 0;
        int j = p - 1;
        while(i < j)
        {
            int tmp = vt[i]->data;
            vt[i]->data = vt[j]->data;
            vt[j]->data = tmp;
            i++;
            j--;
        }
    }
    if(root->pLeft==NULL && root->pRight==NULL)
    return;
    ThayDoi(root->pLeft, vt, p , key);
    ThayDoi(root->pRight,vt, p ,key);
}*/
/*
void thayTheNodeGocBangNodekhac(NodeTree* root, int key)
{
    // 4 2 5 1 6 3 7
    // key == 4 ==>> 1 2 5 4 6 3 7
    if(!root) return;
    vector<NodeTree*>vt(10,NULL);
    ThayDoi(root,vt,0, key);
}
int MaxXiUmSumPath(NodeTree* root, int &result)
{
    if(!root) return 0;
    int left = MaxXiUmSumPath(root->pLeft, result);
    int right = MaxXiUmSumPath(root->pRight, result);
   int max_straight = max(max(left , right)+ root->data, root->data);
   int max_caseVal = max(max_straight,left + right + root->data);
   result = max( max_caseVal, result);
   return max_straight;
}
int maxSum = INT_MIN;
void maxSumfromRoottoLeaf(NodeTree* node , int sum)
{
    if(node == NULL) return;
    if(node->pLeft==NULL && node->pRight == NULL && sum + node->data > maxSum)
    {
        maxSum = sum + node->data;
        return;
    }
    maxSumfromRoottoLeaf(node->pLeft, sum + node->data);
    maxSumfromRoottoLeaf(node->pRight, sum + node->data);
}
// tìm nhánh cây có tổng lớn nhất
int maxPathSum(NodeTree* root)
{
    if(root==NULL) return 0;
    int left = max(maxPathSum(root->pLeft), 0);
    int right = max(maxPathSum(root->pRight),0);
    //maxSum = max (maxSum, left+ right+ root->data); 
    // nếu bỏ comment câu lệnh trên thì ta sẻ trả về hai nhanh cây và cả nút gốc có tổng lớn nhất
    return max(left, right)+ root->data;
}*/
// check xem nhánh cây có tổng L
void printpathSumK(NodeTree* root, vector<int>&vt, int k)
{
    if(!root) return;
    vt.push_back(root->data);
    printpathSumK(root->pLeft,vt,k);
    printpathSumK(root->pRight, vt,k);
    int sum = 0;
    for(int j = vt.size() - 1 ; j >= 0; j--)
    {
        sum+=vt[j];
        if(sum == k)
        {
            for(int i = j ; i <vt.size(); i++)
            {
                cout<<vt[i]<<" ";
            }
            cout<<endl;
        }
    }
    vt.pop_back();
}
void PrintPathwithgivSum(NodeTree* root, int k)
{
    stack<NodeTree*>st;
    if(root==NULL) return;
    int sum = sum + root->data;
    if(sum==k)
    {
        // print stack
    }
    PrintPathwithgivSum(root->pLeft, k);
    PrintPathwithgivSum(root->pRight, k);
}
/*void printStack(stack<NodeTree*>st)
{
    while(!st.empty())
    {
        cout<<st.top()->data<<" ";
        st.pop();
    }
    cout<<endl;
}
 stack<NodeTree*>st;
void PrintAllPathRoottoleaf(NodeTree* root)
{
    if(root==NULL)
     return;
     st.push(root);
     if(root->pLeft==NULL && root->pRight==NULL)
     {
        printStack(st);
        st.pop();
     }
    PrintAllPathRoottoleaf(root->pLeft);
    PrintAllPathRoottoleaf(root->pRight);
}*/
/*int minNode(NodeTree* root)
{
    if(!root) return;
    stack<NodeTree*>s;
    s.push(root);
    int minVal = INT_MAX;
    while(!s.empty())
    {
        NodeTree* tmp = s.top(); s.pop();
        if(tmp->data < minVal)
             minVal = tmp->data;
        if(tmp->pLeft) s.push(tmp->pLeft);
        if(tmp->pRight) s.push(tmp->pRight);
    }
    return minVal;
}*/
int main()
{
    
    NodeTree* root = CreateNode(1);
    root->pLeft = CreateNode(2);
    root->pRight = CreateNode(3);
    root->pLeft->pLeft = CreateNode(4);
    root->pLeft->pRight = CreateNode(5);
    root->pRight->pLeft = CreateNode(6);
    root->pRight->pRight = CreateNode(7);
    int k =5;
    vector<int>vt;
    printpathSumK(root,vt,k);
     return 0;
}