/*
 * 91. Decode Ways
 *
 * A message containing letters from A-Z is being encoded to numbers
 * using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 * Given a non-empty string containing only digits, determine the total
 * number of ways to decode it.
 */

#include "header.h"

class Solution {
    public:
        int numDecodings(string s) {
            // return solution1(s);
            return solution2(s);
        }

        int solution2(string s) {
            if (s.empty() || s[0] == '0') {
                return 0;
            }
            int n = s.length();
            int pre = 1, cur = 1;
            for (int i = 1; i < n; i++) {
                int tmp = cur;
                if (s[i] == '0') {
                    if (s[i - 1] == '1' || s[i - 1] == '2') {
                        cur = pre;
                    } else {
                        return 0;
                    }
                } else {
                    if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                        cur += pre;
                    }
                }
                pre = tmp;
            }
            return cur;
        }

        int solution1(string s) {
            if (s.empty()) {
                return 0;
            }
            if (s[0] == '0') {
                return 0;
            }
            int n = s.length();
            vector<int> dp(n + 1);
            dp[0] = 1;
            dp[1] = 1;
            for (int i = 1; i < n; i++) {
                if (s[i] == '0') {
                    if (s[i - 1] == '1' || s[i - 1] == '2') {
                        dp[i + 1] = dp[i - 1];
                    } else {
                        return 0;
                    }
                } else {
                    if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                        dp[i + 1] = dp[i] + dp[i - 1];
                    } else {
                        dp[i + 1] = dp[i];
                    }
                }
            }
            return dp[n];
        }
};
