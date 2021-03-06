/*
 * 167. Two Sum II - Input array is sorted
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number. The function
 * twoSum should return indices of the two numbers such that they add up to the
 * target, where index1 must be less than index2.
 *
 * Note:
 *     1. Your returned answers (both index1 and index2) are not zero-based.
 *     2. You may assume that each input would have exactly one solution and
 *        you may not use the same element twice.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int low = 0;
            int high = numbers.size() - 1;
            while (low < high) {
                int sum = numbers[low] + numbers[high];
                if (sum == target) {
                    return { low + 1, high + 1 };
                } else if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
            return { -1, -1 };
        }
};
