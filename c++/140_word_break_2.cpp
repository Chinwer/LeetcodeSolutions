/*
 * 140. Word Break II
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each
 * word is a valid dictionary word. Return all such possible sentences.
 *
 * Note:
 *   - The same word in the dictionary may be reused multiple times in
 *     the segmentation.
 *   - You may assume the dictionary does not contain duplicate words.
 */

#include "header.h"

// class Solution {
//     private:
//         int n;
//         string s;
//         vector<string> res, dict;
//         unordered_map<string, int> cnt;

//     public:
//         vector<string> wordBreak(string s, vector<string>& wordDict) {
//             n = s.size();
//             this->s = s;
//             this->dict = wordDict;

//             for (string &w : wordDict) {
//                 cnt[w]++;
//             }

//             vector<bool> dp(n + 1, false);
//             dp[0] = true;
//             for (int i = 1; i <= n; i++) {
//                 for (int j = 0; j < i; j++) {
//                     if (dp[j] && cnt[s.substr(j, i - j)]) {
//                         dp[i] = true;
//                     }
//                 }
//             }
//             if (!dp[n]) {
//                 return {};
//             }

//             string path;
//             backtrack(0, path);
//             return res;
//         }

//         void backtrack(int start, string &path) {
//             if (start == n) {
//                 if (!path.empty()) {
//                     res.push_back(path);
//                 }
//                 return;
//             }
//             string word;
//             for (int i = start; i < n; i++) {
//                 word += s[i];
//                 if (cnt[word]) {
//                     string p = path.empty() ?
//                         word : path + " " + word;
//                     backtrack(i + 1, p);
//                 }
//             }
//         }
// };


class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            if (!can_split(s, wordDict)) {
                return {};
            }

            unordered_map<string, int> cnt;
            for (string &w : wordDict) {
                cnt[w]++;
            }

            int n = s.size();
            vector<vector<string>> dp(n + 1, vector<string>());
            dp[0] = { "" };
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    string sub = s.substr(j, i - j);
                    if (!dp[j].empty() && cnt[sub]) {
                        for (string &str : dp[j]) {
                            dp[i].push_back(str.empty() ? sub : str + " " + sub);
                        }
                    }
                }
            }
            return dp[n];
        }

        bool can_split(string &s, vector<string> &dict) {
            int n = s.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && find(dict.begin(), dict.end(), s.substr(j, i - j)) != dict.end()) {
                        dp[i] = true;
                    }
                }
            }
            return dp[n];
        }
};
