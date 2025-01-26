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

void mirrorImage(Node* root)
{
    if(root == nullptr)
        return;

    // Swap left and right child
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Mirror the left subtree
    mirrorImage(root->left);

    // Mirror the right subtree
    mirrorImage(root->right);
}

void Inorder(Node* root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main()
{
    //your code here
    cout << "Enter the Root Elements: ";
    Node* root = BTree(); 

    cout << "Inorder traversal of the original tree is: ";
    Inorder(root);
    cout << endl;



    mirrorImage(root);
    cout << "Inorder traversal of the mirrored tree is: ";
    Inorder(root);
    cout << endl;

    return 0;
}