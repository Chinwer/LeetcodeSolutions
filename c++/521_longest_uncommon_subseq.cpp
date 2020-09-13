/*
 * 521. Longest Uncommon Subsequence I
 *
 * Given two strings a and b, find the length of the longest uncommon subsequence between them.
 *
 * A subsequence of a string s is a string that can be obtained after deleting any number of
 * characters from s. For example, "abc" is a subsequence of "aebdc" because you can delete the
 * underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc",
 * "aeb", and "" (empty string).
 *
 * An uncommon subsequence between two strings is a string that is a subsequence of one but not the other.
 *
 * Return the length of the longest uncommon subsequence between a and b. If the longest
 * uncommon subsequence doesn't exist, return -1.
 *
 * Constraints:
 *
 * 1 <= a.length, b.length <= 100
 * a and b consist of lower-case English letters.
 */

#include "header.h"

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};