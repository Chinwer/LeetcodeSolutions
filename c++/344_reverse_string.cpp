/*
 * 344. Reverse String
 *
 * Write a function that reverses a string. The input string is
 * given as an array of characters char[].
 *
 * Do not allocate extra space for another array, you must do this
 * by modifying the input array in-place with O(1) extra memory.
 *
 * You may assume all the characters consist of printable ascii characters.

 */

#include "header.h"
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};
