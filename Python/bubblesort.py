def bubble_sort(arr):
    n = len(arr)
    swapped = False
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j + 1]:
                swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
         
        if not swapped:
            return


arr = [76, 22, 21, 96, 70, 20]
bubble_sort(arr)

# Output:
# [20, 21, 22, 70, 76, 96]
