/*
 * 1140. Stone Game II
 *
 * Alex and Lee continue their games with piles of stones.  There are a
 * number of piles arranged in a row, and each pile has a positive integer
 * number of stones piles[i].  The objective of the game is to end with
 * the most stones. 
 *
 * Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
 *
 * On each player's turn, that player can take all the stones in the first
 * X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 *
 * The game continues until all the stones have been taken.
 *
 * Assuming Alex and Lee play optimally, return the maximum number of
 * stones Alex can get.
 *
 * Constraints:
 *
 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10 ^ 4
 */

#include "header.h"

class Solution {
    public:
        int stoneGameII(vector<int>& piles) {
            int sum = 0, n = piles.size();
            // dp[i][j] means maximum score the current player can get
            // when M == j and there are stones piles[i...n - 1] left
            vector<vector<int>> dp(n, vector(n, 0));
            for (int i = n - 1; i >= 0; i--) {
                sum += piles[i];
                for (int j = 0; j < n; j++) {
                    if (i + 2 * j >= n) {
                        dp[i][j] = sum;
                        continue;
                    }
                    for (int x = 1; x <= 2 * j; x++) {
                        dp[i][j] = max(dp[i][j], sum - dp[i + x][max(x, j)]);
                    }
                }
            }
            return dp[0][1];
        }
};
