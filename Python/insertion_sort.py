"""
Python program for implementation of Insertion Sort
"""

#function to perform insertion sort
from array import array


def insertionSort(array):
    for i in range(1, len(array)):
        key = array[i]
        
        j = i-1
        while j>=0 and key < array[j]:
            array[j+1] = array[j]
            j -= 1

        array[j+1] = key

if __name__ == "__main__":
    #sample code to test above
    arr = [22, 32, 12 ,21 ,67, 2, 7, 16]
    print("Original array: ", arr)
    insertionSort(arr)
    print("Sorted Array:   ", arr)