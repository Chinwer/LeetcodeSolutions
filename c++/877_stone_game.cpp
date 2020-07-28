/*
 * 877. Stone Game
 *
 * Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
 *
 * The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
 *
 * Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.
 *
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
 *
 * Note:
 *   - 2 <= piles.length <= 500
 *   - piles.length is even.
 *   - 1 <= piles[i] <= 500
 *   - sum(piles) is odd.
 */

#include "header.h"

class Solution {
    public:
        bool stoneGame(vector<int>& piles) {
            // return solution1(piles);
            return solution2(piles);
        }

        bool solution2(vector<int> &piles) {
            int n = piles.size();
            // dp[i][j] means the maximum difference between
            // the score of the first hand and second hand
            vector<vector<int>> dp(n, vector(n, 0));
            for (int i = 0; i < n; i++) {
                dp[i][i] = piles[i];
            }
            for (int i = n - 2; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
                }
            }
            return dp[0][n - 1] > 0;
        }

        bool solution1(vector<int> &piles) {
            int n = piles.size();
            vector<vector<pair<int, int>>> dp(n, vector(n, pair(0, 0)));
            for (int i = 0; i < n; i++) {
                dp[i][i].first = piles[i];
            }
            for (int i = n - 2; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    int left = piles[i] + dp[i + 1][j].second;
                    int right = piles[j] + dp[i][j - 1].second;
                    if (left > right) {
                        dp[i][j].first = left;
                        dp[i][j].second = dp[i + 1][j].first;
                    } else {
                        dp[i][j].first = right;
                        dp[i][j].second = dp[i][j - 1].first;
                    }
                }
            }
            return dp[0][n - 1].first - dp[0][n - 1].second;
        }
};
