/*
 * 978. Longest Turbulent Subarray
 *
 * A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
 *
 *   - For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
 *   - OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
 *   - That is, the subarray is turbulent if the comparison sign flips between each adjacent
 *     pair of elements in the subarray.
 *
 * Return the length of a maximum size turbulent subarray of A.
 *
 * Note:
 *
 * 1 <= A.length <= 40000
 * 0 <= A[i] <= 10^9
 */

#include "header.h"

class Solution {
    public:
        int maxTurbulenceSize(vector<int>& A) {
            // return solution1(A);
            return solution2(A);
        }

        int solution2(vector<int> &A) {
            int dp = 1, n = A.size();
            int prediff = 0, res = 1;
            for (int i = 1; i < n; i++) {
                int diff = A[i] - A[i - 1];
                if ((diff > 0 && prediff <= 0) ||
                    (diff < 0 && prediff >= 0)) {
                    dp += 1;
                } else if (!diff) {
                    dp = 1;
                } else {
                    dp = 2;
                }
                prediff = diff;
                res = max(res, dp);
            }
            return res;
        }

        int solution1(vector<int> &A) {
            int prediff = 0;
            int n = A.size();
            vector<int> dp(n);
            dp[0] = 1;
            int res = 1;
            for (int i = 1; i < n; i++) {
                int diff = A[i] - A[i - 1];
                if ((diff > 0 && prediff <= 0) ||
                    (diff < 0 && prediff >= 0)) {
                    dp[i] = dp[i - 1] + 1;
                } else if (!diff) {
                    dp[i] = 1;
                } else {
                    dp[i] = 2;
                }
                prediff = diff;
                res = max(res, dp[i]);
            }
            return res;
        }
};
