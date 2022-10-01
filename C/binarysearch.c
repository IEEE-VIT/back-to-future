// Binary Search Algorithm in C++

#include <stdio.h>

int binarysearch(int *arr, int size, int x)
{
    // your code goes here
}

int main()
{
    int arr[6] = {20, 21, 22, 70, 76, 96};
    int x = 22;
    int index = binarysearch(arr, 6, x);
    printf("%d is at index %d", x, index);
    return 0;
}