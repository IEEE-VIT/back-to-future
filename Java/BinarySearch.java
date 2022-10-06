// Binary Search Algorithm in Java

public class BinarySearch {
    // Array of integers
    static int[] arr = { 2, 3, 4, 10, 40 };
    // Element to be searched
    static int x = 10;

    public static void main(String[] args) {
        // Binary Search
        System.out.println(binarySearch(arr, x));
    }

    static int binarySearch(int[] array, int x) {
            int low=0,high= array.length-1;
        // Repeat until the pointers low and high meet each other
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (array[mid] == x)
                return mid;

            if (array[mid] < x)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

    

}

    // Output:
// 3
