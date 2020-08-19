/*
 * 784. Letter Case Permutation
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.
 *
 * Return a list of all possible strings we could create. You can return the
 * output in any order.
 *
 * Constraints:
 *   - S will be a string with length between 1 and 12.
 *   - S will consist only of letters or digits.
 */

#include "header.h"

class Solution {
    private:
        vector<string> res;

    public:
        vector<string> letterCasePermutation(string S) {
            backtrack(0, S);
            return res;
        }

        void backtrack(int start, string &s) {
            res.push_back(s);
            int n = s.length();
            for (int i = start; i < n; i++) {
                if (is_digit(s[i])) {
                    continue;
                }
                int delta;
                if (is_lowercase(s[i])) {
                    delta = -32;
                } else {
                    delta = 32;
                }
                s[i] += delta;
                backtrack(i + 1, s);
                s[i] -= delta;
            }
        }

        bool is_digit(char c) {
            return '0' <= c && c <= '9';
        }

        bool is_lowercase(char c) {
            return 'a' <= c && c <= 'z';
        }
};
