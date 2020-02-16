/*
 * 1287. Element Appearing More Than 25% In Sorted Array
 * Given an integer array sorted in non-decreasing order, there is exactly one
 * integer in the array that occurs more than 25% of the time.
 *
 * Return that integer.
 *
 * Constraints:
 *
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^5
 */

#include "header.h"

class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int cnt = 1;
            int size = arr.size();
            int candidate = arr[0];

            for (int i = 0; i < size - 1; i++) {
                if (arr[i + 1] == arr[i]) {
                    cnt++;
                } else {
                    if (cnt > size / 4) {
                        return candidate;
                    } else {
                        candidate = arr[i + 1];
                        cnt = 1;
                    }
                }
            }
            return candidate;
        }
};
