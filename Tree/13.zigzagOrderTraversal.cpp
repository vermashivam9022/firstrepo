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

vector<int> findSpiral(Node* root)
 {
    // code here

    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    int level=0;

    while(!q.empty())
    {
        vector<int> current_level;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* temp=q.front();
            q.pop();
            current_level.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push (temp->right);
            
        }
        
        if(level%2==0)
            reverse(current_level.begin(),current_level.end());
        ans.insert(ans.end(),current_level.begin(),current_level.end());
        
        level++;
        
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

void printVector(vector<int>& v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    
    cout << "Enter the Root Elements of the tree: ";
    Node* root = BTree(); 
    
    vector<int> spiral_order = findSpiral(root);
    cout << "Spiral Order traversal: ";
    printVector(spiral_order);
    return 0;
}