/*
 * 697. Degree of an Array
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements. Your
 * task is to find the smallest possible length of a (contiguous) subarray of
 * nums, that has the same degree as nums.
 *
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 */

#include "header.h"

class Solution {
    public:
        int findShortestSubArray(vector<int>& nums) {
            /* Method 1 */
           
            //    if (nums.empty()) {
            //     return 0;
            // }

            // int degree = 0;
            // map<int, int> dict;
            // int size = nums.size();
            // map<int, vector<int>> pos;
            // for (int i = 0; i < size; i++) {
            //     dict[nums[i]]++;
            //     pos[nums[i]].push_back(i);
            //     degree = max(degree, dict[nums[i]]);
            // }

            // int res = INT32_MAX;
            // for (auto it : dict) {
            //     if (it.second == degree) {
            //         int dist = pos[it.first].back() - pos[it.first].front() + 1;
            //         res = min(res, dist);
            //     }
            // }
            // return res;

            /* Method 2 */

            if (nums.empty()) {
                return 0;
            }

            int degree = 0;
            int res = INT32_MAX;
            int size = nums.size();
            map<int, int> dict;
            map<int, vector<int>> pos;

            for (int i = 0; i < size; i++) {
                dict[nums[i]]++;
                if (pos[nums[i]].size() <= 2) {
                    pos[nums[i]].push_back(i);
                } else {
                    pos[nums[i]].back() = i;
                }
                if (dict[nums[i]] > degree) {
                    degree = dict[nums[i]];
                    res = pos[nums[i]].back() - pos[nums[i]].front() + 1;
                } else if (dict[nums[i]] == degree) {
                    res = min(res, pos[nums[i]].back() - pos[nums[i]].front() + 1);
                }
            }

            return res;
        }
};
