/*
 * Determine whether there exists a one-to-one character mapping from one string s1 to another s2.
 * For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.
 * Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
 */

#include <bits/stdc++.h>
#define MAX_CHAR 256

using std::string;
using std::cout;
using std::endl;
using std::boolalpha;

bool isomorphic(string s1, string s2) {
    int s1_len = s1.length(), s2_len = s2.length();
	
	// base case
	if (s1_len != s2_len) {
		return false;
	}

	// initialize visited characters in s2
	bool marked[MAX_CHAR] = {false};

	// store mapping of s1's chars to that of s2, initialize as -1
	int map[MAX_CHAR];
	memset(map, -1, sizeof(map));

	// process all chars
	for (int i = 0; i < s2_len; i++) {
		// if current char of s1 is seen for the first time
		if (map[s1[i]] == -1) {
			// if current char of s2 is already seen, one-to-one mapping not possible
			if (marked[s2[i]]) {
				return false;
			}
			// mark current char of s2 as visited
            marked[s2[i]] = true;
            // store mapping of current chars
            map[s1[i]] = s2[i];
        // check if previous appearance mapped to same char of s2
        } else if (map[s1[i]] != s2[i]) {
            return false;
        }
    }
    
    return true;
}

void print_isomorphic(string s1, string s2) {
    cout << "Are \"" << s1 << "\" and \"" << s2 << "\" isomorphic?: " << boolalpha << isomorphic(s1,s2) << endl;
}

int main() {
    string s1 = "abc", s2 = "bcd", s3 = "foo", s4 = "bar";
    print_isomorphic(s1,s2);
    print_isomorphic(s3,s4);
}
