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

// Function to print Tree
void printInorder(Node *root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Function to create a tree

Node * BuildTree()
{
    int x;
    cout << "enter the Root Element: " << endl;
    cin >> x;
    if(x==-1)
        return nullptr;
    Node* root = new Node(x);                               //create root node

    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        cin >> x;

        if(x!=-1)                                               // if -1 the  child is null
        {
            temp->left = new Node(x);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        cin >> x;

        if(x!=-1)
        {
            temp->right = new Node(x);
            q.push(temp->right);
        }
    }
}
int main()
{
    //your code here
    Node* root=BuildTree();
    
    cout << "Inorder traversal of the constructed tree is: \n";
    printInorder(root);
    return 0;
}