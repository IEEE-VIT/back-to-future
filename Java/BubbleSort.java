import java.util.Arrays;

class Main {
  static void bubbleSort(int array[]) {
    int size = array.length;
    // loop over each element of the array to access them
    for (int i = 0; i < size - 1; i++)
      // compare the elements of the array with a loop
      for (int j = 0; j < size - i - 1; j++)
        // compare two adjacent elements in the array
        if (array[j] > array[j + 1]) {
          // Swap if the elements aren't in the right order
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
  }

  public static void main(String args[]) {
    int[] data = { 5, 3, 4, 1, 2 };
    // call the method using class name
    Main.bubbleSort(data);
    
    System.out.println("Array sorted with bubble sort: ");
    System.out.println(Arrays.toString(data));
  }
}

// Output: Array sorted with bubble sort: [1, 2, 3, 4, 5]
