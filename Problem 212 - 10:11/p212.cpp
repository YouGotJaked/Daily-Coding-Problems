/*
 * Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ...
 * Given a column number, return its alphabetical column id.
 * For example, given 1, return "A".
 * Given 27, return "AA".
 */

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::srand;
using std::reverse;

char *column_id(int col) {
    char* res = new char[26]; // result
    int i = 0; // current index in str
    
    while (col > 0) {
        int rem = col % 26;
        // must be 'Z' in output
        if (rem == 0) {
            res[i++] = 'Z';
            col = (col / 26) - 1;
        } else {
            res[i++] = (rem - 1) + 'A';
            col /= 26;
        }
    }
    res[i] = '\0'; // null-terminated string
    reverse(res, res + strlen(res));
    return res;
}

int main() {
    for (int i = 1; i < 100; i++) {
        cout << column_id(i) << endl;
    }
}
