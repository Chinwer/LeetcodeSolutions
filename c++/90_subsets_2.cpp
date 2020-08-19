/*
 * 90. Subsets II
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 */

#include "header.h"

class Solution {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> chosen;
            backtrack(0, nums, chosen);
            return res;
        }

        void backtrack(int start, vector<int> &nums, vector<int> &chosen) {
            int n = nums.size();
            res.push_back(chosen);
            for (int i = start; i < n; i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue;
                }
                chosen.push_back(nums[i]);
                backtrack(i + 1, nums, chosen);
                chosen.pop_back();
            }
        }
};
