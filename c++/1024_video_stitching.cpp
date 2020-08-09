/*
 * 1024. Video Stitching
 *
 * You are given a series of video clips from a sporting event that
 * lasted T seconds. These video clips can be overlapping with each
 * other and have varied lengths.
 *
 * Each video clip clips[i] is an interval: it starts at time clips[i][0]
 * and ends at time clips[i][1]. We can cut these clips into segments freely:
 * for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
 *
 * Return the minimum number of clips needed so that we can cut the
 * clips into segments that cover the entire sporting event ([0, T]). If
 * the task is impossible, return -1.
 *
 * Constraints:
 *   - 1 <= clips.length <= 100
 *   - 0 <= clips[i][0] <= clips[i][1] <= 100
 *   - 0 <= T <= 100
 */

#include "header.h"

class Solution {
    public:
        int videoStitching(vector<vector<int>>& clips, int T) {
            // return greedy(clips, T);
            return dynamic_programming(clips, T);
        }

        int dynamic_programming(vector<vector<int>>& clips, int T) {
            int n = clips.size();
            vector<int> dp(T + 1, INT_MAX);
            // base case
            dp[0] = 0;
            for (int i = 1; i <= T; i++) {
                for (int j = 0; j < n; j++) {
                    if (clips[j][0] <= i && clips[j][1] >= i) {
                        dp[i] = min(dp[i], dp[clips[j][0]] + 1);
                    }
                }
            }
            return dp[T] == INT_MAX ? -1 : dp[T];
        }

        int greedy(vector<vector<int>>& clips, int T) {
            int n = clips.size();
            sort(clips.begin(), clips.end(), compare);
            int res = 0, cur_start = 0, max_end = 0;

            int i = 0;
            while (i < n && max_end < T) {
                cur_start = max_end;
                max_end = 0;
                if (clips[i][0] > cur_start) {
                    return -1;
                }
                while (i < n && clips[i][0] <= cur_start) {
                    if (clips[i][1] > max_end) {
                        max_end = clips[i][1];
                    }
                    i++;
                }
                res++;
            }
            return max_end >= T ? res : -1;
        }

        static bool compare(const vector<int> &clip1, const vector<int> &clip2) {
            return clip1[0] < clip2[0];
        }
};
