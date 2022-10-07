use std::io::{self, Read};

fn main() {
    let input_str = read_user_input();
    let original_tokens = tokenize(&input_str);
    let result = infix_to_postfix(&original_tokens);
    println!("{:?}", result);
}

pub fn read_user_input() -> String {
    let mut buffer = String::new();
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    handle.read_to_string(&mut buffer);
    buffer
}

pub fn tokenize(input_str: &String) -> Vec<InfixToken> {
    let mut tokens: Vec<InfixToken> = Vec::new();
    for ele in input_str.split_whitespace() {
        if ele == "+" {
            tokens.push(InfixToken::Operator(Operator::Add));
        }
        else if ele == "-" {
            tokens.push(InfixToken::Operator(Operator::Sub));
        }
        else if ele == "*" {
            tokens.push(InfixToken::Operator(Operator::Mul));
        }
        else if ele == "/" {
            tokens.push(InfixToken::Operator(Operator::Div));
        }
        else if ele == "(" {
            tokens.push(InfixToken::LeftParen);
        }
        else if ele == ")" {
            tokens.push(InfixToken::RightParen);
        }
        else if ele == "\n" {
            continue;
        }
        else {
            tokens.push(InfixToken::Operand(ele.parse::<isize>().unwrap()));
        }
    }
    tokens
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum Operator {
    // `+`
    Add,
    // `-`
    Sub,
    // `*`
    Mul,
    // `/`
    Div,
}

#[derive(Debug, PartialEq)]
pub enum InfixToken {
    Operator(Operator),
    Operand(isize),
    LeftParen,
    RightParen,
}

#[derive(Debug, PartialEq)]
pub enum PostfixToken {
    Operator(Operator),
    Operand(isize),
}

/// Transforms an infix expression to a postfix expression.
///
/// If the infix expression is valid, outputs `Some(_)`;
/// otherwise, outputs `None`.
pub fn infix_to_postfix(tokens: &[InfixToken]) -> Option<Vec<PostfixToken>> {
    if check_valid(tokens) {
        let mut stack = Vec::new();
        let mut output_vec: Vec<PostfixToken> = Vec::new();
        for token in tokens {
            if let InfixToken::Operand(value) = token {
                output_vec.push(PostfixToken::Operand(*value));
            }
            else if let InfixToken::LeftParen = token {
                stack.push(token);
            }
            else if let InfixToken::RightParen = token {
                while true {
                    let popout_token = stack.pop().unwrap();
                    if let InfixToken::LeftParen = popout_token {
                        break;
                    }
                    else {
                        if let InfixToken::Operator(operator) = popout_token {
                            output_vec.push(PostfixToken::Operator(*operator));
                        }
                    }
                }
            }
            else if let InfixToken::Operator(operator) = token {
                if stack.len() == 0 {
                    stack.push(token);
                }
                else {
                    while true {
                        if stack.len() >= 1 {
                            let top_token = stack[stack.len() - 1];

                            if let InfixToken::Operator(stack_operator) = top_token {
                                if *stack_operator == Operator::Add || *stack_operator == Operator::Sub {
                                    if *operator == Operator::Sub || *operator == Operator::Add {
                                        if let InfixToken::Operator(operator4out) = stack.pop().unwrap() {
                                            output_vec.push(PostfixToken::Operator(*operator4out));
                                        } else { break }
                                    } else { break }
                                } else if *stack_operator == Operator::Mul || *stack_operator == Operator::Div {
                                    if let InfixToken::Operator(operator4out) = stack.pop().unwrap() {
                                        output_vec.push(PostfixToken::Operator(*operator4out));
                                    } else { break }
                                }
                            }
                            else {
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                    stack.push(token);
                }
            }
        }

        for x in 0..stack.len() {
            if let InfixToken::Operator(operator) = stack.pop().unwrap() {
                output_vec.push(PostfixToken::Operator(*operator));
            }
        }

        return Some(output_vec);
    }
    else {
        return None;
    }
}

pub fn check_valid(tokens: &[InfixToken]) -> bool {
    if tokens.len() >= 1 {
        if let InfixToken::Operator(_) = tokens[tokens.len() - 1] {
            return false;
        }

        if let InfixToken::LeftParen = tokens[tokens.len() - 1] {
            return false;
        }

        if let InfixToken::RightParen = tokens[0] {
            return false;
        }

        if let InfixToken::Operator(_) = tokens[0] {
            return false;
        }

        let mut index = 0;
        for eachEle in tokens {
            if index == 0 {
                index += 1;
                continue;
            }
            else {
                let previous = &tokens[index - 1];
                if let InfixToken::Operand(_) = eachEle {
                    if let InfixToken::Operand(_) = previous {
                        return false;
                    }

                    if let InfixToken::RightParen = previous {
                        return false;
                    }
                }

                if let InfixToken::LeftParen = eachEle {
                    if let InfixToken::Operand(_) = previous {
                        return false;
                    }

                    if let InfixToken::RightParen = previous {
                        return false;
                    }
                }

                if let InfixToken::Operator(_) = eachEle {
                    if let InfixToken::LeftParen = previous {
                        return false;
                    }

                    if let InfixToken::Operator(_) = previous {
                        return false;
                    }
                }

                if let InfixToken::RightParen = eachEle {
                    if let InfixToken::LeftParen = previous {
                        return false;
                    }

                    if let InfixToken::Operator(_) = previous {
                        return false;
                    }
                }
            }
            index += 1;
        }


        let mut num_paren = 0;
        for eachEle in tokens {
            if let InfixToken::LeftParen = eachEle {
                num_paren += 1;
            }
            if let InfixToken::RightParen = eachEle {
                num_paren -= 1;
            }
        }

        if num_paren != 0 {
            return false;
        }

        return true;
    }
    else {
        return false;
    }
}
