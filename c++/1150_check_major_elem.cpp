/*
 * 1150. Check If a Number Is Majority Element in a Sorted Array
 * Given an array nums sorted in non-decreasing order, and a number target,
 * return True if and only if target is a majority element. A majority element
 * is an element that appears more than N/2 times in an array of length N.
 *
 * Note:
 *     1. 1 <= nums.length <= 1000
 *     2. 1 <= nums[i] <= 10^9
 *     3. 1 <= target <= 10^9
 */

#include <vector>
using namespace std;

class Solution {
public:
  bool isMajorityElement(vector<int> &nums, int target) {
      int cnt = 0;
      int size = nums.size();
      for (int num : nums) {
          cnt += (num == target) ? 1 : 0;
      }
      return cnt > size / 2;
  }
};
