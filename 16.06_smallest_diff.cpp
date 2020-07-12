/*
 * 面试题 16.06. Smallest Difference LCCI
 *
 * Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference.
 * Return the difference.
 *
 * Note:

 * 1 <= a.length, b.length <= 100000
 * -2147483648 <= a[i], b[i] <= 2147483647
 * The result is in the range [-2147483648, 2147483647]
 */

#include "header.h"

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long res = INT_MAX;
        int pa = 0, pb = 0;
        int sa = a.size(), sb = b.size();
        while (pa < sa && pb < sb) {
            long cur_a = a[pa];
            long cur_b = b[pb];
            if (cur_a == cur_b) {
                return 0;
            } else if (cur_a < cur_b) {
                res = min(res, cur_b - cur_a);
                pa++;
            } else {
                res = min(res, cur_a - cur_b);
                pb++;
            }
        }
        while (pa < sa) {
            long cur_a = a[pa];
            long cur_b = b[sb - 1];
            res = min(res, abs(cur_a - cur_b));
            pa++;
        }
        while (pb < sb) {
            long cur_a = a[sa - 1];
            long cur_b = b[pb];
            res = min(res, abs(cur_a - cur_b));
            pb++;
        }
        return res;
    }
};
