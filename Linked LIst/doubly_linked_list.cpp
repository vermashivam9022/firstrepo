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

Node* insertAtFront(Node* head,int data)
{
    Node* newNode=new Node(data);
    if(head==nullptr)return newNode;
    newNode->next=head;
    head->pre=newNode;
    return newNode;
}

Node* insertAtEnd(Node* head,int data)
{
    Node* newNode=new Node(data);
    if(head==nullptr)return newNode;
    Node* temp=head;
    while (temp->next)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->pre=temp;
    return head;
}

Node* insertAtPos(Node* head, int data, int pos)
{
    Node* newNode = new Node(data);

    // Case 1: Insert at the beginning
    if (pos == 1)
    {
        newNode->next = head;
        if (head != nullptr)
            head->pre = newNode;
        return newNode;  // New node becomes the head
    }

    Node* temp = head;
    int c = 1;

    // Traverse to the node just before the insertion position
    while (temp != nullptr && c < pos - 1)
    {
        temp = temp->next;
        c++;
    }

    // If temp is nullptr, position is out of bounds
    if (temp == nullptr)
    {
        cout << "Position " << pos << " exceeds the length of the list" << endl;
        delete newNode;
        return head;
    }

    // Case 2: Insert in between nodes or at the end
    newNode->next = temp->next;
    newNode->pre = temp;

    if (temp->next != nullptr)
    {
        temp->next->pre = newNode;
    }
    temp->next = newNode;

    return head;
}

Node* deleteFront(Node* head)
{
    if(head==nullptr)
    {
        cout << "DLL Is empty..can't delete" << endl;
        return head;
    }
    if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    head=head->next;
    delete head->pre;
    head->pre=nullptr;
    return head;
}

Node* deleteEnd(Node* head)
{
    if(head==nullptr)
    {
        cout << "DLL Is empty..can't delete" << endl;
        return head;
    }
    if(head->next==nullptr)
    {
        delete head;
        return nullptr;
    }
    Node* temp=head;
    while (temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next->pre=nullptr;
    delete temp->next;
    temp->next=nullptr;
    return head;
    
}


Node* DeleteAtPos(Node* head,int k)
{
    if(head==nullptr)
        {
            cout << "DLL Is empty..can't delete" << endl;
            return head;
        }
    if(head->next==nullptr)
    {
        if(k==1)
        {
            delete head;
            return nullptr;
        }
        else
        {
            cout << "Deletion is not possible at giv pos: ";
            return head;
        }
    }
    Node* temp=head;
    int c=1;
// Traverse to the k-th node
    while (temp != nullptr && c < k)
    {
        temp = temp->next;
        c++;
    }

    if (temp == nullptr)
    {
        cout << "Position " << k << " exceeds the length of the list: ";
        return head;
    }
    Node* back=temp->pre;
    Node* front=temp->next;


// Case 1: Deleting the head node
    if(back==nullptr)
        {
            head = temp->next;  // Move head to the next node
            if (head != nullptr)
                head->pre = nullptr;
            delete temp;
        }
// Case 2: Deleting a middle node
    else if(back!=nullptr && front!=nullptr)
    {
        back->next=front;
        front->pre=back;
        temp->pre=temp->next=nullptr;
        delete temp;
    }
 // Case 3: Deleting the last node
    else
    {
        back->next=nullptr;
        temp->pre=nullptr;
        delete temp;

    }
    return head;
}

int main()
{
    //your code here
    vector<int> arr={};
    Node* head=ConvertArrayToDLL(arr);
    printDLL(head);

    // cout << "Insert 10 at Front: ";
    // head=insertAtFront(head,10);
    // printDLL(head);
    // return 0;

    // cout << "Insert 10 at End: ";
    // head=insertAtEnd(head,10);
    // printDLL(head);

    // cout << "Delete from Front: ";
    // head=deleteFront(head);
    // printDLL(head);

    // cout << "Delete from End: ";
    // head=deleteEnd(head);
    // printDLL(head);

    // cout << "Delete from pos 5: ";
    // head=DeleteAtPos(head,5);
    // printDLL(head);

    cout << "Insert 500 at Pos5 : ";
    head=insertAtPos(head,500,1);
    printDLL(head);


    return 0;
}