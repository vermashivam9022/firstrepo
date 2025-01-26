#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d)
        {
            data=d;
            next=nullptr;
        }
    Node(int d, Node* n)
    {
        data=d;
        next=n;
    }
};

Node* convertArrayToNode(vector<int> arr)
{
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* temp;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
    
}


int main()
{
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArrayToNode(arr);

    return 0;
}