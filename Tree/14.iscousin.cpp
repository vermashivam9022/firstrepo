#include<bits/stdc++.h>
using namespace std;

// Node structure
class Node
{   public:
    int data;
    Node *left, *right;
    Node(int item)
    {
        data = item;
        left = right = nullptr;
    }
};
  bool isSibling(Node* root, int x, int y) {
    // Check if the two nodes are siblings (share the same parent)
    if (!root) return false;
    if (root->left && root->right) {
        if ((root->left->data == x && root->right->data == y) ||
            (root->left->data == y && root->right->data == x)) {
            return true;
        }
    }
    // Recur for left and right subtrees
    return isSibling(root->left, x, y) || isSibling(root->right, x, y);
}

bool isCousins(Node* root, int x, int y) {
    if (!root) return false;

    queue<Node*> q;
    q.push(root);

    vector<int> levelv(2, -1); // To store levels of x and y
    int level = 0;

    // BFS to find levels of x and y
    while (!q.empty()) {

        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            if (temp->data == x) levelv[0] = level;
            if (temp->data == y) levelv[1] = level;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        level++;
        
        if(levelv[0]!=levelv[1]) return false;          //if one of the node found at some level so second not cant be on another level
        if (levelv[0] != -1 && levelv[1] != -1) break; // Exit early if both levels are found
    }
    
     

    // Check if x and y are at the same level but not siblings
    return !isSibling(root, x, y);
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
    
    int x, y;
    cout << "Enter two nodes: ";
    cin >> x >> y;
    
    if (isCousins(root, x, y))
        cout << "The nodes are cousins." << endl;
    else
        cout << "The nodes are not cousins." << endl;

    return 0;
}