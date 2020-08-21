/*
 * 691. Stickers to Spell Word
 *
 * We are given N different types of stickers. Each sticker has a lowercase English word on it.
 *
 * You would like to spell out the given target string by cutting individual letters from your
 * collection of stickers and rearranging them.
 *
 * You can use each sticker more than once if you want, and you have infinite quantities of
 * each stickers.
 *
 * What is the minimum number of stickers that you need to spell out the target?
 * If the task is impossible, return -1.
 *
 * Note:
 *   - stickers has length in the range [1, 50].
 *   - stickers consists of lowercase English words (without apostrophes).
 *   - target has length in the range [1, 15], and consists of lowercase English letters.
 *   - In all test cases, all words were chosen randomly from the 1000 most common US English
 *     words, and the target was chosen as a concatenation of two random words.
 *   - The time limit may be more challenging than usual. It is expected that a 50 sticker
 *     test case can be solved within 35ms on average.
 */

#include "header.h"

class Solution {
    private:
        int INF = 0x3f3f3f3f;

    public:
        int minStickers(vector<string>& stickers, string target) {
            int n = stickers.size(), m = target.size(), len = 1 << m;
            vector<vector<int>> cnt(n, vector(26, 0));
            for (int i = 0; i < n; i++) {
                for (char c : stickers[i]) {
                    cnt[i][c - 'a']++;
                }
            }
            vector<int> dp(len, INF);
            dp[0] = 0;
            for (int i = 0; i < len; i++) {
                if (dp[i] == INF) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    int next = i;
                    vector<int> tmp = cnt[j];
                    for (int k = 0; k < m; k++) {
                        if (next & (1 << k)) {
                            continue;
                        }
                        if (tmp[target[k] - 'a'] > 0) {
                            next |= (1 << k);
                            tmp[target[k] - 'a']--;
                        }
                    }
                    dp[next] = min(dp[next], dp[i] + 1);
                }
            }
            return dp[len - 1] == INF ? -1 : dp[len - 1];
        }
};
