#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
void index(Node* root,int &l,int &r,int base)
    {
        if(root==NULL)
            return;
        l=min(l,base);
        r=max(r,base);
        index(root->left,l,r,base-1);
        index(root->right,l,r,base+1);
    }
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
vector<int> topView(Node *root) {
    // code here
    
    Node* temp=root;
    int l_index=0;
    int r_index=0;
    
    index(root,l_index,r_index,0);      // calculate leftmostindex and rightmostindex
    
    
    int size=r_index - l_index + 1;
    
    vector<int> ans(size);
    vector<int>visited(size,0);
    
    
    int base_index=abs(l_index);     //base index for root node in vector ans  eg.. suppose l=-2 then root node will be on 2 index &  l=-2 node will be on 0;
    
    queue<pair<Node*,int>> q;               
    q.push({root,base_index});
    
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node *tmp=q.front().first;
            int b_index=q.front().second;
            q.pop();
            
            if(visited[b_index]==0)
            {
                visited[b_index]=1;
                ans[b_index]=tmp->data;
            }
            
            if(tmp->left)
                q.push({tmp->left,b_index-1});
            if(tmp->right)
                q.push({tmp->right,b_index+1});
        }
        
    }
    
    return ans;
    
}

Node* BTree()
{
    int x;
    cin >> x;
    if(x==-1)
        return nullptr;
    Node* root = new Node(x);                           // create root node

    cout <<"enter left child of " <<root->data <<" :";
    root->left = BTree();
        
    cout <<"enter Right child of " <<root->data <<" :";
    root->right = BTree();

    return root;
}

int main()
{
    //your code here
    cout << "Enter the Root Elements of the tree: ";
    Node* root = BTree(); 

    cout << "Top view of the tree is: ";
    vector<int> top_view = topView(root);
    for(int i=0;i<top_view.size();i++)
        cout << top_view[i] << " ";
    cout << endl;  // print top view traversal of tree.
    return 0;
}