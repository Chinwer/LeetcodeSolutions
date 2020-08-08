/*
 * 1314. Matrix Block Sum
 *
 * Given a m * n matrix mat and an integer K, return a matrix answer
 * where each answer[i][j] is the sum of all elements mat[r][c] for
 * i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid
 * position in the matrix.
 *
 * Constraints:
 *   - m == mat.length
 *   - n == mat[i].length
 *   - 1 <= m, n, K <= 100
 *   - 1 <= mat[i][j] <= 100
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
            int m = mat.size();
            int n = mat[0].size();
            vector<vector<int>> prefix(m + 1, vector(n + 1, 0));
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j]
                        + prefix[i][j - 1] - prefix[i - 1][j - 1];
                }
            }
            vector<vector<int>> res(m, vector(n, 0));
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    int x0 = max(i - K - 1, 0);
                    int y0 = max(j - K - 1, 0);
                    int x1 = min(i + K, m);
                    int y1 = min(j + K, n);
                    res[i - 1][j - 1] = prefix[x1][y1] - prefix[x1][y0]
                        - prefix[x0][y1] + prefix[x0][y0];
                }
            }
            return res;
        }
};
