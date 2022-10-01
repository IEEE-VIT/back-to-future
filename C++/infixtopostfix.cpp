// Infix to Postfix Conversion using Stack in C++

#include <iostream>

using namespace std;

int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(expression) << endl;
}

string infixToPostfix(string expression)
{
    // your code goes here
}

// Output
// abcd^e-fgh*+^*+i-