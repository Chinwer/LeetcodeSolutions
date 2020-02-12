/*
 * 485. Max Consecutive Ones
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 *
 * Note:
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 */

#include <vector>
using namespace std;

int max(int a, int b);

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            // int cnt = 0;
            // int res = 0;
            // int size = nums.size();
            // for (int i = 0; i < size; i++) {
            //     if (nums[i] == 1) {
            //         cnt += 1;
            //     } else {
            //         res = max(res, cnt);
            //         cnt = 0;
            //     }
            // }
            // return max(res, cnt);

            int size = nums.size();
            int front = -1, back = -1;
            int cnt = 0, res = 0;
            for (int i = 0; i < size; i++) {
                if (nums[i] == 0) {
                    back = i;
                    cnt = back - front - 1;
                    res = max(res, cnt);
                    front = i;
                }
            }
            res = max(res, size - front - 1);
            return res;
        }
};
