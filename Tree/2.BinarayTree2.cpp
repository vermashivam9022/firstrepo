#include<bits/stdc++.h>
using namespace std;

// construct the tree with this sequence first create all left child ten only right chile
/*
eg,.        5 2 3 -1 -1 6 -1 -1 -1

       `    5
         2     -1
      3     6
   -1 -1  -1 -1
*/

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


// Function to print Tree
void printInorder(Node *root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    cout << "Enter the Root Element: ";
    Node* root =BTree();


    cout << "Inorder traversal of the constructed tree is: \n";
    printInorder(root);
    return 0;

    return 0;
}