/*
 * 1243. Array Transformation
 * Given an initial array arr, every day you produce a new array using the array
 * of the previous day.
 *
 * On the i-th day, you do the following operations on the array of day i-1 to
 * produce the array of day i:
 *
 * If an element is smaller than both its left neighbor and its right neighbor,
 * then this element is incremented. If an element is bigger than both its left
 * neighbor and its right neighbor, then this element is decremented. The
 * first and last elements never change. After some days, the array does not
 * change. Return that final array.
 *
 * Constraints:
 *
 * 1 <= arr.length <= 100
 * 1 <= arr[i] <= 100
 */

#include "header.h"

class Solution {
    public:
        vector<int> transformArray(vector<int>& arr) {
            int cnt;
            vector<int> res(arr);
            int size = arr.size();

            do {
                cnt = 0;
                vector<int> tmp(res);
                for (int i = 1; i < size - 1; i++) {
                    if (tmp[i - 1] < tmp[i] && tmp[i] > tmp[i + 1]) {
                        cnt++;
                        res[i]--;
                    } else if (tmp[i - 1] > tmp[i] && tmp[i] < tmp[i + 1]) {
                        cnt++;
                        res[i]++;
                    }
                }
            } while (cnt);

            return res;
        }
};
