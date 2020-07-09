/*
 * 763. Partition Labels
 *
 * A string S of lowercase English letters is given. We want to partition this
 * string into as many parts as possible so that each letter appears in at
 * most one part, and return a list of integers representing the size of these parts.
 *
 * Note:
 * S will have length in range [1, 500].
 * S will consist of lowercase English letters ('a' to 'z') only.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        vector<int> partitionLabels(string S) {
            vector<int> res;
            int len = S.length();
            map<char, int> last_pos;
            // find the last position of every character
            for (int i = 0; i < len; i++) {
                last_pos[S[i]] = i;
            }

            int start = 0, end;
            while (start < len) {
                end = last_pos[S[start]];
                for (int i = start; i < end; i++) {
                    if (S[i] != S[start] && last_pos[S[i]] > end) {
                        // expand the partition
                        end = last_pos[S[i]];
                    }
                }
                res.push_back(end - start + 1);
                start = ++end;
            }
            return res;
        }
};
