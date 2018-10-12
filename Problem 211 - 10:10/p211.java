/*
 * Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string.
 * For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].
 */

class p108 {
    
    int[] find_pattern(String str, String pattern) {
        int len_diff = str.length() - pattern.length();
        ArrayList<Integer> arr_lst = new ArrayList<Integer>(len_diff);
        // base case
        if (pattern.length() < str.length) {
            return {};
        }
        for (int i = 0; i < len_diff;) {
            while (str.substring(i).equals(pattern.substring(i))) {
                i++
            }
        }
    }
    
    public static void main(String[] args) {
        
    }
}
