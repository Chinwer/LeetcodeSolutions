/*
 * Interview 08.03. Magic Index
 */

#include "header.h"

class Solution {
    public:
        int findMagicIndex(vector<int>& nums) {
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                if (nums[i] == i) {
                    return i;
                }
            }
            return -1;
        }
};
