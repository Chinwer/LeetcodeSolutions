/*
 * 304. Range Sum Query 2D - Immutable
 *
 * Given a 2D matrix, find the sum of the elements inside the
 * rectangle defined by its upper left corner (row1, col1) and lower
 * right corner (row2, col2).
 *
 * Note:
 *   1. You may assume that the matrix does not change.
 *   2. There are many calls to sumRegion function.
 *   3. You may assume that row1 ≤ row2 and col1 ≤ col2.
 */

#include "header.h"

class NumMatrix {
    private:
        vector<vector<int>> dp;

    public:
        NumMatrix(vector<vector<int>>& matrix) {
            if (matrix.empty() || matrix[0].empty()) {
                return;
            }
            int m = matrix.size();
            int n = matrix[0].size();
            dp = vector(m + 1, vector(n + 1, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] + matrix[i][j] - dp[i][j];
                }
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2) {
            return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
        }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
