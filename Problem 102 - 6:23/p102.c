/*
 * Given a list of integers and a number K, return which contiguous elements of the list sum to K.
 * For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4].
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define LEN(x) (sizeof(x) / sizeof(x[0]))

typedef struct range {
    int head;
    int tail;
} Range;

Range *sum_to_K(int *arr, int length, int K) {
    int sum, index = 0;
    Range *r = malloc(sizeof(*r));
	
    for (int i = 0; i < length; i++) {
        sum = arr[i];
        
        for (int j = i + 1; j <= length; j++) {
            // sum is between indexes i and j - 1
            if (sum == K) {
                r->head = i;
                r->tail = j - 1;
                return r;
            }
            if (sum > K || j == K) {
                break;
            }
            sum += arr[j];
        }
    }
    
    return NULL;
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

void print_range(Range r, int *arr) {
    printf("[ ");
    for (int i = r.head; i <= r.tail; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int K = 9;
    Range *r = sum_to_K(arr, LEN(arr), K);
    printf("Array: ");
    print_array(arr, LEN(arr));
    printf("The following elements sum to %d: ", K);
    print_range(*r, arr);
}
