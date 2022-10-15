// Check if a number is prime or not in C.

#include <stdio.h>

int IsPrime(int n)
{
    // your code goes here
    // return 1 if n is prime else return 0
    int i;
    for(i=2;i<=n/2;i++){
        if(n%i==0)
           return 0;
    }
    return 1;
}
int main()
{
    int n = 73;
    int result = IsPrime(n);
    printf("%d", result);
}

// Output
// 73