/*
 * 357. Count Numbers with Unique Digits
 *
 * Given a non-negative integer n, count all numbers with unique
 * digits, x, where 0 <= x < 10^n.
 *
 * Constraints:
 *   - 0 <= n <= 8
 */

#include "header.h"

class Solution {
    public:
        int countNumbersWithUniqueDigits(int n) {
            if (!n) {
                return 1;
            }
            if (n == 1) {
                return 9;
            }
            int dp = 9;
            // base case
            int res = 10;
            for (int i = 2; i <= n; i++) {
                dp = (11 - i) * dp;
                res += dp;
            }
            return res;
        }
};
