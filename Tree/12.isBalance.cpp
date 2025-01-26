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

int height(Node *root,bool &valid)
   {
       if(root==NULL)
        return -1;

       int l=height(root->left,valid);
       int r=height(root->right,valid);
       
       if(abs(l-r)>1)
            valid=false;
       return 1+max(l,r);
   }
   
   
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node* root) {
        // Code here
        bool valid=true;
        height(root,valid);
        return valid;
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
    
    cout << "Is the tree balanced? " << (isBalanced(root)? "Yes" : "No") << endl;  // Call the function and print the result.
    return 0;
}