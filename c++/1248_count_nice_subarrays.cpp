/*
 * 1248. Count Number of Nice Subarrays
 *
 * Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.
 * Return the number of nice sub-arrays.
 *
 * Constraints:

 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 */

#include "header.h"

class Solution {
    public:
        int numberOfSubarrays(vector<int>& nums, int k) {
            /* math solution */
            // odds[i] represents index of the kth odd number in nums

            // vector<int> odds = { -1 };
            // int size = nums.size();
            // for (int i = 0; i < size; i++) {
            //     if (nums[i] & 1) {
            //         // nums[i] is an odd number
            //         odds.push_back(i);
            //     }
            // }
            // odds.push_back(size);

            // int res = 0;
            // size = odds.size() - 1;
            // for (int i = 1; i + k <= size; i++) {
            //     res += (odds[i] - odds[i - 1]) * (odds[i + k] - odds[i + k - 1]);
            // }
            // return res;

            /* prefix sum solution */
            vector<int> cnt;
            cnt.push_back(1);
            int res = 0, odd = 0;
            for (int num : nums) {
                odd += num & 1;
                res += odd >= k ? cnt[odd - k] : 0;
                cnt[odd]++;
            }
            return res;
        }
};
