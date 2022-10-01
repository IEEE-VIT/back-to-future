// Linear Search in Java

public class linearsearch {
    public static void main(String[] args) {
        // Array of integers
        int[] arr = { 2, 3, 4, 10, 40 };
        // Element to be searched
        int x = 10;
        // Linear Search
        linearSearch(arr, x);

    }

    static void linearSearch(int[] arr, int x) {
        // Linear Search
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                System.out.println("Element found at index " + i);
                return;
            }

        }

    }
}

// Output:
// Element found at index 3