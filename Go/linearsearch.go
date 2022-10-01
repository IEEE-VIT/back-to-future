// Linear Search in Go

package main

import "fmt"

func main() {

	var arr = []int{2, 3, 4, 10, 40}
	var x = 10
	linearSearch(arr, x)

}

func linearSearch(arr []int, x int) {

	for i := 0; i < len(arr); i++ {
		if arr[i] == x {
			fmt.Println("Element found at index: ", i)
		}

	}
}

// Output:
// Element found at index:  3
