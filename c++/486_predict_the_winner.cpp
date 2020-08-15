/*
 * 486. Predict the Winner
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one
 * of the numbers from either end of the array followed by the player 2 and then
 * player 1 and so on. Each time a player picks a number, that number will
 * not be available for the next player. This continus until all the scores have
 * been chosen. The player with the maximum score wins.
 *
 * Given an array of scores, predict whether player 1 is the winner. You can
 * assume each player plays to maximize his score.
 *
 * Constraints:
 *   - 1 <= length of the array <= 20.
 *   - Any scores in the given array are non-negative integers and will not
 *     exceed 10000000.
 *   - If the scores of both players are equal, then player 1 is still the winner.
 */

#include "header.h"

class Solution {
    public:
        bool PredictTheWinner(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n, vector(n, 0));
            for (int i = 0; i < n; i++) {
                dp[i][i] = nums[i];
            }
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    dp[i][j] = max(
                        nums[i] - dp[i + 1][j],
                        nums[j] - dp[i][j - 1]
                    );
                }
            }
            return dp[0][n - 1] >= 0;
        }
};
class Solution {
    public:
        bool PredictTheWinner(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n, vector(n, 0));
            for (int i = 0; i < n; i++) {
                dp[i][i] = nums[i];
            }
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    dp[i][j] = max(
                        nums[i] - dp[i + 1][j],
                        nums[j] - dp[i][j - 1]
                    );
                }
            }
            return dp[0][n - 1] >= 0;
        }
};
