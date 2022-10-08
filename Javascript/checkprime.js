// Check if a number is prime or not using JavaScript

function isPrime(num) {
    for(var i = 2 ; i<=num/2 ; i++){
        if(num%i == 0)return false;
    }

    return true;
}

console.log(isPrime(73)); 

// Output:
// true