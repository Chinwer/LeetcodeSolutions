/*
 * Interview 10.01. Sorted Merge LCCI
 */

#include "header.h"

class Solution {
    public:
        void merge(vector<int>& A, int m, vector<int>& B, int n) {
            int idx = m + n - 1;
            m--;
            n--;
            while (n >= 0) {
                if (m < 0 || B[n] >= A[m]) {
                    A[idx--] = B[n--];
                } else {
                    A[idx--] = A[m--];
                }
            }
        }
};
