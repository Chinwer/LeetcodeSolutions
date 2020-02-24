/*
 * 254. Factor Combinations
 * Numbers can be regarded as product of its factors. For example,
 *
 * 8 = 2 x 2 x 2;
 * = 2 x 4.
 *
 * Write a function that takes an integer n and return all possible combinations
 * of its factors.
 *
 * Note:
 *
 * You may assume that n is always positive.
 * Factors should be greater than 1 and less than n.
 */

#include "header.h"

class Solution {
    private:
        vector<vector<int>> res;

    public:
        vector<vector<int>> getFactors(int n) {
            vector<int> output;
            backtrack(output, n, 2);
            return res;
        }

        void backtrack(vector<int> &output, int n, int start) {
            if (output.size() >= 1) {
                output.push_back(n);
                res.push_back(output);
                output.pop_back();
            }

            int end = sqrt(n);
            for (int i = start; i <= end; i++) {
                if (!(n % i)) {
                    output.push_back(i);
                    backtrack(output, n / i, i);
                    output.pop_back();
                }
            }
        }
};
