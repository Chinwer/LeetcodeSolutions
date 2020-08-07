/*
 * 931. Minimum Falling Path Sum
 *
 * Given a square array of integers A, we want the minimum sum of a
 * falling path through A.
 *
 * A falling path starts at any element in the first row, and chooses one
 * element from each row. The next row's choice must be in a column that
 * is different from the previous row's column by at most one.
 *
 * Constraints:
 *   - 1 <= A.length == A[0].length <= 100
 *   - -100 <= A[i][j] <= 100
 */

#include "header.h"

class Solution {
    public:
        int minFallingPathSum(vector<vector<int>> &A) {
            int m = A.size();
            int n = A[0].size();
            vector<vector<int>> dp(m, vector(n, INT_MAX));

            // base case
            for (int i = 0; i < n; i++) {
                dp[0][i] = A[0][i];
            }
            // state transfer
            for (int i = 1; i < m; i++) {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][0];
                dp[i][n - 1] = min(dp[i - 1][n - 2], dp[i - 1][n - 1]) + A[i][n - 1];
                for (int j = 1; j < n - 1; j++) {
                    int min_ = _min(
                        dp[i - 1][j - 1],
                        dp[i - 1][j],
                        dp[i - 1][j + 1]
                    ) + A[i][j];
                    dp[i][j] = min(dp[i][j], min_);
                }
            }
            int res = INT_MAX;
            for (int i = 0; i < n; i++) {
                res = min(res, dp[m - 1][i]);
            }
            return res;
        }

        int _min(int a, int b, int c) {
            return min(a, min(b, c));
        }
};
