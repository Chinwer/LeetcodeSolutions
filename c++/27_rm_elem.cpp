/*
 * 27. Remove Element
 * Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length. Do not allocate extra space for another
 * array, you must do this by modifying the input array in-place with O(1) extra
 * memory. The order of elements can be changed. It doesn't matter what you
 * leave beyond the new length.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = 0;
            int j = nums.size() - 1;

            while (j >= 0 && nums[j] == val) {
                j--;
            }

            while (i <= j) {
                if (nums[i] != val) {
                    i++;
                } else {
                    nums[i++] = nums[j--];
                    while (i <= j && nums[j] == val) {
                        j--;
                    }
                }
            }
            return i;
        }
};
