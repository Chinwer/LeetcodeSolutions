/*
 * 96. Unique Binary Search Tres
 *
 * Given n, how many structurally unique BST's that store values 1...n ?
 *
 * Constraints:
 *   1 <= n <= 19
 */

#include "header.h"

class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    dp[i] += dp[i - j] * dp[j - 1];
                }
            }
            return dp[n];
        }
};
