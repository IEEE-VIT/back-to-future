// Binary Tree Implementation in C

#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    // your code goes here
}

void PrintTree(struct node *root)
{
    // your code goes here
}

void insert(struct node *root, int data)
{
    // your code goes here
}

int main()
{
    struct node *root = newNode(100);
    insert(root, 50);
    insert(root, 200);
    insert(root, 25);

    PrintTree(root);
    return 0;
}
