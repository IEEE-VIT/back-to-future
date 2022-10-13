// Selection Sort in C

#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int index = 0;
    int min;
    for (int i = 0; i < n; i++)
    {
        min = arr[i];
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                index = j;
                min = arr[index];
            }
        }
        if (arr[i] != arr[index])
        {
            arr[i] += arr[index];
            arr[index] = arr[i] - arr[index];
            arr[i] -= arr[index];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[6] = {76, 22, 21, 96, 70, 20};
    selectionSort(arr, 6);
    return 0;
}

// Output
// 20 21 22 70 76 96