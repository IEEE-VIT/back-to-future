#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;

        node(int val)
        {
            data = val;
            next = NULL;
        }
}; 

//Insertion
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);

    if(head==NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = n;

    return;
}

//Printing
void display(node*head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";

    return;
}

//Searching
bool search(node* &head, int key)
{
    node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


//Deletion
void deleteAtHead(node* &head)
{
    node* todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(node* &head, int val)
{
    if(head==NULL)
    {
        return;
    }

    if(head->next==NULL)
    {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val)
    {
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node* reverse(node* &head)
{

    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    node* newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

int main()
{   
    //Creating the linked list.
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    //Displaying the initial linked list.
    display(head);
    cout<<endl;

    //Creating the new head of the reversed linked list.
    node* newhead = reverse(head);
    display(newhead);
    cout<<endl;

    return 0;
}