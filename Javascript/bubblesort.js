// Bubble Sort in JavaScript

function bubbleSort(arr) {
    for (let i = arr.length - 1; i > 0; i--) {
        for (let j = 0; j < i; j++) {
          if (arr[j] > arr[j + 1]) {
            [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]
          }
        }
      }
      return arr
}

var arr = [76, 22, 21, 96, 70, 20];

console.log(bubbleSort(arr));

// Output:

// [ 20, 21, 22, 70, 76, 96 ]