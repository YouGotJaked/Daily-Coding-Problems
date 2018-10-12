/* 
 * You are given an array of nonnegative integers.
 * Let's say you start at the beginning of the array and are trying to advance to the end. 
 * You can advance at most, the number of steps that you're currently on.
 * Determine whether you can get to the end of the array.
 * 
 * For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.
 *
 * Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
 */

#include <stdio.h>
#include <stdbool.h>

#define getName(var) #var

bool can_reach_end(int *arr, int len) {
	if (len <= 1) {
		return true;
	}	

	int max = arr[0];
	for (int i = 0; i < len; i++) {
		// not enough to go to next index
		if (max <= i && arr[i] == 0) {
			return false;
		}

		// update max
		if (i + arr[i] > max) {
			max = i + arr[i];
		}

		// enough to reach end
		if (max >= len - 1) {
			return true;
		}
	}

	return false;
}

void print_arr(int *arr, int len) {
	printf("%s: %s\n", getName(arr), can_reach_end(arr,len) ? "true" : "false");
}


int main() {
	int a1[6] = {1, 3, 1, 2, 0, 1};
	int len_a1 = sizeof(a1) / sizeof(a1[0]);
	int a2[5] = {1, 2, 1, 0, 0};
	int len_a2 = sizeof(a2) / sizeof(a2[0]);
	int a3[] = {};
	int len_a3 = sizeof(a3) / sizeof(a3[0]);
	int a4[1] = {0};
	int len_a4 = sizeof(a4) / sizeof(a4[0]);
	print_arr(a1,len_a1);
	print_arr(a2,len_a2);
	print_arr(a3,len_a3);
	print_arr(a4,len_a4);
}
