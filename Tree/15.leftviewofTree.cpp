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

// Function to print left view traversal of tree

vector<int> leftView(Node *root) 
{
    if(!root)
        return {};
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        int size=q.size();
        ans.push_back(q.front()->data);
        
        for(int i=0;i<size;i++)
        {
            Node * temp=q.front();
            q.pop();
        
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }      
    }
    return ans;
}

vector<int> rightView(Node *root)
{
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    
    while(!q.empty())
    {
        int size=q.size();
        ans.push_back(q.back()->data);
        
        for(int i=0;i<size;i++)
        {
            Node* temp=q.front();
            q.pop();
            
            if(temp->left)
                 q.push(temp->left);
            if(temp->right)
                 q.push(temp->right);
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

    cout << "Left view of the tree is: ";
    vector<int> left_view = leftView(root);
    for(int i=0;i<left_view.size();i++)
        cout << left_view[i] << " ";
    cout << endl;  // print left view traversal of tree.

    cout << "Right view of the tree is: ";
    vector<int> right_view = rightView(root);
    for(int i=0;i<right_view.size();i++)
        cout << right_view[i] << " ";
    cout << endl;  // print right view traversal of tree.


    return 0;
}