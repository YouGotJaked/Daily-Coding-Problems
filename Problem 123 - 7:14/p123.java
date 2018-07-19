/*
 * Given a string, return whether it represents a number.
 *
 * Here are the different kinds of numbers:
 *	"10", a positive integer
 *	"-10", a negative integer
 *	"10.1", a positive real number
 *	"-10.1", a negative real number
 *	"1e5", a number in scientific notation
 *
 * And here are examples of non-numbers:
 *	"a"
 *	"x 1"
 *	"a -2"
 *	"-"
 */

public class p123 {
    public static boolean isInteger(String str) {
        // base case
        if (str == null || str.isEmpty()) {
            return false;
        }

        int i = 0;

        // check for negative numbers
        if (str.charAt(0) == '-') {
            if (str.length() == 1) {
                return false;
            }
            i = 1;
        }

        for (; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c < '0' || c > '9') {
                if (c != '.' && c != 'e') { // include decimals and scientific notation
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String s1 = "10"; //true
        String s2 = "-10"; //true
        String s3 = "10.1"; //true
        String s4 = "-10.1"; //true
        String s5 = "1e5"; //true
        String s6 = "a"; //false
        String s7 = "x 1"; //false
        String s8 = "a -2"; //false
        String s9 = "-"; //false
        System.out.println(isInteger(s1));
        System.out.println(isInteger(s2));
        System.out.println(isInteger(s3));
        System.out.println(isInteger(s4));
        System.out.println(isInteger(s5));
        System.out.println(isInteger(s6));
        System.out.println(isInteger(s7));
        System.out.println(isInteger(s8));
        System.out.println(isInteger(s9));
    }
}
