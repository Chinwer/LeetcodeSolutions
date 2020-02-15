/*
 * 977. Squares of a Sorted Array
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 *
 * Note:
 *
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 */

#include "header.h"

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& A) {
            /* Method 1 */

            //  int pivot = 0;
            // int min_abs = 10001;
            // int size = A.size();
            // for (int i = 0; i < size; i++) {
            //     if (abs(A[i]) < min_abs) {
            //         pivot = i;
            //         min_abs = abs(A[i]);
            //     }
            // }

            // int l = pivot - 1;
            // int r = pivot + 1;
            // vector<int> res;
            // res.push_back(min_abs * min_abs);

            // while (l >= 0 && r < size) {
            //     if (abs(A[l]) < abs(A[r])) {
            //         res.push_back(A[l] * A[l]);
            //         l--;
            //     } else {
            //         res.push_back(A[r] * A[r]);
            //         r++;
            //     }
            // }
            // while (r < size) {
            //     res.push_back(A[r] * A[r]);
            //     r++;
            // }
            // while (l >= 0) {
            //     res.push_back(A[l] * A[l]);
            //     l--;
            // }
            // return res;

            /* Method 2 */

            int size = A.size();
            int l = 0, r = size - 1;
            vector<int> res(size);

            for (int &a : A) {
                a = a * a;
            }

            for (int i = size - 1; i >= 0; i--) {
                if (A[l] < A[r]) {
                    res[i] = A[r--];
                } else {
                    res[i] = A[l++];
                }
            }
            return res;
        }
};
