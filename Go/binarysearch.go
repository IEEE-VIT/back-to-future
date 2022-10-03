// Binary Search in Go

package main

import (
	"fmt"
)

func main() {

	var arr = []int{2, 3, 4, 10, 40}
	var x = 10
	fmt.Println(binarySearch(arr, x))

}

func binarySearch(arr []int, x int) int {
	low := 0
	high := len(arr) - 1 
	for low < high{
		median := (low + high) / 2

		if arr[median] < x{
			low = median + 1
		}else{
			high = median - 1
		}
	if arr[low] == x{
		return low
	}
	}
	
	return -1 // return index or -1 if element is not found
}
	


// Output:

// 3
