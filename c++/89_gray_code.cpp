/*
 * 89. Gray Code
 *
 * The gray code is a binary numeral system where two successive values
 * differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in
 * the code, print the sequence of gray code.
 * A gray code sequence must begin with 0.
 */

#include "header.h"

class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> res;
            vector<string> digits;
            digits.push_back("0");
            for (int i = 0; i < n; i++) {
                vector<string> tmp;
                for (string d : digits) {
                    tmp.push_back("0" + d);
                }
                reverse(digits.begin(), digits.end());
                for (string d : digits) {
                    tmp.push_back("1" + d);
                }
                digits = tmp;
            }
            for (string d : digits) {
                res.push_back(str_to_int(d));
            }
            return res;
        }

        int str_to_int(string digits) {
            int n = digits.length(), num = 0;
            for (int i = 0; i < n; i++) {
                num += (1 << i) * (digits[i] - '0');
            }
            return num;
        }
};
