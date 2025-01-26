#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

int countNonLeafNodes(Node *root)
{
    if(root == nullptr)
        return 0;

    //leaf nodes
    if(root->left == nullptr && root->right == nullptr)
        return 0;

    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    
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
    //Tree creation
    cout << "Enter the Root Element: ";
    Node* root = BTree();

    cout << "Number of non-leaf nodes in the tree is: " << countNonLeafNodes(root) << endl;
    return 0;
}