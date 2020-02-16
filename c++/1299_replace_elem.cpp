/*
 * 1299. Replace Elements with Greatest Element on Right Side
 * Given an array arr, replace every element in that array with the greatest
 * element among the elements to its right, and replace the last element with
 * -1.
 *
 * After doing so, return the array.
 *
 * Constraints:
 *
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i] <= 10^5
 */

#include "header.h"

class Solution {
    public:
        vector<int> replaceElements(vector<int>& arr) {
            int size = arr.size();
            int max = arr[size - 1];
            vector<int> res(size, -1);

            for (int i = size - 2; i >= 0; i--) {
                res[i] = max;
                if (arr[i] > max) {
                    max = arr[i];
                }
            }

            return res;
        }
};
