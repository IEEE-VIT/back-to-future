// Fibonacci sequence in Java


public class Fibonacci {

    public static void main(String[] args) {
        // Fibonacci sequence
        int n = 10;
        fib(n);
    }

    static void fib(int n) {
       int  firstTerm = 0, secondTerm = 1;
        System.out.println("Fibonacci Series till " + n + " terms:");

        for (int i = 1; i <= n; ++i) {
            System.out.print(firstTerm + ", ");

            // compute the next term
            int nextTerm = firstTerm + secondTerm;
            firstTerm = secondTerm;
            secondTerm = nextTerm;
        }

    }

}

// Output:
// 0 1 1 2 3 5 8 13 21 34
