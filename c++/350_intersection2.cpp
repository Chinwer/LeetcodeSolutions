/*
 * 350. Intersection of Two Arrays II
 * Given two arrays, write a function to compute their intersection.
 *
 * Note:
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 * Follow up:
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 *
 * What if nums1's size is small compared to nums2's size? Which
 * algorithm is better?
 *
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 */

#include "header.h"

class Solution{
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            map<int, int> dict;
            for (int num : nums1) {
                dict[num]++;
            }
            for (int num : nums2) {
                if (dict[num] > 0) {
                    res.push_back(num);
                    dict[num]--;
                }
            }
            return res;
        }
};
