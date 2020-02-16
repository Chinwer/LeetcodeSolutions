/*
 * 1170. Compare Strings by Frequency of the Smallest Character
 * Let's define a function f(s) over a non-empty string s, which calculates the
 * frequency of the smallest character in s. For example, if s = "dcce" then
 * f(s) = 2 because the smallest character is "c" and its frequency is 2.
 *
 * Now, given string arrays queries and words, return an integer array answer,
 * where each answer[i] is the number of words such that f(queries[i]) < f(W),
 * where W is a word in words.
 *
 * Constraints:
 *
 * 1 <= queries.length <= 2000
 * 1 <= words.length <= 2000
 * 1 <= queries[i].length, words[i].length <= 10
 * queries[i][j], words[i][j] are English lowercase letters.
 *
 */

#include "header.h"

class Solution {
    public:
        vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
            vector<int> res;
            vector<int> acc(11, 0), cnt(11, 0);

            for (string word : words) {
                cnt[freq(word)]++;
            }
            for (int i = 1; i < 11; i++) {
                acc[i] = acc[i - 1] + cnt[i];
            }
            for (string query : queries) {
                res.push_back(words.size() - acc[freq(query)]);
            }
            return res;
        }

        // s.length >= 1
        int freq(string s) {
            char candidate = s[0];
            int cnt = 1, len = s.length();
            for (int i = 1; i < len; i++) {
                if (s[i] == candidate) {
                    cnt++;
                } else if (s[i] < candidate) {
                    candidate = s[i];
                    cnt = 1;
                }
            }
            return cnt;
        }
};
