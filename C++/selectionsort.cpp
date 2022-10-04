// Selection Sort Algorithm in C++

#include <bits/stdc++.h>

using namespace std;

void SelectionSort(int *arr, int size)
{
    int n=size;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main()
{
    int arr[6] = {76, 22, 21, 96, 70, 20};
    SelectionSort(arr, 6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Output

// 20 21 22 70 76 96