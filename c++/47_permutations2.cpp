/*
 * 47. Permutatios II
 * Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> res;
            permutation(res, 0, nums);
            return res;
        }

        void permutation(vector<vector<int>> &res, int start, vector<int>& nums) {
            int n = nums.size();
            if (start == n) {
                res.push_back(nums);
            } else {
                map<int, int> cnt;
                for (int i = start; i < n; i++) {
                    if (!cnt[nums[i]]) {
                        swap(nums[i], nums[start]);
                        permutation(res, start + 1, nums);
                        swap(nums[i], nums[start]);
                        cnt[nums[i]]++;
                    }
                }
            }
        }

        void swap(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
};
