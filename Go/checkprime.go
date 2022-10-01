// Check Prime Number in Go

package main

import "fmt"

func main() {
	var num int = 73

	if isPrime(num) {
		fmt.Println(num, "is a prime number")
	} else {
		fmt.Println(num, "is not a prime number")
	}
}

func isPrime(num int) bool {
	// your code here
	return false // change this to return true if num is prime
}

// Output:
// Enter a number: 73
// 73 is a prime number
