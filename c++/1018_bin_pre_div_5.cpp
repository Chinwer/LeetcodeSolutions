/*
 * 1018. Binary Prefix Divisible By 5
 * Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to
 * A[i] interpreted as a binary number (from most-significant-bit to
 * least-significant-bit.)
 *
 * Return a list of booleans answer, where answer[i] is
 * true if and only if N_i is divisible by 5.
 *
 * Note:
 *     * 1 <= A.length <= 30000
 *     * A[i] is 0 or 1
 */

#include "header.h"

class Solution {
    public:
        vector<bool> prefixesDivBy5(vector<int>& A) {
            int mod = 0;
            int size = A.size();
            vector<bool> res(size);
            for (int i = 0; i < size; i++) {
                mod = (mod * 2 + A[i]) % 5;
                if (!mod) {
                    res[i] = true;
                }
            }
            return res;
        }
};
