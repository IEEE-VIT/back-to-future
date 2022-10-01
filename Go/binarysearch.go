// Binary Search in Go

package main

import "fmt"

func main() {

	var arr = []int{2, 3, 4, 10, 40}
	var x = 10
	fmt.Println(binarySearch(arr, x))

}

func binarySearch(arr []int, x int) int {
	// your code here
	return -1 // return index or -1 if element is not found
}

// Output:

// 3
