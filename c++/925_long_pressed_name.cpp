/*
 * 925. Long Pressed Name
 * Your friend is typing his name into a keyboard.  Sometimes, when typing a character c,
 * the key might get long pressed, and the character will be typed 1 or more times.
 *
 * You examine the typed characters of the keyboard.  Return True if it is possible that
 * it was your friends name, with some characters (possibly none) being long pressed.
 *
 * Constraints:
 *
 * 1 <= name.length <= 1000
 * 1 <= typed.length <= 1000
 * The characters of name and typed are lowercase letters.
 */

#include "header.h"
using namespace std;

class Solution {
    public:
        bool isLongPressedName(string name, string typed) {
            int slow = 0, fast = 0;
            int len1 = name.length();
            int len2 = typed.length();
            while (slow < len1 || fast < len2) {
                if (name[slow] == typed[fast]) {
                    slow++;
                    fast++;
                } else {
                    if (slow > 0 && name[slow - 1] == typed[fast]) {
                        fast++;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
};
