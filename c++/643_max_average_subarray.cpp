/*
 * 643. Maximum Average Subarray I
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
 *
 * Note:
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            double res = 0;
            double sum = 0;
            int size = nums.size();
            for (int i = 0; i < k; i++) {
                sum += nums[i];
            }
            res = sum;
            for (int i = k; i < size; i++) {
                sum += (nums[i] - nums[i - k]);
                res = max(res, sum);
            }
            return res / k;
        }
};
