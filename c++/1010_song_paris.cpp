/*
 * 1010. Pairs of Songs With Total Durations Divisible by 60
 * In a list of songs, the i-th song has a duration of time[i] seconds. 
 *
 * Return the number of pairs of songs for which their total duration in seconds
 * is divisible by 60.  Formally, we want the number of indices i < j with
 * (time[i] + time[j]) % 60 == 0.
 *
 * Note:
 *
 * 1 <= time.length <= 60000
 * 1 <= time[i] <= 500
 */

#include "header.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> cnt(60, 0);

        for (int t : time) {
            int mod = t % 60;
            if (!mod) {
                res += cnt[mod];
            } else if (cnt[60 - mod] > 0) {
                res += cnt[60 - mod];
            }
            cnt[mod]++;
        }

        return res;
    }
};
