/*
 * 219. Contains Duplicate
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 */

#include <map>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            map<int, int> dict;
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                if (!dict.count(nums[i])) {
                    dict[nums[i]] = 1;
                } else {
                    return true;
                }
                if (dict.size() > k) {
                    dict.erase(nums[i - k]);
                }
            }
            return false;
        }
};
