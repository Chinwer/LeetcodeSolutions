/*
 * 448. Find All Numbers Disappeared in an Array
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once. Find all the elements of [1, n]
 * inclusive that do not appear in this array. Could you do it without extra
 * space and in O(n) runtime? You may assume the returned list does not count as
 * extra space.
 */

#include <map>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            // Hash table
            //
            // vector<int> res;
            // map<int, int> dict;
            // for (int num : nums) {
            //     dict[num]++;
            // }
            // for (int i = 1; i <= nums.size(); i++) {
            //     if (!dict[i]) {
            //         res.push_back(i);
            //     }
            // }
            // return res;

            // In-place
            vector<int> res;
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                int idx = abs(nums[i]) - 1;
                if (nums[idx] > 0) {
                    nums[idx] *= -1;
                }
            }
            for (int i = 1; i <= size; i++) {
                if (nums[i - 1] > 0) {
                    res.push_back(i);
                }
            }
            return res;
        }
};
