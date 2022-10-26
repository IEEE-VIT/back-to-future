// Fibonacci sequence in Java

public class Fibonacci {

    public static void main(String[] args) {
        // Fibonacci sequence
        int n = 10;
        fib(n);
    }

    static void fib(int n) {
        // Fibonacci sequence
        // your code here
        int num1 = 0;
        int num2 = 1;
        int num3;
        System.out.println(num1); //print 0
        System.out.println(num2);//print 1
        //start loop from 2
        for (int i =2;i<n;i++){
            //add the two numbers
            num3 = num1+num2;
            //print
            System.out.println(num3);
            //swap the numbers
            num1 = num2;
            num2=num3;
            num3=num1;
        }


    }

}

// Output:
// 0 1 1 2 3 5 8 13 21 34