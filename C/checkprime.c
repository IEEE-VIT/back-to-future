// Check if a number is prime or not in C.

#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int n)
{
    // your code goes here
    // return true if n is prime else return false
}
int main()
{
    int n = 73;
    bool result = IsPrime(n);
    if (result)
        printf("%d is a prime number", n);
    else
        printf("%d is not a prime number", n);
    return 0;
}

// Output
// 73 is a prime number