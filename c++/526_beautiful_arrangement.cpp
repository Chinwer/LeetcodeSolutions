/*
 * 526. Beautiful Arrangement
 *
 * Suppose you have N integers from 1 to N.
 * We define a beautiful arrangement as an array that is constructed
 * by these N numbers successfully if one of the following is true for
 * the ith position (1 <= i <= N) in this array:
 *   - The number at the ith position is divisible by i.
 *   - i is divisible by the number at the ith position.
 *
 * Now given N, how many beautiful arrangements can you construct?
 *
 * Note:
 *   - N is a positive integer and will not exceed 15.
 */

#include "header.h"

class Solution {
    private:
        int res = 0, N;

    public:
        int countArrangement(int N) {
            this->N = N;
            vector<int> nums;
            for (int i = 1; i <= N; i++) {
                nums.push_back(i);
            }
            backtrack(0, nums);
            return res;
        }

        void backtrack(int start, vector<int> &nums) {
            if (start == N) {
                res++;
                return;
            }
            for (int i = start; i < N; i++) {
                if (divisible(start + 1, nums[i])) {
                    swap(nums[i], nums[start]);
                    backtrack(start + 1, nums);
                    swap(nums[i], nums[start]);
                }
            }
        }

        bool divisible(int a, int b) {
            return a % b == 0
                || b % a == 0;
        }

        void swap(int &a, int &b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
};
