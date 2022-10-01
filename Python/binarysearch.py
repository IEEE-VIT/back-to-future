# Binary Search Algorithm in Python

def binary_search(arr, x):
    # your code goes here
    # return the index of the element if found
    return -1  # if not found

    pass


arr = [2, 3, 4, 10, 40]
x = 10
result = binary_search(arr, x)

if result == -1:
    print("Element is not present in array")
else:
    print("Element is present at index", result)

# Output:
# Element found at index 3
