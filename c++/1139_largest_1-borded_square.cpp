/*
 * 1139. Largest 1-Bordered Square
 *
 * Given a 2D grid of 0s and 1s, return the number of elements in the
 * largest square subgrid that has all 1s on its border, or 0 if such
 * a subgrid doesn't exist in the grid.
 *
 * Constraints:
 *
 * 1 <= grid.length <= 100
 * 1 <= grid[0].length <= 100
 * grid[i][j] is 0 or 1
 */

#include "header.h"

class Solution {
    public:
        int largest1BorderedSquare(vector<vector<int>>& grid) {
            if (grid.empty()) {
                return 0;
            }
            int res = 0;
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<vector<int>>> dp(m + 1, vector(n + 1, vector(2, 0)));
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (grid[i - 1][j - 1]) {
                        dp[i][j][0] = dp[i][j - 1][0] + 1;
                        dp[i][j][1] = dp[i - 1][j][1] + 1;
                        int len = min(dp[i][j][0], dp[i][j][1]);
                        while (len > res) {
                            if (dp[i - len + 1][j][0] >= len && dp[i][j - len + 1][1] >= len) {
                                break;
                            }
                            len--;
                        }
                        res = max(res, len);
                    }
                }
            }
            return res * res;
        }
};
