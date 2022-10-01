// Linear Search in Rust
use std::convert::TryInto;
fn main() {
    let arr = [2, 3, 4, 10, 40];
    let x = 10;
    println!("{}", linear_search(arr, x));
}

fn linear_search(arr: [i32; 5], x: i32) -> i32 {
    let mut i = 0;
    while i < arr.len() {
        if arr[i] == x {
            return i.try_into().unwrap();
        }
        i += 1;
    }
    return -1;
}

// Output:
// 3
