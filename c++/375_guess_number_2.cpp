/*
 * 375. Guess Number Higher or Lower II
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you gurss wrong, I'll tell you whether the number I picked
 * is higher or lower.
 *
 * However, when you guess a particular number x, and you guess wrong, you pay $x.
 * You win the game when you guess the number I picked.
 *
 * Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
 */

#include "header.h"

class Solution {
    public:
        int getMoneyAmount(int n) {
            vector<vector<int>> dp(n + 1, vector(n + 1, 0));
            for (int i = n - 1; i > 0; i--) {
                for (int j = i + 1; j <= n; j++) {
                    int res = INT_MAX;
                    // for (int k = i + 1; k < j; k++) {
                    // optimized
                    for (int k = (i + j + 1) / 2; k < j; k++) {
                        res = min(
                            res,
                            k + max(dp[i][k - 1], dp[k + 1][j])
                        );
                    }
                    res = min(res, i + dp[i + 1][j]);
                    res = min(res, j + dp[i][j - 1]);
                    dp[i][j] = res;
                }
            }
            return dp[1][n];
        }
};
