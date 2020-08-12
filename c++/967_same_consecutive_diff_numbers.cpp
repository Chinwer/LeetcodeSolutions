/*
 * 967. Numbers With Same Consecutive Differences
 *
 * Return all non-negative integers of length N such that the absolute
 * difference between every two consecutive digits is K.
 *
 * Note that every number in the answer must not have leading zeros
 * except for the number 0 itself. For example, 01 has one leading
 * zero and is invalid, but 0 is valid.
 *
 * You may return the answer in any order.
 *
 * Note:
 *   1. 1 <= N <= 9
 *   2. 0 <= K <= 9
 */

#include "header.h"

class Solution {
    public:
        vector<int> numsSameConsecDiff(int N, int K) {
            vector<int> res = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            for (int n = 1; n < N; n++) {
                set<int> tmp;
                for (int num : res) {
                    if (!num) {
                        continue;
                    }
                    int last_digit = num % 10;
                    if (last_digit - K >= 0) {
                        tmp.insert(num * 10 + last_digit - K);
                    }
                    if (last_digit + K <= 9) {
                        tmp.insert(num * 10 + last_digit + K);
                    }
                }
                res = vector(tmp.begin(), tmp.end());
            }
            return res;
        }
};
