// Infix to Postfix Conversion using Stack in C++

#include <iostream>

using namespace std;

string InfixToPostfix(string expression)
{
    // your code goes here
    // return the postfix expression
}

int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    cout << InfixToPostfix(expression) << endl;
}

// Output
// abcd^e-fgh*+^*+i-