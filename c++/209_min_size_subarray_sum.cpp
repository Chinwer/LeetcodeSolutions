/*
 * 209. Minimum Size Subarray Sum
 *
 * Given an array of n positive integers and a positive integer s,
 * find the minimal length of a contiguous subarray of which the sum ≥ s.
 * If there isn't one, return 0 instead.
 *
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution
 * of which the time complexity is O(n log n). 
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            // brute force solution, time limit exceeded
            // int res = INT32_MAX;
            // int size = nums.size();
            // for (int i = 0; i < size; i++) {
            //     int sum = 0;
            //     for (int j = i; j < size; j++) {
            //         sum += nums[j];
            //         if (sum >= s && (j - i + 1) < res) {
            //             res = j - i + 1;
            //         }
            //     }
            // }
            // return res == INT32_MAX ? 0 : res;

            // O(n) time complexity solution
            if (nums.empty()) {
                return 0;
            }

            int sum = 0, left = 0, right = 0;
            // change INT32_MAX to INT_MAX when submiting on Leetcode
            int res = INT32_MAX, size = nums.size();
            while (right < size) {
                sum += nums[right];
                while (sum >= s) {
                    res = min(res, right - left + 1);
                    sum -= nums[left];
                    left++;
                }
                right++;
            }
            return res == INT32_MAX ? 0 : res;
        }
};
