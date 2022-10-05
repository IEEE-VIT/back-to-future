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
void display(node* &head)
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

//Reversing a linked list Iteratively 
node* recreverse(node* &head)
{

    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    node* newhead = recreverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

//Reversing a linked list iteratively
node* itreverse(node* &head)
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


//Reversing K elements of a linked list
//Concept: The idea revolves around reversing the first k elements of a linked list iteratively and then recursively calling the function where we would pass the new linked list.
node* kreverse(node* &head, int k)
{
    //Reversing the first K nodes.
    node* prev = NULL;
    node* curr = head;
    node* nxt;

    int c = 0; //Counter variable for only reversing k elements in the linked list.

    while(c<k && curr!=NULL)
    {   
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        c++;
    }

    //Boundary condition.
    if(nxt!=NULL)
    {
        //Recursively calling the function by passing the rest of the unreversed linked list whose node is denoted by the next pointer.
        head->next = kreverse(nxt, k);
    }

    return prev;
}

int main()
{   
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    int k;
    cin>>k;

    display(head);
    cout<<endl;

    node* newhead = kreverse(head, k);

    display(newhead);

    return 0;

}