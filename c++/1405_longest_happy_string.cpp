/*
 * 1405. Longest Happy String
 *
 * A string is called happy if it does not have any of the string 'aaa', 'bbb' or 'ccc' as a substring.
 *
 * Given three integers a, b and c, return any string s, which satisfies following conditions:
 *   - s is happy and longest possible.
 *   - s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b'
 *     and at most c occurrences of the letter 'c'.
 *   - s will only contain 'a', 'b' and 'c' letters.
 *
 * If there is no such string s return the empty string "".
 *
 * Constraints:
 *   - 0 <= a, b, c <= 100
 *   - a + b + c > 0
 */

#include "header.h"

class Solution {
    public:
        string longestDiverseString(int a, int b, int c) {
            vector<pair<int, char>> left;
            left.push_back({ a, 'a' });
            left.push_back({ b, 'b' });
            left.push_back({ c, 'c' });

            string res;
            while (left[0].first || left[1].first || left[2].first) {
                sort(left.rbegin(), left.rend());
                if (res.empty() || res.back() != left[0].second) {
                    if (left[0].first-- > 0) {
                        res += left[0].second;
                    }
                    if (left[0].first-- > 0) {
                        res += left[0].second;
                    }
                } else {
                    if (left[1].first-- > 0) {
                        res += left[1].second;
                    } else {
                        break;
                    }
                }
            }
            return res;
        }
};
