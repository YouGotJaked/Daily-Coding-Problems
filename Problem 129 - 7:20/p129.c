/*
 * Given a real number n, find the square root of n.
 * For example, given n = 9, return 3.
 */

#include <stdio.h>

// Big O: O(log n)
int square_root(int n) {
    // base case
    if (n == 0 || n == 1) {
        return n;
    }

    int start = 1;
    int end = n;
    int ans;
    
    // binary search
    while (start <= end) {
        int mid = (start + end) / 2;
        
        // perfect square
        if (mid * mid == n) {
            return mid;
        }
        
        // floor(sqrt(n))
        if (mid * mid < n) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    
    return ans;
}

void print_sqrt(int n) {
    printf("sqrt(%d) = %d\n", n, square_root(n));
}

int main() {
    print_sqrt(144);
}
