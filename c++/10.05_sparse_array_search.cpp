/*
 * 面试题 10.05. Sparse Array Search LCCI
 *
 * Given a sorted array of strings that is interspersed with empty strings,
 * write a method to find the location of a given string.
 * Note:
 *   - 1 <= words.length <= 1000000
 */

#include "header.h"

class Solution {
    public:
        int findString(vector<string>& words, string s) {
            int size = words.size();
            int left = 0, right = size - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int tmp = mid;
                while (words[mid] == "" && mid > left) {
                    mid--;
                }
                if (words[mid] == "") {
                    left = mid + 1;
                    continue;
                }
                if (words[mid] == s) {
                    return mid;
                } else if (words[mid] < s) {
                    left = tmp + 1;
                } else {
                    right = tmp - 1;
                }
            }
            return -1;
        }
};
