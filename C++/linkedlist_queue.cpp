#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node* back;

public:
    Queue()
    {
        front = back = NULL;
    }

    void enqueue(int val){
        Node* temp = new Node(val);

        if(front == NULL){
            back = front = temp;
            return;
        }

        back->next = temp;
        back = temp;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow \n";
        }

        Node* toDelete = front;
        front = front->next;

        delete toDelete;
    }

    int peek(){
        if(isEmpty()){
            cout << "Queue Underflow \n";
            return INT_MAX;
        }

        return front->data;
    }

    bool isEmpty(){
        if(front == NULL){
            return 1;
        }
        return 0;
    }
};

int main()
{
    Queue q;
    for (int i = 1; i <= 3; i++)
    {
        q.enqueue(i);
    }
    cout << "Front of the element is: " << q.peek() << endl;
    q.dequeue();
    cout << "Front of the element is: " << q.peek() << endl;
    q.dequeue();
    cout << "Front of the element is: " << q.peek();
    q.dequeue();

    return 0;
}