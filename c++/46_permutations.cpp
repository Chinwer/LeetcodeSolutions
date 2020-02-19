/*
 * 46. Permutations.
 * Given a collection of distinct integers, return all possible permutations.
 */

#include "header.h"

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        permutation(res, 0, nums);
        return res;
    }

    void permutation(vector<vector<int>> &res, int start, vector<int> &nums)
    {
        int n = nums.size();
        if (start == n)
        {
            res.push_back(nums);
        }
        else
        {
            for (int i = start; i < n; i++)
            {
                swap(nums[start], nums[i]);
                permutation(res, start + 1, nums);
                swap(nums[start], nums[i]);
            }
        }
    }

    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
