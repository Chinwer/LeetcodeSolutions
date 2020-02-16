/*
 * Interview 01.02. Check Permutation
 */

#include "header.h"

class Solution {
    public:
        bool CheckPermutation(string s1, string s2) {
            int res = 0;

            for (char c : s1) {
                res ^= c;
            }
            for (char c : s2) {
                res ^= c;
            }

            return !res;
        }
};
