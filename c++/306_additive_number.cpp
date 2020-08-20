/*
 * 306. Additive Number
 *
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at leat three numbers.
 * Except for the first two numbers, each subsequent number in the sequence
 * must be the sum of the preceding two.
 *
 * Given a string containing only digits '0'-'9', write a function to
 * determine if it's an additive number.
 *
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Constraints:
 *   - num consists only of digits '0'-'9'.
 *   - 1 <= num.length <= 35
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 */

#include "header.h"

class Solution {
    public:
        bool isAdditiveNumber(string num) {
            int n = num.size();
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (dfs(0, i, j, num)) {
                        return true;
                    }
                }
            }
            return false;
        }

        bool dfs(int i, int j, int k, string &s) {
            if ((s[i] == '0' && j - i > 1) ||
                (s[j] == '0' && k - j > 1)) {
                return false;
            }
            string a = s.substr(i, j - i);
            string b = s.substr(j, k - j);
            string sum = add(a, b);
            int n = sum.size(), m = s.size();
            if (k + n > m || sum != s.substr(k, n)) {
                return false;
            }
            if (k + n == m) {
                return true;
            }
            return dfs(j, k, k + n, s);
        }

        string add(string &a, string &b) {
            string res;
            int carry = 0;
            int i = a.size() - 1;
            int j = b.size() - 1;

            while (i >= 0 || j >= 0 || carry > 0) {
                int n1 = i >= 0 ? a[i--] - '0' : 0;
                int n2 = j >= 0 ? b[j--] - '0' : 0;
                res += (n1 + n2 + carry) % 10 + '0';
                carry = (n1 + n2 + carry) / 10;
            }
            reverse(res.begin(), res.end());
            return res;
        }
};
