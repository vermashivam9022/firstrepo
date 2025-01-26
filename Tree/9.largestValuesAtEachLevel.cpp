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
int maximum(vector<int> v)
    {
        int max=INT_MIN;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>max)
                max=v[i];
        }
        return max;
    }
vector<int> largestElements(Node * root)
{
    if(root==NULL)
            return {};
        queue<Node*> q;
        q.push(root);
        
        vector<int> ans;
        
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
                    q.push(temp->right);
            }
            
            ans.push_back(maximum(current_level));
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
int main()
{
    //Tree creation
    cout << "Enter the Root Element: ";
    Node* root =BTree(); 

    vector<int> largestElement = largestElements(root);

    //Printing largest elements in the tree at Each Level
    cout << "Largest elements at ecah level in the tree are: ";
    for (int i = 0; i < largestElement.size(); i++)
        cout << largestElement[i] << " ";
    cout << endl;


    return 0;
}