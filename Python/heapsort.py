# Heap Sort Algorithm in Python

def heapify(arr, i, length):
    left = 2 * i + 1
    right = 2 * i + 2
    max_index = i

    if left < length and arr[left] > arr[max_index]:
        max_index = left

    if right < length and arr[right] > arr[max_index]:
        max_index = right

    if max_index != i:
        swap(arr, max_index, i)
        heapify(arr, max_index, length)


def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]


# sorting is in the ascending order
def heap_sort(arr):
    for i in range(math.floor(len(arr) / 2), -1, -1):
        heapify(arr, i, len(arr))

    length = len(arr)
    # reorganise the heap by removing the root
    for i in range(len(arr) - 1, 0, -1):
        swap(arr, 0, i)
        length -= 1
        heapify(arr, 0, length)
    print(arr)


arr = [76, 22, 21, 96, 70, 20]
heap_sort(arr)

# Output:
# [20, 21, 22, 70, 76, 96]
