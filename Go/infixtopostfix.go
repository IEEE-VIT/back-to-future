// Infix to Postfix Conversion using Stack in Golang

package main

import (
	"fmt"
)

func main() {
	var infix string = "a+b*(c^d-e)^(f+g*h)-i"
	fmt.Println("Infix Expression: ", infix)
	fmt.Println("Postfix Expression: ", infixToPostfix(infix))
}

func infixToPostfix(infix string) string {
	// your code here
	return "" // change this to return the postfix expression
}

// Output:
// Infix Expression:  a+b*(c^d-e)^(f+g*h)-i
// Postfix Expression:  abcd^e-fgh*+^*+i-
