// Linear Search Algorithm in C

#include <stdio.h>

int linearsearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("Element is present at index %d", i);
            return 0;
        }
    }
    printf("Element is not present in array");
    return 0;
}

int main()
{
    int arr[5] = {2,
                  3,
                  4,
                  10,
                  40};
    int x = 10;
    linearsearch(arr, 5, x);
    return 0;
}
