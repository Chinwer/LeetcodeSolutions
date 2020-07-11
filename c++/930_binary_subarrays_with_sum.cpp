/*
 * 930. Binary Subarrays With Sum
 *
 * In an array A of 0s and 1s, how many non-empty subarrays have sum S?
 *
 * Note:
 * 1. A.length <- 30000
 * 2. 0 <= S  <= A.length
 * 3. A[i] is either 0 or 1
 */

#include "header.h"

class Solution {
    public:
        int numSubarraysWithSum(vector<int>& A, int S) {
            int res = 0, sum = 0;
            map<int, int> cnt;
            cnt[0]++;
            for (int a : A) {
                sum += a;
                res += cnt[sum - S];
                cnt[sum]++;
            }
            return res;
        }
};
