#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    // Function to add node at front
    void addAtFront(Node *n)
    {
        n->next = head;
        head = n;
    }

    // Function to check whether the list is Empty
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    // Function to add note at the end
    void addAtEnd(int num)
    {
        Node *n = new Node(num);
        if (head == NULL)
        {
            head = n;
            n->next = NULL;
        }
        else
        {
            Node *n2 = getLastNode();
            n2->next = n;
        }
    }

    // Function To Get the last node
    Node *getLastNode()
    {
        Node *ptr = head;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        return ptr;
    }

    // Function To Search a Value
    Node *search(int k)
    {
        Node *ptr = head;

        while (ptr != NULL && ptr->data != k)
        {
            ptr = ptr->next;
        }
        return ptr;
    }

    // Function To Delete Any Node
    Node *deleteNode(int x)
    {
        Node *n = search(x);
        Node *ptr = head;

        if (ptr == n)
        {
            head = n->next;
            return n;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n->next;
            return n;
        }
    }

    // Function to Reverse a Linked List
    // Iterative Method
    void reverseList()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nextPtr;

        while (curr != NULL)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        head = prev;
    }
    // Recursive Method
    Node *reverseListRecursively(Node *n)
    {
        if (n == NULL)
        {
            return NULL;
        }
        if (n->next == NULL)
        {
            head = n;
            return n;
        }
        Node *ptr = reverseListRecursively(n->next);
        ptr->next = n;
        n->next = NULL;

        return n;
    }

    // Function to reverse 'k' nodes in a Linked List
    Node *reverseK(Node *n, int k)
    {
        Node *prev = NULL;
        Node *curr = n;
        Node *nextPtr = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;

            count++;
        }

        if (nextPtr != NULL)
        {
            n->next = reverseK(nextPtr, k);
        }

        head = prev;
        return prev;
    }

    // Funtion To Print List Nodes
    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    // Returns the size of the Linked List
    int length()
    {
        int l = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }

    // Appends the last K Nodes to the Front of the Linked List
    void append_Last_K_Nodes(int k)
    {
        int n = length();
        int count = 0;

        Node *newHead;
        Node *newTail;
        Node *tail = head;

        k = k % n; // If k>n

        while (tail->next != NULL)
        {
            if (count == n - k - 1)
            {
                newTail = tail;
            }
            if (count == n - k)
            {
                newHead = tail;
            }
            tail = tail->next;
            count++;
        }

        newTail->next = NULL;
        tail->next = head;
        head = newHead;
    }

    // Function to intersect 2 Linked Lists
    void intersect(LinkedList l, int pos)
    {
        Node *temp1 = head;
        pos--;
        while (pos--)
        {
            temp1 = temp1->next;
        }

        Node *temp2 = l.head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }

    // Find intersection of 2 linked Lists
    // Time Complexity of this function is: O(max(n,m)
    int findIntersection(LinkedList l)
    {
        int n = length();
        int m = l.length();

        int diff;
        Node *ptr1;
        Node *ptr2;
        if (n > m)
        {
            diff = n - m;
            ptr1 = head;
            ptr2 = l.head;
        }
        else
        {
            diff = m - n;
            ptr1 = l.head;
            ptr2 = head;
        }

        while (diff)
        {
            ptr1 = ptr1->next;
            if (ptr1 == NULL)
            {
                return -1;
            }
            diff--;
        }

        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1 == ptr2)
            {
                return ptr1->data;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return -1;
    }

    // Put Even Position Nodes After Odd Poition Nodes
    void evenNodesAfterOddNodes()
    {
        Node *oddPtr = head;
        Node *evenPtr = head->next;
        Node *evenStrt = evenPtr;

        while (oddPtr->next != NULL && evenPtr->next != NULL)
        {
            oddPtr->next = evenPtr->next;
            oddPtr = oddPtr->next;

            evenPtr->next = oddPtr->next;
            evenPtr = evenPtr->next;
        }

        oddPtr->next = evenStrt;
        if (oddPtr->next == NULL)
        {
            evenPtr->next = NULL;
        }
    }

    // Merge 2 Sorted Linked Lists
    LinkedList mergeSortedLists(LinkedList l)
    {
        LinkedList ans;
        Node *ptr1 = head;
        Node *ptr2 = l.head;
        Node *dummyNode = new Node(-1);
        Node *ptr3 = dummyNode;

        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->data < ptr2->data)
            {
                ptr3->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr3->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr3 = ptr3->next;
        }

        while (ptr1 != NULL)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        while (ptr2 != NULL)
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }

        ans.head = dummyNode->next;
        return ans;
    }

    // Constructor
    LinkedList()
    {
        head = NULL;
    }
};

int main()
{
    LinkedList l;
    l.addAtEnd(1);
    l.addAtEnd(4);
    l.addAtEnd(2);
    l.addAtEnd(5);
    cout << l.search(5)->data;
    l.display();

    return 0;
}