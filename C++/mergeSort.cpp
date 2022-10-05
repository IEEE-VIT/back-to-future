//MERGE SORT
//We basically keep deviding the array wrt respect to its mid element until it narrows down to 1 element. Then we *merge* the 2 arrays in a manner that the resultant array is already sorted. we perform this recursively in each heirarchial stage of the division. In the end, we are left with 2 arrays which are sorted independantly. Now when we will merge the 2 of em, we will finally get the sorted array.
//RECURRENCE RELATION: T(n)=2T(n/2) + n
// TIME COMPLEXITY: n*log(n)


#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    //Making the temporary arrays.
    int a[n1];
    int b[n2];

    for(int i=0;i<n2;i++)
    {
        a[i]=arr[l+i];
    }

    for(int i=0;i<n2; i++)
    {
        b[i]=arr[mid+1+i];
    }

    // Merging and Sorting the arrays.
    int i=0;        //pointer to traverse over the array a
    int j=0;        //pointer to traverse over the array b
    int k=0;        //pointer to traverse over the main array.

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }

    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }

    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }



}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(arr, l ,mid);
        mergeSort(arr, mid+1, r);

        merge(arr,l,mid,r);

    }   
}

int main()
{   
    int arr[] = {5,4,1,2,5,8};
    mergeSort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}