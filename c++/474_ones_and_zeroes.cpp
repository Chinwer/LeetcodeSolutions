/*
 * 474. Ones and Zeroes
 *
 * Given an array, strs, with strings consisting of only 0s and 1s. ALso
 * two integers m and n.
 *
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 *
 * Constraints:
 *   - 1 <= strs.length <= 600
 *   - 1 <= strs[i].length <= 10
 *   - strs[i] consists only of digits '0' and '1'.
 *   - 1 <= m, n <= 100
 */

#include "header.h"

class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            int len = strs.size();
            vector<vector<int>> dp(m + 1, vector(n + 1, 0));
            for (string &s : strs) {
                pair<int, int> c = count(s);
                for (int i = m; i >= c.first; i--) {
                    for (int j = n; j >= c.second; j--) {
                        dp[i][j] = max(dp[i][j], dp[i - c.first][j - c.second] + 1);
                    }
                }
            }
            return dp[m][n];
        }

        pair<int, int> count(string &s) {
            int zero_cnt = 0, one_cnt = 0;
            for (char c : s) {
                one_cnt += c == '1';
                zero_cnt += c == '0';
            }
            return { zero_cnt, one_cnt };
        }
};
