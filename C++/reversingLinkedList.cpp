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
    node* prev = NULL;      //Creating a previous pointer which would point towards the node before the current node and initialising it to NULL.
    node* curr = head;      //Creating the current pointer which will point to the current node and initialising it to the passed head.
    node* nxt = curr->next;     //Creating the next pointer that would point to the next node of the current node.

    while(curr!=NULL)
    {
        nxt = curr->next;       //Initialising the nxt node to the next node of the current node to traverse over the linked list.
        curr->next = prev;      //Changing the link of the current node to that of the previous node.
        
        prev = curr;        //Making the previous node the current node.
        curr = nxt;         //Making the current node the next node.
    }

    return prev;        //By the time the while loop terminates, the current node would become NULL and the previous node will become the new head of the reversed linked list.
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