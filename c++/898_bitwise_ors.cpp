/*
 * 898. Bitwise ORs of Subarrays
 *
 * We have an array A of non-negative integers.
 *
 * For every (contiguous) subarray B = [A[i], A[i + 1], ..., A[j]]
 * (with i <= j), we take the bitwise OR of all the elements in B,
 * obtaining a result A[i] | A[i + 1] | ... | A[j].
 *
 * Return the number of possible results. (Results that occur more
 * than once are only counted once in the final answer.)
 *
 * Note:
 *   1. 1 <= A.length <= 50000
 *   2. 0 <= A[i] <= 10^9
 */

#include "header.h"

class Solution {
    public:
        int subarrayBitwiseORs(vector<int>& A) {
            int n = A.size();
            if (n < 2) {
                return n;
            }
            unordered_set<int> set;
            for (int i = 0; i < n; i++) {
                set.insert(A[i]);
                for (int j = i - 1; j >= 0; j--) {
                    if ((A[j] | A[i]) == A[j]) {
                        break;
                    }
                    A[j] |= A[i];
                    set.insert(A[j]);
                }
            }
            return set.size();
        }
};
