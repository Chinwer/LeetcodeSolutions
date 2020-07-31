/*
 * 338. Counting Bits
 *
 * Given a non negative integer number num.
 * For every numbers i in the range 0 <= i <= num calculate the number
 * of 1's in their binary representation and return them as an array.
 *
 * Follow up:
 *
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */

#include "header.h"

class Solution {
    public:
        vector<int> countBits(int num) {
            vector<int> dp(num + 1);
            for (int i = 1; i <= num; i++) {
                // solution1
                // dp[i] = dp[i >> 1] + (i & 1);

                // solution2
                dp[i] = dp[i & (i - 1)] + 1;
            }
            return dp;
        }
};
