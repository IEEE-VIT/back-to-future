// Fibonacci sequence generator in Go

package main

import "fmt"

func main() {
	var n int = 10
	fibonacci(n)
}

func fibonacci(n int) {
	// your code here
	a := 0
	b := 1
	c := 1

	fmt.Print(a, " ")
	fmt.Print(b, " ")
	for i := 0; i < n-2; i++ {
		c = a + b

		fmt.Print(c, " ")

		a = b
		b = c
	}
}

// Output:

// 0 1 1 2 3 5 8 13 21 34
