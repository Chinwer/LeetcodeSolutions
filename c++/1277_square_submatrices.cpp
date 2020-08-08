/*
 * 1277. Count Square Submatrices with All Ones
 *
 * Gien a m * n matrix of ones and zeros, return how many square
 * submatrices have all ones.
 *
 * Constraints:
 *   - 1 <= arr.length <= 300
 *   - 1 <= arr[0].length <= 300
 *   - 0 <= arr[i][j] <= 1
 */

#include "header.h"

class Solution {
    public:
        int countSquares(vector<vector<int>>& matrix) {
            int res = 0;
            int m = matrix.size();
            int n = matrix[0].size();
            // dp[i][j]: maximum length of square matrix of all ones
            //   with matrix[i][j] as its lower right corner
            vector<vector<int>> dp(m, vector(n, 0));
            // base case: the first row
            for (int i = 0; i < n; i++) {
                if (matrix[0][i]) {
                    res++;
                    dp[0][i] = 1;
                }
            }
            // base case: the first column
            for (int i = 1; i < m; i++) {
                if (matrix[i][0]) {
                    res++;
                    dp[i][0] = 1;
                }
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (!matrix[i][j]) {
                        continue;
                    }
                    int len = _min(
                        dp[i][j - 1],
                        dp[i - 1][j],
                        dp[i - 1][j - 1]
                    );
                    dp[i][j] = len + 1;
                    res += dp[i][j];
                }
            }
            return res;
        }

        int _min(int a, int b, int c) {
            return min(a, min(b, c));
        }
};
