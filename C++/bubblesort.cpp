// Bubble Sort Algorithm in C++

#include <iostream>

using namespace std;

void BubbleSort(int *arr, int n)
{
   
    int counter=1;

    while(counter<n ){
        for(int i=0;i<n-counter;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        counter++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main()
{
    int arr[6] = {76, 22, 21, 96, 70, 20};
    BubbleSort(arr, 6);
    return 0;
}

// Output

// 20 21 22 70 76 96