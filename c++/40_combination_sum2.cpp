/*
 * 40. Combination Sum II
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate numbers
 * sums to target.
 *
 * Each number in candidates may only be used once in the combination.
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
        vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
            vector<int> comb;
            sort(candidates.begin(), candidates.end());
            backtrack(comb, candidates, target, 0);
            return res;
        }

        void backtrack(vector<int> &comb, vector<int> &candi,
                       int target, int start) {
            if (!target) {
                res.push_back(comb);
                return;
            }

            int n = candi.size();
            for (int i = start; i < n; i++) {
                if (candi[i] > target) {
                    continue;
                }

                if (i > start && candi[i] == candi[i - 1]) {
                    continue;
                }

                comb.push_back(candi[i]);
                backtrack(comb, candi, target - candi[i], i + 1);
                comb.pop_back();
            }
        }
};
