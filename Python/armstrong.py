def armstrong(n):
    s=0
    n1=n
    l=len(str(n))
    while(n>0):
        d=n%10
        s=s+(d**l)
        n=n//10

    if(s==n1):
        return True
    else:
        return False
        
        
num=153
print(armstrong(num))
