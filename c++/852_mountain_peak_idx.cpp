/*
 * 852. Peak Index in a Mountain Array
 */

#include "header.h"

class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& A) {
            for (int i = 0; i < A.size() - 1; i++) {
                if (A[i + 1] < A[i]) {
                    return i;
                }
            }
            return -1;
        }
};
