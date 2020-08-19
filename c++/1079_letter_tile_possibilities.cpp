/*
 * 1079. Letter Tile Possibilities
 *
 * You have n tiles, where each tile has one letter tiles[i] printed on it.
 *
 * Return the number of possible non-empty sequences of letters you can
 * make using the letters printed on those tiles.
 *
 * Constraints:
 *   - 1 <= tiles.length <= 7
 *   - tiles consists of uppercase English letters.
 */

#include "header.h"

class Solution {
    private:
        int res;

    public:
        int numTilePossibilities(string tiles) {
            vector<int> cnt(26);
            for (char c : tiles) {
                cnt[c - 'A']++;
            }
            backtrack(cnt);
            return res;
        }

        void backtrack(vector<int> &cnt) {
            for (int i = 0; i < 26; i++) {
                if (!cnt[i]) {
                    continue;
                }
                res++;
                cnt[i]--;
                backtrack(cnt);
                cnt[i]++;
            }
        }
};
