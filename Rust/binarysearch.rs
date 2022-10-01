// Binary search algorithm in Rust

fn main() {
    let arr = [2, 3, 4, 10, 40];
    let x = 10;
    println!("{}", binary_search(arr, x))
}

fn binary_search(arr: [i32; 5], x: i32) -> i32 {
    // your code goes here
    // return -1 if element not found else return index
}

// Output:
// 3
