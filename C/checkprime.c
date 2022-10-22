// Check if a number is prime or not in C.

#include <stdio.h>

int IsPrime(int n)
{
    //Trial Division Method
    if(n == 2 || n == 3) {
        return 1;
    }
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
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
// 1