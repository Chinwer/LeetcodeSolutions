/*
 * 905. Sort Array By Parity
 * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
 *
 * You may return any answer array that satisfies this condition.
 *
 * Note:
 *
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 */

#include "header.h"

class Solution {
    public:
        vector<int> sortArrayByParity(vector<int>& A) {
            int size = A.size();
            vector<int> res(size);
            int l = 0, r = size - 1;

            for (int i = 0; i < size; i++) {
                if (A[i] % 2) {
                    // odd number
                    res[r--] = A[i];
                } else {
                    // even number
                    res[l++] = A[i];
                }
            }
            return res;
        }
};
