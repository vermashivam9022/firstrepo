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


// function to find no of node ----------------------------------------------------------------
int getsize(Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + getsize(root->left) + getsize(root->right);
}


// function to create a Tree----------------------------------------------------------------
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
    //Tree creation
    cout << "Enter the Root Element: ";
    Node* root =BTree(); 

    cout<< "No of Node in Given Tree is :"<< getsize(root)<<endl;

    
    return 0;
}