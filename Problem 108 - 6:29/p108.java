/*
 * Given two strings A and B, return whether or not A can be shifted some number of times to get B.
 * For example, if A is 'abcde' and B is 'cdeab', return true.
 * If A is 'abc' and B is 'acb', return false.
 */

class p108 {
    public static boolean shiftable(String A, String B) {
        // base cases
        if (A.length() != B.length()) {
            return false;
        } else if (A.equals(B)) {
            return true;
        }
        
        String temp = shiftString(A);
        for (int i = 0; i < B.length(); i++) {
            if (temp.equals(B)) {
                return true;
            }
            temp = shiftString(temp);
        }
        
        return false;
    }
    
    // shift characters of string once to the right
    public static String shiftString(String str) {
        String temp = str.substring(1, str.length());
        return temp + str.charAt(0);
    }
    
    public static void printBoolean(boolean b) {
        System.out.printf("%s", b ? "true\n" : "false\n");
    }
    
    public static void main(String[] args) {
        String A = "abcde";
        String B = "cdeab";
        System.out.println("A: " + A + "\nB: " + B);
        printBoolean(shiftable(A, B));
        
        A = "abc";
        B = "acb";
        System.out.println("A: " + A + "\nB: " + B);
        printBoolean(shiftable(A, B));
    }
}
