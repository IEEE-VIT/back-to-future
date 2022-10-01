// Linear Search Algorithm in Javascript 

function linearSearch(arr, x) {
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

var arr = [2, 3, 4, 10, 40];
const x = 10;
var result = linearSearch(arr, x);
console.log(result);

// Output:
// 3