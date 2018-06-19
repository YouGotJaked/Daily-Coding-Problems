/*
 * Given an array of integers, find the missing positive integer in linear time and constance space.
 * In other words, find the lowest positive integer that does not exist in the array.
 * The array can contain duplicates and negative numbers as well.
 */

#include <stdio.h>
#include <stdlib.h>

// swap two integers
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// put all non-positive (negative and 0) numbers on left side of array and return their count
int segregate(int *arr, int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            swap(&arr[i], &arr[j++]);
        }
    }
    return j;
}

// find smallest positive integer in all positive array
int missing_positive(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        // make arr[arr[i] - 1] negative to mark arr[i] as visited
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    
    // return first positive index value
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            return ++i;
    }
    
    return ++size;
}

// find smallest positive integer in positive and negative array
int missing(int *arr, int size) {
    // separate positive and negative numbers
    int shift = segregate(arr, size);
    
    return missing_positive(arr + shift, size - shift);
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

void p4(int *arr, int size) {
    printf("The array is ");
    print_array(arr, size);
    printf("The missing positive number is %d\n", missing(arr, size));
}

int main() {
    int a1[] = {3, 4, -1, 1};
    int a1_size = sizeof(a1) / sizeof(a1[0]);
    int a2[] = {1, 2, 0};
    int a2_size = sizeof(a2) / sizeof(a2[0]);
    p4(a1, a1_size);
    p4(a2, a2_size);
}
