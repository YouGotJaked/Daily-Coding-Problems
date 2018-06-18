/*
 * Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array execept the one at i.
 */

#include <stdlib.h>
#include <stdio.h>

int *p2(int *arr, int size) {
    // allocate left and right temp arrays
    int *l = (int*) malloc(sizeof(int) * size);
    int *r = (int*) malloc(sizeof(int) * size);
    
    // allocate product array
    int *prod = (int*) malloc(sizeof(int) * size);
    
    // construct left array, leftmost element is 1
    l[0] = 1;
    for (int i = 1; i < size; i++) {
        l[i] = arr[i - 1] * l[i - 1];
    }
    
    // construct right array, rightmost element is 1
    r[size - 1] = 1;
    for (int j = size - 2; j >= 0; j--) {
        r[j] = arr[j + 1] * r[j + 1];
    }
    
    // construct product array
    for (int k = 0; k < size; k++) {
        prod[k] = l[k] * r[k];
    }
    return prod;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0)
            printf("[ ");
        printf("%d ", arr[i]);
        if (i == size - 1)
            printf("]\n");
    }
}

void p2_helper(int *arr, int size) {
    printf("The array is ");
    print_array(arr, size);
    printf("The product array is ");
    print_array(p2(arr, size), size);
}

int main() {
    int a1[] = {1, 2, 3, 4, 5};
    int a1_size = sizeof(a1) / sizeof(a1[0]);
    int a2[] = {3, 2, 1};
    int a2_size = sizeof(a2) / sizeof(a2[0]);
    p2_helper(a1, a1_size);
    p2_helper(a2, a2_size);
}


