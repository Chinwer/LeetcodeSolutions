/*
 * 面试题 08.04. Power Set LCCI
 *
 * Write a method to return all subsets of a set.
 * The elements in a set are pairwise distinct.
 *
 * Note: The result set should not contain duplicated subsets.
 */

#include "header.h"

class Solution {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            // return solution1(nums);
            return solution2(nums);
        }

        vector<vector<int>> solution2(vector<int> &nums) {
            int n = nums.size();
            res.push_back({});
            for (int i = 0; i < n; i++) {
                auto tmp = res;
                for (auto t : tmp) {
                    t.push_back(nums[i]);
                    res.push_back(t);
                }
            }
            return res;
        }

        vector<vector<int>> solution1(vector<int> &nums) {
            int n = nums.size();
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
