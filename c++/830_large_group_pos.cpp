/*
 * 830. Positions of Large Groups
 * In a string S of lowercase letters, these letters form consecutive groups of
 * the same character. For example, a string like S = "abbxxxxzyy" has the
 * groups "a", "bb", "xxxx", "z" and "yy". Call a group large if it has 3 or
 * more characters.  We would like the starting and ending positions of every
 * large group. The final answer should be in lexicographic order.
 *
 * Note:  1 <= S.length <= 1000
 */


#include "header.h"

class Solution {
    public:
        vector<vector<int>> largeGroupPositions(string S) {
            int l = 0, r = 0;
            int len = S.length();
            vector<vector<int>> res;

            while (r < len) {
                if (S[r] == S[r + 1]) {
                    r++;
                } else {
                    if (r - l >= 2) {
                        res.push_back({l, r});
                    }
                    r++;
                    l = r;
                }
            }
            return res;
        }
};
