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
int height(struct Node* node) {
        if(node==NULL)
            return 0;
        if(node->left==NULL && node->right==NULL)
            return 0;
        return 1+ max(height(node->left),height(node->right));
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

    cout<< "Height of Given Tree is :"<< height(root)<<endl;
    return 0;
}