# python program to print fibonacci series

    # your code goes here
def fibonacci(n):
    a, b = 0, 1
    count = 0

    if n<=0:
        return
    elif n==1:
        print(a)
        return
    else:
        while count<n:
            print(a, end=' ')
            s = a + b
            a = b
            b = s
            count+=1
        
    # print the fibonacci series
    pass


n = int(10)

fibonacci(n)

# Output:

# 0 1 1 2 3 5 8 13 21 34
