// Binary search algorithm in Rust

fn main() {
    let arr = [2, 3, 4, 10, 40];
    let x = 10;
    if binary_search(arr, x) {
        println!("Element found at index {}", x);
    } else {
        println!("Element not found");
    }
}

fn binary_search(arr: [i32; 5], x: i32) -> bool {
    // your code goes here
}

// Output:
// Element found at index 3
