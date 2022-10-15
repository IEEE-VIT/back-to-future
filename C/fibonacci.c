// Fibonacci sequence in C

#include <stdio.h>

void fib(int n)
{
    // your code goes here
    // print the sequence
    int a,b,c,i;
    a=1;b=0;c=0;
    for(i=1;i<=n;i++){
        printf("%d ",c);
        c=a+b;
        a=b;b=c;
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