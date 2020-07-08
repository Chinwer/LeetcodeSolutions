/*
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            // naive solution, time limit exceeded
            //
            // if (s.empty()) {
            //     return string();
            // }
            // string res;
            // int max_len = 1;
            // int len = s.length();
            // for (int i = 0; i < len; i++) {
            //     for (int j = max_len + 1; j <= len - i; j++) {
            //         string substr = s.substr(i, j);
            //         if (is_palindrome(substr)) {
            //             res = substr;
            //             max_len = 
            //         }
            //     }
            // }
            // return res;

            // dynamic programming
            //
            // int n = s.length();
            // if (n < 2) {
            //     return s;
            // }

            // int max_len = 1, start;
            // vector<vector<bool>> dp(n, vector<bool>(n));
            // for (int i = n - 2; i >= 0; i--) {
            //     for (int j = i + 1; j < n; j++) {
            //         if (s[i] != s[j]) {
            //             dp[i][j] = false;
            //         } else {
            //             if (j - i < 3) {
            //                 dp[i][j] = true;
            //             } else {
            //                 dp[i][j] = dp[i + 1][j - 1];
            //             }
            //         }
            //         if (dp[i][j] && (j - i + 1) > max_len) {
            //             start = i;
            //             max_len = j - i + 1;
            //         }
            //     }
            // }
            // return s.substr(start, max_len);

            // center spreading solution
            int len = s.length();
            if (len < 2) {
                return s;
            }

            int max_len = 1;
            string res = s.substr(0, 1);
            for (int i = 0; i < len - 1; i++) {
                string oddstr = center_spread(s, i, i);
                string evenstr = center_spread(s, i, i + 1);
                string maxstr = oddstr.length() > evenstr.length() ? oddstr : evenstr;
                if (maxstr.length() > max_len) {
                    max_len = maxstr.length();
                    res = maxstr;
                }
            }
            return res;
        }

        bool is_palindrome(string s) {
            // s is not empty
            int len = s.length();
            int mid = (len + 1) / 2;
            for (int i = 0; i < mid; i++) {
                if (s[i] != s[len - 1 - i]) {
                    return false;
                }
            }
            return true;
        }

        string center_spread(string s, int left, int right) {
            int len = s.length();
            while (left >= 0 && right < len && s[left] == s[right]) {
                // spread
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        }
};
