/*
 * 1085. Sum of Digits in the Minimum Number
 * Given an array A of positive integers, let S be the sum of the digits of the
 * minimal element of A.
 *
 * Return 0 if S is odd, otherwise return 1.
 *
 * Note:
 *
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 */

#include "header.h"

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min_ = INT32_MAX;
        for (int a : A) {
            if (a < min_) {
                min_ = a;
            }
        }

        int res = 0;
        string digits = to_string(min_);
        for (char d : digits) {
            res += (d - '0') % 2;
            res %= 2;
        }

        return 1 - res;
    }
};
