/*
 * Given two rectangles on a 2D graph, return the area of their intersection.
 * If the rectanges don't intersect, return 0.
 *
 * For example, given the following rectangles:
 * 	{
 *		"top_left": (1, 4), 
 *		"dimensions": (3, 3) # width, height
 *	}
 * and
 * 	{
 *		"top_left": (0, 5),
 *		"dimensions": (4, 3) # width, height
 *	}
 * return 6.
 */

#include <bits/stdc++.h>

typedef struct point {
	int x, y;
} Point;

bool overlap(Point l1, Point r1, Point l2, Point r2) {
	// if one rectange is to the left of other
	if (l1.x > r2.x || l2.x > r1.x) {
		return false;
	}

	// if one rectangle is above other
	if (l1.y < r2.y || l2.y < r1.y) {
		return false;
	}

	return true;
}

int main() {
	Point l1 = (0,10}, r1 = {10,0);
	Point l2 = {5,5}, r2 = {15,0};
	overlap(l1,r1,l2,r2) ? printf("Rectangles overlap\n"); : printf("Rectangles do not overlap\n");
}
