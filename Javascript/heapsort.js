// Heap Sort in JavaScript

const maxHeapify = (arr, n, i) => {
    let largest = i;
    let l = 2 * i + 1;
    let r = 2 * i + 2; 
    
     if (l < n && arr[l] > arr[largest]) {
           largest = l; 
     }

     if (r < n && arr[r] > arr[largest]) {
          largest = r; 
     }
    
     
     if (largest != i) { 
          let temp = arr[i]; 
          arr[i] = arr[largest]; 
          arr[largest] = temp; 
    
        maxHeapify(arr, n, largest); 
      } 
  }
  

function heapSort(arr) {
     var n = arr.length;
      for (let i = parseInt(n / 2 - 1); i >= 0; i--) {
        maxHeapify(arr, n, i); 
    }
 
    for (let i = n - 1; i >= 0; i--) { 
       let temp = arr[0]; 
       arr[0] = arr[i]; 
       arr[i] = temp;  
       maxHeapify(arr, i, 0); 
    } 

    return arr;
}

var arr = [76, 22, 21, 96, 70, 20];

console.log(heapSort(arr));

// Output:

// [ 20, 21, 22, 70, 76, 96 ]