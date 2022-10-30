def merge_arr(arr, left, mid, right):
	n1 = mid - left + 1
	n2 = right - mid

	L = [0]*(n1)
	R = [0]*(n2)


	for i in range(0, n1):
		L[i] = arr[left + i]

	for j in range(0, n2):
		R[j] = arr[mid + 1 + j]

	i = 0
	j = 0
	k = left

	while i < n1 and j < n2:
		if L[i] <= R[j]:
			arr[k] = L[i]
			i += 1
		else:
			arr[k] = R[j]
			j += 1
		k += 1

	while i < n1:
		arr[k] = L[i]
		i += 1
		k += 1

	while j < n2:
		arr[k] = R[j]
		j += 1
		k += 1



def MergeSort(arr, left, right):
	if left < right:
		m = left+(right-left)//2

		MergeSort(arr, left, m)
		MergeSort(arr, m+1, right)
		merge_arr(arr, left, m, right)



n = int(input("Enter the length of the array: "))
arr=[]
for i in range(n):
    x=int(input("Enter element: "))
    arr.append(x)

MergeSort(arr, 0, n-1)
print("\nSorted array is:")
for i in range(n):
	print("%d" % arr[i],end=" ")
