/*
 * 1004. Max Consecutive Ones III
 *
 * Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
 *
 * Return the length of the longest (contiguous) subarray that contains only 1s.
 *
 * Note:
 *
 * 1 <= A.length <= 20000
 * 0 <= K <= A.length
 * A[i] is 0 or 1
 */

#include "header.h"

class Solution {
    public:
        int longestOnes(vector<int>& A, int K) {
            int res = 0, slow = 0, fast = 0;
            int zero_cnt = 0, size = A.size();
            while (fast < size) {
                zero_cnt += A[fast] == 0;
                while (zero_cnt > K) {
                    zero_cnt -= A[slow] == 0;
                    slow++;
                }
                res = max(res, fast - slow + 1);
                fast++;
            }
            return res;
        }
};
