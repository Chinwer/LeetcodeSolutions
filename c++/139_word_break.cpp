/*
 * 139. Word Break
 *
 * Given a non-empty string s and a dictionary wordDict containing
 * a list of non-empty words, determine if s can be segmented into
 * a space-separated sequence of one or more dictionary words.
 *
 * Note:
 *
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 */

#include "header.h"

class Solution {
    private:
        unordered_map<int, int> memo;

    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            // return top_down(s, 0, s.size() - 1, wordDict);
            return bottom_up(s, wordDict);
        }

        bool bottom_up(string s, vector<string> &wordDict) {
            int n = s.length();
            vector<bool> dp(n);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    auto it = find(wordDict.begin(), wordDict.end(), s.substr(j, i - j + 1));
                    if (dp[j] && it != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[n - 1];
        }

        bool top_down(string s, int start, int end, vector<string> &wordDict) {
            if (start > end) {
                return true;
            }
            if (memo.count(start)) {
                return memo[start];
            }
            string sub;
            for (int i = start; i <= end; i++) {
                sub += s[i];
                auto it = find(wordDict.begin(), wordDict.end(), sub);
                if (it != wordDict.end() && top_down(s, i + 1, end, wordDict)) {
                    memo[start] = true;
                    return true;
                }
            }
            memo[start] = false;
            return false;
        }
};
