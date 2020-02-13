/*
 * 561. Array Partition I
 * Given an array of 2n integers, your task is to group these integers into n
 * pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of
 * min(ai, bi) for all i from 1 to n as large as possible.
 *
 * Note:
 *     n is a positive integer, which is in the range of [1, 10000].
 *     All the integers in the array will be in the range of [-10000, 10000].
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int res = 0;
            int size = nums.size();
            for (int i = 0; i < size; i += 2) {
                res += nums[i];
            }
            return res;
        }
};
