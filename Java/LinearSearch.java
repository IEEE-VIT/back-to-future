// Linear Search in Java

public class LinearSearch {
    public static void main(String[] args) {
        // Array of integers
        int[] arr = { 2, 3, 4, 10, 40 };
        // Element to be searched
        int x = 10;
        // Linear Search
        System.out.println(linearSearch(arr, x));

    }

    static int linearSearch(int[] arr, int x) {
        // Linear Search
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                return i;
            }

        }
        return -1;

    }
}

// Output:
// 3