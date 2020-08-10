/*
 * 467. Unique Substrings in Wraparound String
 *
 * Consider the string s to be the infinite wraparound string of
 * "abcdefghijklmnopqrstuvwxyz", so s will look like this:
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...".
 *
 * Now we have another string p. Your job is to find out how many
 * unique non-empty substrings of p are present in s. In particular,
 * your input is the string p and you need to output the number of
 * different non-empty substrings of p in the string s.
 *
 * Note: p consists of only lowercase English letters and the size of p
 * might be over 10000.
 */

#include "header.h"

class Solution {
    public:
        int findSubstringInWraproundString(string p) {
            vector<int> dp(26);
            int cnt = 0, n = p.length();
            for (int i = 0; i < n; i++) {
                if (i && is_cont(p[i - 1], p[i])) {
                    cnt++;
                } else {
                    cnt = 1;
                }
                int idx = p[i] - 'a';
                dp[idx] = max(dp[idx], cnt);
            }
            return accumulate(dp.begin(), dp.end(), 0);
        }

        bool is_cont(char prev, char succ) {
            return prev == 'z' ? succ == 'a' : succ == prev + 1;
        }
};
