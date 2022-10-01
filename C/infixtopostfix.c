// Infix to Postfix Conversion using Stack in C

#include <stdio.h>

void infixToPostfix(char *infix)
{
    // your code goes here
}
int main()
{
    char expression[100] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(expression);
    return 0;
}

// Output
// abcd^e-fgh*+^*+i-