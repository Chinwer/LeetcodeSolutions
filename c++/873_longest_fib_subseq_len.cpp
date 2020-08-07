/*
 * 873. Length of Longest Fibonacci Subsequence
 *
 * A sequence X_1, X_2, ..., X_n is fibonacci-like if:
 *   - n >= 3
 *   - X_i + X_[i + 1] = X_[i + 2] for all i + 2 <= n
 *
 * Given a strictly increasing array A of positive integers forming a
 * sequence, find the length of the longest fibonacci-like subsequence
 * of A. If one does not exist, return 0.
 *
 * (Recall that a subsequence is derived from another sequence A
 *  by deleting any number of elements (including none) from A,
 *  without changing the order of the remaining elements. For example,
 * [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)
 *
 * Note:
 *
 * 3 <= A.length <= 1000
 * 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
 * (The time limit has been reduced by 50% for submissions in Java, C, and C++.)
 */

#include "header.h"

class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& A) {
            int n = A.size();
            if (!n) {
                return 0;
            }
            unordered_map<int, int> index_map;
            for (int i = 0; i < n; i++) {
                index_map[A[i]] = i;
            }
            vector<vector<int>> dp(n, vector<int>(n, 0));

            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    int diff = A[i] - A[j];
                    if (diff < A[j] && index_map.count(diff)) {
                        int idx = index_map[diff];
                        dp[j][i] = dp[idx][j] + 1;
                    }
                    res = max(res, dp[j][i] + 2);
                }
            }

            return res > 2 ? res : 0;
        }
};
