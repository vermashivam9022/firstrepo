#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int x)                           //constuctor to get value of x
    {
        data = x;
        left = right = nullptr;
    }
};

int countLeaves(Node* root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
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
    Node* root =BTree(); 

    cout << "Number of Leaves in the tree is: " << countLeaves(root) << endl;
    return 0;
}