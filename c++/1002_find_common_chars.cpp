/*
 * 1002. Find Common Characters
 * Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
 *
 * You may return the answer in any order.
 *
 * Note:
 *
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
 */

#include "header.h"

class Solution {
    public:
        vector<string> commonChars(vector<string>& A) {
            /* Method 1 */
            // vector<string> res;
            // int size = A.size();
            // string inter = A[0];
            // for (int i = 1; i < size; i++) {
            //     string new_inter;
            //     map<char, int> dict;
            //     for (char ch : inter) {
            //         dict[ch]++;
            //     }
            //     for (char ch : A[i]) {
            //         if (--dict[ch] >= 0) {
            //             new_inter.push_back(ch);
            //         }
            //     }
            //     inter = new_inter;
            // }
            // for (char ch : inter) {
            //     res.push_back(string(1, ch));
            // }
            // return res;

            vector<string> res;
            vector<int> cnt(26, 101);
            for (string a : A) {
                vector<int> tmp(26, 0);
                for (char ch : a) {
                    tmp[ch - 'a']++;
                }
                for (int i = 0; i < 26; i++) {
                    cnt[i] = min(cnt[i], tmp[i]);
                }
            }

            for (int i = 0; i < 26; i++) {
                for (int i = 0; i < cnt[i]; i++) {
                    res.push_back(string(1, i + 'a'));
                }
            }
            return res;
        }
};
