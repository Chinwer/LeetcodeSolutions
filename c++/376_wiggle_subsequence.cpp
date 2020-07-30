/*
 * 376. Wiggle Subsequence
 *
 *
 * A sequence of numbers is called a wiggle sequence if the
 * differences between successive numbers strictly alternate
 * between positive and negative. The first difference
 * (if one exists) may be either positive or negative.
 * A sequence with fewer than two elements is trivially a
 * wiggle sequence.
 *
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the
 * differences (6,-3,5,-7,3) are alternately positive and negative.
 * In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences,
 * the first because its first two differences are positive and the
 * second because its last difference is zero.
 *
 * Given a sequence of integers, return the length of the longest
 * subsequence that is a wiggle sequence. A subsequence is obtained
 * by deleting some number of elements (eventually, also zero) from
 * the original sequence, leaving the remaining elements in their original order.
 *
 * Follow up:
 * Can you do it in O(n) time?
 */

#include "header.h"

class Solution {
    public:
        int wiggleMaxLength(vector<int>& nums) {
            // return greedy_solution(nums);
            // return dp(nums);
            return greedy_optimized(nums);
        }

        int greedy_optimized(vector<int> &nums) {
            int n = nums.size();
            if (n < 2) {
                return n;
            }
            int flag = nums[1] - nums[0];
            int res = flag ? 2 : 1;
            for (int i = 2; i < n; i++) {
                int diff = nums[i] - nums[i - 1];
                if ((diff > 0 && flag <= 0) || (diff < 0 && flag >= 0)) {
                    res++;
                    flag = diff;
                }
            }
            return res;
        }

        int dp(vector<int> &nums) {
            int n = nums.size();
            if (n < 2) {
                return n;
            }
            int up = 1, down = 1;
            for (int i = 1; i < n; i++) {
                if (nums[i] > nums[i - 1]) {
                    up = down + 1;
                } else if (nums[i] < nums[i - 1]) {
                    down = up + 1;
                }
            }
            return max(up, down);
        }

        int greedy_solution(vector<int> &nums) {
            int n = nums.size();
            if (n < 2) {
                return n;
            }
            bool diff;
            int i = 0, res = 0;
            while (i < n - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
            if (i == n - 1) {
                return 1;
            }
            res++;
            diff = nums[i] > nums[++i];
            while (i < n - 1) {
                if (nums[i] == nums[i + 1]) {
                    i++;
                    continue;
                }
                if ((nums[i] > nums[i + 1]) == diff) {
                    i++;
                    continue;
                }
                i++;
                res++;
                diff = !diff;
            }
            return res;
        }
};
