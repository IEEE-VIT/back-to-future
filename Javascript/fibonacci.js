// Fibonacci sequence generator in JavaScript 

function fibonacci(n) {
    let array = [];

    array[0] = 0;
    array[1] = 1;
  
    for (let i = 2; i < n; i++) {
      array[i] = array[i - 2] + array[i - 1];
    }
  
    return array;
}

console.log(fibonacci(10));

// Output:
// 0 1 1 2 3 5 8 13 21 34