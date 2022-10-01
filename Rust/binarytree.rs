// Binary Tree in Rust

fn main() {
    let tree = Node::new(100);
    let tree = tree.insert(200);
    let tree = tree.insert(50);
    let tree = tree.insert(25);
    tree.printtree();
}

struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Node {
        Node {
            value,
            left: None,
            right: None,
        }
    }

    fn insert(&self, value: i32) -> Node {
        // your code goes here
    }
    fn print_tree(&self) {
        // your code goes here
    }
}
