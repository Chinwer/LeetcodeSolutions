/*
 * 560. Subarray Sum Equals K
 *
 * Given an array of integers and an integer k, you need to find the
 * total number of continuous subarrays whose sum equals to k.
 *
 * Constraints:
 *   - The length of the array is in range [1, 20000].
 *   - The range of numbers in the array is [-1000, 1000] and the
 *     range of the integer k is [-1e7, 1e7].
 */
#include "header.h"

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> cnt;
            cnt[0] = 1;
            int res = 0, pre = 0;
            for (auto &num : nums) {
                pre += num;
                if (cnt.count(pre - k)) {
                    res += cnt[pre - k];
                }
                cnt[pre]++;
            }
            return res;
        }
};
