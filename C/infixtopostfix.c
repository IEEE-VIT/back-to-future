// Infix to Postfix Conversion using Stack in C

#include <stdio.h>

void InfixToPostfix(char *infix)
{
    // your code goes here
    // print the postfix expression
}
int main()
{
    char expression[100] = "a+b*(c^d-e)^(f+g*h)-i";
    InfixToPostfix(expression);
    return 0;
}

// Output
// abcd^e-fgh*+^*+i-