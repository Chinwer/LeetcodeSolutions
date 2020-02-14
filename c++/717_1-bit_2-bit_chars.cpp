/*
 * 717. 1-bit and 2-bit Characters
 * We have two special characters. The first character can be represented by one
 * bit 0. The second character can be represented by two bits (10 or 11). Now
 * given a string represented by several bits. Return whether the last character
 * must be a one-bit character or not. The given string will always end with a
 * zero.
 *
 * Note:
 * 1 <= len(bits) <= 1000.
 * bits[i] is always 0 or 1.
 */

#include "header.h"

class Solution {
    public:
        bool isOneBitCharacter(vector<int>& bits) {
            // int last = bits.size() - 1;
            // int i = 0;
            // while (i < last) {
            //     if (bits[i] == 1) {
            //         i += 2;
            //         if (i > last) {
            //             return false;
            //         }
            //     } else {
            //         i++;
            //     }
            // }
            // return true;

            // int last = bits.size() - 1;
            // int i = 0;
            // while (i < last) {
            //     i += (bits[i] + 1);
            // }
            // return i == last;

            // Greedy algorithm
            int size = bits.size();
            int i = size - 2;
            while (i && bits[i]) {
                i--;
            }
            return (size - i) % 2 == 0;
        }
};
