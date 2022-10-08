// Binary Search Algorithm in Javascript

function binarySearch(arr, x) {
    let start=0, end=arr.length-1;
         
    
    while (start<=end){
 
        let mid=Math.floor((start + end)/2);
  
       
        if (arr[mid]===x) return true;
 
        else if (arr[mid] < x)
             start = mid + 1;
        else
             end = mid - 1;
    }
  
    return false;
}

var arr = [2, 3, 4, 10, 40];

const x = 10;

var result = binarySearch(arr, x);

console.log(result);

// Output:
// true