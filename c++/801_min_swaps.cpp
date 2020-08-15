/*
 * 801. Minimum Swaps To Make Sequences Increasing
 *
 * We have two integer sequences A and B of the same non-zero length.
 *
 * We are allowed to swap elements A[i] and B[i].  Note that both
 * elements are in the same index position in their respective sequences.
 *
 * At the end of some number of swaps, A and B are both strictly increasing.
 * (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ...
 * < A[A.length - 1].)
 *
 * Given A and B, return the minimum number of swaps to make both sequences
 * strictly increasing.  It is guaranteed that the given input always makes
 * it possible.
 *
 * Note:
 *
 *   - A, B are arrays with the same length, and that length will be in the range [1, 1000].
 *   - A[i], B[i] are integer values in the range [0, 2000].
 */

#include "header.h"

class Solution {
    public:
        int minSwap(vector<int>& A, vector<int>& B) {
            int n = A.size();
            int dp_keep = 0, dp_swap = 1;
            for (int i = 1; i < n; i++) {
                int tmp_keep = dp_keep, tmp_swap = dp_swap;
                bool b1 = A[i] > A[i - 1] && B[i] > B[i - 1];
                bool b2 = A[i] > B[i - 1] && B[i] > A[i - 1];
                if (b1 && b2) {
                    dp_keep = min(tmp_keep, tmp_swap);
                    dp_swap = min(tmp_keep, tmp_swap) + 1;
                } else if (b1) {
                    dp_swap++;
                } else {
                    dp_keep = tmp_swap;
                    dp_swap = tmp_keep + 1;
                }
            }
            return min(dp_keep, dp_swap);
        }
};
