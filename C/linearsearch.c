// Linear Search Algorithm in C

#include <stdio.h>

int LinearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[5] = {2,
                  3,
                  4,
                  10,
                  40};
    int x = 10;
    int result = LinearSearch(arr, 5, x);
    printf("%d", result);

    return 0;
}

// Output

// 3