/*
 * 1220. Count Vowels Permutation
 *
 * Given an integer n, your task is to count how many strings of
 * length n can be formed under the following rules:
 *
 * Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 * Each vowel 'a' may only be followed by an 'e'.
 * Each vowel 'e' may only be followed by an 'a' or an 'i'.
 * Each vowel 'i' may not be followed by another 'i'.
 * Each vowel 'o' may only be followed by an 'i' or a 'u'.
 * Each vowel 'u' may only be followed by an 'a'.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 *
 * Constraints:
 *
 * 1 <= n <= 2 * 10^4
 */

#include "header.h"

class Solution {
    public:
        int countVowelPermutation(int n) {
            int mod = 1000000007;
            vector<int> dp = { 1, 1, 1, 1, 1 };
            for (int i = 1; i < n; i++) {
                vector<int> tmp = dp;
                dp[0] = tmp[1];
                dp[1] = (tmp[0] + tmp[2]) % mod;
                dp[2] = (((((tmp[0] + tmp[1]) % mod) + tmp[3]) % mod) + tmp[4]) % mod;
                dp[3] = (tmp[2] + tmp[4]) % mod;
                dp[4] = tmp[0];
            }
            int res = 0;
            for (int d : dp) {
                res = (res + d) % mod;
            }
            return res;
        }
};
