/*
 * 1027. Longest Arithmetic Sequence
 *
 * Given an array A of integers, return the length of the longest
 * arithmetic subsequence A.
 *
 * Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k]
 * with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence
 * B is arithmetic if B[i + 1] - B[i] are all the same value (for 0 <= i <
 * B.length - 1).
 *
 * Note:
 *   1. 2 <= A.length <= 2000
 *   2. 0 <= A[i] <= 10000
 */

#include "header.h"

class Solution {
    public:
        int longestArithSeqLength(vector<int>& A) {
            int res = 0, n = A.size();
            vector<unordered_map<int, int>> dp(n);
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    int diff = A[i] - A[j];
                    if (dp[j].count(diff)) {
                        dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                    } else {
                        dp[i][diff] = 2;
                    }
                    res = max(res, dp[i][diff]);
                }
            }
            return res;
        }
};
