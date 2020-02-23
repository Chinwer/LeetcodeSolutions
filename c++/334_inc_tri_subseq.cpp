/*
 * 334. Increasing Triplet Subsequence
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 *
 * Formally the function should:
 *
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 *
 * Note:
 *
 * Your algorithm should run in O(n) time complexity and O(1) space complexity.
 */

#include "header.h"

class Solution {
    public:
        bool increasingTriplet(vector<int> &nums) {
            /* Method 1 */
            // int n = nums.size();
            // vector<int> dp(1, INT32_MAX);

            // for (int num : nums) {
            //     if (num > dp.back()) {
            //         dp.push_back(num);
            //         if (dp.size() > 2) {
            //             return true;
            //         }
            //     } else {
            //         for (int &d : dp) {
            //             if (d >= num) {
            //                 d = num;
            //                 break;
            //             }
            //         }
            //     }
            // }

            // return false;

            /* Method 2(Optimized method 1) */
            int n = nums.size();
            if (n < 3) {
                return false;
            }

            int min = INT32_MAX, mid = INT32_MAX;
            for (int num : nums) {
                if (num <= min) {
                    min = num;
                } else if (num <= mid) {
                    mid = num;
                } else {
                    return true;
                }
            }
            return false;
        }
};
