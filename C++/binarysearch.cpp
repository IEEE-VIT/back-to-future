// Binary Search Algorithm in C++

#include <iostream>

using namespace std;

int BinarySearch(int *arr, int size, int x)
{
    // your code goes here
    // return the index of x in arr if found otherwise return -1
}

int main()
{
    int arr[5] = {2, 3, 4, 10, 40};
    int x = 10;
    int z = BinarySearch(arr, 5, x);
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