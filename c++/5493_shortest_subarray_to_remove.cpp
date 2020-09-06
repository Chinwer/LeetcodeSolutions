/*
 * 5493. Shortest Subarray to be Removed to Make Array Sorted
 *
 * Given an integer array arr, remove a subarray (can be empty)
 * from arr such that the remaining elements in arr are non-decreasing.
 *
 * A subarray is c contiguous subsequence of the array.
 *
 * Return the length of the shortest subarray to remove.
 *
 * Constraints:
 *   - 1 <= arr.length <= 10^5
 *   - 0 <= arr[i] <= 10^9
 */

#include "header.h"

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), l = 0, r = n - 1;
        while (l < n - 1 && arr[l] <= arr[l + 1]) {
            l++;
        }
        while (r > 0 && arr[r - 1] <= arr[r]) {
            r--;
        }
        if (l == n - 1) {
            return 0;
        }
        if (r == 0) {
            return n - 1;
        }
        int res = min(n - l - 1, r);

        int i = 0, j = r;
        while (i <= j && i <= l && j < n) {
            if (arr[i] > arr[j]) {
                j++;
            } else {
                i++;
                res = min(res, j - i);
            }
        }
        return res;
    }
};