/*
 * 1218. Longest Arithmetic Subsequence of Given Difference
 *
 * Given an integer array arr and an integer difference, return the
 * length of the longest subsequence in arr which is an arithmetic
 * sequence such that the difference between adjacent elements in the
 * subsequence equals difference.
 *
 * Constraints:
 *   - 1 <= arr.length <= 10^5
 *   - -10^4 <= arr[i], difference <= 10^4
 */

#include "header.h"

class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            int res = 1;
            int n = arr.size();
            unordered_map<int, int> hash;
            for (int i : arr) {
                int tmp = hash[i - difference] + 1;
                hash[i] = tmp;
                res = max(res, tmp);
            }
            return res;
        }
};
