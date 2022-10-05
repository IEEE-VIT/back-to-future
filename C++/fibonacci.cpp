// Fibonacci Series in C++

#include <iostream>

using namespace std;
void fib(int n)
{
    int t1=0;
    int t2=1;
    int nextterm;
    for(int i=1;i<=n;i++){
        cout<<t1<<" ";
        nextterm=t1+t2;
        t1=t2;
        t2=nextterm;
    }
    return;
}

int main()
{
    fib(10);
}

// Output

// 0 1 1 2 3 5 8 13 21 34