/*
 * 986. Interval List Intersections
 *
 * Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

 * Return the intersection of these two interval lists.

 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
 *
 * Note:

 * 0 <= A.length < 1000
 * 0 <= B.length < 1000
 * 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
 */

#include "header.h"

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        // original version
        // vector<vector<int>> res;
        // int ptr_a = 0, ptr_b = 0;
        // int size_a = A.size(), size_b = B.size();
        // while (ptr_a < size_a && ptr_b < size_b) {
        //     vector<int> &a = A[ptr_a];
        //     vector<int> &b = B[ptr_b];
        //     if (!is_joint(a, b)) {
        //         res.push_back(get_intersection(a, b));
        //         if (a[0] <= b[0]) {
        //             if (ptr_b == size_b - 1 || a[1] < B[ptr_b + 1][0]) {
        //                 ptr_a++;
        //             } else {
        //                 ptr_b++;
        //             }
        //         } else {
        //             if (ptr_a == size_a - 1 || b[1] < A[ptr_a + 1][0]) {
        //                 ptr_b++;
        //             } else {
        //                 ptr_a++;
        //             }
        //         }
        //     } else {
        //         if (a[0] < b[0]) {
        //             ptr_a++;
        //         } else {
        //             ptr_b++;
        //         }
        //     }
        // }
        // return res;

        // optimized version

        int ai = 0, bi = 0;
        int sa = A.size(), sb = B.size();
        vector<vector<int>> res;

        while (ai < sa && bi < sb) {
            vector<int> &a = A[ai];
            vector<int> &b = B[bi];
            int lo = max(a[0], b[0]);
            int hi = min(a[1], b[1]);
            if (lo <= hi) {
                // a and b has intersection
                res.push_back(vector<int>{ lo, hi });
            }
            if (a[1] == hi) {
                ai++;
            }
            if (b[1] == hi) {
                bi++;
            }
        }
        return res;
    }

    bool is_joint(vector<int> &a, vector<int> &b) {
        return a[1] < b[0] || b[1] < a[0];
    }

    vector<int> get_intersection(vector<int> &a, vector<int> &b) {
        return vector<int>{ max(a[0], b[0]), min(a[1], b[1]) };
    }
};
