/*
 * 69. Sqrt(x)
 * 
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 */

#include "header.h"

class Solution {
    public:
        int mySqrt(int x) {
            if (x < 2) {
                return x;
            }

            return method_rec(x);
        }

        int method_calcu(int x) {
            int l = (int) exp(0.5 * log(x));
            int r = l + 1;
            // Overflow error!
            return r * r > x ? l : r;
        }

        int method_bin(int x) {
            // Overflow error!
            int l = 2, r = x / 2 + 1;
            while (l < r) {
                int m = l + (r - l) / 2;
                int div = x / m;
                if (m == div) {
                    return m;
                } else if (m < div) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            return --l;
        }

        // Stack overflow
        int method_rec(int x) {
            int l = method_rec(x >> 2) << 1;
            int r = l + 1;
            return r * r > x ? l : r;
        }

        int method_newton(int x) {
            double x0 = x;
            double x1 = (x0 + x / x0) / 2;
            while (abs(x0 - x1) >= 1) {
                x0 = x1;
                x1 = (x0 + x / x0) / 2;
            }
            return int(x1);
        }
};
