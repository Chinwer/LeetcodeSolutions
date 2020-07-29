/*
 * 221. Maximum Square
 *
 * Given 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 */

#include "header.h"

class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            if (matrix.empty()) {
                return 0;
            }
            int res = 0;
            int m = matrix.size();
            int n = matrix[0].size();
            vector<vector<int>> dp(m, vector(n, 0));
            for (int i = 0; i < n; i++) {
                if (matrix[0][i] == '1') {
                    res = 1;
                    dp[0][i] = 1;
                }
            }
            for (int i = 0; i < m; i++) {
                if (matrix[i][0] == '1') {
                    res = 1;
                    dp[i][0] = 1;
                }
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][j] == '0') {
                        continue;
                    }
                    int len = min(dp[i - 1][j], dp[i][j - 1]);
                    if (matrix[i - len][j - len] == '1') {
                        dp[i][j] = len + 1;
                    } else {
                        dp[i][j] = len;
                    }
                    res = max(res, dp[i][j]);
                }
            }
            return res * res;
        }
};
