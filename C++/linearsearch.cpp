// Linear Search Algorithm in C++

#include <iostream>

using namespace std;
int linearsearch(int *arr, int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {2, 3, 4, 10, 40};
    int x = 10;
    int z = linearsearch(arr, 5, x);
    if (z == -1)
    {
        cout << "Element is not present in array";
    }
    else
    {
        cout << "Element is present at index " << z;
    }
    return 0;
}
