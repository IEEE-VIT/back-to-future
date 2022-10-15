// Bubble sort algorithm in C

#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    // your code goes here
    // print the sorted array
    int i,j,t;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
      printf("%d ",arr[i]);
}

int main()
{
    int arr[6] = {76, 22, 21, 96, 70, 20};
    bubbleSort(arr, 6);
    return 0;
}

// Output
// 20 21 22 70 76 96