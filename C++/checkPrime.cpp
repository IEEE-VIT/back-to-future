// Check Prime Number in C++

#include <iostream>

using namespace std;
bool IsPrime(int n)
{
    // your code goes here
    // check if the number is prime or not and return true or false accordingly
}

int main()
{
    int n = 73;
    bool result = IsPrime(n);
    if (result)
    {
        cout << n << " is a prime number";
    }
    else
    {
        cout << n << " is not a prime number";
    }
    return 0;
}

// Output
// 73 is a prime number