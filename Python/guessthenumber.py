import random

num = random.randint(0,9)
guessNum = int(input("Enter number between 0 and 9: "))

while guessNum != num:
    print("Number not matched")
    guessNum = int(input("Enter number between 0 and 9: "))

print("\nCongratulations, you number matched")