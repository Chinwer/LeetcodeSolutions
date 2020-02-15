/*
 * 1099. Two Sum Less Than K
 * Given an array A of integers and integer K, return the maximum S such that
 * there exists i < j with A[i] + A[j] = S and S < K. If no i, j exist
 * satisfying this equation, return -1.
 *
 * Note:
 *
 * 1 <= A.length <= 100
 * 1 <= A[i] <= 1000
 * 1 <= K <= 2000
 */

#include "header.h"

class Solution {
    public:
        int twoSumLessThanK(vector<int>& A, int K) {
            int res = -1;
            int size = A.size();
            sort(A.begin(), A.end());

            int l = 0, r  = size - 1;
            while (l < r) {
                if (A[l] + A[r] >= K) {
                    r--;
                } else {
                    res = max(res, A[l] + A[r]);
                    l++;
                }
            }

            return res;
        }
};
