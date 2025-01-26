#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* pre;
    Node* next;

    Node(int d){
        data=d;
        pre=nullptr;
        next=nullptr;
    }

    Node(int d,Node* p,Node* n)
    {
        data=d;
        pre=p;
        next=n;
    }
};


Node* ConvertArrayToDLL(vector<int> &arr)
{
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        newNode->pre=temp;
        temp=temp->next;
    }
    return head;

}

void printDLL(Node* head)
{
    if(head==nullptr) cout << "DLL IS EMPTY.." << endl;
    while (head)
    {
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

Node* reverseDLL(Node* head)
{
    Node* last=head->pre;
    Node* curr=head;

    while(curr)
    {   
        last=curr->pre;
        curr->pre=curr->next;
        curr->next=last;
        curr=curr->pre;
    }
    if (last!=nullptr)
        head=last->pre;
    return head;

}

int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9};

    Node* head=ConvertArrayToDLL(arr);
    printDLL(head);
    head=reverseDLL(head);
    printDLL(head);


    return 0;
}