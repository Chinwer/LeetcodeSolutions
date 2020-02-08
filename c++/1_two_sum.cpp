/*
 * 1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target. You may assume that each input would have
 * exactly one solution, and you may not use the same element twice.
 */

#include <map>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            vector<int> res;
            // map<value, index>
            map<int, int> map;
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                if (map.count(nums[i])) {
                    res.push_back(map[nums[i]]);
                    res.push_back(i);
                    return res;
                }
                map[target - nums[i]] = i;
            }
            return res;
        }
};
