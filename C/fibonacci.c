// Fibonacci sequence in C

#include <stdio.h>

int getfib(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    }
    return getfib(n-1) + getfib(n-2);
}

void fib(int n)
{
    for(int i = 0; i < n; i++) {
        printf("%d ", getfib(i));
    }
}

int main()
{
    int n = 10;

    fib(n);
    return 0;
}

// Output
// 0 1 1 2 3 5 8 13 21 34