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

    static int binarySearch(int[] arr, int x) {
        // Binary Search
        // your code here
        int first = 0;
        int last = arr.length-1;
        if ((last-first)>1){
            int mid = (last+first)/2;
            if (arr[mid]<x){
                first = mid+1;
            }
            else{
                last=mid;
            }
        }
        if (arr[first]==x){
            return first;
        }
        else if (arr[last]==x){
            return last;
        }
        else{
            return -1;
        }

    }

}

// Output:
// 3
