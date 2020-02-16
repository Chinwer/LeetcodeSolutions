/*
 * 1331. Rank Transform of an Array
 * Given an array of integers arr, replace each element with its rank.
 *
 * The rank represents how large the element is. The rank has the following
 * rules:
 *
 * Rank is an integer starting from 1.
 * The larger the element, the larger the rank. If two elements are equal, their
 * rank must be the same. Rank should be as small as possible.
 *
 * Constraints:
 *
 * 0 <= arr.length <= 105
 * -109 <= arr[i] <= 109
 */

#include "header.h"

class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            int idx = 0, cnt = 1;
            map<int, int> hash;
            vector<int> res(arr);

            sort(res.begin(),res.end());

            for (int num : res) {
                if (!hash[num]) {
                    hash[num] = cnt++;
                }
            }
            for (int num : arr) {
                res[idx++] = hash[num];
            }
            return res;
        }
};
