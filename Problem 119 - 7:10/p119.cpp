/*
 * Given a set of closed intervals, find the smallest set of numbers that covers all the intervals.
 * If there are multiple smallest sets, return any of them.
 * For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 0], one set of numbers that covers all these intervals is {3, 6}.
 */

#include "../include/stdc++.h"

using namespace std;

struct Interval {
    int start, end;
};

// compare two Intervals based on start time
bool comp_Int(Interval i1, Interval i2) {
    return i1.start < i2.start;
}

// merge overlapping intervals, print result
void merge_Ints(Interval arr[], int n) {
    // base case
    if (n <= 0) {
        return;
    }

    // create empty stack
    stack<Interval> s;
    
    // sort in increasing order of start time
    sort(arr, arr + n, comp_Int);
    
    // push first Interval to stack
    s.push(arr[0]);
    
    // start from next Interval, merge if necessary
    for (int i = 1; i < n; i++) {
        Interval top = s.top();
        
        // push Interval to stack top if not overlapping
        if (top.end < arr[i].start) {
            s.push(arr[i]);
        // otherwise update end if current Interval is more
        } else if (top.end < arr[i].end) {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    
    // print stack
    cout << "Merged Intervals: ";
    while (!s.empty()) {
        Interval i = s.top();
        cout << "[" << i.start << "," << i.end << "] ";
        s.pop();
    }
    cout << endl;
}

int main() {
    Interval arr[] = { {0, 3}, {2, 6}, {3, 4}, {6, 0}};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_Ints(arr, n);
}
