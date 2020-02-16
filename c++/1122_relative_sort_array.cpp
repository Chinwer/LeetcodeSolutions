/*
 * 1122. Relative Sort Array
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 *
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be placed
 * at the end of arr1 in ascending order.
 *
 * Constraints:
 *
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 */

#include "header.h"

class Solution {
    public:
        vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
            // map<int, int> cnt, pos;
            // int size1 = arr1.size();
            // int size2 = arr2.size();
            // vector<int> res, tail;

            // for (int i = 0; i < size2; i++) {
            //     pos[arr2[i]] = i;
            // }
            // for (int i = 0; i < size1; i++) {
            //     if (pos.count(arr1[i])) {
            //         cnt[arr1[i]]++;
            //     } else {
            //         tail.push_back(arr1[i]);
            //     }
            // }
            // for (int a : arr2) {
            //     for (int i = 0; i < cnt[a]; i++) {
            //         res.push_back(a);
            //     }
            // }
            // sort(tail.begin(), tail.end());
            // res.insert(res.end(), tail.begin(), tail.end());
            // return res;
        }
};
