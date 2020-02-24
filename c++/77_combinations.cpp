/*
 * 77. Combinations
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 */

#include "header.h"

class Solution {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> combine(int n, int k) {
            // vector<int> comb;
            // backtrack(comb, n, k, 0);
            // return res;

            vector<int> nums(k);
            init(nums, n, k);

            int j = 0;
            while (j < k) {
                res.push_back(vector<int>(nums.begin(), nums.end() - 1));
                j = 0;
                while (j < k && nums[j + 1] == nums[j] + 1) {
                    nums[j] = j + 1;
                    j++;
                }
                nums[j]++;
            }

            return res;
        }

        void init(vector<int> &nums, int n, int k) {
            for (int i = 0; i < k; i++) {
                nums[i] = i + 1;
            }
            nums.push_back(n + 1);
        }

        void backtrack(vector<int> &comb, int n, int k, int start) {
            if (comb.size() == k) {
                res.push_back(comb);
                return;
            }

            for (int i = start; i < n; i++) {
                comb.push_back(i + 1);
                backtrack(comb, n, k, i + 1);
                comb.pop_back();
            }
        }
};
