/* 
 * Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i,j) satisfies either i % j = 0 or j % i = 0.
 * 
 * For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. * Given [1, 3, 6, 24], return [1, 3, 6, 24].
 */

#include <bits/stdc++.h>

using std::sort;
using std::vector;
using std::cout;

void lrg_div_sub(int *arr, int n) {
    // sort so divisors come first
    sort(arr, arr+n);
    
    // store divisors count
    vector <int> div_count(n, 1);
    
    // store previous divisors
    vector <int> prev(n, -1);
    
    // store index of largest element in max size subset
    int max_idx = 0;
    
    // iterate to find chain ending with arr[i]
    for (int i = 1; i < n; i++) {
        // consider smaller elements
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0) {
                if (div_count[i] < div_count[j] + 1) {
                    div_count[i] = div_count[j] + 1;
                    prev[i] = j;
                }
            }
        }
        // update last index of largest subset if current subset is more
        if (div_count[max_idx] < div_count[i]) {
            max_idx = i;
        }
    }
    
    // print result
    int k = 0;
    while (k >= 0) {
        cout << arr[k] << " ";
        k = prev[k];
    }
    cout << "\n";
}

int main() {
	int a1[] = {3, 5, 10, 20, 21};
	int a2[] = {1, 3, 6, 24};
	int n1 = sizeof(a1) / sizeof(a1[0]);
	int n2 = sizeof(a2) / sizeof(a2[0]);
    lrg_div_sub(a1,n1);
    lrg_div_sub(a2,n2);
}
