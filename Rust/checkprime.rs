// Check Prime Number in Rust

fn main() {
    let num = 73;
    check_prime(num);
    if check_prime(num) {
        println!("{} is a prime number", num);
    } else {
        println!("{} is not a prime number", num);
    }
}

fn check_prime(num: i32) -> bool {
    // your code goes here
    // return true if num is prime, else return false
}

// Output:
// 73 is a prime number
