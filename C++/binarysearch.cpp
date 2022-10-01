// Binary Search Algorithm in C++

#include <iostream>

using namespace std;

int binarysearch(int *arr, int size, int x)
{
    // your code goes here
}

int main()
{
    int arr[5] = {2, 3, 4, 10, 40};
    int x = 10;
    int z = binarysearch(arr, 5, x);
    if (z == -1)
    {
        cout << "Element is not present in array";
    }
    else
    {
        cout << "Element is present at index " << z;
    }
    return 0;
}