//RADIX SORT IMPLEMENTATION

#include <iostream>
using namespace std;
 
// A getMax function to get maximum value in a[]
int getMax(int a[], int n)
{
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void countSort(int a[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
 
// Radix Sort
void radixsort(int a[], int n)
{
    int m = getMax(a, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
 
// A print function to print an array
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
 
// Driver Code
int main()
{
    int a[] = { 112, 35, 9, 41, 744, 62, 3, 98, 615, 22 };
    int n = sizeof(a) / sizeof(a[0]);
     
    radixsort(a, n);
    print(a, n);
    return 0;
}

// OUTPUT 

// 3 9 22 35 41 62 98 112 615 744
