#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data=d;
        this->next=nullptr;
    }
    Node(int d, Node* n)
    {
        this->data=d;
        this->next=n;
    }

};

Node* convertArrayToLL(vector<int> &arr)
{
    if(arr.size()==0)
    {
        Node* head=nullptr;
        return head;
    }
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* NewNode=new Node(arr[i]);
        temp->next=NewNode;
        temp=NewNode;
    }
    return head;
}

void printLL(Node* temp)
{
    if(temp==nullptr) cout << "Can't print LL...LL is empty" << endl;
    while(temp)
    {
        cout << temp->data << " ";                                //   (*temp).data << endl;
        temp=temp->next;
    }
    cout  << endl;
    
}

int lengthOfLL(Node* head)
{
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

int search(Node* head, int n)
{
    while(head)
    {
        if(head->data==n)return 1;
        head=head->next;
    }
    return 0;
    
}
Node* insertLast(Node* head,int data)
{
    if(head==nullptr){
        head=new Node(data);
        return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=new Node(data);
    return head;
}

Node* insertFront(Node* head,int data)
{
    Node* newNode= new Node(data);
    if(head==nullptr)return newNode;
    newNode->next=head;
    return newNode;
}

Node* insertAtPos(Node* head,int data,int pos)
{
    Node* newNode= new Node(data);
    if(head==nullptr)
    {
        if(pos==1)
            return newNode;
        else
        {
            cout << "At given pos insertion can't be done" << endl;
            return head;
        }    
    } 
    if(pos==1)
    {
        newNode->next=head;
        return newNode;
    }
    Node* temp=head;
    int c=0;
    while(temp!=nullptr)
    {
        c++;
        if(c==pos-1)
        {
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    if(temp==nullptr)
        cout << "Insertion cant be done at given pos: ";
    
    return head;
}

Node* insertBeforevalue(Node* head,int data,int val)
{
    if(head==nullptr)
    {
        cout << "given value is not present..insertion can't be done ";
        return head;
    } 
    Node* newNode= new Node(data);
    if(head->data==val)
    {
        newNode->next=head;
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        if(temp->next->data==val)
        {
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    if(temp->next==nullptr)
        cout << "Insertion cant be done as given value is not present: ";
    
    return head;
}


Node* deletefront(Node* head)
{
    if(head==nullptr) cout << "LL is Empty..Deletion can't perfomed" << endl;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* deleteEnd(Node* head)
{
    if(head==nullptr){
        cout << "LL is empty..Deletion can't performed" << endl;
        return head;
    }
    if(head->next==nullptr)
    {
        delete head;
        head=nullptr;
        return head;
    }
    Node* temp=head;
    while (temp->next->next)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
Node* deleteAtPos(Node* head,int pos)
{

    if(head==nullptr){
        cout << "LL is empty..Deletion can't performed" << endl;
        return head;
    }
    if(pos==1)
    {
        Node* temp=head;
        head=head->next;       
        delete temp;
        return head;
    }
    Node* temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    Node* deletenode=temp->next;
    temp->next=deletenode->next;
    delete deletenode;
    return head;
}


Node* deletetheValue(Node* head,int data)
{
    if(head==nullptr){
        cout << "LL is empty..Deletion can't performed" << endl;
        return head;
    }
    if(head->data==data)
    {
        Node* temp=head;
        head=head->next;       
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* pre=nullptr;
    while(temp!=nullptr)
    {
        if(temp->data==data)
        {   
            pre->next=temp->next;
            delete temp;
            break;
        }
        pre=temp;
        temp=temp->next;
    }
    if(pre->next==nullptr)cout << data<<" is not found..can't delete !! ";
    return head;
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9};

    Node* head=convertArrayToLL(arr);

    printLL(head);

    cout << "length of LL:"<<lengthOfLL(head) << endl;  
    cout << "90 is presnt or not:"<< search(head,90) << endl;

    cout << "Insert 10 at end: ";
    head=insertLast(head,10);
    printLL(head);

    cout << "Insert 50 at front: ";
    head=insertFront(head,50);
    printLL(head);

    cout << "Insert 100 at pos 15: ";
    head=insertAtPos(head,100,15);
    printLL(head);


    cout << "Insert 100 at pos 3: ";
    head=insertAtPos(head,100,3);
    printLL(head);

    cout << "Insert 200 at before 90: ";
    head=insertBeforevalue(head,200,90);
    printLL(head);

    cout << "Insert 200 at before 10: ";
    head=insertBeforevalue(head,200,10);
    printLL(head);
    
    cout << "Delete Front eleement: ";
    head=deletefront(head);
    printLL(head);

    cout << "Delete last eleement: ";
    head=deleteEnd(head);
    printLL(head);

    cout << "Delete eleement at Pos 3 : ";
    head=deleteAtPos(head,3);
    printLL(head);

    cout << "Delete eleement 100 : ";
    head=deletetheValue(head,100);
    printLL(head);

    cout << "Delete eleement 4 : ";
    head=deletetheValue(head,4);
    printLL(head);

    cout << "Delete eleement 50 : ";
    head=deletetheValue(head,50);
    printLL(head);

    return 0;

}