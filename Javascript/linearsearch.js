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
var x = 10;
var result = linearSearch(arr, x);
if (result == -1) {
    console.log("Element is not present in array");
}
else {
    console.log("Element is present at index " + result);
}

// Output:
// Element is present at index 3