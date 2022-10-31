n=int(input("Enter a number: "))
n1=n
s=0
while(n>0):
    d=n%10
    s=s+(d**3)
    n=n//10

if(s==n1):
    print("It is an Armstrong number!")

else:
    print("It is not an Armstrong number.")