/*
 * 415. Add Strings
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * Note:
 *     1. The length of both num1 and num2 is < 5100.
 *     2. Both num1 and num2 contains only digits 0-9.
 *     3. Both num1 and num2 does not contain any leading zero.
 *     4. You must not use any built-in BigInteger library or convert the inputs to
 *        integer directly.
 */

#include <string>
using namespace std;

int max(int a, int b);

class Solution {
    public:
        string addStrings(string num1, string num2) {
            int len1 = num1.length();
            int len2 = num2.length();
            int len = max(len1, len2);

            int carry = 0;
            int i = len1 - 1;
            int j = len2 - 1;
            int idx = len - 1;
            string res(len, 0);

            while (i >= 0 && j >= 0) {
                carry += (num1[i--] + num2[j--] - '0' - '0');
                res[idx--] = (carry % 10);
                carry /= 10;
            }
            while (i >= 0) {
                carry += (num1[i--] - '0');
                res[idx--] = (carry % 10);
                carry /= 10;
            }
            while (j >= 0) {
                carry += (num2[j--] - '0');
                res[idx--] = (carry % 10);
                carry /= 10;
            }
            if (carry != 0) {
                res.insert(0, to_string(carry));
                return res;
            }
            res.erase(0, res.find_first_not_of('0'));
            if (res.empty()) {
                return "0";
            }
            return res;
        }
};
