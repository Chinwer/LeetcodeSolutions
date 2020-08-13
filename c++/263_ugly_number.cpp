/*
 * 263. Ugly Number
 *
 * Write a program to check whether a given number is an ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include
 * 2, 3, 5.
 *
 * Note:
 *   1. 1 is typically treated as an ugly number.
 *   2. Input is within the 32-bit signed integer ranger: [-2^31, 2^31 - 1].
 */

#include "header.h"

class Solution {
    public:
        bool isUgly(int num) {
            if (num < 1) {
                return false;
            }
            int factors[3] = { 2, 3, 5 };
            for (int f : factors) {
                while (num % f == 0) {
                    num /= f;
                }
            }
            return num == 1;
        }
};
