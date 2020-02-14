/*
 * 349. Intersection of Two Arrays
 * Given two arrays, write a function to compute their intersection.
 *
 * Note:
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 */

#include "header.h"

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            /* Method 1 */

            //  vector<int> res;
            // map<int, int> dict;
            // map<int, bool> added;
            // for (int num : nums1) {
            //     dict[num]++;
            // }
            // for (int num : nums2) {
            //     if (dict.count(num) && !added.count(num)) {
            //         res.push_back(num);
            //         added[num] = true;
            //     }
            // }
            // return res;

            /* Method 2 */

            // set<int> res;
            // map<int, int> dict;
            // for (int num : nums1) {
            //     dict[num]++;
            // }
            // for (int num : nums2) {
            //     if (dict.count(num)) {
            //         res.insert(res.end(), num);
            //     }
            // }
            // return vector<int>(res.begin(), res.end());

            /* Method 3 */
            vector<int> res;
            set<int> nums(nums1.begin(), nums1.end());
            for (int num : nums2) {
                if (nums.erase(num)) {
                    res.push_back(num);
                }
            }
            return res;
        }
};
