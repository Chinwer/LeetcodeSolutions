/*
 * 1133. Largest Unique Number
 * Given an array of integers A, return the largest integer that only occurs
 * once.
 *
 * If no integer occurs once, return -1.
 *
 * Note:
 *
 * 1 <= A.length <= 2000
 * 0 <= A[i] <= 1000
 */

#include "header.h"

class Solution {
    public:
        int largestUniqueNumber(vector<int>& A) {
            int res = -1;
            map<int, int> cnt;
            for (int a : A) {
                cnt[a]++;
            }
            for (auto it : cnt) {
                if (it.first > res && it.second == 1) {
                    res = it.first;
                }
            }
            return res;
        }
};
