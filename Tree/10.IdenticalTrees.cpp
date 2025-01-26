#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == nullptr && r2 == nullptr)
        return true;
    if((r1!=nullptr && r2==nullptr)||(r1==nullptr && r2!=nullptr))
        return false;
    if(r1->data == r2->data)
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    return false;
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
    cout << "Enter the Root Elements of the first tree: ";
    Node* root1 = BTree(); 

    cout << "Enter the Root Elements of the second tree: ";
    Node* root2 = BTree();
    
    cout << "Are the two trees identical? " << (isIdentical(root1, root2)? "Yes" : "No") << endl;
    return 0;
}