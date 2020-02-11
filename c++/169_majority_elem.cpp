/*
 * 169. Majority Element
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times. You may assume that the
 * array is non-empty and the majority element always exist in the array.
 */

#include <map>
#include <vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            // Hash map algorithm
            //
            // int size = nums.size();
            // int major = size / 2;
            // map<int, int> dict;

            // for (int i = 0; i < size; i++) {
            //     if (dict.count(nums[i])) {
            //         dict[nums[i]]++;
            //     } else {
            //         dict[nums[i]] = 0;
            //     }
            // }
            // for (auto it : dict) {
            //     if (it.second >= major) {
            //         return it.first;
            //     }
            // }
            // return -1;

            // Boyer-Moore voting algorithm
            int cnt = 0;
            int candidate;
            int size = nums.size();
            for (int num : nums) {
                if (cnt == 0) {
                    candidate = num;
                }
                cnt += (num == candidate ? 1 : -1);
            }
            return candidate;
        }
};
