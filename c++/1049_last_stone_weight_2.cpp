/*
 * 1049. Last Stone Weight II
 *
 * We have a collection of rocks, each rock has a positive integer weight.
 *
 * Each turn, we choose any two rocks and smash them together.
 * Suppose the stones have weights x and y with x <= y. 
 * The result of this smash is:
 *
 *   - If x == y, both stones are totally destroyed;
 *   - If x != y, the stone of weight x is totally destroyed, and the stone
 * of weight y has new weight y-x.
 *
 * At the end, there is at most 1 stone left.  Return the smallest possible
 * weight of this stone (the weight is 0 if there are no stones left.)
 */

#include "header.h"

class Solution {
    public:
        int lastStoneWeightII(vector<int>& stones) {
            // return original(stones);
            return optimized(stones);
        }

        int optimized(vector<int>& stones) {
            int sum = 0, n = stones.size();
            for (int s : stones) {
                sum += s;
            }
            int average = sum / 2;
            // dp[i]: maximum weight we can get with package size equals to i
            vector<int> dp(average + 1);
            for (int s : stones) {
                for (int j = average; j >= s; j--) {
                    dp[j] = max(dp[j], dp[j - s] + s);
                }
            }
            return sum - 2 * dp[average];
        }

        int original(vector<int>& stones) {
            int sum = 0, n = stones.size();
            for (int s : stones) {
                sum += s;
            }
            int average = sum / 2;
            vector<vector<int>> dp(n + 1, vector(average + 1, 0));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= average; j++) {
                    if (stones[i - 1] > j) {
                        dp[i][j] = dp[i - 1][j];
                        continue;
                    }
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i - 1][j - stones[i - 1]] + stones[i - 1]
                    );
                }
            }
            return sum - 2 * dp[n][average];
        }
};
