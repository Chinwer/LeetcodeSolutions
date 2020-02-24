/*
 * 216. Combination Sum III
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 *
 * Note:
 *
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 */

#include "header.h"

class Solution {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<int> comb, nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            backtrack(comb, nums, k, n, 0);
            return res;
        }

        void backtrack(vector<int> &comb, vector<int> &nums,
                       int k, int n, int start) {
            if (!n) {
                if (comb.size() == k) {
                    res.push_back(comb);
                }
                return;
            }

            for (int i = start; i < 9; i++) {
                if (nums[i] > n) {
                    break;
                }

                comb.push_back(nums[i]);
                if (comb.size() > k) {
                    comb.pop_back();
                    break;
                }
                backtrack(comb, nums, k, n - nums[i], i + 1);
                comb.pop_back();
            }
        }
};
