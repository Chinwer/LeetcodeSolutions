/*
 * 1240. Tiling a Rectangle with the Fewest Squares
 *
 * Given a rectangle of size n x m, find the minimum number of integer-sided
 * squares that tile the rectangle.
 *
 * Constraints:
 *   - 1 <= n <= 13
 *   - 1 <= m <= 13
 */

#include "header.h"

class Solution {
    private:
        const int INF = 0x3f3f3f3f;

    public:
        int tilingRectangle(int n, int m) {
            vector<vector<int>> dp(n + 1, vector(m + 1, INF));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (i == j) {
                        dp[i][j] = 1;
                        continue;
                    }
                    for (int k = 1; k < i; k++) {
                        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                    }
                    for (int k = 1; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
                    }
                    int min_ = min(i, j);
                    for (int p = 1; p <= min_; p++) {
                        for (int k = 1; k <= p; k++) {
                            if (p - k <= 0 || j - p <= 0 ||
                                i - p + k <= 0 || j - p - k <= 0) {
                                continue;
                            }
                            dp[i][j] = min(
                                dp[i][j],
                                dp[p - k][j - p] + dp[i - p + k][j - p - k] + dp[i - p][p + k] + 2
                            );
                        }
                    }
                }
            }
            return dp[n][m];
        }
};
