// Binary Tree Algorithm in C++

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    //defining constructor
    Node(int d){
        this->data=d;
        this -> left = NULL;
        this -> right = NULL;
    }

};

Node *NewNode(int data)
{
    Node* temp=new Node(data);
    return temp;
}

Node *Insert(Node *node, int data)
{
    
    if(data == -1) {
        return NULL;
    }

    Node* temp=new Node(data);
    node->left=temp;
    return node;
    
}

Node *PrintTree(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            
            cout << endl;
            if(!q.empty()) { 
              
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

int main()
{
    Node *root = NewNode(100);
    Insert(root, 50);
    Insert(root, 150);
    Insert(root, 25);
    PrintTree(root);
}
