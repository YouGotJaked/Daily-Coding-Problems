/*
 * You are in an infinite 2D gride where you can move in any of the 8 directions:
 * (x,y) to
 *  (x + 1, y),
 *  (x - 1, y),
 *  (x, y + 1),
 *  (x, y - 1),
 *  (x - 1, y - 1),
 *  (x + 1, y + 1),
 *  (x - 1, y + 1),
 *  (x + 1, y - 1)
 *
 * You are given a sequence of points and the order in which you need to cover the points.
 * Give the minimum number of steps in which you can achieve it.
 * You start from the first point.
 *
 * Example:
 *  Input: [(0,0), (1,1), (1,2)]
 *  Output: 2
 *  It takes 1 step to move from (0,0) to (1,1).
 *  It takes one more step to move from (1,1) to (1,2).
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(x,y) (x > y ? x : y)

typedef struct Point2D {
    int x, y;
} Point2D;

// return minimum number of steps required to reach last point from first point
int min_steps(Point2D *p, int size) {
    int steps = 0;
    
    for (int i = 1; i < size; i++) {
        int x = abs(p[i].x - p[i - 1].x);
        int y = abs(p[i].y - p[i - 1].y);
        steps += MAX(x,y);
    }
    
    return steps;
}

// print sequence of points as pairs
void print_points(Point2D *p, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" (%d,%d)", p[i].x, p[i].y);
        if (i != size - 1) {
            printf(",");
        }
    }
    printf(" ]\n");
}

int main() {
    Point2D p[3];
    p[0].x = 0, p[0].y = 0;
    p[1].x = 1, p[1].y = 1;
    p[2].x = 1, p[2].y = 2;
    int p_size = sizeof(p) / sizeof(p[0]);
    print_points(p,p_size);
    printf("Min steps: %d\n", min_steps(p,p_size));
    return 0;
}
