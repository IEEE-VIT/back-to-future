// Selection Sort in JavaScript 

function selectionSort(arr) {
    for (var i = 0; i < arr.length; i++) {  
        var temp = arr[i];  
        for (var j = i + 1; j < arr.length; j++) {  
            if (temp > arr[j]) {  
                temp = arr[j];  
            }  
        }  
        var index = arr.indexOf(temp);  
        var tempVal = arr[i];  
        arr[i] = temp;  
        arr[index] = tempVal;  
    }  
}

var arr = [76, 22, 21, 96, 70, 20];

selectionSort(arr);
console.log(arr);

// Output:

// [ 20, 21, 22, 70, 76, 96 ]