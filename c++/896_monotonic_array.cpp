/*
 * 896. Monotonic Array
 * An array is monotonic if it is either monotone increasing or monotone decreasing.
 *
 * An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
 *
 * Return true if and only if the given array A is monotonic.
 *
 * Note:
 *
 * 1 <= A.length <= 50000
 * -100000 <= A[i] <= 100000
 */

#include "header.h"

class Solution {
    public:
        bool isMonotonic(vector<int>& A) {
            /* Method 1 */
           
            // int size = A.size();
            // if (size < 2) {
            //     return true;
            // }

            // int i = 0;
            // while (i < size - 1 && A[i] == A[i + 1]) {
            //     i++;
            // }
            // if (i == size - 1) {
            //     return true;
            // }

            // bool is_inc = A[i + 1] > A[i];
            // while (i < size - 1) {
            //     if (A[i + 1] != A[i] && A[i + 1] >= A[i] != is_inc) {
            //         return false;
            //     }
            //     i++;
            // }
            // return true;

            /* Method 2 */
            int size = A.size();
            if (size < 2) {
                return true;
            }

            bool is_inc = false;
            bool is_dec = false;

            for (int i = 0; i < size - 1; i++) {
                if (A[i + 1] > A[i]) {
                    is_inc = true;
                }
                if (A[i + 1] < A[i]) {
                    is_dec = true;
                }
                if (is_inc && is_dec) {
                    return false;
                }
            }
            return true;
        }
};
