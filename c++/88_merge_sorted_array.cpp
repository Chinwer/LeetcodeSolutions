/*
 * 88. Merge Sorted Array
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *     1. The number of elements initialized in nums1 and nums2 are m and n respectively.
 *     2. You may assume that nums1 has enough space (size that is greater or equal to m
 *        + n) to hold additional elements from nums2.
 */

#include <vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if (!n) {
                return;
            }

            int i = 0, j = 0, idx = 0;
            vector<int> tmp(nums1.begin(), nums1.begin() + m);

            while (i < m && j < n) {
                if (tmp[i] <= nums2[j]) {
                    nums1[idx++] = tmp[i++];
                } else {
                  nums1[idx++] = nums2[j++];
                }
            }
            while (i < m) {
                nums1[idx++] = tmp[i++];
            }
            while (j < n) {
                nums1[idx++] = nums2[j++];
            }
        }
};
