import random

num = random.randint(0,9)
guessNum = int(input("Enter number between 0 and 9: ")) #Guessing the number

while guessNum != num:
    print("Number not matched")       #If number does not match
    guessNum = int(input("Enter number between 0 and 9: "))

print("\nCongratulations, you number matched")  #If the number match

#Output

#Enter number between 0 and 9: 4
#Number not matched
#Enter number between 0 and 9: 3
#Number not matched
#Enter number between 0 and 9: 7

#Congratulations, you number matched