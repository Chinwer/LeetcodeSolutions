/*
 * 62. Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below) .
 *
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Constraints:
 *   - 1 <= m, n <= 1000
 *   - It's guraranteed that the answer will be less than or equal to 2 * 10 ^ 9
 */

#include "header.h"

class Solution {
    public:
        int uniquePaths(int m, int n) {
            // the matrix is n x m (n rows and m columns)
            vector<vector<int>> dp(n, vector(m, 1));
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
            return dp[n - 1][m - 1];
        }
};
