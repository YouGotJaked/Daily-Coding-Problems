/*
 * Given an array of numbers, returns whether any two sums to K.
 * For example, given [10, 15, 3, 7] and K of 17, return true since 10 + 7 is 17.
 */

#include "../include/stdc++.h"

using namespace std;

// O(nlogn)
bool p1(int *arr, int size, int K) {
    int hi,lo;
    
    //sort array
    sort(arr, arr + size);
    
    lo = 0;
    hi = size - 1;
    while (lo < hi) {
        if (arr[lo] + arr[hi] == K) {
            return true;
        } else if (arr[lo] + arr[hi] < K) {
            lo++;
        } else { // arr[lo] + arr[hi] > K
            hi--;
        }
    }
    return false;
}

int main() {
    int arr[] = {10, 15, 3, 7};
    int K = 17;
    int size = sizeof(arr) / sizeof(arr[0]);
    
    string output = p1(arr, size, K) ? "True" : "False";
    
    cout << output << endl;
    return 0;
}

