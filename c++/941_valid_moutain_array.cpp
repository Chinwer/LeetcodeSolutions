/*
 * 941. Valid Mountain Array
 * Given an array A of integers, return true if and only if it is a valid mountain array.
 *
 * Recall that A is a mountain array if and only if:
 *
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 * A[0] < A[1] < ... A[i-1] < A[i]
 * A[i] > A[i+1] > ... > A[A.length - 1]
 *
 * Note:
 *
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 */

#include "header.h"

class Solution {
    public:
        bool validMountainArray(vector<int>& A) {
            int size = A.size();
            if (size < 3) {
                return false;
            }

            int i;
            for (i = 0; i < size - 1; i++) {
                if (A[i + 1] > A[i]) {
                    continue;
                } else if (A[i + 1] == A[i]) {
                    return false;
                } else {
                    break;
                }
            }
            if (i == size - 1 || i == 0) {
                return false;
            }
            while (i < size - 1) {
                if (A[i + 1] >= A[i]) {
                    return false;
                }
                i++;
            }
            return true;
        }
};
