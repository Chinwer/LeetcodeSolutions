/*
 * 面试题 08.01. Three Steps Problem LCCI
 *
 * A child is running up a staircase with n steps and can hop either 1 step,
 * 2 steps or 3 steps at a time. Implement a method to count how many possible
 * ways the child can run up the stairs. The result may be large, so return it
 * module 1000000007
 *
 * Note:
 *   1 <= n <= 1000000
 */

#include "header.h"

class Solution {
    public:
        int waysToStep(int n) {
            if (n < 3) {
                return n;
            }
            if (n == 3) {
                return 4;
            }
            int mod = 1000000007;
            int res, prev = 4, pprev = 2, ppprev = 1;
            for (int i = 0; i < n - 2; i++) {
                res = (((prev % mod)+ pprev) % mod + ppprev) % mod;
                ppprev = pprev;
                pprev = prev;
                prev = res;
            }
            return res;
        }
};
