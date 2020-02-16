/*
 * Interview 01.01. Is Unique
 *
 */

#include "header.h"

class Solution {
    public:
        bool isUnique(string astr) {
            // int cnt[26] = { 0 };
            // for (char c : astr) {
            //     int i = c - 'a';
            //     cnt[i]++;
            //     if (cnt[i] > 1) {
            //         return false;
            //     }
            // }
            // return true;

            // Bit Operation Method
            int flag = 0;

            for (char c : astr) {
                int tmp = c - 'a';
                if (flag & (1 << tmp)) {
                    return false;
                }
                flag |= (1 << tmp);
            }

            return true;
        }
};
