/*
 * 1200. Minimum Absolute Difference
 * Given an array of distinct integers arr, find all pairs of elements with the
 * minimum absolute difference of any two elements. 
 *
 * Return a list of pairs in ascending order(with respect to pairs), each pair
 * [a, b] follows
 *
 * a, b are from arr
 * a < b
 * b - a equals to the minimum absolute difference of any two elements in arr
 *
 * Constraints:
 *
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 */

#include "header.h"

class Solution {
    public:
        vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
            std::ios::sync_with_stdio(false);
            vector<vector<int>> res;
            int size = arr.size();
            int min_diff = INT32_MAX;
            sort(arr.begin(), arr.end());

            for (int i = 0; i < size - 1; i++) {
                if (arr[i + 1] - arr[i] < min_diff) {
                    min_diff =  arr[i + 1] - arr[i];
                }
            }

            for (int i = 0; i < size - 1; i++) {
                if (arr[i + 1] - arr[i] == min_diff) {
                    res.push_back({ arr[i], arr[i + 1] });
                }
            }

            return res;
        }
};
