// Linear Search in Rust

fn main() {
    let arr = [2, 3, 4, 10, 40];
    let x = 10;
    linear_search(arr, x);
}

fn linear_search(arr: [i32; 5], x: i32) {
    let mut i = 0;
    while i < arr.len() {
        if arr[i] == x {
            println!("Element found at index {}", i);
            return;
        }
        i += 1;
    }
    println!("Element not found");
}

// Output:
// Element found at index 3
