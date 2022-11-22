// Bubble sort algorithm in Java 

public class Main {
    // Array of integers
    static int[] arr = { 76, 22, 21, 96, 70, 20 };

    // Bubble Sort
    public static void main(String[] args) {
        // Bubble Sort
        bubbleSort(arr);
    }

    static void bubbleSort(int[] arr) {
        // Bubble Sort
        // your code here
        // print the sorted array
        int n = arr.length;  
        int temp = 0;  
         for(int i=0; i < n; i++){  
                 for(int j=1; j < (n-i); j++){  
                          if(arr[j-1] > arr[j]){  
                                 //swap elements  
                                 temp = arr[j-1];  
                                 arr[j-1] = arr[j];  
                                 arr[j] = temp;  
                         }  
                          
                 }  
         }
        for (int i=0;i<n;i++){
            System.out.println(arr[i]);
        }  

    }

}

// Output:
// [20, 21, 22, 70, 76, 96]

