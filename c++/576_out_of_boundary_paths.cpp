/*
 * 576. Out of Boundary Paths
 *
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of
 * the ball, you can move the ball to adjacent cell or cross the grid
 * boundary in four directions (up, down, left, right). However, you can
 * at most move N times. Find out the number of paths to move the
 * ball out of grid boundary. The answer may be very large, return it
 * after mod 109 + 7.
 *
 * Note:
 *
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
 */

#include "header.h"

class Solution {
    public:
        int findPaths(int m, int n, int N, int i, int j) {
            if (!N) {
                return 0;
            }
            int mod = 1000000007;
            vector<vector<vector<int>>> dp(m, vector(n, vector(N + 1, 0)));
            for (int i = 0; i < m; i++) {
                dp[i][0][1]++;
                dp[i][n - 1][1]++;
            }
            for (int i = 0; i < n; i++) {
                dp[0][i][1]++;
                dp[m - 1][i][1]++;
            }
            for (int k = 2; k <= N; k++) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int up = i > 0 ? dp[i - 1][j][k - 1] : 0;
                        int down = i < m - 1 ? dp[i + 1][j][k - 1] : 0;
                        int left = j > 0 ? dp[i][j - 1][k - 1] : 0;
                        int right = j < n - 1 ? dp[i][j + 1][k - 1] : 0;
                        dp[i][j][k] = (((((up + down) % mod) + left) % mod) + right) % mod;
                    }
                }
            }
            int res = 0;
            for (int k = 1; k <= N; k++) {
                res = (res + dp[i][j][k]) % mod;
            }
            return res;
        }
};
