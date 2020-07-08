/*
 * 125. Valid Palindrome
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note:
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 * Constraints:
 * s consists only of printable ASCII characters.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            if (s.empty()) {
                return true;
            }

            int l = 0, r = s.size() - 1;
            while (l <= r) {
                while (l <= r && !isalnum(s[l])) {
                    l++;
                }
                while (l <= r && !isalnum(s[r])) {
                    r--;
                }
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
};
