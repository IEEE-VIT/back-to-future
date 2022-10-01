// Binary Tree Algorithm in C++

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *NewNode(int data)
{
    // your code goes here
}

Node *Insert(Node *node, int data)
{
    // your code goes here
}

Node *PrintTree(Node *node)
{
    // your code goes here
}

int main()
{
    Node *root = NewNode(100);
    Insert(root, 50);
    Insert(root, 150);
    Insert(root, 25);
    PrintTree(root);
}
