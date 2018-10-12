/*
 * Suppose you are gien two lists of n points, one list (p1, p2, ... , pN) on the line y = 0 and the other list (q1, q2, ... , qN) on the line y = 1;
 * Imagine a set of n line segments connect each point p[i] to q[i].
 * Write an algorithm to determine how many pairs of the line segments intersect.
 */

#include <iostream>

#define CLOCKWISE 1
#define COUNTERCLOCKWISE 2

using std::cout;
using std::endl;
using std::min;
using std::max;

typedef struct point {
    int x;
    int y;
} Point;

bool on_segment(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x)) &&
           (q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    
    // co-linear
    if (val == 0) {
        return 0;
    }
    
    return (val > 0) ? CLOCKWISE : COUNTERCLOCKWISE;
}

bool intersect(Point p1, Point q1, Point p2, Point q2) {
    // 4 special cases
    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);
    
    // general case
    if (o1 != o2 && o3 != o4) {
        return true;
    }
    
    /*
     * special co-linear cases
     */
    // p2 on p1q1
    if (o1 == 0 && on_segment(p1,p2,q1)) {
        return true;
    }
    // q2 on p1q1
    if (o2 == 0 && on_segment(p1,q2,q1)) {
        return true;
    }
    // p1 on p2q2
    if (o3 == 0 && on_segment(p2,p1,q2)) {
        return true;
    }
    // q1 on p2q2
    if (o4 == 0 && on_segment(p2,q1,q2)) {
        return true;
    }
    
    return false;
}

void print_solution(Point p1, Point q1, Point p2, Point q2) {
    intersect(p1, q1, p2, q2) ? cout << "Yes" << endl : cout << "No" << endl;
}

int main() {
    Point p1 = {1,1}, q1 = {10,1};
    Point p2 = {1,2}, q2 = {10,2};
        
    print_solution(p1, q1, p2, q2);
    
    Point p3 = {10,0}, q3 = {0,10};
    Point p4 = {0,0}, q4 = {10,10};
    print_solution(p3, q3, p4, q4);
    
    Point p5 = {-5,-5}, q5 = {0,0};
    Point p6 = {1,1}, q6 = {10,10};
    print_solution(p5, q5, p6, q6);
}
