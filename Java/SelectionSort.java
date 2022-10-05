// Selection Sort Algorithm in Java 

public class SelectionSort {
    // Array of integers
    static int[] arr = { 76, 22, 21, 96, 70, 20 };

    // Selection Sort
    public static void main(String[] args) {
        // Selection Sort
        selectionSort(arr);
    }

    static void selectionSort(int[] arr) {
        // Selection Sort
        // your code here
        int n = arr.length;
 
        for (int i = 0; i < n-1; i++)
        {
        
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
 
           
         
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
        // print the array
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();

    }

}

// Output:
// [20, 21, 22, 70, 76, 96]
