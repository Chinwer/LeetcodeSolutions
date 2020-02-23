/*
 * 300. Longest Increasing Subsequence
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Note:
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length. Your algorithm should run in O(n2) complexity.
 *
 * Follow up:
 * Could you improve it to O(n log n) time complexity?
 */

#include "header.h"

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            /* Method 1, O(n^2) */
            // int n = nums.size();
            // if (!n) {
            //     return 0;
            // }

            // int res = 1;
            // vector<int> dp(n, 1);
            // for (int i = 1; i < n; i++) {
            //     int max = 1;
            //     int j = i - 1;
            //     while (j >= 0) {
            //         if (nums[j] < nums[i] && dp[j] > max) {
            //             max = dp[j];
            //         }
            //         j--;
            //     }
            //     dp[i] = max + 1;
            //     if (dp[i] > res) {
            //         res = dp[i];
            //     }
            // }

            // return res;

            /* Method 2, O(nlogn) */
            int res = 0, n = nums.size();
            vector<int> dp(n, 0);
            for (int num : nums) {
                int l = 0, r = res;
                while (l < r) {
                    int m = l + (r - l) / 2;
                    if (dp[m] < num) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                dp[r] = num;
                if (r == res) {
                    res++;
                }
            }
            return res;
        }
};
