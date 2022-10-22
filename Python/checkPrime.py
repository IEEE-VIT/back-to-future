# check if a number is prime or composite

def check_prime(n):
    if n > 1:
      for i in range(2, int(n/2)+1):
        if (n % i) == 0:
            return False
    else:
        return True


print(check_prime(73))
# Output:
# True
