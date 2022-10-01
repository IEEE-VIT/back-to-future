// Linear Search in Go

package main

import "fmt"

func main() {

	var arr = []int{2, 3, 4, 10, 40}
	var x = 10
	fmt.Println(linearSearch(arr, x))

}

func linearSearch(arr []int, x int) int {

	for i := 0; i < len(arr); i++ {
		if arr[i] == x {
			return i
		}

	}
	return -1
}

// Output:
// 3
