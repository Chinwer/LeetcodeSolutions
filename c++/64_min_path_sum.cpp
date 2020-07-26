/*
 * 64. Minimum Path Sum
 *
 * Given a m x n grid filled with non-negative numbers, find a path
 * from top left to bottom right which minimizes the sum of all numbers
 * along its path.
 *
 * Note:
 * You can only move either down or right at any point in time.
 */

#include "header.h"

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            if (grid.empty()) {
                return 0;
            }
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector(n, 0));
            // base case: the first row
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[0][i];
                dp[0][i] = sum;
            }
            sum = 0;
            // base case: the first column
            for (int i = 0; i < m; i++) {
                sum += grid[i][0];
                dp[i][0] = sum;
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] = grid[i][j] + min(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
            return dp[m - 1][n - 1];
        }
};
