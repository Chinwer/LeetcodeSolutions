/*
 * 1064. Fixed Point
 * Given an array A of distinct integers sorted in ascending order, return the
 * smallest index i that satisfies A[i] == i.  Return -1 if no such i exists.
 *
 * Note:
 *
 * 1 <= A.length < 10^4
 * -10^9 <= A[i] <= 10^9
 */

#include "header.h"

class Solution {
public:
    int fixedPoint(vector<int>& A) {
        // int res = -1;
        // for (int i = 0; i < A.size(); i++) {
        //     if (A[i] == i) {
        //         res = i;
        //         break;
        //     }
        // }
        // return res;

        int l = 0, r = A.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m] >= m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l == A[l] ? l : -1;
    }
};
