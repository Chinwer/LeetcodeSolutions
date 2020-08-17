/*
 * 401. Binary Watch
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0 - 11)
 * and the 6 LEDs on the bottom represent the minutes (0 - 59)
 *
 * Each LED represents a zero or one, with the least significant bit on the right.
 *
 * Given a non-negative integer n which represents the number of LEDs that
 * are currently on, return all possible times the watch could represent.
 *
 * Note:
 *   - The order of output does not matter.
 *   - The hour must not contain a leading zero, for example "01:00" is not valid,
 *     it should be "1:00".
 *   - THe minute must be consist of two digits and may contain a leading zero,
 *     for example "10:2" is not valid, it should be "10:02".
 */

#include "header.h"

class Solution {
    private:
        vector<string> res;
        unordered_map<int, int> digits = {
            {0, 1}, {1, 2}, {2, 4}, {3, 8}, {4, 1},
            {5, 2}, {6, 4}, {7, 8}, {8, 16}, {9, 32}
        };

    public:
        vector<string> readBinaryWatch(int num) {
            pair<int, int> time = { 0, 0 };
            backtrack(time, num, 0);
            return res;
        }

        void backtrack(pair<int, int> &time, int num, int start) {
            if (time.first > 11 || time.second > 59) {
                return;
            }
            if (!num) {
                string h = to_string(time.first);
                string m = to_string(time.second);
                if (time.second < 10) {
                    m = "0" + m;
                }
                res.push_back(h + ":" + m);
            } else {
                for (int i = start; i < 10; i++) {
                    auto tmp = time;
                    if (i < 4) {
                        time.first += digits[i];
                    } else {
                        time.second += digits[i];
                    }
                    backtrack(time, num - 1, i + 1);
                    time = tmp;
                }
            }
        }
};
