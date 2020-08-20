/*
 * 1291. Sequential Digits
 *
 * An integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit.
 *
 * Return a sorted list of all the integers in the range [low, high] inclusive
 * that have sequential digits.
 *
 * Constraints:
 *   - 10 <= low <= high <= 10^9
 */

#include "header.h"

class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> res;
            for (int i = 1; i <= 9; i++) {
                int num = i;
                for (int j = i + 1; j <= 9; j++) {
                    num = 10 * num + j;
                    if (low <= num && num <= high) {
                        res.push_back(num);
                    }
                }
            }
            sort(res.begin(), res.end());
            return res;
        }
};
