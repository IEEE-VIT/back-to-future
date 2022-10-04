import random

num = random.randint(0,9)
guessNum = int(input()) #Guessing the number

while guessNum != num:
    print("False")       #If number does not match
    guessNum = int(input())

print("True")  #If the number match

#Output

#3
#False
#4
#False
#2
#True