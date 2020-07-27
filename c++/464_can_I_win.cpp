/*
 * 464. Can I Win
 *
 * In the "100 game," two players take turns adding, to a running total,
 * any integer from 1..10. The player who first causes the running total
 * to reach or exceed 100 wins.
 *
 * What if we change the game so that players cannot re-use integers?
 *
 * For example, two players might take turns drawing from a common pool
 * of numbers of 1..15 without replacement until they reach a total >= 100.
 *
 * Given an integer maxChoosableInteger and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both
 * players play optimally.
 *
 * You can always assume that maxChoosableInteger will not be larger than 20
 * and desiredTotal will not be larger than 300.
 */

#include "header.h"

class Solution {
    public:
        bool canIWin(int maxChoosableInteger, int desiredTotal) {
            if (maxChoosableInteger >= desiredTotal) {
                return true;
            }
            int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
            if (sum < desiredTotal) {
                return false;
            }

            vector<int> dp(1 << maxChoosableInteger);
            return recursion(maxChoosableInteger, desiredTotal, 0, dp);
        }

        bool recursion(int n, int target, int state, vector<int> &dp) {
            if (dp[state]) {
                return dp[state] == 1;
            }
            bool res = false;
            for (int i = 1; i <= n; i++) {
                int cur = 1 << (i - 1);
                // number i has been chosen before
                if (cur & state) {
                    continue;
                }
                if (i >= target ||
                    !recursion(n, target - i, state | cur, dp)) {
                    res = true;
                    break;
                }
            }
            dp[state] = res ? 1 : 2;
            return res;
        }
};
