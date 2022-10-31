#include <iostream>
using namespace std;

struct node {
    char data;
    struct node* right;
    struct node* left;
};

struct node* newNode(char data=' ', struct node* left=NULL, struct node* right=NULL) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = left;
    n->right = right;
    return n;
}

void inorder_pre(struct node* n) {
    if(n == NULL) return;
    inorder_pre(n->left);
    cout<<n->data<<" ";
    inorder_pre(n->right);
}

void inorder_post(struct node* n) {
    if(n == NULL) return;
    inorder_post(n->right);
    cout<<n->data<<" ";
    inorder_post(n->left);
}

struct stack_node {
    struct node* n;
    struct stack_node* next;
};

struct stack_node* newStackNode(struct node* n, struct stack_node* next=NULL) {
    struct stack_node* s;
    s = (struct stack_node*)malloc(sizeof(struct stack_node));
    s->n = n;
    s->next = next;
    return s;
}

class Stack {
    struct stack_node* top;
    public:
        Stack() {
            top = NULL;
        }

        void push(struct node* n) {
            top = newStackNode(n, top);
        }

        void pop() {
            if (top == NULL) return;
            struct stack_node *p = top;
            top = top->next;
            free(p);
        }

        struct node* peek() {
            return top->n;
        }
};


int eval_pre(struct node* root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return (int)(root->data)-48; 
    int l_val = eval_pre(root->left);
    int r_val = eval_pre(root->right);
    if (root->data == '+')
        return l_val+r_val;
    if (root->data == '-')
        return l_val-r_val;
    if (root->data == '*')
        return l_val*r_val;
    return l_val/r_val;
}

int eval_post(struct node* root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return (int)(root->data)-48; 
    int l_val = eval_post(root->right);
    int r_val = eval_post(root->left);
    if (root->data == '+')
        return l_val+r_val;
    if (root->data == '-')
        return l_val-r_val;
    if (root->data == '*')
        return l_val*r_val;
    return l_val/r_val;
}


int main() {
    Stack s;
    int choice, size;
    cin>>choice>>size;
    struct node *x,*y;
    char pe[40];
    if (choice == 1) {
        for (int i=0; i<size; i++) {
            cin>>pe[i];
            if (isalnum(pe[i])) {
                s.push(newNode(pe[i]));
            }
            else {
                x = s.peek();
                s.pop();
                y = s.peek();
                s.pop();
                s.push(newNode(pe[i],x,y));
            }
        }
        inorder_post(s.peek());
        cout<<endl<<eval_post(s.peek())<<endl;
    }
    else if (choice == 2) {
        for (int i=0; i<size; i++)
            cin>>pe[i];
        for (int i=size-1; i>=0; i--) {
            if (isalnum(pe[i])) {
                s.push(newNode(pe[i]));
            }
            else {
                x = s.peek();
                s.pop();
                y = s.peek();
                s.pop();
                s.push(newNode(pe[i],x,y));
            }
        }
        inorder_pre(s.peek());
        cout<<endl<<eval_pre(s.peek())<<endl;
    }
    return 0;
}