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

void InorderTraversal(Node* root)    //o(n)
{
    if (root == nullptr)
        return;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

void preOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

 // Function to return the level order traversal of a tree.
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        
        if(root==NULL)
            return {};
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int> current_level;
            
            for(int i=0;i<size;i++)
            {
                Node *temp=q.front();
                q.pop();
                current_level.push_back(temp->data);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            ans.push_back(current_level);
            
        }
        
        return ans;
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


void printArray(vector<int> arr)
{   cout << "[";
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << "]" << ",";
}
void priny2DArray(vector<vector<int>> arr)
{
    int n=arr.size();
    cout << "[";
    for(int i=0;i<n;i++)
    {
        printArray(arr[i]);
    }
    cout << "]" << endl;
}
int main()
{
    //Tree creation
    cout << "Enter the Root Element: ";
    Node* root =BTree(); 

    /*
            1
        2       3
     4     5   

    */

    cout << "\nInorder traversal: ";
    InorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Level order traversal: ";
    vector<vector<int>> ans=levelOrder(root);
    priny2DArray(ans);
    cout << endl;

    return 0;
}

