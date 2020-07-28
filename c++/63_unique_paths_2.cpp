/*
 * 63. Unique Paths II
 *
 * A robot is located at the top-left corner of a m x n grid
 * (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid
 * (marked 'Finish' in the diagram below).
 *
 * Now consider if some obstacles are added to the grids.
 * How many unique paths would there be?
 *
 * Note: m and n will be at most 100.
 */

#include "header.h"

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.empty()) {
                return 0;
            }
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> dp(m, vector(n, 0));
            for (int i = 0; i < m; i++) {
                if (obstacleGrid[i][0]) {
                    break;
                } else {
                    dp[i][0] = 1;
                }
            }
            for (int i = 0; i < n; i++) {
                if (obstacleGrid[0][i]) {
                    break;
                } else {
                    dp[0][i] = 1;
                }
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (obstacleGrid[i][j]) {
                        continue;
                    }
                    if (!obstacleGrid[i - 1][j]) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (!obstacleGrid[i][j - 1]) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
};
