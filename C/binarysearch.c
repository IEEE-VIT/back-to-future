// Binary Search Algorithm in C++

#include <stdio.h>

int BinarySearch(int *arr, int size, int x)
{
    // your code goes here
    // return the index of the element if found else return -1
}

int main()
{
    int arr[5] = {2, 3, 4, 10, 40};
    int x = 10;
    int index = BinarySearch(arr, 5, x);
    printf("%d", index);
    return 0;
}

// Output

// 3