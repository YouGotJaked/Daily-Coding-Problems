/*
 * Given a string and a set of characters, return the shortest substring containing all the characters in the set.
 * For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
 * If there is no substring containing all the characters in the set, return null.
 */

public class p103 {
    // hash size
    public static final int SIZE = 256;
    
    public static String findSubstring(String str, char[] set) {
        int str_len = str.length();
        int set_len = set.length;
        
        // return empty string if string is shorter than length of character set
        if (str_len < set_len) {
            System.out.println("No such substring exists.");
            return "";
        }
        
        int hash_str[] = new int[SIZE];
        int hash_set[] = new int[SIZE];
        
        // count occurrence of characters of set
        for (int i = 0; i < set_len; i++) {
            hash_set[set[i]]++;
        }
        
        int count = 0, start = 0, start_index = -1, min_len = Integer.MAX_VALUE;
        char curr_char;
        
        // traverse string
        for (int j = 0; j < str_len; j++) {
            curr_char = str.charAt(j);
            
            // count occurrence of characters of string
            hash_str[curr_char]++;
            
            // increment count if string's char matches set's char
            if (hash_set[curr_char] != 0 && hash_str[curr_char] <= hash_set[curr_char]) {
                count++;
            }
            
            // if all characters match
            if (count == set_len) {
                curr_char = str.charAt(start);
                
                // remove character if it appears more times in hash than set
                while (hash_str[curr_char] > hash_set[curr_char] || hash_set[curr_char] == 0) {
                    if (hash_str[curr_char] > hash_set[curr_char]) {
                        hash_str[curr_char]--;
                    }
                    curr_char = str.charAt(++start);
                }
            
                // update substring size
                int sub_len = j - start + 1;
                if (min_len > sub_len) {
                    min_len = sub_len;
                    start_index = start;
                }
            }
        }
        
        if (start_index == -1) {
            System.out.println("No such substring exists.");
            return "";
        }
        
        return str.substring(start_index, start_index + min_len);
    }
    
    public static void main(String[] args) {
        String str = "figehaeci";
        char[] set = {'a', 'e', 'i'};
        System.out.println("The smallest substring of " + str + " is " + findSubstring(str,set));
    }
}
