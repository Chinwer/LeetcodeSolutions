/*
 * 191. Number of 1 Bits
 *
 * Write a function that takes an unsigned integer and return the
 * number of '1' bits it has (also known as the Hamming weight).
 *
 * Note:
 *
 * Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above the input represents the signed integer -3.
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */

#include "header.h"

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int res = 0;
            while (n) {
                n &= n - 1;
                res++;
            }
            return res;
        }
};
