/*
 * 457. Circular Array Loop
 *
 * You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

 * Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

 
 * Note:

 * -1000 ≤ nums[i] ≤ 1000
 * nums[i] ≠ 0
 * 1 ≤ nums.length ≤ 5000
 */

#include "header.h"

class Solution {
    public:
        bool circularArrayLoop(vector<int>& nums) {
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                int last_pos, pos = i, len = 1;
                bool direction = nums[i] > 0;
                /***********************
                 * Attention here! CANNOT USE MAP HERE, USE ARRAY INSTEAD!
                 * Explanation:
                 *   access a map is slower than an array
                 */
                // map<int, bool> accessed;
                vector<int> accessed(size, 0);
                do {
                    if (accessed[pos]) {
                        break;
                    }
                    last_pos = pos;
                    accessed[pos] = 1;
                    pos = (((pos + nums[pos]) % size) + size) % size;
                    if (pos == i && len > 1) {
                        return true;
                    }
                    len++;
                } while (nums[pos] > 0 == direction);
            }
            return false;
        }
};
