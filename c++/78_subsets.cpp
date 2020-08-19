/*
 * 78. Subsets
 *
 * Given a set of distinct integers, nums, return all possible subsets
 * (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 */

#include "header.h"

class Solution {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> chosen;
            backtrack(0, nums, chosen);
            return res;
        }

        void backtrack(int start, vector<int> &nums, vector<int> &chosen) {
            int n = nums.size();
            res.push_back(chosen);
            for (int i = start; i < n; i++) {
                chosen.push_back(nums[i]);
                backtrack(i + 1, nums, chosen);
                chosen.pop_back();
            }
        }
};
