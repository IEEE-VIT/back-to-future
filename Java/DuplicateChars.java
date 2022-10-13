// Check if the given String has duplicate characters, ignoring case.
public class DuplicateChars {
	
	public static void main(String[] args) {		
		String str1 = "duplicate";
		String str2 = "character";
		
		System.out.println("'" + str1 + "' contains duplicate characters? " + checkDuplicateChars(str1));
		System.out.println("'" + str2 + "' contains duplicate characters? " + checkDuplicateChars(str2));
	}
	
	static boolean checkDuplicateChars(String str) {
		// Trim leading and trailing spaces
		str = str.trim();
		
		// Convert all the characters in the String to lower case
		str = str.toLowerCase();		
		
		// Convert the given string to a char array
		char[] chars = str.toCharArray();
		
		// Check each characters present in the string
		for (int i = 0; i < chars.length; i++) {			
			for (int j = i + 1; j < chars.length; j++) {
				if (chars[i] == chars[j]) {					
					return true; // Found a duplicate character
				}
			}			
		}
			
		return false; // No duplicate character found		
	}
}