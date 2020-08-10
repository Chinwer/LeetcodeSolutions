/*
 * 650. 2 Keys Keyboard
 *
 * Initially on a notepad only one character 'A' is present. You can
 * perform two operations on this notepad for each step:
 *   1. Copy All: You can copy all the characters present on the
 *      notepad (partial copy is not allowed).
 *   2. Paste: You can paste the characters which are copied last time.
 *
 * Given a number n. You have to get exactly n 'A' on the notepad
 * by performing the minimum number of steps permitted. Output the
 * minimum number of steps to get n 'A'.
 *
 * Note: The n will be in the range [1, 1000].
 */

#include "header.h"

class Solution {
    public:
        int minSteps(int n) {
            // return solution1(n);
            // return solution2(n);
            return solution3(n);
        }

        int solution3(int n) {
            int res = 0, d = 2;
            while (n > 1) {
                while (n % d == 0) {
                    res += d;
                    n /= d;
                }
                d++;
            }
            return res;
        }

        int solution2(int n) {
            vector<int> dp(n + 1, n);
            dp[0] = dp[1] = 0;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    if (i % j == 0) {
                        dp[i] = min(dp[i], dp[j] + i / j);
                    }
                }
            }
            return dp[n];
        }

        int solution1(int n) {
            if (!n) {
                return 0;
            }
            // dp[i][j]: there are i 'A's on screen, and j 'A's in cache
            vector<vector<int>> dp(n + 1, vector(n + 1, n));
            dp[1][0] = 0;
            dp[1][1] = 1;
            for (int i = 1; i <= n; i++) {
                int min_ = dp[i][0];
                for (int j = 1; j < i; j++) {
                    dp[i][j] = min(dp[i][j], dp[i - j][j] + 1);
                    min_ = min(min_, dp[i][j]);
                }
                dp[i][i] = min_ + 1;
            }
            return dp[n][n] - 1;
        }
};
