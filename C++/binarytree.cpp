// Binary Tree Algorithm in C++

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    // your code goes here
}

Node *insert(Node *node, int data)
{
    // your code goes here
}

Node *printTree(Node *node)
{
    // your code goes here
}

int main()
{
    Node *root = newNode(100);
    insert(root, 50);
    insert(root, 150);
    insert(root, 25);
    printTree(root);
}
