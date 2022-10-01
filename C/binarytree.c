// Binary Tree Implementation in C

#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *NewNode(int data)
{
    // your code goes here
}

void PrintTree(struct node *root)
{
    // your code goes here
}

void Insert(struct node *root, int data)
{
    // your code goes here
}

int main()
{
    struct node *root = NewNode(100);
    Insert(root, 50);
    Insert(root, 200);
    Insert(root, 25);

    PrintTree(root);
    return 0;
}
