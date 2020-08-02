/*
 * 413. Arithmetic Slices
 *
 * A sequence of numbers is called arithmetic if it consists of at least
 * three elements and if the difference between any two consecutive
 * elements is the same.
 *
 * For example, these are arithmetic sequences:
 *   1, 3, 5, 7, 9
 *   7, 7, 7, 7
 *   3, -1, -5, -9
 *
 * The following sequence is not arithmetic:
 *   1, 1, 2, 5, 7
 *
 * A zero-indexed array A consisting of N numbers is given. A slice of
 * that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 *
 * A slice (P, Q) of the array A is called arithmetic if the sequence:
 * A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular,
 * this means that P + 1 < Q.
 *
 * The function should return the number of arithmetic slices in the
 * array A.
 */

#include "header.h"

class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& A) {
            // return original_dp(A);
            return optimized_dp(A);
        }

        int optimized_dp(vector<int> &A) {
            int n = A.size();
            if (n < 3) {
                return 0;
            }
            int dp = 0;
            int res = 0, pre_diff = A[1] - A[0];
            for (int i = 2; i < n; i++) {
                int diff = A[i] - A[i - 1];
                if (diff != pre_diff) {
                    dp = 0;
                } else {
                    dp++;
                    res += dp;
                }
                pre_diff = diff;
            }
            return res;
        }

        int original_dp(vector<int> &A) {
            int n = A.size();
            if (n < 3) {
                return 0;
            }
            vector<int> dp(n);
            int res = 0, pre_diff = A[1] - A[0];
            for (int i = 2; i < n; i++) {
                int diff = A[i] - A[i - 1];
                if (diff == pre_diff) {
                    dp[i] = dp[i - 1] + 1;
                    res += dp[i];
                }
                pre_diff = diff;
            }
            return res;
        }
};
