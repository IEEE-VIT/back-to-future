// Infix to postfix conversion using stack in rust

use std::io;
use std::io::prelude::*;

fn main() {
    let mut expression = "a+b*(c^d-e)^(f+g*h)-i".to_string();
    println!("{}", expression);
}

fn infix_to_postfix(expression: String) -> String {
    // your code goes here
    // return the postfix expression
}

// Output:
// abcd^e-fgh*+^*+i-
