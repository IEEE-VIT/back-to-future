// Infix to postfix conversion using stack in rust

use std::io;
use std::io::prelude::*;

fn main() {
    let mut expression = "a+b*(c^d-e)^(f+g*h)-i".to_string();
    infixtopostfix(expression);
}

fn infixtopostfix(expression: String) {
    // your code goes here
}

// Output:
// abcd^e-fgh*+^*+i-
