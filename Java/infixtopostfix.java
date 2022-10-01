// Infix to Postfix Conversion using Stack in Java

import java.util.Stack;

public class infixtopostfix {
    // Infix expressio
    static String exp = "a+b*(c^d-e)^(f+g*h)-i";
    // Stack
    static Stack<Character> stack = new Stack<Character>();

    public static void main(String[] args) {
        // Infix to Postfix Conversion using Stack
        infixToPostfix(exp);
    }

    static void infixToPostfix(String exp) {
        // Infix to Postfix Conversion using Stack
        // your code here

    }

}

// Output:
// abcd^e-fgh*+^*+i-