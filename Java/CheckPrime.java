
// Check if the number is prime or not using java
public class CheckPrime {
  // Number to be checked
  static long num = 73;

  public static void main(String[] args) {
    // Check if the number is prime or not
    System.out.println(checkPrime(num));
  }

  // Check if the number is prime or not
  static boolean checkPrime(int num) {
    // Check if the number is prime or not
    // your code here
    if (num <= 1) return false;

    for (long i = 2; i < num; i++)
      if (num % i == 0)
        return false;

    return true;
  }

}

// Output:
// true
