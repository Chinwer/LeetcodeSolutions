/*
 * 39. Combination Sum
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 */

#include "header.h"

class Solution {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
            vector<int> comb;
            backtrack(comb, candidates, target, 0);
            return res;
        }

        void backtrack(vector<int> &comb, vector<int> &candidates,
                       int target, int start) {
            if (!target) {
                res.push_back(comb);
                return;
            }

            int n = candidates.size();
            for (int i = start; i < n; i++) {
                if (candidates[i] > target) {
                    continue;
                }

                comb.push_back(candidates[i]);
                backtrack(comb, candidates, target - candidates[i], i);
                comb.pop_back();
            }
        }
};
