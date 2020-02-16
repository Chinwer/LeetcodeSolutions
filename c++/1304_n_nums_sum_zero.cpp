/*
 * 1304. Find N Unique Integers Sum up to Zero
 * Given an integer n, return any array containing n unique integers such that
 * they add up to 0.
 *
 * Constraints:
 *
 * 1 <= n <= 1000
 */

#include "header.h"

class Solution {
    public:
        vector<int> sumZero(int n) {
            /* Method 1 */
            // vector<int> res;
            // if (n % 2) {
            //     res.push_back(0);
            // }
            // for (int i = 1; i <= n / 2; i++) {
            //     res.push_back(i);
            //     res.push_back(-i);
            // }
            // return res;

            /* Method 2, double pointers */
            vector<int> res(n, 0);
            int i = n / 2, l = 0, r = n - 1;
            while (l < r) {
                res[l++] = -i;
                res[r--] = i;
                i--;
            }
            return res;
        }
};
