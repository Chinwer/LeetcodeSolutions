/*
 * 1089. Duplicate Zeros
 * Given a fixed length array arr of integers, duplicate each occurrence of
 * zero, shifting the remaining elements to the right.
 *
 * Note that elements beyond the length of the original array are not written.
 *
 * Do the above modifications to the input array in place, do not return
 * anything from your function.
 *
 * Note:
 *
 * 1 <= arr.length <= 10000
 * 0 <= arr[i] <= 9
 */

#include "header.h"

class Solution {
    public:
        void duplicateZeros(vector<int>& arr) {
            int size = arr.size();
            map<int, int> delta;

            int cnt = 0;
            // Whether the rightest zero should be duplicated
            bool flag = false;
            int l = 0, r = size - 1;

            while (l < r) {
                if (!arr[l++]) {
                    cnt++;
                    r--;
                }
            }

            flag = (l != r);

            int tmp = size - 1 - cnt;
            l = tmp;
            r = size - 1;

            while (cnt > 0) {
                if (!arr[l] && (l != tmp || flag)) {
                    cnt--;
                    arr[r--] = 0;
                    arr[r--] = 0;
                } else {
                    arr[r--] = arr[l];
                }
                l--;
            }
        }
};
