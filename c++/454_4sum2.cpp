/*
 * 454. 4Sum II
 * Given four lists A, B, C, D of integer values, compute how many tuples (i, j,
 * k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤
 * 500. All integers are in the range of -228 to 228 - 1 and the result is
 * guaranteed to be at most 231 - 1.
 *
 */

#include "header.h"

class Solution {
    public:
        int fourSumCount(vector<int> &A, vector<int> &B,
                         vector<int> &C, vector<int> &D) {
            int size = A.size();
            if (!size) {
                return 0;
            }

            int res = 0;
            map<int, int> cnt;
            for (int a : A) {
                for (int b : B) {
                    cnt[-a - b]++;
                }
            }
            for (int c : C) {
                for (int d : D) {
                    res += cnt[c + d];
                }
            }

            return res;
        }
};
