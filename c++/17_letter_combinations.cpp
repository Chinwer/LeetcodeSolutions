/*
 * 17. Letter Combination of a Phone Number
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */

#include "header.h"

class Solution {
    private:
        vector<string> chars = {
            "abc", "def",  "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> res = {};

    public:
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) {
                return {};
            }

            string output;
            backtrack(output, digits, 0);
            return res;
        }

        void backtrack(string output, string digits, int idx) {
            if (output.length() == digits.length()) {
                res.push_back(output);
                return;
            }

            int j = digits[idx] - '0' - 2;
            int n = chars[j].length();
            for (int i = 0; i < n; i++) {
                output.push_back(chars[j][i]);
                backtrack(output, digits, idx + 1);
                output.pop_back();
            }
        }
};
