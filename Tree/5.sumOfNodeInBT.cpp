#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

int sumBT(Node* root)
{
    if (root == nullptr)
        return 0;
    return root->data + sumBT(root->left) + sumBT(root->right);
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

    cout << "Sum of all nodes in the tree is: " << sumBT(root) << endl;


    return 0;
}