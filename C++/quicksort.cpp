#include<iostream>

using namespace std;

int partition(int A[], int l, int h)
{
    int temp;
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] >= pivot);
        do
        {
            j--;
        } while (A[j] < pivot);
        if (i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}
int main()
{
    int size;
    cin >> size;
    int A[size];
    for(int i=0;i<size;i++){
        cin >> A[i];
    }
    QuickSort(A,0, size-1);
    for (int i = size-1; i >=0 ; i--)
        cout << A[i] << " ";
}