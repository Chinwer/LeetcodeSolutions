/*
 * 424. Longest Repeating Character Replacement
 *
 * Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
 * In one operation, you can choose any character of the string and change it to any other uppercase English character.
 * Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
 *
 * Note:
 * Both the string's length and k will not exceed 104.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {
            map<char, int> cnt;
            int len = s.length();
            int res = 0, slow = 0, fast = 0, max_count = 0;
            while (fast < len) {
                cnt[s[fast]]++;
                max_count = max(max_count, cnt[s[fast]]);
                while (max_count + k < fast - slow + 1) {
                    cnt[s[slow]]--;
                    slow++;
                }
                res = max(res, fast - slow + 1);
                fast++;
            }
            return res;
        }
};
