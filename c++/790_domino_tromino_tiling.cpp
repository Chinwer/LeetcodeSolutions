/*
 * 790. Domino and Tromino Tiling
 *
 * We have two types of tile: a 2x1 domino shape, and an "L" tromino shape.
 * These shapes may be rotated:
 *
 * XX <- domino
 *
 * XX <- "L" tromino
 * X
 *
 * Given N, how many ways are there to tile a 2xN board?
 * Return your answer modulo 10^9 + 7.
 *
 * (In a tiling, every square must be covered by a tile.
 *  Two tilings are different if and only if there are two
 *  4-directionally adjacent cells on the board such that
 *  exactly one of the tilings has both squares occupied
 *  by a tile.)
 *
 * Note:
 *  -  N  will be in range [1, 1000].
 */

#include "header.h"

class Solution {
    public:
        int numTilings(int N) {
            // return solution1(N);
            return solution2(N);
        }

        int solution2(int N) {
            const int mod = 1e9 + 7;
            // dp[i][0]: number of ways with all cells tiled up to column i
            // dp[i][1]: number of ways with all cells but the upper right one tiled up to column i
            // dp[i][2]: number of ways with all cells but the lower right one tiled up to column i
            vector<vector<long>> dp(N + 1, vector(3, 0l));
            dp[0][0] = 1;
            for (int i = 1; i <= N; i++) {
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + (i < 2 ? 0 : dp[i - 2][0]);
                dp[i][0] %= mod;
                dp[i][1] = dp[i - 1][2] + (i < 2 ? 0 : dp[i - 2][0]);
                dp[i][1] %= mod;
                dp[i][2] = dp[i - 1][1] + (i < 2 ? 0 : dp[i - 2][0]);
                dp[i][2] %= mod;
            }
            return dp[N][0];
        }

        int solution1(int N) {
            vector<int> dp(N + 3);
            const int mod = 1e9 + 7;
            dp[0] = 1;
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 5;
            for (int i = 4; i <= N; i++) {
                dp[i] = ((2 * dp[i - 1]) % mod + dp[i - 3]) % mod;
            }
            return dp[N];
        }
};
