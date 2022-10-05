#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int k = 0;			//finding out the maximum entered value in the array.
    for(int i=0; i<n; i++)
    {
        k=max(k,arr[i]);
    }

    int count[k+1]={0};	//Creating a count array of the length k+1 to maintain the frequency of each element of the array.

    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }

    for(int i=1; i<k+1; i++)	//Manipulating the count array to find out the position of each element in the main array.
    {
        count[i]+=count[i-1];
    }

    int result[n];		//Creating a result array to get the final output array

    for(int i=n-1; i>=0; i--)
    {
        count[arr[i]]--;
        result[count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++)		//Appending the main array by the help of the result array
    {
        arr[i] = result[i];
    }

    return;
}

int main()
{
    int n;

    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Entered Array"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    countSort(arr,n);

    cout<<endl;

    cout<<"Sorted array"<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}