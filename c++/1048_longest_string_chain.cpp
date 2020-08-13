/*
 * 1048. Longest String Chain
 *
 * Given a list of words, each word consists of English
 * lowercase letters.
 *
 * Let's say word1 is a predecessor of word2 if and only
 * if we can add exactly one letter anywhere in word1 to
 * make it equal to word2.  For example, "abc" is a
 * predecessor of "abac".
 *
 * A word chain is a sequence of words [word_1, word_2,
 * ..., word_k] with k >= 1, where word_1 is a predecessor
 * of word_2, word_2 is a predecessor of word_3, and so on.
 *
 * Return the longest possible length of a word chain with
 * words chosen from the given list of words.
 *
 * Note:
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] only consists of English lowercase letters.
 */

#include "header.h"

class Solution {
    public:
        int longestStrChain(vector<string>& words) {
            int n = words.size();
            sort(words.begin(), words.end(), [](string &a, string &b) {
                return a.length() < b.length();
            });
            int res = 1;
            vector<int> dp(n, 1);
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (is_pred(words[j], words[i])) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                res = max(res, dp[i]);
            }
            return res;
        }

        bool is_pred(string &w1, string &w2) {
            int l1 = w1.length();
            int l2 = w2.length();
            if (l2 - l1 != 1) {
                return false;
            }
            int i = 0, j = 0;
            while (i < l1 && j < l2) {
                if (w1[i] == w2[j]) {
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            if (i == l1) {
                return true;
            }
            return false;
        }
};
