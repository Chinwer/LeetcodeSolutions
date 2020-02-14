/*
 * 1013. Partition Array Into Three Parts With Equal Sum
 * Given an array A of integers, return true if and only if we can partition the
 * array into three non-empty parts with equal sums.
 *
 * Formally, we can partition the array if we can find indexes i+1 < j with
 * (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1]
 * + ... + A[A.length - 1])
 *
 * Note:

 * 3 <= A.length <= 50000
 * -10000 <= A[i] <= 10000
 */

#include "header.h"

class Solution {
    public:
        bool canThreePartsEqualSum(vector<int>& A) {
            // int sum = 0;
            // for (int a : A) {
            //     sum += a;
            // }
            // if (sum % 3) {
            //     return false;
            // }

            // int s = 0;
            // int cnt = 0;
            // int size = A.size();
            // for (int i = 0; i < size; i++) {
            //     s += A[i];
            //     if (s == sum / 3) {
            //         cnt++;
            //         s = 0;
            //     }
            // }
            // return cnt == 3;

            int sum = 0;
            for (int a : A) {
                sum += a;
            }
            if (sum % 3) {
                return false;
            }

            int avg = sum / 3;
            int size = A.size();
            int lsum = 0, rsum = 0;
            int i = 0, j = size - 1;

            while (i < size) {
                lsum += A[i];
                if (lsum == avg) {
                    break;
                }
                i++;
            }
            while (j >= 0) {
                rsum += A[j];
                if (rsum == avg) {
                    break;
                }
                j--;
            }

            return i < j && lsum == rsum && lsum == avg;
        }
};
