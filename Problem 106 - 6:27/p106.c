/*
 * Given an integer list where each number represents the number of hops you can make, determine whether you can reach to the last index starting at index 0.
 * For example, [2, 0, 1, 0] returs true while [1, 1, 0, 1] returns false.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// greedy solution
// time complexity: O(n)
// space complexity: O(1)
bool canHop(int *arr, int length) {
    int last = length - 1;
    for (int i = last; i >= 0; i--) {
        if (i + arr[i] >= last) {
            last = i;
        }
    }
    return last == 0;
}

void print_array(int *arr, int length) {
    assert(arr != NULL);
    
    for (int i = 0; i < length; i++) {
        if (i == 0)
            printf("[ ");
        printf("%d ", arr[i]);
        if (i == length - 1)
            printf("]\n");
    }
}

void print_bool(bool hop) {
    printf("%s", hop ? "true\n" : "false\n");
}

int main() {
    int a1[4] = {2, 0, 1, 0};
    int a2[4] = {1, 1, 0, 1};
    int a1_len = sizeof(a1) / sizeof(a1[0]);
    int a2_len = sizeof(a2) / sizeof(a2[0]);
    
    print_array(a1, a1_len);
    print_bool(canHop(a1, a1_len));
    
    print_array(a2, a2_len);
    print_bool(canHop(a2, a2_len));
    return 0;
}
