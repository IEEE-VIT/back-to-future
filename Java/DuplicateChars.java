import java.util.Scanner;

// Check if the given String has duplicate characters.

public class DuplicateChars {
	
	public static void main(String[] args) {
		
		// Our variables
		String str = "";
		char[] chars;		
		boolean hasDuplicate = false;
		
		// Create a Scanner object
		Scanner input = new Scanner(System.in);
		
		// Ask the user to enter a string
		System.out.println("Enter a string to check: ");
		str = input.nextLine();
		
		// Convert the given string to a char array
		chars = str.toCharArray();
		
		// Check each characters present in the string
		for (int i = 0; i < chars.length; i++) {			
			hasDuplicate = false;
			
			for (int j = i + 1; j < chars.length; j++) {
				if (chars[i] == chars[j]) {
					// Found a duplicate, break out from the loop
					hasDuplicate = true;
					break;
				}
			}
			
			// If there was a duplicate in the loop then break out 
			if (hasDuplicate) {				
				break;
			}
		}
		
		if (hasDuplicate) {
			System.out.println("The string contains duplicate characters.");			
		} else {
			System.out.println("NO duplicate characters present in the string.");			
		}		
		
		// Close the Scanner
		input.close();
	}
}