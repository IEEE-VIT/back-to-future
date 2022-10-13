// Binary Search Algorithm in C++

#include <stdio.h>
#include <math.h>

int BinarySearch(int *arr, int size, int x)
{
    int l = 0;
    int r = size - 1;
    int m;
    while (l <= r)
    {
        m = floor((l + r) / 2);
        if (arr[m] < x) {
            l = m + 1;
        } else if (arr[m] > x) {
            r = m - 1;
        } else {
            return m;
        }
    }
    return -1;
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