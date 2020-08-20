/*
 * 1239. Maximum Length of a Concatenated String with Unique Characters
 *
 * Given an array of strings arr. String s is a concatenation of a
 * subsequence of arr which have unique characters.
 *
 * Return the maximum possible length of s.
 *
 * Constraints:
 *   - 1 <= arr.length <= 16
 *   - 1 <= arr[i].length <= 26
 *   - arr[i] contains only lowercase English letters.
 */

#include "header.h"

class Solution {
    private:
        int n, res = 0;
        vector<string> arr;

    public:
        int maxLength(vector<string>& arr) {
            n = arr.size();
            this->arr = arr;
            backtrack(0, 0, 0);
            return res;
        }

        void backtrack(int start, int mask, int len) {
            res = max(res, len);
            for (int i = start; i < n; i++) {
                int m = get_mask(arr[i]);
                if (m == -1 || (m & mask) > 0) {
                    continue;
                }
                backtrack(i + 1, mask | m, len + arr[i].size());
            }
        }

        int get_mask(string &s) {
            int res = 0;
            for (char &c : s) {
                int num = 1 << (c - 'a');
                if ((res & num) > 0) {
                    return -1;
                }
                res |= num;
            }
            return res;
        }
};
