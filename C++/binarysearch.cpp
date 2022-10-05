// Binary Search Algorithm in C++

#include <iostream>

using namespace std;

int BinarySearch(int arr[], int size, int x)
{
    
    int s=0;
    int e=size-1;
    //2 pointer
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]<x){
            s=mid+1;
            return s;
        }else{
            e=mid-1;
            return e;
        }
    }

    return -1;

}

int main()
{
    int arr[5] = {2, 3, 4, 10, 40};
    int x = 10;
    int z = BinarySearch(arr, 5, x);
    cout << z;
    return 0;
}