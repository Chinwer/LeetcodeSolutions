/*
 * 35. Search Insert Position
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order. You may assume no duplicates in the array.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int mid;
            int low = 0;
            int high = nums.size();

            while (low < high) {
                mid = (low + high) / 2;
                if (nums[mid] > target) {
                    high = mid;
                } else {
                    low = ++mid;
                }
            }
            return --low;
        }
};
