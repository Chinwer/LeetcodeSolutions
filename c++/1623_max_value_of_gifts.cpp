/*
 * 1623. Maximum Value of Gifts
 *
 * 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
 * （价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右
 * 或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物
 * 的价值，请计算你最多能拿到多少价值的礼物？
 *
 * Note:
 *   - 0 < grid.length <= 200
 *   - 0 < grid[0].length <= 200
 */

#include "header.h"

class Solution {
    public:
        int maxValue(vector<vector<int>>& grid) {
            if (grid.empty()) {
                return 0;
            }
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector(n, 0));
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[0][i];
                dp[0][i] = sum;
            }
            sum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[i][0];
                dp[i][0] = sum;
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] = grid[i][j] + max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
            return dp[m - 1][n - 1];
        }
};
